using RegistryManipulatorLib.COM;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace RegistryManipulatorTests
{
    
    
    /// <summary>
    ///This is a test class for QueryManagerTest and is intended
    ///to contain all QueryManagerTest Unit Tests
    ///</summary>
  [TestClass()]
  public class QueryManagerTest
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
    ///A test for GetClassCurVer
    ///</summary>
    [TestMethod()]
    public void GetClassCurVerTest()
    {
      //base class
      {
        string className = "Word.Application";
        string actual;
        actual = QueryManager.GetClassCurVer(className);
        Assert.IsNotNull(actual);
        Assert.IsTrue(className.Length < actual.Length);
      }

      //actual current version
      {
        string className = QueryManager.GetClassCurVer("Word.Application");
        string expected = className;
        string actual;
        actual = QueryManager.GetClassCurVer(className);
        Assert.AreEqual(expected, actual);
      }
    }

    /// <summary>
    ///A test for GetClassID
    ///</summary>
    [TestMethod()]
    public void GetClassIDTest()
    {
      string className = QueryManager.GetClassCurVer("Word.Application");
      string actual;
      actual = QueryManager.GetClassID(className);
      Assert.IsNotNull(actual);
      Assert.AreNotEqual("", actual);
    }

    private void ValidateCLSID(CLSID actual)
    {
      Assert.IsNotNull(actual);
      AssertExtensions.IsNotEmpty(actual.Guid);
      AssertExtensions.IsNotEmpty(actual.Name);
      //AssertExtensions.IsNotEmpty(actual.LocalServer32); //optional
      //AssertExtensions.IsNotEmpty(actual.InProcServer32); //optional
      AssertExtensions.IsNotEmpty(actual.ProgID);
      AssertExtensions.IsNotEmpty(actual.TypeLib);
      AssertExtensions.IsNotEmpty(actual.VersionIndependentProgID);
      //AssertExtensions.IsNotEmpty(actual.Version); //optional
    }

    /// <summary>
    ///A test for GetCLSID
    ///</summary>
    [TestMethod()]
    public void GetCLSIDTest()
    {
      //Note: The following classes does not have a TypeLib: Word.Application, ADODB.Connection, GoogleUpdate.CoreClass, System.Collections.ArrayList
      CLSID actual;

      actual = QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("InternetExplorer.Application"))); /**/ ValidateCLSID(actual);
      actual = QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("Scripting.FileSystemObject")));   /**/ ValidateCLSID(actual);
      actual = QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("giffile")));                      /**/ ValidateCLSID(actual);
      actual = QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("WindowsInstaller.Installer")));   /**/ ValidateCLSID(actual);
      actual = QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("WScript.Shell")));                /**/ ValidateCLSID(actual);
    }

    private void ValidateTypeLib(TypeLib actual)
    {
      Assert.IsNotNull(actual);
      AssertExtensions.IsNotEmpty(actual.Guid);
      AssertExtensions.IsNotEmpty(actual.Name);
      AssertExtensions.IsNotEmpty(actual.Win32Path);
      AssertExtensions.IsNotEmpty(actual.Flags);
      AssertExtensions.IsNotEmpty(actual.HelpDir);
    }

    /// <summary>
    ///A test for GetTypeLib
    ///</summary>
    [TestMethod()]
    public void GetTypeLibTest()
    {
      //Note: The following classes does not have a link between CLSID.Version to an actual TypeLib: InternetExplorer.Application

      TypeLib actual;

      actual = QueryManager.GetTypeLib(QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("Scripting.FileSystemObject"))));   /**/ ValidateTypeLib(actual);
      actual = QueryManager.GetTypeLib(QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("giffile"))));                      /**/ ValidateTypeLib(actual);
      actual = QueryManager.GetTypeLib(QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("WindowsInstaller.Installer"))));   /**/ ValidateTypeLib(actual);
      actual = QueryManager.GetTypeLib(QueryManager.GetCLSID(QueryManager.GetClassID(QueryManager.GetClassCurVer("WScript.Shell"))));                /**/ ValidateTypeLib(actual);
    }

    /// <summary>
    ///A test for GetTypeLibInterfaces
    ///</summary>
    [TestMethod()]
    [Ignore]
    public void GetTypeLibInterfacesTest()
    {
      string guid = QueryManager.GetClassID(QueryManager.GetClassCurVer("InternetExplorer.Application"));
      CLSID clsid = QueryManager.GetCLSID(guid);
      Assert.IsNotNull(clsid);
      AssertExtensions.IsNotEmpty(clsid.TypeLib);

      string expected = "{0002DF05-0000-0000-C000-000000000046}";
      string[] actual;
      actual = QueryManager.GetTypeLibInterfaces(clsid.TypeLib);

      Assert.IsNotNull(actual);
      Assert.IsTrue(actual.Length > 0);

      bool found = false;
      foreach (string interfaceGuid in actual)
      {
        if (expected.Equals(interfaceGuid))
          found = true;
      }
      Assert.IsTrue(found);
    }

    private void ValidatePath(string actual)
    {
      Assert.IsNotNull(actual);
      Assert.AreNotEqual(string.Empty, actual);
    }

    /// <summary>
    ///A test for GetComponentFilePath
    ///</summary>
    [TestMethod()]
    public void GetComponentFilePathTest()
    {
      string actual;
      actual = QueryManager.GetComponentFilePath("InternetExplorer.Application"); /**/ ValidatePath(actual);
      actual = QueryManager.GetComponentFilePath("Word.Application");             /**/ ValidatePath(actual);
      actual = QueryManager.GetComponentFilePath("Scripting.FileSystemObject");   /**/ ValidatePath(actual);
      actual = QueryManager.GetComponentFilePath("ADODB.Connection");             /**/ ValidatePath(actual);
      actual = QueryManager.GetComponentFilePath("giffile");                      /**/ ValidatePath(actual);
      actual = QueryManager.GetComponentFilePath("WindowsInstaller.Installer");   /**/ ValidatePath(actual);
      actual = QueryManager.GetComponentFilePath("WScript.Shell");                /**/ ValidatePath(actual);
    }

    /// <summary>
    ///A test for ExportComponentRegistry
    ///</summary>
    [TestMethod()]
    public void ExportComponentRegistryTest()
    {
      string className = "InternetExplorer.Application"; //"MyAltComServer.MyServerImpl";
      string filePath = Environment.GetEnvironmentVariable("TEMP") + "\\ExportComponentRegistryTest.tmp";
      bool expected = true;
      bool actual;
      System.IO.File.Delete(filePath);

      actual = QueryManager.ExportComponentRegistry(className, filePath);
      Assert.AreEqual(expected, actual);

      Assert.IsTrue( System.IO.File.Exists(filePath) );
    }
  }
}
