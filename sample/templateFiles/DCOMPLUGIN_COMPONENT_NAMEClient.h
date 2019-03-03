#pragma once

#include "IComErrorProvider.h"
DCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST

namespace DCOMPLUGIN_PACKAGE_NAME {

#ifdef DCOMPLUGIN_COMPONENT_NAME_CLIENT_EXPORTS
#define DCOMPLUGIN_COMPONENT_NAME_DLL_API __declspec(dllexport)
#else
#define DCOMPLUGIN_COMPONENT_NAME_DLL_API __declspec(dllimport)
#endif

///<summary>Client class for connection to DCOMPLUGIN_COMPONENT_NAMEServer.</summary>
class DCOMPLUGIN_COMPONENT_NAME_DLL_API DCOMPLUGIN_COMPONENT_NAMEClient : public virtual IComErrorProvider, 
DCOMPLUGIN_ALL_SERVICES_VIRTUAL_IMPL

{
public:
  DCOMPLUGIN_COMPONENT_NAMEClient();
  virtual ~DCOMPLUGIN_COMPONENT_NAMEClient();

  ///<summary>Defines if the DCOMPLUGIN_COMPONENT_NAMEServer is available.</summary>
  ///<returns>Returns true if the client is connected with the DCOMPLUGIN_COMPONENT_NAMEServer server. Returns false otherwise.</returns>
  bool isConnected();

  //DCOMPLUGIN_COMPONENT_NAMEProtoLib interfaces

  //IComErrorProvider
  virtual unsigned int GetLastComErrorCode();
  virtual std::string GetLastComErrorStr();
  
  DCOMPLUGIN_ALL_SERVICES_DECLARATION

protected:
  ///<summary>Error code returned by the last internal call to the server.</summary>
  unsigned long mLastError;

  ///<summary>DCOMPLUGIN_COMPONENT_NAMEClient private implementation pointer.</summary>
  void * mInstance;
};

}  // namespace DCOMPLUGIN_PACKAGE_NAME
