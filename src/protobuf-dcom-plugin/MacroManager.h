#pragma once

#include <vector>
#include <string>

class MacroManager
{
private:
  MacroManager();
public:
  ~MacroManager();

  static MacroManager & getInstance();

  struct MACRO
  {
    std::string name;
    std::string value;
  };
  typedef std::vector<MACRO> MacroVector;
  MacroVector mRegisteredMacros;

  void clear();
  void registerMacro(const char * iName, const char * iValue);
  void registerMacro(const char * iName, const std::string & iValue);
  bool hasMacro(const char * iName);
  std::string getMacro(const char * iName);
  void removeMacro(const char * iName);
  void replaceMacros(std::string & ioBuffer);
  
private:
  //attributes
  static const size_t INVALID_INDEX = (size_t)-1;

  //methods
  void sort();
  size_t getMacroIndex(const char * iName);

};
