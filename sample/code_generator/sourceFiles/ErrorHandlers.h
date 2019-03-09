#pragma once

#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <string>

namespace testdemo {

///<summary>Provide the file name of the current executable.</summary>
///<returns>Returns a string containing the file name of the current executable. ie: MyProcessName.exe</returns>
std::string getProcessFilename();

///<summary>Display an error message box which shows the last error code and its description.</summary>
void MessageBoxLastError();

///<summary>Display an error message box which shows the last error code and its description.</summary>
///<param name="hr">A return value of a call to a Win32 API.</param>
void MessageBoxLastComError(HRESULT hr);

///<summary>Returns a string representation of the given error code.</summary>
///<param name="hr">A return value of a call to a Win32 API.</param>
///<returns>Returns a string representation of the given error code.</returns>
std::string GetComErrorDescription(HRESULT hr);

}  // namespace testdemo
