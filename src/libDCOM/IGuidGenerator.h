#pragma once

#include <string>

class IGuidGenerator
{
public:
  virtual std::string newGuid() = 0;
};
