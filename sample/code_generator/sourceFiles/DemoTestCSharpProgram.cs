using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using LibDemoServer;

namespace DemoTestCSharp
{
  class DemoTestCSharpProgram
  {
    public static bool isPrintable(byte b)
    {
      char c = (char)b;
      if (b == 0x0A || b == 0x0D)
        return false;
      if (!Char.IsControl(c))
        return true;
      if (Char.IsWhiteSpace(c))
        return true;
      return false;
    }

    public static string ByteArrayToString(byte[] bytes)
    {
      var sb = new StringBuilder();
      foreach (var b in bytes)
      {
        if (sb.Length > 0)
          sb.Append(", ");
        if (isPrintable(b))
        {
          char c = (char)b;
          sb.Append("'" + c + "'");
        }
        else
        {
          sb.Append("0x");
          //string hex = BitConverter.ToString(b);
          string hex = b.ToString("X2");
          sb.Append(hex);
        }
      }
      return sb.ToString();
    }

    public static T[] ToSZArray<T>(Array array)
    {
      T[] dest = new T[array.Length];
      Array.Copy(array, dest, array.Length);
      return dest;
    }

    static void TestGetSequentialNumber()
    {
      CoDemoServerClass c = new CoDemoServerClass();

      for (int i = 0; i < 3; i++)
      {
        //build request
        byte[] request = new byte[] { };
        Console.WriteLine("CoDemoServerClass.GetSequentialNumber(" + ByteArrayToString(request) + ");");

        //make call
        object responseObj = c.GetSequentialNumber(request);
        Array responseArray = (Array)responseObj;
        byte[] responseBytes = ToSZArray<byte>(responseArray);

        //print response
        Console.WriteLine("  returns: " + ByteArrayToString(responseBytes));
      }
    }

    static void TestHello()
    {
      //build request
      byte[] request = new byte[] { 0x0A, 0x07, (byte)'A', (byte)'n', (byte)'t', (byte)'o', (byte)'i', (byte)'n', (byte)'e' };
      Console.WriteLine("CoDemoServerClass.Hello(" + ByteArrayToString(request) + ");");

      //make call
      CoDemoServerClass c = new CoDemoServerClass();
      object responseObj = c.Hello(request);
      Array responseArray = (Array)responseObj;
      byte[] responseBytes = ToSZArray<byte>(responseArray);

      //print response
      Console.WriteLine("  returns: " + ByteArrayToString(responseBytes));
    }

    static void Main(string[] args)
    {
      TestGetSequentialNumber();
      TestHello();
    }
  }
}
