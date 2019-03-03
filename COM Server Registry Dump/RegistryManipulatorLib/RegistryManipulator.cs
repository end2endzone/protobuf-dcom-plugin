using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Win32;
using System.Diagnostics;

namespace RegistryManipulatorLib
{
  public class RegistryManipulator
  {
    public static string GetKeyDefaultValue(string keyName)
    {
      object value = Registry.GetValue(keyName, null, null);
      if (value != null)
      {
        return value.ToString();
      }
      return null;
    }

    public static string GetStringValue(string keyName, string valueName)
    {
      object value = Registry.GetValue(keyName, valueName, null);
      if (value != null)
      {
        return value.ToString();
      }
      return null;
    }

    public static bool ExportKey(string keyName, string filePath)
    {
      Process process = new Process();
      process.StartInfo.FileName = "cmd.exe";
      process.StartInfo.Arguments = "/c reg.exe export \"" + keyName + "\" \"" + filePath + "\"";
      process.StartInfo.CreateNoWindow = true;
      process.StartInfo.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
      process.StartInfo.UseShellExecute = false;
      process.Start();
      process.WaitForExit();

      if (process.ExitCode == 0)
      {
        return true;
      }
      return false;
    }

    public static bool ExportKey(string keyName, ref byte[] bytes)
    {
      //output to a temporary file
      string filePath = Environment.GetEnvironmentVariable("TEMP") + "\\ExportKey.tmp";
      bool success = ExportKey(keyName, filePath);
      if (success)
      {
        bytes = System.IO.File.ReadAllBytes(filePath);
        System.IO.File.Delete(filePath);
        return true;
      }
      else
      {
        bytes = null;
        return false;
      }
    }

    private static byte[] _registryHeader;
    public static byte[] GetRegistryFileHeader()
    {
      if (_registryHeader == null)
      {
        var bytesList = new List<byte>();

        bytesList.Add(0xFF);
        bytesList.Add(0xFE);

        string textHeader = "Windows Registry Editor Version 5.00";
        foreach(char c in textHeader)
        {
          bytesList.Add( Convert.ToByte(c) );
          bytesList.Add( 0x00 ); //unicode
        }

        bytesList.Add(0x0D);
        bytesList.Add(0x00);
        bytesList.Add(0x0A);
        bytesList.Add(0x00);

        _registryHeader = bytesList.ToArray();
      }

      return _registryHeader;
    }

    public static void RemoveRegistryFileHeader(ref byte[] bytes)
    {
      byte[] header = GetRegistryFileHeader();
      
      //look for the header in bytes
      bool headerFound = true;
      if (bytes.Length < header.Length)
      {
        headerFound = false; //bytes array cannot contain the header
      }
      for (int i = 0; headerFound && i < header.Length; i++)
      {
        if (header[i] != bytes[i])
          headerFound = false;
      }

      if (headerFound)
      {
        //remove the header from bytes
        var bytesList = bytes.ToList<byte>();
        bytesList.RemoveRange(0, header.Length);
        bytes = bytesList.ToArray();
      }
    }

    public static bool KeyExists(string keyName)
    {
      RegistryKey hive = GetRegistryHive(keyName);
      string path = GetKeyPath(keyName);
      RegistryKey requestKey = hive.OpenSubKey(path);
      if (requestKey != null)
        return true;
      return false;
    }

    public static bool HasClass(string name)
    {
      string classDesc = GetKeyDefaultValue("HKEY_CLASSES_ROOT\\" + name);
      if (classDesc == null)
        return false;
      return !classDesc.Equals(string.Empty);
    }

    public static RegistryKey GetRegistryHive(string keyName)
    {
      if (keyName.Contains(Registry.ClassesRoot.ToString()))
        return Registry.ClassesRoot;
      else if (keyName.Contains(Registry.CurrentConfig.ToString()))
        return Registry.CurrentConfig;
      else if (keyName.Contains(Registry.CurrentUser.ToString()))
        return Registry.CurrentUser;
      else if (keyName.Contains(Registry.LocalMachine.ToString()))
        return Registry.LocalMachine;
      else if (keyName.Contains(Registry.Users.ToString()))
        return Registry.Users;
      else
        return Registry.CurrentUser;
    }

    public static string GetKeyPath(string keyName)
    {
      RegistryKey key = GetRegistryHive(keyName);
      string keyPath = keyName.Replace(key.ToString() + "\\", "");
      return keyPath;
    }

    public static string[] GetSubKeys(string keyName)
    {
      RegistryKey hive = GetRegistryHive(keyName);
      string path = GetKeyPath(keyName);
      RegistryKey requestKey = hive.OpenSubKey(path);
      string[] subKeys = requestKey.GetSubKeyNames();
      return subKeys;
    }

  }
}
