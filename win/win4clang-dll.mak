PROJECT      = luawin
WINVER      += 0x0601
_WIN32_IE   += 0x0800
TARGET       = $(PROJECT).dll
OBJDIR       = $(Output)\obj
LUADIR       = $(Lua)#env name case sensitive
XLBDIR       = ..\..
BUILD       += /DDEBUG
#BUILD        = /DNDEBUG
#VERBOSE      = -v
CL           = clang-cl.exe
LINK         = lld-link.exe
LIBS        += lua53.lib
INCLUDES    += -I$(XLBDIR) -I$(LUADIR)
CFLAGS      += /std:c++17
CFLAGS      += -ferror-limit=500
CXXFLAGS    += $(CFLAGS) $(BUILD) $(INCLUDES) /DWINVER=$(WINVER) /D_WIN32_IE=$(_WIN32_IE)
LDFLAGS      = /LIBPATH:"$(LUADIR)" /DLL /SUBSYSTEM:WINDOWS /DEF:$(PROJECT).def
SHELL        = cmd.exe

ifeq ($(BIND_GDI), 1)
OBJS        += $(OBJDIR)\luawin_gdi.obj
CXXFLAGS    += -DBIND_GDI
endif

ifeq ($(BIND_DLG), 1)
OBJS        += $(OBJDIR)\luawin_dlg.obj
CXXFLAGS    += -DBIND_DLG
endif

ifeq ($(BIND_NWM), 1)
OBJS        += $(OBJDIR)\luawin_nwm.obj
CXXFLAGS    += -DBIND_NWM
endif

ifeq ($(BIND_SHL), 1)
OBJS        += $(OBJDIR)\luawin_shl.obj
CXXFLAGS    += -DBIND_SHL
endif

ifeq ($(BIND_COM), 1)
OBJS        += $(OBJDIR)\luawin_com.obj
CXXFLAGS    += -DBIND_COM
endif

ifeq ($(BIND_MSG), 1)
OBJS        += $(OBJDIR)\luawin_msg.obj
CXXFLAGS    += -DBIND_MSG
endif

ifeq ($(BIND_PROCESS), 1)
OBJS        += $(OBJDIR)\luawin_process.obj
CXXFLAGS    += -DBIND_PROCESS
endif

ifeq ($(BIND_KM), 1)
OBJS        += $(OBJDIR)\luawin_km.obj
CXXFLAGS    += -DBIND_KM
endif

ifeq ($(BIND_CTRL), 1)
OBJS        += $(OBJDIR)\luawin_ctrl.obj
CXXFLAGS    += -DBIND_CTRL
endif

ifeq ($(BIND_SNMP), 1)
OBJS        += $(OBJDIR)\luawin_snmp.obj
CXXFLAGS    += -DBIND_SNMP
endif



all: $(TARGET)
	@echo.
	@echo [---$(PROJECT)---]
	@echo WINVER=$(WINVER)
	@echo _WIN32_IE=$(_WIN32_IE)

$(OBJDIR)\$(PROJECT).obj: $(PROJECT).cpp $(PROJECT).h $(XLBDIR)\xlb.h
	@echo [---compile---] $< : $@
	@time /T
	@$(CL) --version
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_dlg.obj: luawin_dlg.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_nwm.obj: luawin_nwm.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_shl.obj: luawin_shl.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_com.obj: luawin_com.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_msg.obj: luawin_msg.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_gdi.obj: luawin_gdi.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_process.obj: luawin_process.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_km.obj: luawin_km.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_ctrl.obj: luawin_ctrl.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(OBJDIR)\luawin_snmp.obj: luawin_snmp.cpp $(PROJECT).h
	@echo [---compile---] $< : $@
	@time /T
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T



#mt.exe
#https://docs.microsoft.com/en-us/cpp/build/how-to-embed-a-manifest-inside-a-c-cpp-application?view=vs-2019
#exe resourceid #1; dll resourceid #2

$(TARGET): $(OBJDIR)\$(PROJECT).obj $(OBJS)
	@echo.
	@echo [---linking---] $(TARGET)
	@$(LINK) --version
	@time /T
	$(LINK) /out:$(OBJDIR)\$(TARGET) $(OBJDIR)\$(PROJECT).obj $(OBJS) $(LDFLAGS) $(LIBS) $(VERBOSE)
	@echo [---manifest---]
	@mt.exe -nologo -manifest $(TARGET).manifest -outputresource:$(OBJDIR)\$(TARGET);#2 
	@time /T

clean:
	del $(OBJDIR)\$(PROJECT).lib
	del $(OBJDIR)\$(PROJECT).obj
	del $(OBJDIR)\$(PROJECT).dll
