Const HKEY_CLASSES_ROOT   = &H80000000
Const HKEY_CURRENT_USER   = &H80000001
Const HKEY_LOCAL_MACHINE  = &H80000002
Const HKEY_USERS          = &H80000003


Function loadTextFile(path)
  Const ForReading = 1
  Const ForWriting = 2
  
  'Read whole file
  Set objFSO = CreateObject("Scripting.FileSystemObject")
  Set objFile = objFSO.OpenTextFile(path, ForReading)
  loadTextFile = objFile.ReadAll
  objFile.Close
  
  'Removed unrequired last CRLF characters
  If Right(loadTextFile, 2) = vbCrLf Then
    strText = Left(loadTextFile, Len(loadTextFile) - 2)
  End If
  
  Set objFile = nothing
  Set objFSO = nothing
End Function

Function saveFile(content, path)
  Const ForReading = 1
  Const ForWriting = 2

  'Write content to file
  Set objFSO = CreateObject("Scripting.FileSystemObject")
  Set objFile = objFSO.CreateTextFile(path, true, false)
  objFile.Write content
  objFile.Close

  Set objFile = nothing
  Set objFSO = nothing

  saveFile = true
End Function

Function replaceInFile(strFile, strOld, strNew)
  Const ForReading = 1
  Const ForWriting = 2

  'Read whole file
  Set objFSO = CreateObject("Scripting.FileSystemObject")
  Set objFile = objFSO.OpenTextFile(strFile, ForReading)
  strText = objFile.ReadAll
  objFile.Close

  ''Removed unrequired last CRLF characters
  'If Right(strText, 2) = vbCrLf Then
  '  strText = Left(strText, Len(strText) - 2)
  'End If 

  'Process with search and replace
  strNewText = Replace(strText, strOld, strNew)

  'Save changes to same file
  Set objFile = objFSO.OpenTextFile(strFile, ForWriting)
  objFile.Write strNewText
  objFile.Close

  Set objFile = nothing
  Set objFSO = nothing
End Function

Function replaceXmlCommentBlock(strText, strTagName)
  'Process with search and replace
  tagStart = "///<" & strTagName & ">"
  tagEnd   = "///</" & strTagName & ">"
  startPos = InStr(strText, tagStart)
  If startPos > 0 Then
    endPos = InStr(startPos, strText, tagEnd)
    If endPos > 0 Then
      'proceed with search and replace
      length = endPos+len(tagEnd)-startPos
      oldText = mid(strText, startPos, length)
      strTmp = Replace(strText, oldText, strTagName)
      strText = strTmp
    End If
  End If
End Function

Function insertString(str, value, offset)
  If offset = 0 Then
      str = value + str
  Else
      str = Left(str, offset) + value + Left(Mid(str, offset), Len(str) - offset + 1)
  End if
End Function

Function isVcxProjFile(content)
  isVcxProjFile = false
  startPos = InStr(content, "<Project")
  If startPos > 0 Then
    startPos = InStr(content, "<ItemGroup")
    If startPos > 0 Then
      startPos = InStr(content, "<ProjectConfiguration")
      If startPos > 0 Then
        isVcxProjFile = true
      End If
    End If
  End If
End Function

Function isVcxProjFilterFile(content)
  isVcxProjFilterFile = false
  startPos = InStr(content, "<Project")
  If startPos > 0 Then
    startPos = InStr(content, "<ItemGroup>")
    If startPos > 0 Then
      startPos = InStr(content, "<Filter")
      If startPos > 0 Then
        isVcxProjFilterFile = true
      End If
    End If
  End If
End Function

Function getFileExtension(path)
  getFileExtension = ""
  lastDotPos = InStrRev(path, ".")
  If lastDotPos <> 0 Then
    getFileExtension = Mid(path, lastDotPos+1, 9999)
  End If
End Function

Function getNameOfFile(path)
  Dim i, iLastSlashPos, iLastDotPos
  iLastSlashPos = InStrRev(path,"\")
  iLastDotPos = InStrRev(path,".")
  If iLastDotPos <= iLastSlashPos Then
    iLastDotPos = Len(path)+1
  End If
  getNameOfFile = Mid(path,iLastSlashPos+1,iLastDotPos-1-iLastSlashPos)
End Function

Function getVsProjectFileType(filename)
  extension = getFileExtension(filename)
  getVsProjectFileType = "None"
  If extension = "h" Then
    getVsProjectFileType = "ClInclude"
  ElseIf extension = "cpp" Then
    getVsProjectFileType = "ClCompile"
  End If
End Function

Function addProjectFile(content, filename, filtername)
  If isVcxProjFile(content) Then
    endProjectPos = InStr(content, "</Project>")
    If endProjectPos > 0 Then
      strInsert = ""
      strInsert = strInsert & "  <ItemGroup>" & vbNewLine
      strInsert = strInsert & "    <" & getVsProjectFileType(filename) & " Include=""" & filename & """ />" & vbNewLine
      strInsert = strInsert & "  </ItemGroup>" & vbNewLine
      insertString content, strInsert, endProjectPos
    End If
  ElseIf isVcxProjFilterFile(content) Then
    endProjectPos = InStr(content, "</Project>")
    If endProjectPos > 0 Then
      strInsert = ""
      strInsert = strInsert & "  <ItemGroup>" & vbNewLine
      strInsert = strInsert & "    <" & getVsProjectFileType(filename) & " Include=""" & filename & """>" & vbNewLine
      strInsert = strInsert & "      <Filter>" & filtername & "</Filter>" & vbNewLine
      strInsert = strInsert & "    </" & getVsProjectFileType(filename) & ">" & vbNewLine
      strInsert = strInsert & "  </ItemGroup>" & vbNewLine
      insertString content, strInsert, endProjectPos
    End If
  End If
End Function

Function removeProjectFile(content, filename)
  tagStartPattern = "    <" & getVsProjectFileType(filename) & " Include=""" & filename & """"
  tagStartPos = InStr(content, tagStartPattern )
  If tagStartPos > 0 Then

    'identify how the tag ends
    hasClosingTag = false
    tagEndPattern = ">"
    tagEndPos = InStr(tagStartPos, content, tagEndPattern)
    If tagStartPos > 0 Then
      previousChar = Mid(content, tagEndPos-1, 1)
      If previousChar = "/" Then
        hasClosingTag = false
      Else
        hasClosingTag = true
      End If
    End If

    'search for end of tag
    If hasClosingTag = false Then
      tagEndPattern = ">" & vbNewLine
      tagEndPos = InStr(tagStartPos, content, tagEndPattern)
    Else
      tagEndPattern = "</" & getVsProjectFileType(filename) & ">" & vbNewLine
      tagEndPos = InStr(tagStartPos, content, tagEndPattern)
    End If
    If tagEndPos > 0 Then
      strOld = Mid(content, tagStartPos, tagEndPos-tagStartPos + Len(tagEndPattern))
      content = Replace(content, strOld, "")
    End If
  End If
End Function

Function AskUserChoice(prompt, options, caption)
  'Build full prompt
  dim fullprompt
  fullprompt = prompt & vbNewLine & vbNewLine
  
  dim i
  for i = 0 to options.Count-1
    fullprompt = fullprompt & "    " & i & ".)  " & options.Item(i) & vbNewLine
  next

  'Loop until user enters a valid number or selects CANCEL
  dim response
  Do
      response = InputBox(fullprompt, caption)
      If response = "" Then WScript.Quit  'Detect Cancel
      If IsNumeric(response) then
        response = cint(response)
        if response >= 0 and response < options.Count Then Exit Do 'Detect value response.
      end if
  Loop

  'return user selection
  AskUserChoice = response
End Function

'https://stackoverflow.com/questions/1233651/how-to-check-for-registry-value-using-vbscript
Function getRegistryValue (strRegistryKey, strDefault )
  Dim WSHShell, value
    
  On Error Resume Next
  Set WSHShell = CreateObject("WScript.Shell")
  value = WSHShell.RegRead( strRegistryKey )
    
  if err.number <> 0 then
    getRegistryValue = strDefault
  else
    getRegistryValue = value
  end if
  On Error Goto 0
    
  set WSHShell = nothing
End Function

Function getRegistryHive(strRegistryKey)
  'set default
  getRegistryHive = HKEY_CURRENT_USER

  'look for the actual string hive in path
  If InStr(1, strRegistryKey, "HKEY_CLASSES_ROOT") Then
    getRegistryHive = HKEY_CLASSES_ROOT
  ElseIf InStr(1, strRegistryKey, "HKEY_CURRENT_USER") Then
    getRegistryHive = HKEY_CURRENT_USER
  ElseIf InStr(1, strRegistryKey, "HKEY_LOCAL_MACHINE") Then
    getRegistryHive = HKEY_LOCAL_MACHINE
  ElseIf InStr(1, strRegistryKey, "HKEY_USERS") Then
    getRegistryHive = HKEY_USERS
  End If
End Function

Function getRegistryHiveName(hiveHandle)
  'set default
  getRegistryHiveName = ""

  If hiveHandle = HKEY_CLASSES_ROOT Then
    getRegistryHiveName = "HKEY_CLASSES_ROOT"
  ElseIf hiveHandle = HKEY_CURRENT_USER Then
    getRegistryHiveName = "HKEY_CURRENT_USER"
  ElseIf hiveHandle = HKEY_LOCAL_MACHINE Then
    getRegistryHiveName = "HKEY_LOCAL_MACHINE"
  ElseIf hiveHandle = HKEY_USERS Then
    getRegistryHiveName = "HKEY_USERS"
  End If
End Function

'https://stackoverflow.com/questions/18098319/iterate-through-registry-subfolders
dim oReg
Set oReg = GetObject("winmgmts://./root/default:StdRegProv")

Function getRegistrySubKeysRecursive(ByRef hiveHandle, ByRef key, ByRef oArraylist, Byref recursive)
  dim hiveName
  hiveName = getRegistryHiveName(hiveHandle)

  'get the name of sub keys
  dim subKeyNames
  oReg.EnumKey hiveHandle, key, subKeyNames

  'for each subkeyname name 
  If Not IsNull(subKeyNames) Then
    For Each subKeyName In subKeyNames
      oArraylist.Add hiveName & "\" & key & "\" & subKeyName

      If recursive Then
        'Recursive call
        getRegistrySubKeysRecursive hiveHandle, key & "\" & subKeyName, oArraylist, recursive
      End If
    Next
  End If
End Function

''Usage:
'  dim subKeys
'  Set subKeys = getRegistrySubKeys("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\App Management", false)
'  If Not IsNull(subKeys) Then
'    For Each subkey In subKeys
'      WScript.Echo subkey
'    Next
'  End If
'  WScript.Echo "done"
'  Set subKeys = getRegistrySubKeys("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\App Management", true)
'  If Not IsNull(subKeys) Then
'    For Each subkey In subKeys
'      WScript.Echo subkey
'    Next
'  End If
'  WScript.Echo "done"
Function getRegistrySubKeys(strRegistryKey, recursive)
  dim hiveHandle
  hiveHandle = getRegistryHive(strRegistryKey)

  dim hiveName
  hiveName = getRegistryHiveName(hiveHandle)
  'WScript.Echo "hiveName=" & hiveName

  'Remove hive name from strRegistryKey
  dim keyPath
  keyPath = strRegistryKey
  keyPath = Replace(keyPath, hiveName & "\", "")
  'WScript.Echo "keyPath=" & keyPath

  'https://stackoverflow.com/questions/13585660/lists-in-vbscript
  Set getRegistrySubKeys = CreateObject("System.Collections.ArrayList")

  getRegistrySubKeysRecursive hiveHandle, keyPath, getRegistrySubKeys, recursive
End Function

Function StringLTrim(ByVal str, char)
  While( Left(str, Len(char)) = char)
    str = Right(str, Len(str)-Len(char))
  Wend
  StringLTrim = str
End Function

Function StringRTrim(ByVal str, char)
  While( Right(str, Len(char)) = char)
    str = Left(str, Len(str)-Len(char))
  Wend
  StringRTrim = str
End Function

Function StringTrim(ByVal str, char)
  StringTrim = StringLTrim(StringRTrim(str, char), char)
End Function

'https://stackoverflow.com/questions/16087470/run-command-line-command-from-vbs
Function runCommand(command)
  const DontWaitUntilFinished = false
  const ShowWindow = 1
  const DontShowWindow = 0
  const WaitUntilFinished = true
  Dim oShell
  Set oShell = WScript.CreateObject ("WScript.Shell")
  oShell.run command, DontShowWindow, WaitUntilFinished
End Function

'
' Capture the results of a command line execution and
' return them to the caller.
'
Function getCommandOutput(theCommand)
  Dim objShell, objCmdExec
  Set objShell = CreateObject("WScript.Shell")
  Set objCmdExec = objshell.exec(thecommand)
  getCommandOutput = objCmdExec.StdOut.ReadAll
End Function

Function RegistryExport(key, filePath)
  dim cmd
  cmd = "cmd.exe /C reg.exe export """ & key & """ """ & filePath & """"
  'MsgBox "cmd=" & cmd, vbOKOnly+vbInformation, DEFAULT_CAPTION
  runCommand cmd
  'MsgBox "filePath=" & filePath, vbOKOnly+vbInformation, DEFAULT_CAPTION
End Function

'https://stackoverflow.com/questions/904739/can-i-pick-up-environment-variables-in-vbscript-wsh-script
Function getEnvironmentVariable(name)
  Dim oShell
  Set oShell = WScript.CreateObject ("WScript.Shell")
  getEnvironmentVariable = oShell.ExpandEnvironmentStrings("%" & name & "%")
End Function

Function fileExists(filePath)
  Set objFSO = CreateObject("Scripting.FileSystemObject")
  fileExists = false
  If objFSO.FileExists(filePath) Then
    fileExists = true
  End if
  Set objFSO = Nothing
End Function

Function deleteFile(filePath)
  Set objFSO = CreateObject("Scripting.FileSystemObject")
  If objFSO.FileExists(filePath) Then
    objFSO.DeleteFile filePath
  End if
  Set objFSO = Nothing
End Function

'https://stackoverflow.com/questions/6060529/read-and-write-binary-file-in-vbscript
Function readBinary(path)
  Dim a
  Dim fso
  Dim file
  Dim i
  Dim ts
  Set fso = CreateObject("Scripting.FileSystemObject")
  Set file = fso.getFile(path)
  If isNull(file) Then
    MsgBox("File not found: " & path)
    Exit Function
  End If
  Set ts = file.OpenAsTextStream()
  a = makeArray(file.size)
  i = 0
  ' Do not replace the following block by readBinary = by ts.readAll(), it would result in broken output, because that method is not intended for binary data 
  While Not ts.atEndOfStream
    a(i) = ts.read(1)
    i = i + 1
  Wend
  ts.close
  readBinary = Join(a,"")
End Function

''https://stackoverflow.com/questions/6060529/read-and-write-binary-file-in-vbscript
''Note: DOES NOT WORK WITH ALL TYPES OF DATA
'Sub writeBinary(bstr, path)
'  Dim fso
'  Dim ts
'  Set fso = CreateObject("Scripting.FileSystemObject")
'  On Error Resume Next
'  Set ts = fso.createTextFile(path)
'  If Err.number <> 0 Then
'    MsgBox(Err.message)
'    Exit Sub
'  End If
'  On Error GoTo 0
'  ts.Write(bstr)
'  ts.Close
'End Sub


'https://www.aspfree.com/c/a/code-examples/binary-file-array-scripting-secrets/
Sub writeBinary(bstr, path)
  Const ForWriting = 2
  Set fso = CreateObject("Scripting.FileSystemObject")
  Set ts = fso.OpenTextFile(path, ForWriting, True)
  For i = 1 to Len(bstr)
    character = Mid(bstr, i, 1)
    asciiCode = Asc(character)
    ts.Write Chr(Clng(asciiCode))
  Next
  ts.Close
End Sub

'https://stackoverflow.com/questions/6060529/read-and-write-binary-file-in-vbscript
Function makeArray(n) ' Small utility function
  Dim s
  s = Space(n)
  makeArray = Split(s," ")
End Function

Function removeRegistryHeader(filePath)
  dim oldBytes
  oldBytes = readBinary(filePath)

  'copy content (remove the first 82 bytes header)
  const HEADER_SIZE = 82
  dim newBytes
  newBytes = MID(oldBytes, HEADER_SIZE+1, Len(oldBytes)-HEADER_SIZE)

  'save as new file
  writeBinary newBytes, filePath

  'MsgBox "Len(oldBytes)=" & Len(oldBytes), vbOKOnly+vbInformation, DEFAULT_CAPTION
  'MsgBox "Len(newBytes)=" & Len(newBytes), vbOKOnly+vbInformation, DEFAULT_CAPTION
End Function

Function removeUnicodeHeader(filePath)
  dim oldBytes
  oldBytes = readBinary(filePath)

  'copy content (remove the 2 bytes header)
  dim newBytes
  newBytes = MID(oldBytes, 3, Len(oldBytes)-2)

  'save as new file
  writeBinary newBytes, filePath

  'MsgBox "Len(oldBytes)=" & Len(oldBytes), vbOKOnly+vbInformation, DEFAULT_CAPTION
  'MsgBox "Len(newBytes)=" & Len(newBytes), vbOKOnly+vbInformation, DEFAULT_CAPTION
End Function

'https://www.aspfree.com/c/a/code-examples/binary-file-array-scripting-secrets/
Sub DeleteArrayElement(ByRef arrArray, intIndex)
  For i = intIndex To UBound(arrArray) - 1
    arrArray(i) = arrArray(i + 1)
  Next
  ReDim Preserve arrArray(UBound(arrArray) - 1)
End Sub

'https://stackoverflow.com/questions/7161739/how-can-i-check-if-a-file-exists
Function fileExists(path)
  fileExists = false
  Set fso = CreateObject("Scripting.FileSystemObject")
  If (fso.FileExists(path)) Then
    fileExists = true
  End If
End Function

Function toUnicodeString(str)
  For i = 1 to Len(str)
    toUnicodeString = toUnicodeString & Mid(str,i,1) & Chr(0)
  Next
End Function
