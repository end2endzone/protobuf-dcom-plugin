#include "dcom.h"

#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <iomanip>

//std::string code2string(const std::vector<std::string> & iLines)
//{
//  std::string output;
//
//  static const char * CRLF = "\x0D\x0A";
//  static const char * LF = "\x0A";
//
//  for(size_t i=0; i<iLines.size(); i++)
//  {
//    bool isLast = (i+1)==iLines.size();
//
//    const std::string & line = iLines[i];
//    output.append(line);
//
//    if (!isLast)
//      output.append(CRLF);
//  }
//
//  return output;
//}

std::string newGuid()
{
  //https://stackoverflow.com/questions/1327157/whats-the-c-version-of-guid-newguid
  GUID guid;
  CoCreateGuid(&guid);

  std::ostringstream os;
  os << std::hex << std::setw(8) << std::setfill('0') << guid.Data1;
  os << '-';
  os << std::hex << std::setw(4) << std::setfill('0') << guid.Data2;
  os << '-';
  os << std::hex << std::setw(4) << std::setfill('0') << guid.Data3;
  os << '-';
  os << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(guid.Data4[0]);
  os << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(guid.Data4[1]);
  os << '-';
  os << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(guid.Data4[2]);
  os << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(guid.Data4[3]);
  os << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(guid.Data4[4]);
  os << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(guid.Data4[5]);
  os << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(guid.Data4[6]);
  os << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(guid.Data4[7]);

  std::string txtGuid = os.str();
  return txtGuid;
}
