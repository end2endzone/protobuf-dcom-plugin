#pragma once

DCOMPLUGIN_ALL_SERVICES_INCLUDE_LIST

namespace DCOMPLUGIN_PACKAGE_NAME {

///<summary>Actual implementation of DCOMPLUGIN_PACKAGE_NAME services.</summary>
///<returns>Returns a string containing the file name of the current executable. ie: MyProcessName.exe</returns>
class DCOMPLUGIN_COMPONENT_NAMEServerImpl :	
                                DCOMPLUGIN_ALL_SERVICES_VIRTUAL_IMPL
{
public:
  DCOMPLUGIN_COMPONENT_NAMEServerImpl();
  virtual ~DCOMPLUGIN_COMPONENT_NAMEServerImpl();

  //DCOMPLUGIN_COMPONENT_NAMEProtoLib interfaces

  DCOMPLUGIN_ALL_SERVICES_DECLARATION
};

}  // namespace DCOMPLUGIN_PACKAGE_NAME
