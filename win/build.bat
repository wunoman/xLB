@echo off

cls

@rem make -f win4clang.mak %1

@rem "C:\Program Files\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat"
@rem "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat"
@rem "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
@rem "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

@rem C:\Program Files (x86)\Windows Kits\10\Include\10.0.17763.0\um

@rem INCLUDE=VSDIR\VC\include;C:\Program Files (x86)\Windows Kits\10\Include\10.0.10150.0\ucrt
@rem LIB=VSDIR\VC\lib\amd64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10150.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\x64
@rem PATH=VSDIR\Common7\IDE;VSDIR\VC\bin

@rem "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Auxiliary\Build\vcvars64.bat"

echo -------------------------------------------------------------------------------
echo building bind Windows API to Lua, using XLB library
echo Provide WINVER=0x...., enviroment $(Lua), $(Output), the name SENSITIVE
echo -------------------------------------------------------------------------------
echo.
echo Lua=%Lua%
echo Output=%Output%
echo.
make BIND_DLG=1 BIND_NWM=1 BIND_SHL=1 BIND_COM=1 BIND_MSG=1 BIND_GDI=1 BIND_PROCESS=1 BIND_KM=1 BIND_CTRL=1 BIND_SNMP=1 -f win4clang-dll.mak %*
