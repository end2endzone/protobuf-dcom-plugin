using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using A = Microsoft.VisualStudio.TestTools.UnitTesting.Assert;

namespace RegistryManipulatorTests
{
  public static class AssertExtensions
  {
    public static void IsNotEmpty(string expression)
    {
      A.IsNotNull(expression);
      A.AreNotEqual(string.Empty, expression);
    }
  }
}
