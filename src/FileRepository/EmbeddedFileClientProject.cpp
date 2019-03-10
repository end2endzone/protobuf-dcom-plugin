/**
 * This file was generated by bin2cpp v2.2.0
 * Copyright (C) 2013-2019 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj', last modified 1552247129.
 * Do not modify this file.
 */
#include "EmbeddedFileClientProject.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ClientProjectFile : public virtual bin2cpp::File
  {
  public:
    ClientProjectFile() { build(); }
    virtual ~ClientProjectFile() {}
    virtual size_t getSize() const { return 8747; }
    virtual const char * getFilename() const { return "DCOMPLUGIN_COMPONENT_NAMEClient.vcxproj"; }
    virtual const char * getBuffer() const { return mBuffer.c_str(); }
    void build()
    {
      mBuffer.clear();
      mBuffer.reserve(getSize()); //allocate all required memory at once to prevent reallocations
      mBuffer.append("\357\273\277<\?xml version=\"1.0\" encoding=\"utf-8\"\?>\r\n<Project DefaultTargets=\"Build\" ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\r\n  <ItemGroup Label=\"ProjectConfigurations\">\r", 200);
      mBuffer.append("\n    <ProjectConfiguration Include=\"Debug|Win32\">\r\n      <Configuration>Debug</Configuration>\r\n      <Platform>Win32</Platform>\r\n    </ProjectConfiguration>\r\n    <ProjectConfiguration Include=\"Release", 200);
      mBuffer.append("|Win32\">\r\n      <Configuration>Release</Configuration>\r\n      <Platform>Win32</Platform>\r\n    </ProjectConfiguration>\r\n  </ItemGroup>\r\n  <PropertyGroup Label=\"Globals\">\r\n    <ProjectName>DCOMPLUGIN_CO", 200);
      mBuffer.append("MPONENT_NAMEClient</ProjectName>\r\n    <ProjectGuid>{DCOMPLUGIN_CLIENT_PROJECT_GUID_UPPER}</ProjectGuid>\r\n    <RootNamespace>DCOMPLUGIN_COMPONENT_NAMEClient</RootNamespace>\r\n  </PropertyGroup>\r\n  <Impo", 200);
      mBuffer.append("rt Project=\"$(VCTargetsPath)\\Microsoft.Cpp.Default.props\" />\r\n  <PropertyGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'Debug|Win32\'\" Label=\"Configuration\">\r\n    <ConfigurationType>DynamicLibrary</", 200);
      mBuffer.append("ConfigurationType>\r\n    <UseOfMfc>false</UseOfMfc>\r\n    <CharacterSet>MultiByte</CharacterSet>\r\n  </PropertyGroup>\r\n  <PropertyGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\" Label=\"", 200);
      mBuffer.append("Configuration\">\r\n    <ConfigurationType>DynamicLibrary</ConfigurationType>\r\n    <UseOfMfc>false</UseOfMfc>\r\n    <CharacterSet>MultiByte</CharacterSet>\r\n  </PropertyGroup>\r\n  <Import Project=\"$(VCTarge", 200);
      mBuffer.append("tsPath)\\Microsoft.Cpp.props\" />\r\n  <ImportGroup Label=\"ExtensionSettings\">\r\n  </ImportGroup>\r\n  <ImportGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'Debug|Win32\'\" Label=\"PropertySheets\">\r\n    <Imp", 200);
      mBuffer.append("ort Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists(\'$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\')\" Label=\"LocalAppDataPlatform\" />\r\n    <Import Project=\"$(VCTa", 200);
      mBuffer.append("rgetsPath)Microsoft.CPP.UpgradeFromVC71.props\" />\r\n  </ImportGroup>\r\n  <ImportGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\" Label=\"PropertySheets\">\r\n    <Import Project=\"$(UserRoot", 200);
      mBuffer.append("Dir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists(\'$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\')\" Label=\"LocalAppDataPlatform\" />\r\n    <Import Project=\"$(VCTargetsPath)Microsoft.CPP", 200);
      mBuffer.append(".UpgradeFromVC71.props\" />\r\n  </ImportGroup>\r\n  <PropertyGroup Label=\"UserMacros\" />\r\n  <PropertyGroup>\r\n    <_ProjectFileVersion>10.0.40219.1</_ProjectFileVersion>\r\n    <OutDir Condition=\"\'$(Configur", 200);
      mBuffer.append("ation)|$(Platform)\'==\'Release|Win32\'\">$(SolutionDir)$(Configuration)\\</OutDir>\r\n    <IntDir Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\">$(Configuration)\\</IntDir>\r\n    <LinkIncremental", 200);
      mBuffer.append(" Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\">false</LinkIncremental>\r\n    <OutDir Condition=\"\'$(Configuration)|$(Platform)\'==\'Debug|Win32\'\">$(SolutionDir)$(Configuration)\\</OutDir>\r\n  ", 200);
      mBuffer.append("  <IntDir Condition=\"\'$(Configuration)|$(Platform)\'==\'Debug|Win32\'\">$(Configuration)\\</IntDir>\r\n    <LinkIncremental Condition=\"\'$(Configuration)|$(Platform)\'==\'Debug|Win32\'\">false</LinkIncremental>\r\n", 200);
      mBuffer.append("  </PropertyGroup>\r\n  <ItemDefinitionGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\">\r\n    <Midl>\r\n      <PreprocessorDefinitions>NDEBUG;%(PreprocessorDefinitions)</PreprocessorDefin", 200);
      mBuffer.append("itions>\r\n      <MkTypLibCompatible>true</MkTypLibCompatible>\r\n      <SuppressStartupBanner>true</SuppressStartupBanner>\r\n      <TargetEnvironment>Win32</TargetEnvironment>\r\n      <TypeLibraryName>$(Ou", 200);
      mBuffer.append("tDir)$(ProjectName).tlb</TypeLibraryName>\r\n      <HeaderFileName>\r\n      </HeaderFileName>\r\n    </Midl>\r\n    <ClCompile>\r\n      <Optimization>MaxSpeed</Optimization>\r\n      <InlineFunctionExpansion>On", 200);
      mBuffer.append("lyExplicitInline</InlineFunctionExpansion>\r\n      <PreprocessorDefinitions>WIN32;NDEBUG;_WINDOWS;_USRDLL;_CRT_SECURE_NO_WARNINGS;_SCL_SECURE_NO_WARNINGS;DCOMPLUGIN_COMPONENT_NAME_CLIENT_EXPORTS;%(Prep", 200);
      mBuffer.append("rocessorDefinitions)</PreprocessorDefinitions>\r\n      <StringPooling>true</StringPooling>\r\n      <RuntimeLibrary>MultiThreadedDLL</RuntimeLibrary>\r\n      <FunctionLevelLinking>true</FunctionLevelLinki", 200);
      mBuffer.append("ng>\r\n      <PrecompiledHeaderOutputFile>\r\n      </PrecompiledHeaderOutputFile>\r\n      <WarningLevel>Level3</WarningLevel>\r\n      <SuppressStartupBanner>true</SuppressStartupBanner>\r\n      <AdditionalI", 200);
      mBuffer.append("ncludeDirectories>$(PROTOBUF_INCLUDE_DIR)</AdditionalIncludeDirectories>\r\n      <PrecompiledHeaderFile>\r\n      </PrecompiledHeaderFile>\r\n    </ClCompile>\r\n    <ResourceCompile>\r\n      <PreprocessorDef", 200);
      mBuffer.append("initions>NDEBUG;%(PreprocessorDefinitions)</PreprocessorDefinitions>\r\n      <Culture>0x0409</Culture>\r\n    </ResourceCompile>\r\n    <Link>\r\n      <OutputFile>$(OutDir)$(ProjectName).dll</OutputFile>\r\n ", 200);
      mBuffer.append("     <SuppressStartupBanner>true</SuppressStartupBanner>\r\n      <RandomizedBaseAddress>false</RandomizedBaseAddress>\r\n      <DataExecutionPrevention>\r\n      </DataExecutionPrevention>\r\n      <ImportLi", 200);
      mBuffer.append("brary>$(OutDir)$(ProjectName).lib</ImportLibrary>\r\n      <TargetMachine>MachineX86</TargetMachine>\r\n      <AdditionalLibraryDirectories>$(PROTOBUF_LIB_DIR)\\$(ConfigurationName)</AdditionalLibraryDirec", 200);
      mBuffer.append("tories>\r\n      <AdditionalDependencies>$(PROTOBUF_RELEASE_LIBRARIES);%(AdditionalDependencies)</AdditionalDependencies>\r\n    </Link>\r\n  </ItemDefinitionGroup>\r\n  <ItemDefinitionGroup Condition=\"\'$(Con", 200);
      mBuffer.append("figuration)|$(Platform)\'==\'Debug|Win32\'\">\r\n    <Midl>\r\n      <PreprocessorDefinitions>_DEBUG;%(PreprocessorDefinitions)</PreprocessorDefinitions>\r\n      <MkTypLibCompatible>true</MkTypLibCompatible>\r\n", 200);
      mBuffer.append("      <SuppressStartupBanner>true</SuppressStartupBanner>\r\n      <TargetEnvironment>Win32</TargetEnvironment>\r\n      <TypeLibraryName>$(OutDir)$(ProjectName).tlb</TypeLibraryName>\r\n      <HeaderFileNa", 200);
      mBuffer.append("me>\r\n      </HeaderFileName>\r\n    </Midl>\r\n    <ClCompile>\r\n      <Optimization>Disabled</Optimization>\r\n      <PreprocessorDefinitions>WIN32;_DEBUG;_WINDOWS;_USRDLL;_CRT_SECURE_NO_WARNINGS;_SCL_SECUR", 200);
      mBuffer.append("E_NO_WARNINGS;DCOMPLUGIN_COMPONENT_NAME_CLIENT_EXPORTS;%(PreprocessorDefinitions)</PreprocessorDefinitions>\r\n      <BasicRuntimeChecks>EnableFastChecks</BasicRuntimeChecks>\r\n      <RuntimeLibrary>Mult", 200);
      mBuffer.append("iThreadedDebugDLL</RuntimeLibrary>\r\n      <PrecompiledHeaderOutputFile>\r\n      </PrecompiledHeaderOutputFile>\r\n      <WarningLevel>Level3</WarningLevel>\r\n      <SuppressStartupBanner>true</SuppressSta", 200);
      mBuffer.append("rtupBanner>\r\n      <DebugInformationFormat>EditAndContinue</DebugInformationFormat>\r\n      <AdditionalIncludeDirectories>$(PROTOBUF_INCLUDE_DIR)</AdditionalIncludeDirectories>\r\n      <PrecompiledHeade", 200);
      mBuffer.append("rFile>\r\n      </PrecompiledHeaderFile>\r\n    </ClCompile>\r\n    <ResourceCompile>\r\n      <PreprocessorDefinitions>_DEBUG;%(PreprocessorDefinitions)</PreprocessorDefinitions>\r\n      <Culture>0x0409</Cult", 200);
      mBuffer.append("ure>\r\n    </ResourceCompile>\r\n    <Link>\r\n      <OutputFile>$(OutDir)$(ProjectName).dll</OutputFile>\r\n      <SuppressStartupBanner>true</SuppressStartupBanner>\r\n      <GenerateDebugInformation>true</G", 200);
      mBuffer.append("enerateDebugInformation>\r\n      <RandomizedBaseAddress>false</RandomizedBaseAddress>\r\n      <DataExecutionPrevention>\r\n      </DataExecutionPrevention>\r\n      <ImportLibrary>$(OutDir)$(ProjectName).li", 200);
      mBuffer.append("b</ImportLibrary>\r\n      <TargetMachine>MachineX86</TargetMachine>\r\n      <AdditionalLibraryDirectories>$(PROTOBUF_LIB_DIR)\\$(ConfigurationName)</AdditionalLibraryDirectories>\r\n      <AdditionalDepend", 200);
      mBuffer.append("encies>$(PROTOBUF_DEBUG_LIBRARIES);%(AdditionalDependencies)</AdditionalDependencies>\r\n    </Link>\r\n  </ItemDefinitionGroup>\r\n  <ItemGroup>\r\n    <ProjectReference Include=\"DCOMPLUGIN_COMPONENT_NAMEPro", 200);
      mBuffer.append("toLib.vcxproj\">\r\n      <Project>{DCOMPLUGIN_PROTOLIB_PROJECT_GUID_LOWER}</Project>\r\n    </ProjectReference>\r\n    <ProjectReference Include=\"DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj\">\r\n      <Project>{D", 200);
      mBuffer.append("COMPLUGIN_SERVER_PROJECT_GUID_LOWER}</Project>\r\n    </ProjectReference>\r\n  </ItemGroup>\r\n  <ItemGroup>\r\n    <ClCompile Include=\"DCOMPLUGIN_COMPONENT_NAMEClient.cpp\">\r\n      <Optimization Condition=\"\'$", 200);
      mBuffer.append("(Configuration)|$(Platform)\'==\'Debug|Win32\'\">Disabled</Optimization>\r\n      <PreprocessorDefinitions Condition=\"\'$(Configuration)|$(Platform)\'==\'Debug|Win32\'\">WIN32;_DEBUG;_WINDOWS;_MBCS;_USRDLL;DCOMP", 200);
      mBuffer.append("LUGIN_COMPONENT_NAME_CLIENT_EXPORTS</PreprocessorDefinitions>\r\n      <BasicRuntimeChecks Condition=\"\'$(Configuration)|$(Platform)\'==\'Debug|Win32\'\">EnableFastChecks</BasicRuntimeChecks>\r\n      <Optimiz", 200);
      mBuffer.append("ation Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\">MaxSpeed</Optimization>\r\n      <PreprocessorDefinitions Condition=\"\'$(Configuration)|$(Platform)\'==\'Release|Win32\'\">WIN32;NDEBUG;_WIND", 200);
      mBuffer.append("OWS;_MBCS;_USRDLL;DCOMPLUGIN_COMPONENT_NAME_CLIENT_EXPORTS</PreprocessorDefinitions>\r\n    </ClCompile>\r\n  </ItemGroup>\r\n  <ItemGroup>\r\n    <ClInclude Include=\"DCOMPLUGIN_COMPONENT_NAMEClient.h\" />\r\n  ", 200);
      mBuffer.append("</ItemGroup>\r\n  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.targets\" />\r\n  <ImportGroup Label=\"ExtensionTargets\">\r\n  </ImportGroup>\r\n</Project>", 147);
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
  const File & getClientProjectFile() { static ClientProjectFile _instance; return _instance; }
}; //bin2cpp
