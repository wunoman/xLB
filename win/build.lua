local MAKEFILE = 'win4clang-dll.mak'

local head = [[
----------------------------------------------------------------------------------------------------
building bind Windows API to Lua, using XLB library
Provide WINVER=0x...., enviroment $(Lua), $(Output), the name SENSITIVE
----------------------------------------------------------------------------------------------------
Lua=$(Lua)
Output=$(Output)
]]

-- make BIND_DLG=1 BIND_NWM=1 BIND_SHL=1 BIND_COM=1 BIND_MSG=1 BIND_GDI=1 BIND_PROCESS=1 BIND_KM=1 BIND_CTRL=1 BIND_SNMP=1 -f win4clang-dll.mak %*
local env = {
  Lua = os.getenv 'Lua',
  Output = os.getenv 'Output'
}

local modules = {
  --[[
  DLG = 1,
  NWM = 1,
  SHL = 1,
  COM = 1,
  GDI = 1,
  KM = 1,
  CTRL = 1,
  SNMP = 1,
  --]]
  BASE = 1,
  MSG = 1,
  PROC = 1,
}

----------------------------------------------------------------------------------------------------
local function main()
  if (not env.Lua or not env.Output) then
    print [[ env Lua and Output expected.]]
    return
  end

  local title = head:gsub('%$%((.-)%)', env)
  print(title)

  local bind_modules = {}
  local defined_macro = {}
  for k, v in pairs(modules) do
    if (v == 1) then
      table.insert(bind_modules, k)
      table.insert(defined_macro, ('BIND_%s=1'):format(k))
    end
  end
  print(('bind modules:\n%s'):format(table.concat(bind_modules, '\n')))

  local command = {
    'make',
    table.concat(defined_macro, ' '),
    'UNICODE=1',
    '-f',
    MAKEFILE,
    --'%*', --TODO: extra argument
  }
  local cmd = table.concat(command, ' ')
  print(cmd)
  os.execute(cmd)
end

----------------------------------------------------------------------------------------------------
main()
