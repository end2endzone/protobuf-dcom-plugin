// MyAltComServer.cpp : Implementation of WinMain


#include "stdafx.h"
#include "resource.h"
#include "MyAltComServer_i.h"
#include "dlldatax.h"


class CMyAltComServerModule : public CAtlExeModuleT< CMyAltComServerModule >
{
public :
	DECLARE_LIBID(LIBID_MyAltComServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MYALTCOMSERVER, "{73303544-1064-4EB2-B59F-1DA165BD479E}")
};

CMyAltComServerModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}

