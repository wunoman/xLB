
cls

@rem make -f win4clang.mak %1

@rem "C:\Program Files\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat"
@rem "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat"
@rem "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
make -f win4clang-dll.mak %1
