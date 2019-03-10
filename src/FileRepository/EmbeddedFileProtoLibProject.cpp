/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj', last modified 1552228002.
 * Do not modify this file.
 */
#include "EmbeddedFileProtoLibProject.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ProtoLibProjectFile : public virtual bin2cpp::File
  {
  public:
    ProtoLibProjectFile() { build(); }
    virtual ~ProtoLibProjectFile() {}
    virtual size_t getSize() const { return 5328; }
    virtual const char * getFilename() const { return "DCOMPLUGIN_COMPONENT_NAMEProtoLib.vcxproj"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("\357\273\277<\?xml version=\"1.0\" encoding=\"utf-8\"\?>\r\n<Project DefaultTargets=\"Build\" ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\r\n  <ItemGroup Label=\"ProjectConfigurations\">\r", 200);
      mBuffer.append("\n    <ProjectConfiguration Include=\"Debug|Win32\">\r\n      <Configuration>Debug</Configuration>\r\n      <Platform>Win32</Platform>\r\n    </ProjectConfiguration>\r\n    <ProjectConfiguration Include=\"Release", 200);
      mBuffer.append("|Win32\">\r\n      <Configuration>Release</Configuration>\r\n      <Platform>Win32</Platform>\r\n    </ProjectConfiguration>\r\n  </ItemGroup>\r\n  <ItemGroup>\r\n    <None Include=\"DCOMPLUGIN_PROTO_FILE_NAME.prot", 200);
      mBuffer.append("o\" />\r\n  </ItemGroup>\r\n  <ItemGroup>\r\n    <ClCompile Include=\"dcomplugin.pb.cc\" />\r\n    <ClCompile Include=\"ErrorHandlers.cpp\" />\r\n    <ClCompile Include=\"MessageSerializer.cpp\" />\r\n    <ClCompile Inc", 200);
      mBuffer.append("lude=\"Registry.cpp\" />\r\n    <ClCompile Include=\"DCOMPLUGIN_PROTO_FILE_NAME.pb.cc\" />\r\n  </ItemGroup>\r\n  <ItemGroup>\r\n    <ClInclude Include=\"dcomplugin.pb.h\" />\r\n    <ClInclude Include=\"IComErrorProvi", 200);
      mBuffer.append("der.h\" />\r\n    <DCOMPLUGIN_ALL_SERVICES_VCXPROJ />\r\n    <ClInclude Include=\"ErrorHandlers.h\" />\r\n    <ClInclude Include=\"MessageSerializer.h\" />\r\n    <ClInclude Include=\"Registry.h\" />\r\n    <ClInclude", 200);
      mBuffer.append(" Include=\"DCOMPLUGIN_PROTO_FILE_NAME.pb.h\" />\r\n  </ItemGroup>\r\n  <PropertyGroup Label=\"Globals\">\r\n    <ProjectGuid>{DCOMPLUGIN_PROTOLIB_PROJECT_GUID_UPPER}</ProjectGuid>\r\n    <Keyword>Win32Proj</Keywo", 200);
      mBuffer.append("rd>\r\n    <RootNamespace>DCOMPLUGIN_COMPONENT_NAMEProtoLib</RootNamespace>\r\n  </PropertyGroup>\r\n  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.Default.props\" />\r\n  <PropertyGroup Condition=\"\'$(Confi", 200);
      mBuffer.append("guration)|$(Platform)\'==\'Debug|Win32\'\" Label=\"Configuration\">\r\n    <ConfigurationType>StaticLibrary</ConfigurationType>\r\n    <UseDebugLibraries>true</UseDebugLibraries>\r\n    <CharacterSet>MultiByte</C", 200);
      mBuffer.append("haracterSet>\r\n  </PropertyGroup>\r\n  <PropertyGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\" Label=\"Configuration\">\r\n    <ConfigurationType>StaticLibrary</ConfigurationType>\r\n    <Us", 200);
      mBuffer.append("eDebugLibraries>false</UseDebugLibraries>\r\n    <WholeProgramOptimization>true</WholeProgramOptimization>\r\n    <CharacterSet>MultiByte</CharacterSet>\r\n  </PropertyGroup>\r\n  <Import Project=\"$(VCTargets", 200);
      mBuffer.append("Path)\\Microsoft.Cpp.props\" />\r\n  <ImportGroup Label=\"ExtensionSettings\">\r\n  </ImportGroup>\r\n  <ImportGroup Label=\"PropertySheets\" Condition=\"\'$(Configuration)|$(Platform)\'==\'Debug|Win32\'\">\r\n    <Impor", 200);
      mBuffer.append("t Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists(\'$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\')\" Label=\"LocalAppDataPlatform\" />\r\n  </ImportGroup>\r\n  <ImportGr", 200);
      mBuffer.append("oup Label=\"PropertySheets\" Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\">\r\n    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists(\'$(UserRootDir)\\Mic", 200);
      mBuffer.append("rosoft.Cpp.$(Platform).user.props\')\" Label=\"LocalAppDataPlatform\" />\r\n  </ImportGroup>\r\n  <PropertyGroup Label=\"UserMacros\" />\r\n  <PropertyGroup />\r\n  <ItemDefinitionGroup Condition=\"\'$(Configuration)", 200);
      mBuffer.append("|$(Platform)\'==\'Debug|Win32\'\">\r\n    <ClCompile>\r\n      <PrecompiledHeader>NotUsing</PrecompiledHeader>\r\n      <WarningLevel>Level3</WarningLevel>\r\n      <Optimization>Disabled</Optimization>\r\n      <P", 200);
      mBuffer.append("reprocessorDefinitions>WIN32;_DEBUG;_LIB;_CRT_SECURE_NO_WARNINGS;_SCL_SECURE_NO_WARNINGS;%(PreprocessorDefinitions)</PreprocessorDefinitions>\r\n      <AdditionalIncludeDirectories>$(PROTOBUF_INCLUDE_DI", 200);
      mBuffer.append("R)</AdditionalIncludeDirectories>\r\n      <PrecompiledHeaderFile>\r\n      </PrecompiledHeaderFile>\r\n      <PrecompiledHeaderOutputFile>\r\n      </PrecompiledHeaderOutputFile>\r\n    </ClCompile>\r\n    <Link", 200);
      mBuffer.append(">\r\n      <SubSystem>Windows</SubSystem>\r\n      <GenerateDebugInformation>true</GenerateDebugInformation>\r\n    </Link>\r\n    <Lib>\r\n      <AdditionalLibraryDirectories>$(PROTOBUF_LIB_DIR)\\$(Configuratio", 200);
      mBuffer.append("nName)</AdditionalLibraryDirectories>\r\n      <AdditionalDependencies>$(PROTOBUF_DEBUG_LIBRARIES)</AdditionalDependencies>\r\n    </Lib>\r\n  </ItemDefinitionGroup>\r\n  <ItemDefinitionGroup Condition=\"\'$(Co", 200);
      mBuffer.append("nfiguration)|$(Platform)\'==\'Release|Win32\'\">\r\n    <ClCompile>\r\n      <WarningLevel>Level3</WarningLevel>\r\n      <PrecompiledHeader>NotUsing</PrecompiledHeader>\r\n      <Optimization>MaxSpeed</Optimizat", 200);
      mBuffer.append("ion>\r\n      <FunctionLevelLinking>true</FunctionLevelLinking>\r\n      <IntrinsicFunctions>true</IntrinsicFunctions>\r\n      <PreprocessorDefinitions>WIN32;NDEBUG;_LIB;_CRT_SECURE_NO_WARNINGS;_SCL_SECURE", 200);
      mBuffer.append("_NO_WARNINGS;%(PreprocessorDefinitions)</PreprocessorDefinitions>\r\n      <AdditionalIncludeDirectories>$(PROTOBUF_INCLUDE_DIR)</AdditionalIncludeDirectories>\r\n      <PrecompiledHeaderFile>\r\n      </Pr", 200);
      mBuffer.append("ecompiledHeaderFile>\r\n      <PrecompiledHeaderOutputFile>\r\n      </PrecompiledHeaderOutputFile>\r\n    </ClCompile>\r\n    <Link>\r\n      <SubSystem>Windows</SubSystem>\r\n      <GenerateDebugInformation>tru", 200);
      mBuffer.append("e</GenerateDebugInformation>\r\n      <EnableCOMDATFolding>true</EnableCOMDATFolding>\r\n      <OptimizeReferences>true</OptimizeReferences>\r\n    </Link>\r\n    <Lib>\r\n      <AdditionalLibraryDirectories>$(", 200);
      mBuffer.append("PROTOBUF_LIB_DIR)\\$(ConfigurationName)</AdditionalLibraryDirectories>\r\n      <AdditionalDependencies>$(PROTOBUF_RELEASE_LIBRARIES)</AdditionalDependencies>\r\n    </Lib>\r\n  </ItemDefinitionGroup>\r\n  <Im", 200);
      mBuffer.append("port Project=\"$(VCTargetsPath)\\Microsoft.Cpp.targets\" />\r\n  <ImportGroup Label=\"ExtensionTargets\">\r\n  </ImportGroup>\r\n</Project>", 128);
    }
    virtual bool save(const char * iFilename) const
    {
      FILE * f = fopen(iFilename, "wb");
      if (!f) return false;
      size_t fileSize = getSize();
      const char * buffer = getBuffer();
      fwrite(buffer, 1, fileSize, f);
      fclose(f);
      return true;
    }
  private:
    std::string mBuffer;
  };
  const File & getProtoLibProjectFile() { static ProtoLibProjectFile _instance; return _instance; }
}; //bin2cpp
