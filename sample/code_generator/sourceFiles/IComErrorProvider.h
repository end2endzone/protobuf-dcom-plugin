#pragma once

#include "TestDemo.pb.h"

namespace testdemo {

class IComErrorProvider
{
public:
  ///<summary>Returns the last error code that occured while processing a COM call.</summary>
  ///<returns>Returns 0 if not error occured. Returns a non-zero value when an error occured. See C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Include\WinError.h for details.</returns>
  virtual unsigned int GetLastComErrorCode() = 0;

  ///<summary>Returns an error message of the last error that occured while processing a COM call.</summary>
  ///<returns>Returns non-empty string describing the last error that occured.</returns>
  virtual std::string GetLastComErrorStr() = 0;
};

}  // namespace testdemo
