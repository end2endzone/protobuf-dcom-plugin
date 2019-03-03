#include "ErrorHandlers.h"

#include <comdef.h>

namespace testdemo {

std::string getProcessFilename()                           
{                                                                 
  std::string path;                                               
  char buffer[MAX_PATH] = {0};                                    
  HMODULE hModule = NULL;                                         
  if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | 
          GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,           
          (LPCSTR) __FUNCTION__,   
          &hModule))                                              
  {                                                               
      int ret = GetLastError();                                   
      return std::string();                                       
  }                                                               
  /*get the path of this DLL*/                                    
  GetModuleFileName(hModule, buffer, sizeof(buffer));             
  if (buffer[0] != '\0')                                          
  {                                                               
    /*remove folders from path*/                                     
    path = buffer;                                                
    while(path.find("/") != std::string::npos)
    {
      path.erase(path.begin(), path.begin()+1);
    }
    while(path.find("\\") != std::string::npos)
    {
      path.erase(path.begin(), path.begin()+1);
    }
  }                                                               
  return path;                                                    
}

std::string toString(DWORD value)
{
  static const int BUFFER_SIZE = 1024;
  char buffer[BUFFER_SIZE];
  sprintf(buffer, "%lu", value);
  std::string str = buffer;
  return str;
}

void MessageBoxLastError()
{
  DWORD dwErrorCode = GetLastError();

  LPVOID lpMessageBuffer; 
  FormatMessage( 
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM,
    NULL,
    dwErrorCode,
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //The user default language
    (LPTSTR) &lpMessageBuffer,
    1,
    NULL 
  );

  std::string caption;
  caption += getProcessFilename();
  std::string message;
  message += "An internal error occured in process ";
  message += getProcessFilename();
  message += "\n";
  message += "\n";
  message += "Error code: ";
  message += toString(dwErrorCode);
  message += "\n";
  message += "Error desc: ";
  message += (LPTSTR)lpMessageBuffer;

  MessageBox(NULL, message.c_str(), caption.c_str(), MB_OK | MB_ICONERROR);
  LocalFree(lpMessageBuffer);
}

void MessageBoxLastComError(HRESULT hr)
{
  _com_error err(hr);
  LPCTSTR lpMessageBuffer = err.ErrorMessage();

  std::string caption;
  caption += getProcessFilename();
  std::string message;
  message += "An internal error occured in process ";
  message += getProcessFilename();
  message += "\n";
  message += "\n";
  message += "Error code: ";
  message += toString(hr);
  message += "\n";
  message += "Error desc: ";
  message += (LPTSTR)lpMessageBuffer;

  MessageBox(NULL, message.c_str(), caption.c_str(), MB_OK | MB_ICONERROR);
}

std::string GetComErrorDescription(HRESULT hr)
{
  _com_error err(hr);
  std::string description = err.ErrorMessage();
  return description;
}

}  // namespace testdemo
