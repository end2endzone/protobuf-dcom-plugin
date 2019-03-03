@echo off

REM ========================================
REM   Configure Google Protocol Buffers...
REM ========================================
REM set PROTOBUF_BIN_DIR=...
REM set PROTOBUF_INCLUDE_DIR=...
REM set PROTOBUF_LIB_DIR=...
REM set PROTOBUF_DEBUG_LIBRARIES=...
REM set PROTOBUF_RELEASE_LIBRARIES=...

REM ============================
REM   Configure Google Test...
REM ============================
REM set GTEST_INCLUDE=...
REM set GTEST_LIBRARY_DIR=...
REM GTEST_DEBUG_LIBRARIES=...
REM GTEST_RELEASE_LIBRARIES=...

set PATH=%PROTOBUF_BIN_DIR%;%PATH%

::Open all solution in the project
for %%f in (*.sln) do (
  start "" "%%f"
)