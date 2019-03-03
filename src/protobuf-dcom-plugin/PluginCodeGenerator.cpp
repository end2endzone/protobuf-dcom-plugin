#include "PluginCodeGenerator.h"
#include <google/protobuf/compiler/cpp/cpp_generator.h>
#include "StreamPrinter.h"
#include "DebugPrinter.h"
#include "ResourceFiles.h"
#include "MacroManager.h"
#include "stringfunc.h"
#include "protofunc.h"
#include "path.h"
#include "dcom.h"
#include "Md5GuidGenerator.h"

#include "FileDescriptorServiceRemover.h"
#include "DComGenerator.h"
#include "ComponentManager.h"

#include <windows.h>

PluginCodeGenerator::PluginCodeGenerator()
{
}

PluginCodeGenerator::~PluginCodeGenerator()
{
}

bool PluginCodeGenerator::Generate(const FileDescriptor * file, const std::string & parameter, GeneratorContext * generator_context, string * error) const
{
#if 0
  static const char * caption = "Debug breakpoint";
  std::string message = "protobuf-dcom-plugin" + std::string("\n\nFile: '") + file->name() + "'.";
  MessageBox(NULL,message.c_str(), caption, 0);
  int a = 0;
#endif

  MacroManager & mgr = MacroManager::getInstance();

  //Generate the C++ code for the service (without generating the services stub)
  //The services will be generated by this plugins
  FileDescriptorServiceRemover r;
  const FileDescriptor * noServiceFile = r.removeServicesFrom(file);
  google::protobuf::compiler::cpp::CppGenerator cpp_generator;
  bool success = cpp_generator.Generate(noServiceFile, parameter, generator_context, error);
  if (!success)
    return false;

  //also generate dcomplugin.proto c++ code
  int numDependencies = file->dependency_count();
  for(int i=0; i<numDependencies; i++)
  {
    const google::protobuf::FileDescriptor * dcompluginDescriptor = file->dependency(i);
    const std::string & name = dcompluginDescriptor->name();
    if (name == "dcomplugin.proto")
    {
      bool success = cpp_generator.Generate(dcompluginDescriptor, parameter, generator_context, error);
      if (!success)
        return false;
    }
  }

  //Show content of the file
  DebugPrinter debugger(generator_context);
  debugger.printFile(file, "debug.txt");

  //Get Component message content
  const google::protobuf::FileOptions & options = file->options();
  dcomplugin::Component componentCopy = options.GetExtension(dcomplugin::component);

  //Validate
  std::string tmp;
  if (error == NULL)
    error = &tmp;
  if (!ComponentManager::validate(componentCopy, "option (dcomplugin.component)", (*error) ))
  {
    //component has missing fields.
    //try to fill the gaps
    ComponentManager::build(componentCopy, (*file) );

    //clear previous errors
    (*error) = "";
    if (!ComponentManager::validate(componentCopy, "option (dcomplugin.component)", (*error) ))
    {
      return false;
    }

    //component is now configured properly
  }

  //prepare generator
  DComGenerator gen;
  gen.init(file, componentCopy);

  //Generate macros based on dcomplugin::Component settings
  MacroManager & macromgr = MacroManager::getInstance();
  registerPropertiesMacros(file, componentCopy);
  registerCodeGenerationMacros(file, componentCopy);

  //extract each files to plugin's output directory
  FileList files = getResourceFiles();
  for(size_t i=0; i<files.size(); i++)
  {
    bin2cpp::File * fileResource = files[i];
    
    std::string filename = fileResource->getFilename();
    macromgr.replaceMacros(filename);

    size_t fileSize = fileResource->getSize();

    //copy content of the file into a private buffer that supports macro replacement
    std::string content;
    char * fileBufferTmp = fileResource->newBuffer();
    if (fileBufferTmp)
    {
      content = toString(fileBufferTmp, fileSize);
      delete[] fileBufferTmp;
      fileBufferTmp = NULL;
    }

    if (filename == "IService.h")
    {
      //duplicate this file for each services...
      int numServices = file->service_count();
      for(int j=0; j<numServices; j++)
      {
        const google::protobuf::ServiceDescriptor * d = file->service(j);
        const std::string & serviceName = d->name();

        //register/register macros for this specific service
        registerServiceBasedMacros(j, file, componentCopy);

        //prepare new filename
        filename.clear();
        filename << "I" << capitalizeFirst(serviceName) << ".h";

        //duplicate content
        std::string fileCopy = content;

        //replace macros in file
        macromgr.replaceMacros(fileCopy);

        //dump content to file
        google::protobuf::io::ZeroCopyOutputStream * s = generator_context->Open(filename.c_str());
        StreamPrinter printer(s); //StreamPrinter takes ownership of the Stream
        printer.print(fileCopy);
      }
    }
    else
    {
      //replace macros in file
      macromgr.replaceMacros(content);

      //dump content to file
      google::protobuf::io::ZeroCopyOutputStream * s = generator_context->Open(filename.c_str());
      StreamPrinter printer(s); //StreamPrinter takes ownership of the Stream
      printer.print(content);
    }
  }

  //Output the modified proto file (with the new generated GUID)
  {
    google::protobuf::FileDescriptorProto protoFile;
    (*file).CopyTo(&protoFile);
    
    //https://groups.google.com/forum/#!topic/protobuf/mKLLDUTgHa4
    //replace component by the modified version
    protoFile.mutable_options()->MutableExtension(dcomplugin::component)->CopyFrom(componentCopy);

    //convert to proto code
    std::string protoCode = toProtoString(protoFile);

    //dump proto code into a file
    std::string protoFilename = getFileNameWithoutExtension(file->name()) << ".proto";
    google::protobuf::io::ZeroCopyOutputStream * stream = generator_context->Open(protoFilename.c_str());
    StreamPrinter printer(stream); //StreamPrinter takes ownership of the Stream
    printer.print("%s", protoCode.c_str());
  }
  int zz = 0;


  if (error)
  {
    std::string & e = (*error);
    //e = "unknown error";
  }

  return true;
}

void PluginCodeGenerator::registerPropertiesMacros(const FileDescriptor * file, const dcomplugin::Component & c) const
{
  MacroManager & mgr = MacroManager::getInstance();

  Md5GuidGenerator gen;
  gen.setProtoFilename( getFileNameWithoutExtension(file->name()) );
  gen.setPackage(file->package());
  gen.setComponentName(c.name());

  //DCOMPLUGIN_PACKAGE_NAME
  mgr.registerMacro("DCOMPLUGIN_PACKAGE_NAME", file->package());

  //DCOMPLUGIN_PROTO_FILE_NAME
  mgr.registerMacro("DCOMPLUGIN_PROTO_FILE_NAME", getFileNameWithoutExtension(file->name()) );

  //register new GUIDs for each projects
  gen.setOutputFilename("client");      mgr.registerMacro("DCOMPLUGIN_CLIENT_PROJECT_GUID_LOWER",       gen.newGuid() );
  gen.setOutputFilename("protolib");    mgr.registerMacro("DCOMPLUGIN_PROTOLIB_PROJECT_GUID_LOWER",     gen.newGuid() );
  gen.setOutputFilename("server");      mgr.registerMacro("DCOMPLUGIN_SERVER_PROJECT_GUID_LOWER",       gen.newGuid() );
  gen.setOutputFilename("server_impl"); mgr.registerMacro("DCOMPLUGIN_SERVER_IMPL_PROJECT_GUID_LOWER",  gen.newGuid() );

  mgr.registerMacro("DCOMPLUGIN_CLIENT_PROJECT_GUID_UPPER",       uppercase(mgr.getMacro("DCOMPLUGIN_CLIENT_PROJECT_GUID_LOWER"     )) );
  mgr.registerMacro("DCOMPLUGIN_PROTOLIB_PROJECT_GUID_UPPER",     uppercase(mgr.getMacro("DCOMPLUGIN_PROTOLIB_PROJECT_GUID_LOWER"   )) );
  mgr.registerMacro("DCOMPLUGIN_SERVER_PROJECT_GUID_UPPER",       uppercase(mgr.getMacro("DCOMPLUGIN_SERVER_PROJECT_GUID_LOWER"     )) );
  mgr.registerMacro("DCOMPLUGIN_SERVER_IMPL_PROJECT_GUID_UPPER",  uppercase(mgr.getMacro("DCOMPLUGIN_SERVER_IMPL_PROJECT_GUID_LOWER")) );

  if (c.has_name())
  {
    //DCOMPLUGIN_COMPONENT_NAME
    mgr.registerMacro("DCOMPLUGIN_COMPONENT_NAME", capitalizeFirst(c.name()));

    //DCOMPLUGIN_IDL_INTERFACE_NAME
    mgr.registerMacro("DCOMPLUGIN_IDL_INTERFACE_NAME", std::string("I") + capitalizeFirst(c.name()));
  }

  if (c.has_appid())
  {
    //DCOMPLUGIN_APPID_GUID
    if (c.appid().has_guid())
    {
      mgr.registerMacro("DCOMPLUGIN_APPID_GUID", c.appid().guid());
    }
    //DCOMPLUGIN_APPID_HELPSTRING
    if (c.appid().has_helpstring())
    {
      mgr.registerMacro("DCOMPLUGIN_APPID_HELPSTRING", c.appid().helpstring());
    }
  }

  if (c.has_typelib() && c.typelib().has_coclass())
  {
    //DCOMPLUGIN_OBJECT_NAME
    if (c.typelib().coclass().has_name())
      mgr.registerMacro("DCOMPLUGIN_OBJECT_NAME", c.typelib().coclass().name());

    //DCOMPLUGIN_OBJECT_FRIENDLYNAME
    if (c.typelib().coclass().has_friendlyname())
      mgr.registerMacro("DCOMPLUGIN_OBJECT_FRIENDLYNAME", c.typelib().coclass().friendlyname());
  }

  if (c.has_typelib())
  {
    //DCOMPLUGIN_LIBRARY_NAME
    if (c.typelib().has_name())
      mgr.registerMacro("DCOMPLUGIN_LIBRARY_NAME", c.typelib().name());

    if (c.typelib().has_id())
    {
      //DCOMPLUGIN_LIBRARY_GUID
      if (c.typelib().id().has_guid())
      {
        mgr.registerMacro("DCOMPLUGIN_LIBRARY_GUID", c.typelib().id().guid());
      }
      //DCOMPLUGIN_LIBRARY_HELPSTRING
      if (c.typelib().id().has_helpstring())
      {
        mgr.registerMacro("DCOMPLUGIN_LIBRARY_HELPSTRING", c.typelib().id().helpstring());
      }
    }

    if (c.has_typelib() && c.typelib().has_cointerface() && c.typelib().cointerface().has_id())
    {
      //DCOMPLUGIN_IDL_INTERFACE_GUID
      if (c.typelib().cointerface().id().has_guid())
      {
        mgr.registerMacro("DCOMPLUGIN_IDL_INTERFACE_GUID", c.typelib().cointerface().id().guid());
      }
      //DCOMPLUGIN_IDL_INTERFACE_HELPSTRING
      if (c.typelib().cointerface().id().has_helpstring())
      {
        mgr.registerMacro("DCOMPLUGIN_IDL_INTERFACE_HELPSTRING", c.typelib().cointerface().id().helpstring());
      }
    }

    if (c.has_typelib() && c.typelib().has_coclass() && c.typelib().coclass().has_id())
    {
      //DCOMPLUGIN_COCLASS_GUID
      if (c.typelib().coclass().id().has_guid())
      {
        mgr.registerMacro("DCOMPLUGIN_COCLASS_GUID", c.typelib().coclass().id().guid());
      }
      //DCOMPLUGIN_COCLASS_HELPSTRING
      if (c.typelib().coclass().id().has_helpstring())
      {
        mgr.registerMacro("DCOMPLUGIN_COCLASS_HELPSTRING", c.typelib().coclass().id().helpstring());
      }
    }
  }
}

void PluginCodeGenerator::registerCodeGenerationMacros(const FileDescriptor * file, const dcomplugin::Component & component) const
{
  DComGenerator gen;
  gen.init(file, component);

  MacroManager & mgr = MacroManager::getInstance();

  mgr.registerMacro("DCOMPLUGIN_CLIENT_DEFINITION",               gen.getClientDefinition() );
  mgr.registerMacro("DCOMPLUGIN_ALL_SERVICES_DECLARATION",        gen.getAllServicesDeclaration() );
  mgr.registerMacro("DCOMPLUGIN_IDL_SERVICES_DECLARATION",        gen.getIdlServicesDeclaration() );
  mgr.registerMacro("DCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST",       gen.getAllServicesIncludeList() );
  mgr.registerMacro("DCOMPLUGIN_COCLASS_DEFINITION",              gen.getCoClassDefinition() );
  mgr.registerMacro("DCOMPLUGIN_COCLASS_DECLARATION",             gen.getCoClassDeclaration() );
  mgr.registerMacro("DCOMPLUGIN_ALL_SERVICES_VIRTUAL_IMPL",       gen.getAllServicesVirtualImplementationString() );
  mgr.registerMacro("DCOMPLUGIN_SERVER_IMPL_TEMPLATE_GLOBAL",     gen.getServerImplTemplateGlobalSection() );
  mgr.registerMacro("DCOMPLUGIN_SERVER_IMPL_TEMPLATE_DEFINITION", gen.getServerImplTemplateDefinition() );
  
  //xml based macros
  mgr.registerMacro("    <DCOMPLUGIN_ALL_SERVICES_VCXPROJ />\r\n",  gen.getAllServicesVcxprojInjection() );
  mgr.registerMacro("    <DCOMPLUGIN_ALL_SERVICES_FILTERS />\r\n",  gen.getAllServicesFiltersInjection() );
}

void PluginCodeGenerator::registerServiceBasedMacros(int iServiceIndex, const FileDescriptor * file, const dcomplugin::Component & component) const
{
  DComGenerator gen;
  gen.init(file, component);

  std::string code;

  code << "///<GENERATEDCODE>" << CRLF;
  code << gen.getServiceInterfaceDeclaration(iServiceIndex);
  code << "///</GENERATEDCODE>";

  //preform registration
  MacroManager & mgr = MacroManager::getInstance();
  mgr.registerMacro("DCOMPLUGIN_CURRENT_SERVICE_INTERFACE_DECLARATION", code );
}
