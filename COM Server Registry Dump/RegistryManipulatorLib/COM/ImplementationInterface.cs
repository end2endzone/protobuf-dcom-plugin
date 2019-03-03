using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RegistryManipulatorLib
{
  namespace COM
  {
    public class ImplementationInterface
    {
      public string Guid { get; set; }
      public string Name { get; set; }
      public string ProxyStubClsid32 { get; set; }
      public string TypeLib { get; set; }
      public string TypeLibVersion { get; set; }
    }
  }
}
