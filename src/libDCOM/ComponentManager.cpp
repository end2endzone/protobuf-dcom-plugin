#include "ComponentManager.h"
#include "stringfunc.h"
#include "path.h"
#include "protofunc.h"
#include "dcom.h"

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}

bool ComponentManager::validate(const dcomplugin::Component & c, std::string & oError)
{
  return validate(c, "", oError);
}

bool ComponentManager::validate(const dcomplugin::Component & c, const std::string & iMessagePrefix, std::string & oError)
{
  if (!c.has_name() || c.name().empty())
  {
    oError = "Missing \"";
    oError.append(iMessagePrefix);
    oError.append(".name\"");
    return false;
  }

  if (!c.has_typelib())
  {
    oError = "Missing \"";
    oError.append(iMessagePrefix);
    oError.append(".typelib\"");
    return false;
  }

  if (!validate(c.typelib(), iMessagePrefix + ".typelib", oError))
    return false;

  if (!validate(c.appid(), iMessagePrefix + ".appid", oError))
    return false;

  return true;
}

bool ComponentManager::validate(const dcomplugin::TypeLib & typelib, const std::string & iMessagePrefix, std::string & oError)
{
  if (!typelib.has_name() || typelib.name().empty())
  {
    oError = "Missing \"";
    oError.append(iMessagePrefix);
    oError.append(".name\"");
    return false;
  }

  if (!validate(typelib.id(), iMessagePrefix + ".id", oError))
    return false;

  if (!validate(typelib.cointerface(), iMessagePrefix + ".cointerface", oError))
    return false;

  if (!validate(typelib.coclass(), iMessagePrefix + ".coclass", oError))
    return false;

  return true;
}

bool ComponentManager::validate(const dcomplugin::CoClass & coclass, const std::string & iMessagePrefix, std::string & oError)
{
  if (!coclass.has_name() || coclass.name().empty())
  {
    oError = "Missing \"";
    oError.append(iMessagePrefix);
    oError.append(".name\"");
    return false;
  }

  if (!coclass.has_friendlyname() || coclass.friendlyname().empty())
  {
    oError = "Missing \"";
    oError.append(iMessagePrefix);
    oError.append(".friendlyname\"");
    return false;
  }

  if (!validate(coclass.id(), iMessagePrefix + ".id", oError))
    return false;

  return true;
}

bool ComponentManager::validate(const dcomplugin::CoInterface & cointerface, const std::string & iMessagePrefix, std::string & oError)
{
  if (!validate(cointerface.id(), iMessagePrefix + ".id", oError))
    return false;

  return true;
}

bool ComponentManager::validate(const dcomplugin::Identifier & id, const std::string & iMessagePrefix, std::string & oError)
{
  if (!id.has_guid() || id.guid().empty())
  {
    oError = "Missing \"";
    oError.append(iMessagePrefix);
    oError.append(".guid\"");
    return false;
  }

  if (!id.has_helpstring() || id.helpstring().empty())
  {
    oError = "Missing \"";
    oError.append(iMessagePrefix);
    oError.append(".helpstring\"");
    return false;
  }

  return true;
}

bool ComponentManager::isValid(const dcomplugin::Component & c)
{
  std::string tmp;
  bool valid = validate(c, tmp);
  return valid;
}

void ComponentManager::build(dcomplugin::Component & c)
{
  //get component name
  const std::string & componentName = c.name();
  if (componentName.empty())
    return; //failed

  if (!c.has_typelib())
  {
    build(*c.mutable_typelib(), componentName);
  }

  if (!c.has_appid())
  {
    build(*c.mutable_appid());
  }

  //fill helpstrings of Identifier messages
  setDefaultHelpstring(*c.mutable_typelib()->mutable_id(), componentName + " 1.0 Type Library");
  setDefaultHelpstring(*c.mutable_typelib()->mutable_cointerface()->mutable_id(), std::string() << "I" << componentName << "Server Interface");
  setDefaultHelpstring(*c.mutable_typelib()->mutable_coclass()->mutable_id(), std::string() << componentName << "ServerImpl Class");
  setDefaultHelpstring(*c.mutable_appid(), "AppID");
}

void ComponentManager::build(dcomplugin::Component & c, const google::protobuf::FileDescriptor & iFileDescriptor)
{
  //create a name of the component based on the file descriptor
  if (!c.has_name())
  {
    std::string fileName = capitalizeFirst(getFileNameWithoutExtension(iFileDescriptor.name()));
    c.set_name(fileName);
  }

  //continue building without the file descriptor
  build(c);
}

void ComponentManager::build(dcomplugin::TypeLib & typelib, const std::string & iComponentName)
{
  if (!typelib.has_name())
  {
    typelib.set_name(iComponentName + "Lib");
  }

  if (!typelib.has_id())
  {
    build(*typelib.mutable_id());
  }

  if (!typelib.has_cointerface())
  {
    build(*typelib.mutable_cointerface(), iComponentName);
  }

  if (!typelib.has_coclass())
  {
    build(*typelib.mutable_coclass(), iComponentName);
  }
}

void ComponentManager::build(dcomplugin::CoClass & coclass, const std::string & iComponentName)
{
  if (!coclass.has_name() || coclass.name().empty())
  {
    coclass.set_name(iComponentName + ".Application");
  }

  if (!coclass.has_friendlyname() || coclass.friendlyname().empty())
  {
    coclass.set_friendlyname(iComponentName + " Class");
  }

  if (!coclass.has_id())
  {
    build(*coclass.mutable_id());
  }
}

void ComponentManager::build(dcomplugin::CoInterface & cointerface, const std::string & iComponentName)
{
  if (!cointerface.has_id())
  {
    build(*cointerface.mutable_id());
  }
}

void ComponentManager::build(dcomplugin::Identifier & id)
{
  if (!id.has_guid() || id.guid().empty())
  {
    std::string value = newGuid();
    value = capitalize(value);
    id.set_guid( value );
  }

  //note: helpstring must be set by the Component builder
}

void ComponentManager::setDefaultHelpstring(dcomplugin::Identifier & id, const std::string & iValue)
{
  if (!id.has_helpstring() || id.helpstring().empty())
  {
    id.set_helpstring( iValue );
  }
}
