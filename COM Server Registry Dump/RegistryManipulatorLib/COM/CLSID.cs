using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RegistryManipulatorLib
{
  namespace COM
  {
    public class CLSID
    {
      public string Guid { get; set; }
      public string Name { get; set; }
      public string LocalServer32 { get; set; }
      public string InProcServer32 { get; set; }
      public string ProgID { get; set; }
      public string TypeLib { get; set; }
      public string VersionIndependentProgID { get; set; }
      public string Version { get; set; }
    }
  }
}
