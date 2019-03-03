using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RegistryManipulatorLib
{
  namespace COM
  {
    public class ServerInfo
    {
      public string Name { get; set; }
      public AppID AppID { get; set; }
      public AppID CLSID { get; set; }
    }
  }
}
