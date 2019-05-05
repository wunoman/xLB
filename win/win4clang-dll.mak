PROJECT      = luawin
TARGET       = $(PROJECT).dll
OBJDIR       = $(Output)\obj
LUADIR       = $(Lua)#env name case sensitive
XLBDIR       = ..\..
#BUILD        = -DDEBUG
#BUILD        = -DNDEBUG
#VERBOSE      = -v
CL           = clang-cl.exe
LINK         = lld-link.exe
LIBS        += lua53.lib
INCLUDES    += -I$(XLBDIR) -I$(LUADIR)
CFLAGS      += /std:c++17
CXXFLAGS    += $(CFLAGS) $(BUILD) $(INCLUDES)
LDFLAGS      = /LIBPATH:"$(LUADIR)" /DLL /SUBSYSTEM:WINDOWS /DEF:$(PROJECT).def

all: $(TARGET)

$(OBJDIR)\$(PROJECT).obj: $(PROJECT).cpp $(PROJECT).h $(XLBDIR)\xlb.h
	@echo [---compile---] $< : $@
	@time /T
	@$(CL) --version
	$(CL) $(CXXFLAGS) -o "$@" -c "$<"
	@time /T

$(TARGET): $(OBJDIR)\$(PROJECT).obj
	@echo [---linking---] $(TARGET)
	@$(LINK) --version
	@time /T
	$(LINK) /out:$(OBJDIR)\$(TARGET) $(OBJDIR)\$(PROJECT).obj $(LDFLAGS) $(LIBS) $(VERBOSE)
	@time /T

clean:
	del $(OBJDIR)\$(PROJECT).lib
	del $(OBJDIR)\$(PROJECT).obj
	del $(OBJDIR)\$(PROJECT).dll
