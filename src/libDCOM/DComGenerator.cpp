#include "DComGenerator.h"
#include "stringfunc.h"
#include "path.h"
#include "protofunc.h"

DComGenerator::DComGenerator() : mFile(NULL)
{
}

DComGenerator::~DComGenerator()
{
}

void DComGenerator::init(const google::protobuf::FileDescriptor *      iFile, const dcomplugin::Component & iComponent)
{
  mFile = iFile;
  mComponent = iComponent;
}

const google::protobuf::FileDescriptor * DComGenerator::getFileDescriptor() const
{
  return mFile;
}

const dcomplugin::Component & DComGenerator::getComponent() const
{
  return mComponent;
}

//code generation methods
std::string DComGenerator::getClientDefinition() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  code << "///<GENERATEDCODE>" << CRLF;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    bool isLastService = (i+1)==numServices;

    //for each method of the service
    int numMethods = service->method_count();
    for(int j=0; j<numMethods; j++)
    {
      bool isLastMethodOfService = (j+1)==numMethods;

      const google::protobuf::MethodDescriptor * method = service->method(j);
      const std::string methodName = method->name();
      const std::string inputTypeName = method->input_type()->full_name();
      const std::string outputTypeName = method->output_type()->full_name();


      bool  isInputTypeEmpty = isEmptyMessage( inputTypeName);
      bool isOutputTypeEmpty = isEmptyMessage(outputTypeName);
      if (!isInputTypeEmpty && !isOutputTypeEmpty)
      {
        code << "bool " << componentName << "Client::" << methodName << "(const " << toCppNamespace(inputTypeName) << " & requestMessage, " << toCppNamespace(outputTypeName) << " & responseMessage)" << CRLF;
        code << "{" << CRLF;
        code << "  if (mServer == NULL)" << CRLF;
        code << "  {" << CRLF;
        code << "    if (mLastError == S_OK)" << CRLF;
        code << "    {" << CRLF;
        code << "      mLastError = E_NOINTERFACE;" << CRLF;
        code << "    }" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //serialise input (prepare input VARIANT buffer)" << CRLF;
        code << "  VARIANT requestBuffer;" << CRLF;
        code << "  VariantInit(&requestBuffer);" << CRLF;
        code << "  HRESULT hr = SerializeMessageToVariant(requestMessage, " << packageName << "::CPLUSPLUS, requestBuffer);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //Serialization failed. Cleanup.." << CRLF;
        code << "    VariantClear(&requestBuffer);" << CRLF;
        code << "" << CRLF;
        code << "    mLastError = hr;" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //make the RPC call" << CRLF;
        code << "  VARIANT responseBuffer;" << CRLF;
        code << "  VariantInit(&responseBuffer);" << CRLF;
        code << "  hr = mServer->" << methodName << "(requestBuffer, &responseBuffer);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //cleanup local allocations" << CRLF;
        code << "    SafeArrayDestroy(requestBuffer.parray);" << CRLF;
        code << "    VariantClear(&requestBuffer);" << CRLF;
        code << "" << CRLF;
        code << "    mLastError = hr;" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //COM call succeeded" << CRLF;
        code << "" << CRLF;
        code << "  //deserialize data into the output message" << CRLF;
        code << "  " << packageName << "::VariantFlavor tmpFlavor;" << CRLF;
        code << "  hr = DeserializeVariantToMessage(responseBuffer, responseMessage, tmpFlavor);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //cleanup memory allocation of client" << CRLF;
        code << "    SafeArrayDestroy(responseBuffer.parray);" << CRLF;
        code << "    VariantClear(&responseBuffer);" << CRLF;
        code << "" << CRLF;
        code << "    mLastError = hr;" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //cleanup memory allocation of client" << CRLF;
        code << "  SafeArrayDestroy(responseBuffer.parray);" << CRLF;
        code << "  VariantClear(&responseBuffer);" << CRLF;
        code << "" << CRLF;
        code << "  return true;" << CRLF;
        code << "}" << CRLF;
      }  
      else if (isInputTypeEmpty && isOutputTypeEmpty)
      {
        code << "bool " << componentName << "Client::" << methodName << "()" << CRLF;
        code << "{" << CRLF;
        code << "  if (mServer == NULL)" << CRLF;
        code << "  {" << CRLF;
        code << "    if (mLastError == S_OK)" << CRLF;
        code << "    {" << CRLF;
        code << "      mLastError = E_NOINTERFACE;" << CRLF;
        code << "    }" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //make the RPC call" << CRLF;
        code << "  HRESULT hr = mServer->" << methodName << "();" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    mLastError = hr;" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //COM call succeeded" << CRLF;
        code << "" << CRLF;
        code << "  return true;" << CRLF;
        code << "}" << CRLF;
      }
      else if (isInputTypeEmpty)
      {
        code << "bool " << componentName << "Client::" << methodName << "(" << toCppNamespace(outputTypeName) << " & responseMessage)" << CRLF;
        code << "{" << CRLF;
        code << "  if (mServer == NULL)" << CRLF;
        code << "  {" << CRLF;
        code << "    if (mLastError == S_OK)" << CRLF;
        code << "    {" << CRLF;
        code << "      mLastError = E_NOINTERFACE;" << CRLF;
        code << "    }" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //make the RPC call" << CRLF;
        code << "  VARIANT responseBuffer;" << CRLF;
        code << "  VariantInit(&responseBuffer);" << CRLF;
        code << "  HRESULT hr = mServer->" << methodName << "(&responseBuffer);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    mLastError = hr;" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //COM call succeeded" << CRLF;
        code << "" << CRLF;
        code << "  //deserialize data into the output message" << CRLF;
        code << "  " << packageName << "::VariantFlavor tmpFlavor;" << CRLF;
        code << "  hr = DeserializeVariantToMessage(responseBuffer, responseMessage, tmpFlavor);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //cleanup memory allocation of client" << CRLF;
        code << "    SafeArrayDestroy(responseBuffer.parray);" << CRLF;
        code << "    VariantClear(&responseBuffer);" << CRLF;
        code << "" << CRLF;
        code << "    mLastError = hr;" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //cleanup memory allocation of client" << CRLF;
        code << "  SafeArrayDestroy(responseBuffer.parray);" << CRLF;
        code << "  VariantClear(&responseBuffer);" << CRLF;
        code << "" << CRLF;
        code << "  return true;" << CRLF;
        code << "}" << CRLF;
      }
      else if (isOutputTypeEmpty)
      {
        code << "bool " << componentName << "Client::" << methodName << "(const " << toCppNamespace(inputTypeName) << " & requestMessage)" << CRLF;
        code << "{" << CRLF;
        code << "  if (mServer == NULL)" << CRLF;
        code << "  {" << CRLF;
        code << "    if (mLastError == S_OK)" << CRLF;
        code << "    {" << CRLF;
        code << "      mLastError = E_NOINTERFACE;" << CRLF;
        code << "    }" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //serialise input (prepare input VARIANT buffer)" << CRLF;
        code << "  VARIANT requestBuffer;" << CRLF;
        code << "  VariantInit(&requestBuffer);" << CRLF;
        code << "  HRESULT hr = SerializeMessageToVariant(requestMessage, " << packageName << "::CPLUSPLUS, requestBuffer);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //Serialization failed. Cleanup.." << CRLF;
        code << "    VariantClear(&requestBuffer);" << CRLF;
        code << "" << CRLF;
        code << "    mLastError = hr;" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //make the RPC call" << CRLF;
        code << "  hr = mServer->" << methodName << "(requestBuffer);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //cleanup local allocations" << CRLF;
        code << "    SafeArrayDestroy(requestBuffer.parray);" << CRLF;
        code << "    VariantClear(&requestBuffer);" << CRLF;
        code << "" << CRLF;
        code << "    mLastError = hr;" << CRLF;
        code << "    return false;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //COM call succeeded" << CRLF;
        code << "" << CRLF;
        code << "  return true;" << CRLF;
        code << "}" << CRLF;
      }

      if (!isLastMethodOfService)
      {
        code << CRLF;
      }

    }
    if (!isLastService)
    {
      code << CRLF;
    }
  }

  code << "///</GENERATEDCODE>";

  return code;
}

std::string DComGenerator::getAllServicesDeclaration() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  static const char * indent = "  ";

  code << "///<GENERATEDCODE>" << CRLF;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    std::string serviceInterfaceName = "I" + capitalizeFirst(serviceName);

    bool isLastService = (i+1)==numServices;

    //for each method of the service
    int numMethods = service->method_count();
    for(int j=0; j<numMethods; j++)
    {
      bool isLastMethodOfService = (j+1)==numMethods;

      const google::protobuf::MethodDescriptor * method = service->method(j);
      const std::string methodName = method->name();
      const std::string inputTypeName = method->input_type()->full_name();
      const std::string outputTypeName = method->output_type()->full_name();

      code << indent << "//" << serviceInterfaceName << ":" << CRLF;

      //add method documentation name
      code << getMethodDocumentation(indent, false, methodName, serviceInterfaceName, inputTypeName, outputTypeName);

      if (!isLastMethodOfService)
      {
        code << CRLF;
      }

    }
    if (!isLastService)
    {
      code << CRLF;
    }
  }

  code << "///</GENERATEDCODE>";

  return code;
}

std::string DComGenerator::getAllServicesIncludeList() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  code << "///<GENERATEDCODE>" << CRLF;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    bool isLastService = (i+1)==numServices;

    code << "#include \"I" << capitalizeFirst(serviceName) << ".h\"" << CRLF;
  }

  code << "///</GENERATEDCODE>";

  return code;
}

std::string DComGenerator::getAllServicesVirtualImplementationString() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string indent = "                        ";
  indent.append(componentName.size()*2, ' ');

  std::string code;

  code << indent << "///<GENERATEDCODE>" << CRLF;
  
  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    std::string serviceInterfaceName = "I" + capitalizeFirst(serviceName);

    bool isLastService = (i+1)==numServices;

    code << indent << "public virtual " << serviceInterfaceName;

    if (!isLastService)
    {
      code << ",";
    }
    code << CRLF;

  }

  code << indent << "///</GENERATEDCODE>";

  return code;
}

std::string DComGenerator::getCoClassDefinition() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  static const char * indent = "  ";

  code << "///<GENERATEDCODE>" << CRLF;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    std::string serviceInterfaceName = "I" + capitalizeFirst(serviceName);

    bool isLastService = (i+1)==numServices;

    //for each method of the service
    int numMethods = service->method_count();
    for(int j=0; j<numMethods; j++)
    {
      bool isLastMethodOfService = (j+1)==numMethods;

      const google::protobuf::MethodDescriptor * method = service->method(j);
      const std::string methodName = method->name();
      const std::string inputTypeName = method->input_type()->full_name();
      const std::string outputTypeName = method->output_type()->full_name();


      bool  isInputTypeEmpty = isEmptyMessage( inputTypeName);
      bool isOutputTypeEmpty = isEmptyMessage(outputTypeName);
      if (!isInputTypeEmpty && !isOutputTypeEmpty)
      {
        code << "STDMETHODIMP Co" << capitalizeFirst(componentName) << "Server::" << methodName << "(VARIANT requestBuffer, VARIANT* responseBuffer)" << CRLF;
        code << "{" << CRLF;
        code << "  " << packageName << "::VariantFlavor flavor;" << CRLF;
        code << "  " << toCppNamespace(inputTypeName) << " requestMessage;" << CRLF;
        code << "" << CRLF;
        code << "  //deserialize requestMessage" << CRLF;
        code << "  HRESULT hr = DeserializeVariantToMessage(requestBuffer, requestMessage, flavor);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //COM call failed. Show error" << CRLF;
        code << "    " << packageName << "::MessageBoxLastComError(hr);" << CRLF;
        code << "    return hr;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //call server implementation" << CRLF;
        code << "  " << toCppNamespace(outputTypeName) << " responseMessage;" << CRLF;
        code << "  g_obj" << capitalizeFirst(componentName) << "ServerImpl." << methodName << "(requestMessage, responseMessage);" << CRLF;
        code << "" << CRLF;
        code << "  //serialize response" << CRLF;
        code << "  hr = SerializeMessageToVariant(responseMessage, flavor, *responseBuffer);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //COM call failed. Show error" << CRLF;
        code << "    " << packageName << "::MessageBoxLastComError(hr);" << CRLF;
        code << "    return hr;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  return S_OK;" << CRLF;
        code << "}" << CRLF;
      }  
      else if (isInputTypeEmpty && isOutputTypeEmpty)
      {
        code << "STDMETHODIMP Co" << capitalizeFirst(componentName) << "Server::" << methodName << "()" << CRLF;
        code << "{" << CRLF;
        code << "  //call server implementation" << CRLF;
        code << "  g_obj" << capitalizeFirst(componentName) << "ServerImpl." << methodName << "();" << CRLF;
        code << "" << CRLF;
        code << "  return S_OK;" << CRLF;
        code << "}" << CRLF;
      }
      else if (isInputTypeEmpty)
      {
        code << "STDMETHODIMP Co" << capitalizeFirst(componentName) << "Server::" << methodName << "(VARIANT* responseBuffer)" << CRLF;
        code << "{" << CRLF;
        code << "  " << packageName << "::VariantFlavor flavor = " << packageName << "::CPLUSPLUS;" << CRLF;
        code << "" << CRLF;
        code << "  //call server implementation" << CRLF;
        code << "  " << toCppNamespace(outputTypeName) << " responseMessage;" << CRLF;
        code << "  g_obj" << capitalizeFirst(componentName) << "ServerImpl." << methodName << "(responseMessage);" << CRLF;
        code << "" << CRLF;
        code << "  //serialize response" << CRLF;
        code << "  HRESULT hr = SerializeMessageToVariant(responseMessage, flavor, *responseBuffer);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //COM call failed. Show error" << CRLF;
        code << "    " << packageName << "::MessageBoxLastComError(hr);" << CRLF;
        code << "    return hr;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  return S_OK;" << CRLF;
        code << "}" << CRLF;
      }
      else if (isOutputTypeEmpty)
      {
        code << "STDMETHODIMP Co" << capitalizeFirst(componentName) << "Server::" << methodName << "(VARIANT requestBuffer)" << CRLF;
        code << "{" << CRLF;
        code << "  " << packageName << "::VariantFlavor flavor;" << CRLF;
        code << "  " << toCppNamespace(inputTypeName) << " requestMessage;" << CRLF;
        code << "" << CRLF;
        code << "  //deserialize requestMessage" << CRLF;
        code << "  HRESULT hr = DeserializeVariantToMessage(requestBuffer, requestMessage, flavor);" << CRLF;
        code << "  if (FAILED(hr))" << CRLF;
        code << "  {" << CRLF;
        code << "    //COM call failed. Show error" << CRLF;
        code << "    " << packageName << "::MessageBoxLastComError(hr);" << CRLF;
        code << "    return hr;" << CRLF;
        code << "  }" << CRLF;
        code << "" << CRLF;
        code << "  //call server implementation" << CRLF;
        code << "  " << toCppNamespace(outputTypeName) << " responseMessage;" << CRLF;
        code << "  g_obj" << capitalizeFirst(componentName) << "ServerImpl." << methodName << "(requestMessage);" << CRLF;
        code << "" << CRLF;
        code << "  return S_OK;" << CRLF;
        code << "}" << CRLF;
      }

      if (!isLastService || !isLastMethodOfService)
      {
        code << CRLF;
      }
    }
  }

  code << "///</GENERATEDCODE>";

  return code;
}

std::string DComGenerator::getCoClassDeclaration() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  static const char * indent = "  ";

  code << "///<GENERATEDCODE>" << CRLF;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    std::string serviceInterfaceName = "I" + capitalizeFirst(serviceName);

    bool isLastService = (i+1)==numServices;

    //for each method of the service
    int numMethods = service->method_count();
    for(int j=0; j<numMethods; j++)
    {
      bool isLastMethodOfService = (j+1)==numMethods;

      const google::protobuf::MethodDescriptor * method = service->method(j);
      const std::string methodName = method->name();
      const std::string inputTypeName = method->input_type()->full_name();
      const std::string outputTypeName = method->output_type()->full_name();


      bool  isInputTypeEmpty = isEmptyMessage( inputTypeName);
      bool isOutputTypeEmpty = isEmptyMessage(outputTypeName);
      if (!isInputTypeEmpty && !isOutputTypeEmpty)
      {
        code << indent << "STDMETHOD(" << methodName << ")(/* [in] */VARIANT requestBuffer, /* [out, retval] */VARIANT* responseBuffer);" << CRLF;
      }  
      else if (isInputTypeEmpty && isOutputTypeEmpty)
      {
        code << indent << "STDMETHOD(" << methodName << ")();" << CRLF;
      }
      else if (isInputTypeEmpty)
      {
        code << indent << "STDMETHOD(" << methodName << ")(/* [out, retval] */VARIANT* responseBuffer);" << CRLF;
      }
      else if (isOutputTypeEmpty)
      {
        code << indent << "STDMETHOD(" << methodName << ")(/* [in] */VARIANT requestBuffer);" << CRLF;
      }

    }
  }

  code << indent << "///</GENERATEDCODE>";

  return code;
}

std::string DComGenerator::getIdlServicesDeclaration() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  static const char * indent = "    ";

  code << indent << "///<GENERATEDCODE>" << CRLF;

  int id = 1;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    std::string serviceInterfaceName = "I" + capitalizeFirst(serviceName);

    bool isLastService = (i+1)==numServices;

    //for each method of the service
    int numMethods = service->method_count();
    for(int j=0; j<numMethods; j++)
    {
      bool isLastMethodOfService = (j+1)==numMethods;

      const google::protobuf::MethodDescriptor * method = service->method(j);
      const std::string methodName = method->name();
      const std::string inputTypeName = method->input_type()->full_name();
      const std::string outputTypeName = method->output_type()->full_name();

      code << indent << "//" << serviceInterfaceName << ":" << CRLF;

      bool  isInputTypeEmpty = isEmptyMessage( inputTypeName);
      bool isOutputTypeEmpty = isEmptyMessage(outputTypeName);
      if (!isInputTypeEmpty && !isOutputTypeEmpty)
      {
        code << indent << "[id(" << id << ")] HRESULT " << methodName << "([in] VARIANT requestBuffer, [out, retval] VARIANT* responseBuffer);" << CRLF;
      }  
      else if (isInputTypeEmpty && isOutputTypeEmpty)
      {
        code << indent << "[id(" << id << ")] HRESULT " << methodName << "();" << CRLF;
      }
      else if (isInputTypeEmpty)
      {
        code << indent << "[id(" << id << ")] HRESULT " << methodName << "([out, retval] VARIANT* responseBuffer);" << CRLF;
      }
      else if (isOutputTypeEmpty)
      {
        code << indent << "[id(" << id << ")] HRESULT " << methodName << "([in] VARIANT requestBuffer);" << CRLF;
      }

      if (!isLastService || !isLastMethodOfService)
      {
        code << CRLF;
      }

      //next id
      id++;
    }
  }

  code << indent << "///</GENERATEDCODE>";

  return code;
}

std::string DComGenerator::getServerImplTemplateGlobalSection() const
{
  const std::string & componentName = mComponent.name();
  const std::string protoFileName = getFileNameWithoutExtension(mFile->name());

  std::string code;

  code << "// TODO: Rename or copy this template to a new file (ie: " << mComponent.name() << "ServerImpl.cpp)" << CRLF;
  code << "//       to prevent overwriting the file on new generation of " << protoFileName << ".proto" << CRLF;
  return code;
}

std::string DComGenerator::getServerImplTemplateDefinition() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    std::string serviceInterfaceName = "I" + capitalizeFirst(serviceName);
    code << "//" << serviceInterfaceName << ":" << CRLF;

    bool isLastService = (i+1)==numServices;

    //for each method of the service
    int numMethods = service->method_count();
    for(int j=0; j<numMethods; j++)
    {
      bool isLastMethodOfService = (j+1)==numMethods;

      const google::protobuf::MethodDescriptor * method = service->method(j);
      const std::string methodName = method->name();
      const std::string inputTypeName = method->input_type()->full_name();
      const std::string outputTypeName = method->output_type()->full_name();

      bool  isInputTypeEmpty = isEmptyMessage( inputTypeName);
      bool isOutputTypeEmpty = isEmptyMessage(outputTypeName);
      if (!isInputTypeEmpty && !isOutputTypeEmpty)
      {
        code << "bool " << capitalizeFirst(componentName) << "ServerImpl::" << methodName << "(const " << toCppNamespace(inputTypeName) << " & requestMessage, " << toCppNamespace(outputTypeName) << " & responseMessage)" << CRLF;
        code << "{" << CRLF;
        code << "  // TODO: build responseMessage based on requestMessage" << CRLF;
        code << "" << CRLF;
        code << "  return true; //success" << CRLF;
        code << "}" << CRLF;
      }  
      else if (isInputTypeEmpty && isOutputTypeEmpty)
      {
        code << "bool " << capitalizeFirst(componentName) << "ServerImpl::" << methodName << "()" << CRLF;
        code << "{" << CRLF;
        code << "  // TODO: implement service method" << CRLF;
        code << "" << CRLF;
        code << "  return true; //success" << CRLF;
        code << "}" << CRLF;
      }
      else if (isInputTypeEmpty)
      {
        code << "bool " << capitalizeFirst(componentName) << "ServerImpl::" << methodName << "(" << toCppNamespace(outputTypeName) << " & responseMessage)" << CRLF;
        code << "{" << CRLF;
        code << "  // TODO: build responseMessage" << CRLF;
        code << "" << CRLF;
        code << "  return true; //success" << CRLF;
        code << "}" << CRLF;
      }  
      else if (isOutputTypeEmpty)
      {
        code << "bool " << capitalizeFirst(componentName) << "ServerImpl::" << methodName << "(const " << toCppNamespace(inputTypeName) << " & requestMessage)" << CRLF;
        code << "{" << CRLF;
        code << "  // TODO: process requestMessage" << CRLF;
        code << "" << CRLF;
        code << "  return true; //success" << CRLF;
        code << "}" << CRLF;
      }  

      if (!isLastService || !isLastMethodOfService)
      {
        code << CRLF;
      }

    }
  }

  return code;
}

std::string DComGenerator::getAllServicesVcxprojInjection() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    bool isLastService = (i+1)==numServices;
    std::string serviceInterfaceName = "I" + capitalizeFirst(serviceName);

    code << "    <ClInclude Include=\"" << serviceInterfaceName << ".h\" />" << CRLF;
  }

  return code;
}

std::string DComGenerator::getAllServicesFiltersInjection() const
{
  const std::string & componentName = mComponent.name();
  const std::string & packageName = mFile->package();

  std::string code;

  //services
  int numServices = mFile->service_count();
  for(int i=0; i<numServices; i++)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(i);
    const std::string & serviceName = service->name();
    
    bool isLastService = (i+1)==numServices;
    std::string serviceInterfaceName = "I" + capitalizeFirst(serviceName);

    code << "    <ClInclude Include=\"" << serviceInterfaceName << ".h\">" << CRLF;
    code << "      <Filter>Services</Filter>" << CRLF;
    code << "    </ClInclude>" << CRLF;
  }

  return code;
}

//helpers
std::string DComGenerator::getMethodDocumentation(const char * iIndentation, bool isPureVirtual, const int iServiceIndex, const int iMethodIndex) const
{
  //service
  int numServices = mFile->service_count();
  if (iServiceIndex >= 0 && iServiceIndex <numServices)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(iServiceIndex);

    //method
    int numMethods = service->method_count();
    if (iMethodIndex >= 0 && iMethodIndex <numMethods)
    {
      const google::protobuf::MethodDescriptor * method = service->method(iMethodIndex);

      return getMethodDocumentation(iIndentation, isPureVirtual, method->name(), service->name(), method->input_type()->full_name(), method->output_type()->full_name());
    }
  }

  return "";
}

std::string DComGenerator::getMethodDocumentation(const char * iIndentation, bool isPureVirtual, const std::string & methodName, const std::string & interfaceName, const std::string & inputTypeName, const std::string & outputTypeName) const
{
  std::string code;

  bool  isInputTypeEmpty = isEmptyMessage( inputTypeName);
  bool isOutputTypeEmpty = isEmptyMessage(outputTypeName);
  if (!isInputTypeEmpty && !isOutputTypeEmpty)
  {
    code << iIndentation << "///<summary>Process the " << methodName << " rpc of the " << interfaceName << " service-></summary>" << CRLF;
    code << iIndentation << "///<param name=\"requestMessage\">A valid request message of type " << toCppNamespace(inputTypeName) << ".</param>" << CRLF;
    code << iIndentation << "///<param name=\"responseMessage\">The response message of type " << toCppNamespace(outputTypeName) << " for the " << methodName << "() rpc.</param>" << CRLF;
    code << iIndentation << "///<returns>Returns true if the call is successful. Returns false otherwise.</returns>" << CRLF;
    code << iIndentation << "virtual bool " << methodName << "(const " << toCppNamespace(inputTypeName) << " & requestMessage, " << toCppNamespace(outputTypeName) << " & responseMessage)";
  }  
  else if (isInputTypeEmpty && isOutputTypeEmpty)
  {
    code << iIndentation << "///<summary>Process the " << methodName << " rpc of the " << interfaceName << " service-></summary>" << CRLF;
    code << iIndentation << "///<returns>Returns true if the call is successful. Returns false otherwise.</returns>" << CRLF;
    code << iIndentation << "virtual bool " << methodName << "()";
  }
  else if (isInputTypeEmpty)
  {
    code << iIndentation << "///<summary>Process the " << methodName << " rpc of the " << interfaceName << " service-></summary>" << CRLF;
    code << iIndentation << "///<param name=\"responseMessage\">The response message of type " << toCppNamespace(outputTypeName) << " for the " << methodName << "() rpc.</param>" << CRLF;
    code << iIndentation << "///<returns>Returns true if the call is successful. Returns false otherwise.</returns>" << CRLF;
    code << iIndentation << "virtual bool " << methodName << "(" << toCppNamespace(outputTypeName) << " & responseMessage)";
  }
  else if (isOutputTypeEmpty)
  {
    code << iIndentation << "///<summary>Process the " << methodName << " rpc of the " << interfaceName << " service-></summary>" << CRLF;
    code << iIndentation << "///<param name=\"requestMessage\">A valid request message of type " << toCppNamespace(inputTypeName) << ".</param>" << CRLF;
    code << iIndentation << "///<returns>Returns true if the call is successful. Returns false otherwise.</returns>" << CRLF;
    code << iIndentation << "virtual bool " << methodName << "(const " << toCppNamespace(inputTypeName) << " & requestMessage)";
  }

  if (isPureVirtual)
  {
    code << " = 0";
  }
  code << ";" << CRLF;

  return code;
}

std::string DComGenerator::getServiceInterfaceDeclaration(int iServiceIndex) const
{
  std::string code;

  //service
  int numServices = mFile->service_count();
  if (iServiceIndex >= 0 && iServiceIndex <numServices)
  {
    const google::protobuf::ServiceDescriptor * service = mFile->service(iServiceIndex);

    std::string serviceInterfaceName = "I" + capitalizeFirst(service->name());
    
    code << "class " << serviceInterfaceName << CRLF;
    code << "{" << CRLF;
    code << "public:" << CRLF;

    //for each method of the service
    int numMethods = service->method_count();
    for(int j=0; j<numMethods; j++)
    {
      bool isLastMethodOfService = (j+1)==numMethods;

      const google::protobuf::MethodDescriptor * method = service->method(j);
      const std::string methodName = method->name();
      const std::string inputTypeName = method->input_type()->full_name();
      const std::string outputTypeName = method->output_type()->full_name();

      //add method documentation name
      code << this->getMethodDocumentation("  ", true, methodName, serviceInterfaceName, inputTypeName, outputTypeName);

      if (!isLastMethodOfService)
      {
        code << CRLF;
      }
    }

    code << "};" << CRLF;
  }

  return code;
}

bool DComGenerator::isEmptyMessage(const std::string & iTypeName) const
{
  const ::google::protobuf::Descriptor * desc = findMessageDescriptor(mFile, iTypeName);
  if (desc == NULL)
    return false;

  int numFields = desc->field_count();
  return numFields == 0;
}

const ::google::protobuf::Descriptor * DComGenerator::findMessageDescriptor(const google::protobuf::FileDescriptor * file, const std::string & iTypeName) const
{
  const ::google::protobuf::Descriptor * msg = file->pool()->FindMessageTypeByName(iTypeName);
  if (msg)
    return msg;

  int numMessages = file->message_type_count();
  for(int i=0; i<numMessages; i++)
  {
    const ::google::protobuf::Descriptor * msg = file->message_type(i);
    
    //build absolute message type: .package.message_name
    std::string absMessageType;
    absMessageType.append(file->package());
    absMessageType.append(".");
    absMessageType.append(msg->name());
    
    if (absMessageType == iTypeName)
    {
      return msg;
    }
  }

  //look in dependencies
  int numDependencies = file->dependency_count();
  for(int i=0; i<numDependencies; i++)
  {
    const ::google::protobuf::FileDescriptor * dependency = file->dependency(i);
    const ::google::protobuf::Descriptor * msg = findMessageDescriptor(dependency, iTypeName);
    if (msg)
      return msg;
  }

  return NULL;
}
