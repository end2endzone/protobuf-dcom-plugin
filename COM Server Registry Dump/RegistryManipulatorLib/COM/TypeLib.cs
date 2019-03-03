using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RegistryManipulatorLib
{
  namespace COM
  {
    public class TypeLib
    {
      public string Guid { get; set; }
      public string Name { get; set; }
      public string Win32Path { get; set; }
      public string Flags { get; set; }
      public string HelpDir { get; set; }
    }
  }
}
