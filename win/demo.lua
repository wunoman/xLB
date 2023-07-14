-- demo for bind Windows API to Lua (0.0.1)
package.cpath = os.getenv('Output') .. [[\luawin\obj\?.dll]]
-- print(package.cpath)
require 'luawin'
local luawin = _ENV.luawin
----------------------------------------------------------------------------------------------------
print('---VERSION:' .. luawin.VERSION)
print('---WINVER:' .. string.format('0x%04x', luawin.WINVER))
print('---UNICODE:' .. string.format('0x%04x', luawin.UNICODE))
----------------------------------------------------------------------------------------------------
if (luawin.CHECK_BIND_BASE) then
  print('---BIND_BASE')
  luawin.load_base()
end
if (luawin.CHECK_BIND_DLG) then
  print('---BIND_DLG')
  luawin.load_dlg()
end
if (luawin.CHECK_BIND_MSG) then
  print('---BIND_MSG')
  luawin.load_msg()
end
if (luawin.CHECK_BIND_PROC) then
  print('---BIND_PROC')
  luawin.load_proc()
end
if (luawin.CHECK_BIND_SNMP) then
  print('---BIND_SNMP')
  luawin.load_snmp()
end
if (luawin.CHECK_BIND_KM) then
  print('---BIND_KM')
  luawin.load_km()
end
if (luawin.CHECK_BIND_CTRL) then
  print('---BIND_CTRL')
  luawin.load_ctrl()
end
if (luawin.CHECK_BIND_NWM) then
  print('---BIND_NWM')
  luawin.load_nwm()
end
if (luawin.CHECK_BIND_SHL) then
  print('---BIND_SHL')
  luawin.load_shl()
end
if (luawin.CHECK_BIND_COM) then
  print('---BIND_COM')
  luawin.load_com()
end

----------------------------------------------------------------------------------------------------
local function T(a) return (luawin.UNICODE) and luawin.a2w(a) or a end

local function A(a) return (luawin.UNICODE) and luawin.cstr(luawin.w2a(a)) or a end
----------------------------------------------------------------------------------------------------
local function write(left, right) print(string.format('%32s : %s', left, right)) end

----------------------------------------------------------------------------------------------------
local function printtable(t)
  for k, v in pairs(t) do print(string.format('%32s : %s', k, v)) end
end

local function printmetatable(ud)
  local mt = getmetatable(ud)
  print('metatable={')
  printtable(mt)
  print('}\n')
end

----------------------------------------------------------------------------------------------------
-- print('---luawin.GetCurrentDirectory='..tostring(luawin.GetCurrentDirectory))

-- print('W.CallWndProc='..tostring(luawin.CallWndProc))
-- local CallWndProc = luawin.CallWndProc(function() return 0; end)
-- print('W.CallWndProc='..tostring(CallWndProc))
-- print('W.CallWndProc='..luawin.type(CallWndProc))

-- local len = 1024
-- local s = string.rep('\0', len)
-- local d = luawin.GetCurrentDirectory(len, s)
-- print('W.GetCurrentDirectory=' .. string.sub(s,1,d))

----------------------------------------------------------------------------------------------------
local function TerminateProcess(pid)
  local hProcess = luawin.OpenProcess(luawin.PROCESS_TERMINATE, false, pid)
  return luawin.TerminateProcess(hProcess, 0)
end

----------------------------------------------------------------------------------------------------
local function EnumWindows()
  print '---> EnumWindows'
  local len = 1024
  local childbuff = string.rep('\0', len)
  local classbuff = string.rep('\0', 1024)

  local childproc = function(hwnd, lParam)
    local len = luawin.GetWindowText(hwnd, childbuff, len)
    if (luawin.UNICODE) then len = 2 * len end
    -- local winText = string.sub(childbuff, 1, len)
    local winText = A(childbuff)
    if (luawin.IsWindow(hwnd) ~= 0) then
      local c = {}
      local nlen = luawin.GetClassName(hwnd, classbuff, 260)
      if (nlen > 0) then
        c.classname = A(classbuff)
      end
      if (winText == '取消') then
        c.target = 'yes'
      end
      if (len ~= 0) then
        c.text = winText
      end
      local s = ([[
{
  classname='$(classname)',
  target='$(target)'
  text='$(text)'
}]]):gsub('%$%((.-)%)', function(s) return c[s] or '' end)
      print(s)
    end
  end

  local cbchildwindow = luawin.EnumWindowsProc(childproc)

  local buff = string.rep('\0', len)
  local count = 0
  local found = {}
  local proc = function(hwnd, lParam)
    local keepgoing = true
    local len = luawin.GetWindowText(hwnd, buff, len)
    if (luawin.UNICODE) then len = 2 * len end
    local winText = string.sub(buff, 1, len)
    winText = A(winText)
    -- if (winText == 'Default IME') then
    -- if (winText == '确定') then -- GB2312 calc 计算器
    --   local ppid = luawin.malloc(4)
    --   local tid = luawin.GetWindowThreadProcessId(hwnd, ppid)
    --   print(('---> %s, %s, %s'):format(winText, luawin.type(ppid), tostring(lParam)))
    --   local pid = luawin.pvtointeger(ppid, 4)
    --   print(('---> pid=%s'):format(tostring(pid)))
    --   TerminateProcess(pid)
    --   luawin.free(ppid)
    --   count = count + 1
    --   print(('---> terminate process count=%d'):format(count))
    -- else

    if (winText == '记事本') then
      table.insert(found, hwnd)
      keepgoing = false
    end

    -- if (luawin.IsWindow(hwnd) and len > 0) then
    --   table.insert(found, hwnd)
    -- end

    -- if (len ~= 0) then
    --   print(winText)
    -- end
    -- hwnd = luawin.GetWindow(hwnd, luawin.GW_CHILD)
    -- if (hwnd) then
    --   luawin.EnumChildWindows(hwnd, cbchildwindow, 31415)
    -- end
    -- end
    return keepgoing -- continue find next window -- return false; -- stop the enumerate
  end

  local cbwindow = luawin.EnumWindowsProc(proc)
  luawin.EnumWindows(cbwindow, 1024)
  for k, hwnd in pairs(found) do
    print('\n', k, hwnd)
    -- luawin.EnumChildWindows(hwnd, cbchildwindow, 31415)
    local h = luawin.GetProcessHandleFromHwnd(hwnd)
    print(h:__lightuserdata())
    if (h) then
      print(luawin.GetProcessId(h))
    end
    break
  end

  -- local hwnd = luawin.FindWindow(T'Button', T'取消')
  -- print(hwnd, luawin.type(hwnd), hwnd:__lightuserdata())
  -- print(luawin.IsWindow(hwnd))
end

----------------------------------------------------------------------------------------------------
local function CloseProcess()
  print '---> CloseProcess'
  local hSnapshot = luawin.CreateToolhelp32Snapshot(luawin.TH32CS_SNAPPROCESS, 0)
  -- print(hSnapshot, luawin.INVALID_HANDLE_VALUE)
  if (luawin.INVALID_HANDLE_VALUE ~= hSnapshot) then
    local pe = luawin.PROCESSENTRY32()
    print(('---> pe=%s'):format(luawin.type(pe)))
    pe.dwSize = luawin.PROCESSENTRY32.typesize
    -- local proc_name = 'notepad.exe'
    local proc_name = 'lua.exe'
    local processIDs = {}
    print(string.rep('-', 80))
    local fOk = luawin.Process32First(hSnapshot, pe)
    while (fOk ~= 0) do
      local exefile = A(pe.szExeFile.tostring)
      print(exefile, pe.th32ProcessID)
      if (exefile == proc_name) then
        table.insert(processIDs, pe.th32ProcessID)
      end
      fOk = luawin.Process32Next(hSnapshot, pe)
    end
    for k, v in pairs(processIDs) do
      print(('found [%d]=%d'):format(k, v))
    end
  end
end

----------------------------------------------------------------------------------------------------
local function SNMP()
  print('luawin.SNMPAPI_CALLBACK=' .. tostring(luawin.SNMPAPI_CALLBACK))
  for k, v in pairs(luawin.SNMPAPI_CALLBACK) do print(k, v); end
end

----------------------------------------------------------------------------------------------------
local function Dialog()
  local title = T 'luawin'
  print(title, type(title), string.len(title))
  local txt = T 'ok?'
  print(txt, type(txt), string.len(txt))
  local r = luawin.MessageBox(nil, txt, title,
    luawin.MB_OKCANCEL | luawin.MB_ICONQUESTION)
  print((r == luawin.IDOK) and 'OK' or 'NO')
end

----------------------------------------------------------------------------------------------------
local function Malloc()
  print('---sizeof PRINTPAGERANGE=' .. luawin.PRINTPAGERANGE.typesize)
  local place = luawin.malloc(luawin.PRINTPAGERANGE.typesize)
  print('---place=' .. luawin.type(place))
  local obj = luawin.PRINTPAGERANGE:newin(place)
  obj.nFromPage = 1
  obj.nToPage = 2
  print('---PRINTPAGERANGE.nFromPage=' .. obj.nFromPage)
  print('---PRINTPAGERANGE.nToPage=' .. obj.nToPage)
  print('---PRINTPAGERANGE=' .. luawin.type(obj))
  obj = nil
  collectgarbage()
  print('--')
  luawin.free(place)
end

local function guid2str(g)
  local d4 = g.Data4
  local s = string.format(
    "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", g.Data1,
    g.Data2, g.Data3, d4[1], d4[2], d4[3], d4[4], d4[5], d4[6],
    d4[7], d4[8])
  return s
end

local function COM()
  local IAccessControl = luawin.IAccessControl
  write('sizeof(IAccessControl)', IAccessControl.typesize)
  write('IAccessControl.QueryInterface',
    tostring(IAccessControl.QueryInterface))
  write('IAccessControl.IID', tostring(IAccessControl.IID))
  write('IAccessControl.IID', luawin.type(IAccessControl.IID))
  write('IAccessControl.IID', guid2str(IAccessControl.IID))
  write('IAccessControl.CLSID', guid2str(IAccessControl.CLSID))
  printmetatable(IAccessControl)
end

----------------------------------------------------------------------------------------------------
local function printBinded()
  local count = 0
  for k, v in pairs(luawin) do
    print(string.format('%48s : %s', k, tostring(v)))
    count = count + 1
  end
  print(('---> binded count=%d'):format(count))
end

----------------------------------------------------------------------------------------------------
local function printGUID()
  local guid = luawin['FOLDERID_AdminTools']
  print(string.format('%32s : %s', 'GUID', tostring(luawin['GUID'])))
  print(string.format('%32s : %s', 'FOLDERID_AdminTools', tostring(guid)))
  printmetatable(guid)

  print(string.rep('-', 97))
  if (guid.__getref) then
    local dr = guid:__getref()
    print(string.format('%32s : %s', '__getref', tostring(dr)))
    print(dr)
    local mt = getmetatable(dr)
    for k, v in pairs(mt) do print(k, v) end
  end

  print(string.rep('-', 97))
  local len = 38 * 2; -- LPOLESTR
  local lpsz = string.rep('\0', len)
  local n = luawin['StringFromGUID2'](guid, lpsz, len)
  write('guid', lpsz)
  write('n', n)

  print(string.rep('-', 97))
  print('guid=' .. guid2str(guid))

  local g2 = luawin.GUID()
  local d4 = g2.Data4
  g2.Data1 = 0x12345678
  -- g2.Data4 = { 0x12, 0x34, 0x56, 0x78, 0x90, 0x01, 0x23, 0x34}
  for k, v in pairs { 0x12, 0x34, 0x56, 0x78, 0x90, 0x01, 0x23, 0x34 } do
    d4[k] = v
  end
  print('guid={' .. guid2str(g2) .. '}')
  -- g2.Data4 = { [3] = 0xff, [5] = 0xdd }
  -- g2.Data4 = { [4] = 0xee }
  d4[3] = 0xff;
  d4[4] = 0xee;
  d4[5] = 0xdd
  print('guid={' .. guid2str(g2) .. '}')
end

----------------------------------------------------------------------------------------------------
EnumWindows()
-- CloseProcess()
--
-- RAS()
-- SNMP()
-- Dialog()
-- Malloc()
-- printBinded()
-- printGUID()
-- COM()

print '---Done.'
