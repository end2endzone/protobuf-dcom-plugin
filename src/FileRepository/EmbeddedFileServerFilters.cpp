/**
 * This file was generated by
 * bin2cpp v1.3.
 * Copyright (C) 2013-2014 end2endzone.com. All rights reserved.
 * Do not modify this file.
 */
#include ".\EmbeddedFileServerFilters.h"
#include <stdio.h> //for FILE
#include <string> //for memcpy
namespace bin2cpp
{
  class ServerFiltersFile : public virtual bin2cpp::File
  {
  public:
    ServerFiltersFile() {}
    ~ServerFiltersFile() {}
    virtual size_t getSize() { return 1433; }
    virtual size_t getSegmentSize() { return 200; }
    virtual size_t getNumSegments() { return 8; }
    virtual const char * getFilename() { return "DCOMPLUGIN_COMPONENT_NAMEServer.vcxproj.filters"; }
    virtual const char * getSegment(size_t iIndex, size_t & oLength)
    {
      oLength = 0;
      if (iIndex >= getNumSegments())
        return NULL;
      const char * buffer = NULL;
      size_t index = 0;
      oLength = getSegmentSize();
      buffer = "\xef\xbb\277<?xml version=\"1.0\" encoding=\"utf-8\"?>\x0d\012<Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\x0d\012  <ItemGroup>\x0d\012    <Filter Include=\"Source Files\">\x0d\012      <UniqueId"; if (iIndex == index) return buffer; index++;
      buffer = "entifier>{5ac598b1-d493-49da-bf00-4d38eab4a040}</UniqueIdentifier>\x0d\012      <Extensions>cpp;c;cxx;rc;def;r;odl;idl;hpj;bat</Extensions>\x0d\012    </Filter>\x0d\012    <Filter Include=\"Header Files\">\x0d\012      <Unique"; if (iIndex == index) return buffer; index++;
      buffer = "Identifier>{ab5c4c5f-3f84-40dc-a54c-0a8461c32a2e}</UniqueIdentifier>\x0d\012      <Extensions>h;hpp;hxx;hm;inl</Extensions>\x0d\012    </Filter>\x0d\012    <Filter Include=\"Resource Files\">\x0d\012      <UniqueIdentifier>{63"; if (iIndex == index) return buffer; index++;
      buffer = "1366e6-6afe-47e8-a5d8-02317eb06640}</UniqueIdentifier>\x0d\012      <Extensions>ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe</Extensions>\x0d\012    </Filter>\x0d\012  </ItemGroup>\x0d\012  <ItemGroup>\x0d\012    <ClCompile In"; if (iIndex == index) return buffer; index++;
      buffer = "clude=\"DCOMPLUGIN_COMPONENT_NAMEServerMain.cpp\">\x0d\012      <Filter>Source Files</Filter>\x0d\012    </ClCompile>\x0d\012    <ClCompile Include=\"DCOMPLUGIN_COMPONENT_NAMEServer.cpp\">\x0d\012      <Filter>Source Files</Filt"; if (iIndex == index) return buffer; index++;
      buffer = "er>\x0d\012    </ClCompile>\x0d\012  </ItemGroup>\x0d\012  <ItemGroup>\x0d\012    <ClInclude Include=\"SmartPointers.h\">\x0d\012      <Filter>Header Files</Filter>\x0d\012    </ClInclude>\x0d\012    <ClInclude Include=\"DCOMPLUGIN_COMPONENT_NAM"; if (iIndex == index) return buffer; index++;
      buffer = "EServer.h\">\x0d\012      <Filter>Header Files</Filter>\x0d\012    </ClInclude>\x0d\012  </ItemGroup>\x0d\012  <ItemGroup>\x0d\012    <Midl Include=\"DCOMPLUGIN_COMPONENT_NAMEServer.idl\">\x0d\012      <Filter>Source Files</Filter>\x0d\012    </"; if (iIndex == index) return buffer; index++;
      oLength = 33;
      buffer = "Midl>\x0d\012  </ItemGroup>\x0d\012</Project>"; if (iIndex == index) return buffer; index++;
      oLength = 0;
      return NULL;
    }
    virtual const char * getMd5() { return "6a5e8c86a415d66329565f7a124a090b"; }
    virtual char * newBuffer()
    {
      size_t size = getSize();
      char * buffer = new char[size];
      if (buffer == NULL)
        return NULL;
      size_t numSegments = getNumSegments();
      size_t segmentLength = 0;
      size_t index = 0;
      for(size_t i=0; i<numSegments; i++)
      {
        const char * segmentBuffer = getSegment(i, segmentLength);
        memcpy(&buffer[index], segmentBuffer, segmentLength);
        index += segmentLength;
      }
      return buffer;
    }
    virtual bool save(const char * iFilename)
    {
      FILE * f = fopen(iFilename, "wb");
      if (!f) return false;
      size_t numSegments = getNumSegments();
      size_t segmentLength = 0;
      const char * buffer = NULL;
      for(size_t i=0; i<numSegments; i++)
      {
        buffer = getSegment(i, segmentLength);
        fwrite(buffer, 1, segmentLength, f);
      }
      fclose(f);
      return true;
    }
  };
  File & getServerFiltersFile() { static ServerFiltersFile _instance; return _instance; }
}; //bin2cpp
