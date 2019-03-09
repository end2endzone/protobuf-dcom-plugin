option explicit

'Test binary read & write functions
dim tmpBuffer1
tmpBuffer1 = ReadByteArrayFromBinaryFile("DemoTest.Antoine.HelloRequest.bin")
PrintObjectInfo "tmpBuffer1", tmpBuffer1
WriteArrayToBinaryFile tmpBuffer1,   "DemoTest.Antoine.HelloRequest.copy1.bin"
WScript.Echo ""

dim tmpBuffer2
tmpBuffer2 = BuildHelloRequestMessage()
PrintObjectInfo "tmpBuffer2", tmpBuffer2
WriteArrayToBinaryFile tmpBuffer2,   "DemoTest.Antoine.HelloRequest.copy2.bin"
WScript.Echo ""





Dim DemoServer
Set DemoServer = CreateObject("DemoServer.object")
PrintObjectInfo "DemoServer", DemoServer
WScript.Echo ""

'=============================================
'Test DemoServer with an array of bytes...
'=============================================

Dim SerializedHelloRequest
SerializedHelloRequest = ReadByteArrayFromBinaryFile("DemoTest.Antoine.HelloRequest.bin")
PrintObjectInfo "SerializedHelloRequest", SerializedHelloRequest
WScript.Echo ""

Dim SerializedHelloResponse
SerializedHelloResponse = DemoServer.Hello(SerializedHelloRequest)
PrintObjectInfo "SerializedHelloResponse", SerializedHelloResponse
WScript.Echo ""

WriteArrayToBinaryFile SerializedHelloResponse, "DemoTest.Antoine.HelloResponse.actual.bin"

'=============================================
'Test DemoServer with an array of bytes...
'=============================================

SerializedHelloRequest = BuildHelloRequestMessage()
PrintObjectInfo "SerializedHelloRequest", SerializedHelloRequest
WScript.Echo ""

SerializedHelloResponse = DemoServer.Hello(SerializedHelloRequest)
PrintObjectInfo "SerializedHelloResponse", SerializedHelloResponse
WScript.Echo ""

WriteArrayToBinaryFile SerializedHelloResponse, "DemoTest.Etienne.HelloResponse.actual.bin"

'done testing

Set DemoServer = Nothing

WScript.Quit







'==============================================================================================================================
'                                                         Functions
'==============================================================================================================================



'Builds a VBScript array of bytes representing a serialized HelloRequest message
'  .TypeName=Variant()
'  .VarType=vbArray with vbVariant elements (vbByte)
'  For C++, the return type is VT_BYREF | VT_VARIANT which contains a SAFEARRAY
Function BuildHelloRequestMessage()
  Dim arr(8) 'Array of 9 elements
  arr(0) = CByte(&h0A) 'asc 10
  arr(1) = CByte(&h07) 'asc 07
  arr(2) = CByte(Asc("E"))
  arr(3) = CByte(Asc("t"))
  arr(4) = CByte(Asc("i"))
  arr(5) = CByte(Asc("e"))
  arr(6) = CByte(Asc("n"))
  arr(7) = CByte(Asc("n"))
  arr(8) = CByte(Asc("e"))
  BuildHelloRequestMessage = arr
End Function


'http://www.motobit.com/tips/detpg_read-write-binary-files/
'Writes to a binary file an array of the following type:
'  TypeName()=Byte()
'  VarType() =vbArray with vbByte elements
' to a binary file
'Fails when ByteArray is the following type:
'  TypeName=Variant()
'  VarType =vbArray with vbVariant elements (vbByte)
'  Error   = ADODB.Stream: Arguments are of the wrong type, are out of acceptable range, or are in conflict with one another.
Function WriteByteArrayToBinaryFile(ByteArray, sSavePath)
     Const adTypeBinary = 1
     Const adSaveCreateOverWrite = 2
     'If LenB(ByteArray) = 0 Then Exit Sub

     Dim oStream
     Set oStream = CreateObject("ADODB.Stream")
     With oStream
         .Type = adTypeBinary
         .Open
         .Write(ByteArray)
         .SaveToFile sSavePath, adSaveCreateOverWrite
         .Close
     End With
     Set oStream = Nothing
End Function



'http://www.motobit.com/tips/detpg_read-write-binary-files/
'Returns an object of the following type:
'  TypeName()=Byte()
'  VarType() =vbArray with vbByte elements
'WARNING: VBScript only supports the VARIANT data type.
'         The returned object is only viable when calling a COM method.
'         Other VBScript methods will fail: 
'             IsArray(object) returns true
'             However, object(x) will fail.
Function ReadByteArrayFromBinaryFile(FileName)
  Const adTypeBinary = 1
  
  'Create Stream object
  Dim BinaryStream
  Set BinaryStream = CreateObject("ADODB.Stream")
  
  'Specify stream type - we want To get binary data.
  BinaryStream.Type = adTypeBinary
  
  'Open the stream
  BinaryStream.Open
  
  'Load the file data from disk To stream object
  BinaryStream.LoadFromFile FileName
  
  'Open the stream And get binary data from the object
  ReadByteArrayFromBinaryFile = BinaryStream.Read
End Function


'Writes to a binary file an array of the following type:
'  TypeName()=Variant()
'  VarType() =vbArray with vbVariant elements (vbByte)
' to a binary file
'Fails when VariantArray is the following type:
'  TypeName=Byte()
'  VarType =vbArray with vbByte elements
'  Error   = Microsoft VBScript runtime error: Type mismatch: 'VariantArray'
Function WriteVariantArrayToBinaryFile(VariantArray, sSavePath)
    Dim oFSO: Set oFSO = CreateObject("Scripting.FileSystemObject")

    ' below lines pupose: checks that write access is possible!
    Dim oTxtStream: Set oTxtStream = oFSO.createTextFile(sSavePath)
    On Error Resume Next
    If Err.number <> 0 Then MsgBox(Err.message) : Exit Function
    On Error GoTo 0
    ' end check of write access

    Dim i
    For i = LBound(VariantArray) To UBound(VariantArray)
      oTxtStream.write Chr(VariantArray(i))
    Next
    oTxtStream.Close

    Set oTxtStream = Nothing

End Function

Function GetVarTypeStringEx(vType)
  Select Case vType   
    Case 0    GetVarTypeStringEx = "vbEmpty"
    Case 1    GetVarTypeStringEx = "vbNull"
    Case 2    GetVarTypeStringEx = "vbInteger"
    Case 3    GetVarTypeStringEx = "vbLong"
    Case 4    GetVarTypeStringEx = "vbSingle"
    Case 5    GetVarTypeStringEx = "vbDouble"
    Case 6    GetVarTypeStringEx = "vbCurrency"
    Case 7    GetVarTypeStringEx = "vbDate"
    Case 8    GetVarTypeStringEx = "vbString"
    Case 9    GetVarTypeStringEx = "vbObject"
    Case 10   GetVarTypeStringEx = "vbError"
    Case 11   GetVarTypeStringEx = "vbBoolean"
    Case 12   GetVarTypeStringEx = "vbVariant"
    Case 13   GetVarTypeStringEx = "vbDataObject"
    Case 14   GetVarTypeStringEx = "vbDecimal"
    Case 17   GetVarTypeStringEx = "vbByte"
    Case Else GetVarTypeStringEx = "unknown"
  End Select
End Function

Function GetVarTypeString(x)
  'Const vbArray = 8192
  Dim y
  y = VarType(x)
  If y < vbArray Then
    GetVarTypeString = GetVarTypeStringEx(VarType(x))
  Else
    Dim elementVarType
    elementVarType = VarType(x)- vbArray
    Dim firstElementDetails
    If elementVarType <> vbVariant Then
      GetVarTypeString = "vbArray with " & GetVarTypeStringEx(elementVarType) & " elements"
    Else
      Dim firstElement
      firstElement = x(LBound(x))
      GetVarTypeString = "vbArray with " & GetVarTypeStringEx(elementVarType) & " elements (" & GetVarTypeString(firstElement) & ")"
    End If
  End If  
End Function

Function IsArrayOfVariant(object)
  IsArrayOfVariant = false
  If IsArray(object) Then
    Dim vType
    vType = VarType(object)
    vType = vType - vbArray
    If vType = vbVariant Then
      IsArrayOfVariant  = true
    End If
  End If
End Function

'Writes to a binary file the given array.
Function WriteArrayToBinaryFile(theArray, sSavePath)
  If IsArrayOfVariant(theArray) Then
    WriteVariantArrayToBinaryFile theArray, sSavePath
  Else
    WriteByteArrayToBinaryFile theArray, sSavePath
  End If
End Function

Sub PrintObjectInfo(name, object)
  WScript.Echo name & ".TypeName=" & TypeName(object)
  WScript.Echo name & ".VarType=" & GetVarTypeString(object)

  If IsArray(object) Then
    WScript.Echo name & ".Array.LBound=" & LBound(object)
    WScript.Echo name & ".Array.UBound=" & UBound(object)
    If IsArrayOfVariant(object) Then
      dim i
      For i = LBound(object) To UBound(object)
        WScript.Echo name & ".Array(" & i & "): .TypeName=" & TypeName(object(i)) & " .Value=" & object(i)
      Next
    End If
  End If
End Sub
