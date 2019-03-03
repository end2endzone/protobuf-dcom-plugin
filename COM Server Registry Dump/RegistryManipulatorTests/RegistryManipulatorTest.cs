using RegistryManipulatorLib;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Microsoft.Win32;

namespace RegistryManipulatorTests
{
    
    
    /// <summary>
    ///This is a test class for RegistryManipulatorTest and is intended
    ///to contain all RegistryManipulatorTest Unit Tests
    ///</summary>
  [TestClass()]
  public class RegistryManipulatorTest
  {


    private TestContext testContextInstance;

    /// <summary>
    ///Gets or sets the test context which provides
    ///information about and functionality for the current test run.
    ///</summary>
    public TestContext TestContext
    {
      get
      {
        return testContextInstance;
      }
      set
      {
        testContextInstance = value;
      }
    }

    #region Additional test attributes
    // 
    //You can use the following additional attributes as you write your tests:
    //
    //Use ClassInitialize to run code before running the first test in the class
    //[ClassInitialize()]
    //public static void MyClassInitialize(TestContext testContext)
    //{
    //}
    //
    //Use ClassCleanup to run code after all tests in a class have run
    //[ClassCleanup()]
    //public static void MyClassCleanup()
    //{
    //}
    //
    //Use TestInitialize to run code before running each test
    //[TestInitialize()]
    //public void MyTestInitialize()
    //{
    //}
    //
    //Use TestCleanup to run code after each test has run
    //[TestCleanup()]
    //public void MyTestCleanup()
    //{
    //}
    //
    #endregion


    /// <summary>
    ///A test for RegistryManipulator Constructor
    ///</summary>
    [TestMethod()]
    public void RegistryManipulatorConstructorTest()
    {
    }

    /// <summary>
    ///A test for getKeyDefaultValue
    ///</summary>
    [TestMethod()]
    public void GetKeyDefaultValueTest()
    {
      Assert.AreEqual("txtfile", RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\.txt"));
      Assert.AreEqual(null, RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\foobar"));
    }

    /// <summary>
    ///A test for getStringValue
    ///</summary>
    [TestMethod()]
    public void GetStringValueTest()
    {
      string keyName = "HKEY_CLASSES_ROOT\\.txt";
      string valueName = "Content Type";
      string expected = "text/plain";
      string actual;
      actual = RegistryManipulator.GetStringValue(keyName, valueName);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for ExportKey
    ///</summary>
    [TestMethod()]
    public void ExportKeyTest()
    {
      string keyName = "HKEY_CLASSES_ROOT\\.txt";
      string filePath = Environment.GetEnvironmentVariable("TEMP") + "\\ExportKeyTest.tmp";
      bool expected = true;
      bool actual;

      System.IO.File.Delete(filePath);

      actual = RegistryManipulator.ExportKey(keyName, filePath);
      Assert.AreEqual(expected, actual);

      Assert.IsTrue( System.IO.File.Exists(filePath) );

      //------------------------------------------------------

      byte[] data = null;
      actual = RegistryManipulator.ExportKey(keyName, ref data);
      Assert.AreEqual(expected, actual);
      Assert.IsNotNull(data);
      Assert.IsTrue(data.Length > 0);
    }

    /// <summary>
    ///A test for HasClass
    ///</summary>
    [TestMethod()]
    public void HasClassTest()
    {
      Assert.AreEqual(true, RegistryManipulator.HasClass("ADODB.Connection"));
      Assert.AreEqual(false, RegistryManipulator.HasClass("foobar"));
    }

    /// <summary>
    ///A test for GetRegistryHive
    ///</summary>
    [TestMethod()]
    public void GetRegistryHiveTest()
    {
      Assert.AreEqual(Registry.ClassesRoot,   RegistryManipulator.GetRegistryHive("HKEY_CLASSES_ROOT\\._sln"));
      Assert.AreEqual(Registry.CurrentConfig, RegistryManipulator.GetRegistryHive("HKEY_CURRENT_CONFIG\\Software"));
      Assert.AreEqual(Registry.CurrentUser,   RegistryManipulator.GetRegistryHive("HKEY_CURRENT_USER\\Software"));
      Assert.AreEqual(Registry.LocalMachine,  RegistryManipulator.GetRegistryHive("HKEY_LOCAL_MACHINE\\SOFTWARE"));
      Assert.AreEqual(Registry.Users,         RegistryManipulator.GetRegistryHive("HKEY_USERS\\.DEFAULT"));
    }

    /// <summary>
    ///A test for GetKeyPath
    ///</summary>
    [TestMethod()]
    public void GetKeyPathTest()
    {
      string expected = "Software\\foobar";
      Assert.AreEqual(expected, RegistryManipulator.GetKeyPath("HKEY_CLASSES_ROOT\\" + expected));
      Assert.AreEqual(expected, RegistryManipulator.GetKeyPath("HKEY_CURRENT_CONFIG\\" + expected));
      Assert.AreEqual(expected, RegistryManipulator.GetKeyPath("HKEY_CURRENT_USER\\" + expected));
      Assert.AreEqual(expected, RegistryManipulator.GetKeyPath("HKEY_LOCAL_MACHINE\\" + expected));
      Assert.AreEqual(expected, RegistryManipulator.GetKeyPath("HKEY_USERS\\" + expected));
    }

    /// <summary>
    ///A test for GetSubKeys
    ///</summary>
    [TestMethod()]
    public void GetSubKeysTest()
    {
      string keyName = "HKEY_LOCAL_MACHINE\\HARDWARE";
      string[] expected = new string[]{"ACPI", "DESCRIPTION", "DEVICEMAP", "RESOURCEMAP"};
      string[] actual;
      actual = RegistryManipulator.GetSubKeys(keyName);
      CollectionAssert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for KeyExists
    ///</summary>
    [TestMethod()]
    public void KeyExistsTest()
    {
      Assert.IsTrue(RegistryManipulator.KeyExists("HKEY_CLASSES_ROOT\\.txt"));
      Assert.IsFalse(RegistryManipulator.KeyExists("HKEY_CLASSES_ROOT\\foobar"));
    }
  }
}
