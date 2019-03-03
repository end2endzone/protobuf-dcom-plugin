using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace COM_Server_Registry_Dump
{
  static class Program
  {
    private static bool ParseArgument(string[] args, string name, ref string value)
    {
      string pattern = "--" + name + "=";
      foreach (string arg in args)
      {
        if (arg.IndexOf(pattern) == 0)
        {
          value = arg.Replace(pattern, "");
          return true;
        }
      }
      value = "";
      return false;
    }

    public static void ShowUsage()
    {
      Console.WriteLine("Usage:");
      Console.WriteLine("  COMServerRegistryDump.exe --class=[value] --of=[value]");
      Console.WriteLine("     class:  Name of the COM class to export registry.");
      Console.WriteLine("     of:     Path of the output file to export the registry.");
      Console.WriteLine("");
    }

    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    static int Main(string[] args)
    {
      Console.WriteLine("COM Server Registry Dump v1.0");

      //validate command line arguments
      string className = "";
      string outputFile = "";
      bool hasClassName = ParseArgument(args, "class", ref className);
      bool hasOutputFile = ParseArgument(args, "of", ref outputFile);

      if (!hasClassName || !hasOutputFile)
      {
        Console.WriteLine("*** Error: Unable to parse command line arguments!");
        Console.WriteLine("");
        ShowUsage();
        return 1;
      }

      //delete output file
      File.Delete(outputFile);
      
      //proceed with the registry extraction
      Console.WriteLine("Exporting registry for class '" + className + "'.");
      bool success = RegistryManipulatorLib.COM.QueryManager.ExportComponentRegistry(className, outputFile);
      if (!success)
      {
        Console.WriteLine("*** Error: Failed exporting registry.");
        Console.WriteLine("");
        return 2;
      }

      //success
      Console.WriteLine("Export completed without error.");
      return 0;
    }
  }
}
