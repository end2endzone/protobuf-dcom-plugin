#include "MacroManager.h"
#include "stringfunc.h"
#include <algorithm>

MacroManager::MacroManager()
{
}

MacroManager::~MacroManager()
{
}

MacroManager & MacroManager::getInstance()
{
  static MacroManager mgr;
  return mgr;
}

struct MACRO
{
  std::string name;
  std::string value;
};
typedef std::vector<MACRO> MacroVector;
MacroVector mRegisteredMacros;

void MacroManager::clear()
{
  mRegisteredMacros.clear();
}

void MacroManager::registerMacro(const char * iName, const char * iValue)
{
  MACRO m;
  m.name = iName;
  m.value = iValue;

  //should we replace an existing macro ?
  size_t index = getMacroIndex(iName);

  //if not found
  if (index == INVALID_INDEX)
  {
    mRegisteredMacros.push_back(m);
  }
  else
  {
    //replace existing macro
    MACRO & old = mRegisteredMacros[index];
    old = m;
  }

  sort();
}

void MacroManager::registerMacro(const char * iName, const std::string & iValue)
{
  registerMacro(iName, iValue.c_str());
}


bool MacroManager::hasMacro(const char * iName)
{
  if (iName == NULL)
    return false;
  size_t index = getMacroIndex(iName);
  return index != INVALID_INDEX;
}

std::string MacroManager::getMacro(const char * iName)
{
  if (iName == NULL)
    return std::string();
  for(size_t i=0; i<mRegisteredMacros.size(); i++)
  {
    const MACRO & m = mRegisteredMacros[i];
    if (m.name == iName)
    {
      return m.value;
    }
  }
  return std::string();
}

void MacroManager::removeMacro(const char * iName)
{
  if (iName == NULL)
    return;

  size_t index = getMacroIndex(iName);
  if (index != INVALID_INDEX)
  {
    //found!
    mRegisteredMacros.erase(mRegisteredMacros.begin() + index);
  }
}

void MacroManager::replaceMacros(std::string & ioBuffer)
{
  for(size_t i=0; i<mRegisteredMacros.size(); i++)
  {
    const MACRO & m = mRegisteredMacros[i];
    size_t pos = ioBuffer.find(m.name);
    if (pos != std::string::npos)
    {
      //macro found
      stringReplace(ioBuffer, m.name.c_str(), m.value.c_str());
    }
  }
}

void MacroManager::sort()
{
  struct MY_SORT_FUNCTION
  {
    bool operator()(const MacroManager::MACRO & a, const MacroManager::MACRO & b)
    {
      if (a.name.size() != b.name.size())
        return a.name.size() >= b.name.size(); //return longest first
      //in case of same length, sort alphabetically
      return a.name < b.name;
    }
  };
  std::sort(mRegisteredMacros.begin(), mRegisteredMacros.end(), MY_SORT_FUNCTION());
}

size_t MacroManager::getMacroIndex(const char * iName)
{
  if (iName == NULL)
    return INVALID_INDEX;

  for(size_t i=0; i<mRegisteredMacros.size(); i++)
  {
    MACRO & tmp = mRegisteredMacros[i];
    if (tmp.name == iName)
    {
      return i;
    }
  }

  return INVALID_INDEX;
}
