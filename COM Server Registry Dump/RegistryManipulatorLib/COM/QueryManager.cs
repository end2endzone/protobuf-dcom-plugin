using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using RegistryManipulatorLib;

namespace RegistryManipulatorLib
{
  namespace COM
  {
    public class QueryManager
    {
      private static string CleanUpFilePath(string path)
      {
        if (File.Exists(path))
          return path;

        //remove " from path
        path = path.Replace("\"", "");
        if (File.Exists(path))
          return path;

        //remove double \ from path
        path = path.Replace("\\\\", "\\");
        if (File.Exists(path))
          return path;

        //remove last word one by one until the path can be found
        {
          string wordPath = path;
          int spaceIndex = wordPath.LastIndexOf(' ');
          while(spaceIndex >= 1)
          {
            //remove the last word
            wordPath = wordPath.Substring(0, spaceIndex);

            //is this a file ?
            if (File.Exists(wordPath))
              return wordPath;

            //keep looking
            spaceIndex = wordPath.LastIndexOf(' ');
          }
        }

        //unable to clean
        return null;
      }

      public static string GetComponentFilePath(string className)
      {
        string CurVer = GetClassCurVer(className);
        string clsid = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\" + CurVer + "\\CLSID");
        if (clsid == null)
          return null;

        string LocalServer32 = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + clsid + "\\LocalServer32");
        if (LocalServer32 != null)
        {
          if (File.Exists(LocalServer32))
          {
            return LocalServer32;
          }
          else
          {
            //try to clean the path to find the file
            string cleanPath = CleanUpFilePath(LocalServer32);
            if (cleanPath != null)
            {
              return cleanPath;
            }
          }
        }

        string InProcServer32 = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + clsid + "\\InProcServer32");
        if (InProcServer32 != null)
        {
          if (File.Exists(InProcServer32))
          {
            return InProcServer32;
          }
          else
          {
            //try to clean the path to find the file
            string cleanPath = CleanUpFilePath(InProcServer32);
            if (cleanPath != null)
            {
              return cleanPath;
            }
          }
        }

        //try to resolve with typelib
        string typelib = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + clsid + "\\TypeLib");
        if (typelib != null)
        {
          string win32_x86 = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\TypeLib\\" + typelib + "\\1.0\\0\\win32");
          if (win32_x86 != null)
          {
            if (File.Exists(win32_x86))
            {
              return win32_x86;
            }
            else
            {
              //try to clean the path to find the file
              string cleanPath = CleanUpFilePath(win32_x86);
              if (cleanPath != null)
              {
                return cleanPath;
              }
            }
          }

          string win32_x64 = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\TypeLib\\" + typelib + "\\1.0\\0\\win32");
          if (win32_x64 != null)
          {
            if (File.Exists(win32_x64))
            {
              return win32_x64;
            }
            else
            {
              //try to clean the path to find the file
              string cleanPath = CleanUpFilePath(win32_x64);
              if (cleanPath != null)
              {
                return cleanPath;
              }
            }
          }
        }
        //failed resolving with typelib

        //try to resolve with InprocServer32
        string InprocServer32 = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + clsid + "\\InprocServer32");
        if (InprocServer32 != null)
        {
          if (File.Exists(InprocServer32))
          {
            return InprocServer32;
          }
          else
          {
            //try to clean the path to find the file
            string cleanPath = CleanUpFilePath(InprocServer32);
            if (cleanPath != null)
            {
              return cleanPath;
            }
          }
        }


        return null;
      }

      public static AppID GetAppID(string execName)
      {
        AppID result = new AppID();

        result.Guid = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\AppID\\" + execName);
        if (result.Guid == null)
          return null;
        result.Name = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\AppID\\" + result.Guid);
        if (result.Name == null)
          return null;

        //success
        result.ExecName = execName;
        return result;
      }

      public static string GetClassCurVer(string className)
      {
        if (!RegistryManipulator.HasClass(className))
          return null; //not such class

        string CurVer = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\" + className + "\\CurVer");
        if (CurVer == null)
          return className;//className is the last version
        return CurVer;
      }

      public static string GetClassID(string className)
      {
        string guid = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\" + className + "\\CLSID");
        if (guid == null)
          return null;
        return guid;
      }

      public static CLSID GetCLSID(string guid)
      {
        CLSID result = new CLSID();

        result.Guid = guid;
        if (result.Guid == null)
          return null;
        result.Name = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + guid);
        if (result.Name == null)
          return null;
        result.LocalServer32 = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + guid + "\\LocalServer32");
        //if (result.LocalServer32 == null)
        //  return null;
        result.InProcServer32 = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + guid + "\\InProcServer32");
        //if (result.InProcServer32 == null)
        //  return null;
        result.ProgID = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + guid + "\\ProgID");
        if (result.ProgID == null)
          return null;
        result.TypeLib = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + guid + "\\TypeLib");
        if (result.TypeLib == null)
          return null;
        result.VersionIndependentProgID = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + guid + "\\TypeLib");
        if (result.VersionIndependentProgID == null)
          return null;
        result.Version = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + guid + "\\Version");
        //if (result.Version == null)
        //  return null;

        //success
        return result;
      }

      public static TypeLib GetTypeLib(string guid, string version)
      {
        TypeLib result = new TypeLib();

        result.Guid = guid;
        if (result.Guid == null)
          return null;
        result.Name = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\TypeLib\\" + guid + "\\" + version);
        if (result.Name == null)
          return null;
        result.Win32Path = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\TypeLib\\" + guid + "\\" + version + "\\0\\win32");
        if (result.Win32Path == null)
        {
          //sub key under version may be something different than "0".
          string[] subVersions = RegistryManipulator.GetSubKeys("HKEY_CLASSES_ROOT\\Wow6432Node\\TypeLib\\" + guid + "\\" + version);
          if (subVersions.Length == 0)
            return null;
          string firstSubVersion = subVersions[0];
          result.Win32Path = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\TypeLib\\" + guid + "\\" + version + "\\" + firstSubVersion + "\\win32");
          if (result.Win32Path == null)
            return null; //failed
        }
        result.Flags = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\TypeLib\\" + guid + "\\" + version + "\\FLAGS");
        if (result.Flags == null)
          return null;
        result.HelpDir = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\TypeLib\\" + guid + "\\" + version + "\\HELPDIR");
        if (result.HelpDir == null)
          return null;

        //success
        return result;
      }

      public static TypeLib GetTypeLib(string guid)
      {
        return GetTypeLib(guid, "1.0");
      }

      public static TypeLib GetTypeLib(CLSID clsid)
      {
        string version = "1.0";
        if (clsid.Version != null)
        {
          version = clsid.Version;
        }

        return GetTypeLib(clsid.TypeLib, version);
      }

      public static ImplementationInterface GetInterface(string guid)
      {
        ImplementationInterface result = new ImplementationInterface();

        result.Guid = guid;
        if (result.Guid == null)
          return null;
        result.Name = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Interface\\" + guid);
        if (result.Name == null)
          return null;
        result.ProxyStubClsid32 = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Interface\\" + guid + "\\ProxyStubClsid32");
        if (result.ProxyStubClsid32 == null)
          return null;
        result.TypeLib = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Interface\\" + guid + "\\TypeLib");
        if (result.TypeLib == null)
          return null;
        result.TypeLibVersion = RegistryManipulator.GetStringValue("HKEY_CLASSES_ROOT\\Interface\\" + guid + "\\TypeLib", "Version");
        if (result.TypeLibVersion == null)
          return null;

        //success
        return result;
      }

      public static string[] GetTypeLibInterfaces(string guid)
      {
        var typelibInterfaces = new List<string>();
        
        //get all interfaces of the system
        string[] interfaces = RegistryManipulator.GetSubKeys("HKEY_CLASSES_ROOT\\Interface");

        //for each interfaces
        foreach(string interfaceGuid in interfaces)
        {
          string interfaceTypeLib = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Interface\\" + interfaceGuid + "\\TypeLib");
          if (guid.Equals(interfaceTypeLib))
          {
            typelibInterfaces.Add(interfaceGuid);
          }
        }

        return typelibInterfaces.ToArray();
      }

      public static bool ExportComponentRegistry(string className, string filePath)
      {
        byte[] bytes = null;

        if (!RegistryManipulator.HasClass(className))
        {
          return false;
        }

        // className
        RegistryManipulator.ExportKey("HKEY_CLASSES_ROOT\\" + className, ref bytes);

        // CurVer
        string CurVer = GetClassCurVer(className);
        AppendComponentRegistry("HKEY_CLASSES_ROOT\\" + CurVer, ref bytes);

        // AppID
        string componentFilePath = QueryManager.GetComponentFilePath(className);
        if (componentFilePath != null)
        {
          string execFilename = Path.GetFileName(componentFilePath);
          string appid = RegistryManipulator.GetStringValue("HKEY_CLASSES_ROOT\\AppID\\" + execFilename, "AppID");
          if (appid != null)
          {
            AppendComponentRegistry("HKEY_CLASSES_ROOT\\AppID\\" + execFilename, ref bytes);
            AppendComponentRegistry("HKEY_CLASSES_ROOT\\AppID\\" + appid, ref bytes);
            AppendComponentRegistry("HKEY_CLASSES_ROOT\\Wow6432Node\\AppID\\" + execFilename, ref bytes);
            AppendComponentRegistry("HKEY_CLASSES_ROOT\\Wow6432Node\\AppID\\" + appid, ref bytes);
          }
        }

        // CLSID
        string CurVerCLSID = GetClassID(CurVer);
        AppendComponentRegistry("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + CurVerCLSID, ref bytes);

        // TypeLib
        string typelib = RegistryManipulator.GetKeyDefaultValue("HKEY_CLASSES_ROOT\\Wow6432Node\\CLSID\\" + CurVerCLSID + "\\TypeLib");
        if (typelib != null)
        {
          AppendComponentRegistry("HKEY_CLASSES_ROOT\\TypeLib\\" + typelib, ref bytes);
          AppendComponentRegistry("HKEY_CLASSES_ROOT\\Wow6432Node\\TypeLib\\" + typelib, ref bytes);

          // interface
          string[] interfaces = GetTypeLibInterfaces(typelib);
          foreach (string interfaceGuid in interfaces)
          {
            AppendComponentRegistry("HKEY_CLASSES_ROOT\\Interface\\" + interfaceGuid, ref bytes);
          }
        }

        //write to output file
        File.WriteAllBytes(filePath, bytes);

        return true;
      }

      private static bool AppendComponentRegistry(string keyName, ref byte[] bytes)
      {
        //verify if key exists
        if (!RegistryManipulator.KeyExists(keyName))
          return false;

        //get registry content of the key
        byte[] tmpBytes = null;
        RegistryManipulator.ExportKey(keyName, ref tmpBytes);
        if (tmpBytes == null)
          return false;

        //remove the header
        RegistryManipulator.RemoveRegistryFileHeader(ref tmpBytes);

        //append to existing content
        var newContent = new byte[bytes.Length + tmpBytes.Length];
        bytes.CopyTo(newContent, 0);
        tmpBytes.CopyTo(newContent, bytes.Length);

        //assigned the new array
        bytes = newContent;
        return true;
      }
    }
  }
}
