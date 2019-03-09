// DCOMPLUGIN_COMPONENT_NAMEServerMain.cpp : Defines the entry point for the application.
//

#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <objbase.h> // 
#include "DCOMPLUGIN_COMPONENT_NAMEServer_h.h"
#include "DCOMPLUGIN_COMPONENT_NAMEServer.h"
#include <stdio.h>

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
  // register/unregister server on demand
  //
  char szUpperCommandLine[MAX_PATH];
  strcpy (szUpperCommandLine, lpCmdLine); // copy command line and work with it.
  _strupr (szUpperCommandLine);

  //Detect silent flag
  bool silent = false;
  if (strstr(szUpperCommandLine, "-S") || strstr(szUpperCommandLine, "/S"))
  {
    silent = true;
  }

  if (strstr (szUpperCommandLine, "UNREGSERVER"))
  {
    HRESULT hr = DllUnregisterServer();
    if (SUCCEEDED(hr))
    {
      if (!silent)
        MessageBox(NULL, "Unregister completed", "Success", MB_OK | MB_ICONINFORMATION);
      return 0;
    }
    else
    {
      if (!silent)
        MessageBox(NULL, "Unregister failed", "Error", MB_OK | MB_ICONERROR);
      return 1;
    }
  }
  else if (strstr (szUpperCommandLine, "REGSERVER"))
  {
    HRESULT hr = DllRegisterServer();
    if (SUCCEEDED(hr))
    {
      if (!silent)
        MessageBox(NULL, "Register completed", "Success", MB_OK | MB_ICONINFORMATION);
      return 0;
    }
    else
    {
      if (!silent)
        MessageBox(NULL, "Register failed", "Error", MB_OK | MB_ICONERROR);
      return 1;
    }
  }

  // initialize the COM library
  ::CoInitialize(NULL);

  // register ourself as a class object against the internal COM table
  // (this has nothing to do with the registry)
  DWORD nToken = CoEXEInitialize();

  // -- the message pump ----------------
  //
  // (loop ends if WM_QUIT message is received)
  //
  MSG msg;
  while (GetMessage(&msg, 0, 0, 0) > 0) 
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  // unregister from the known table of class objects
  CoEXEUninitialize(nToken);

  // 
  ::CoUninitialize();

  return 0;
}
