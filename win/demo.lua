-- demo for bind Windows API to Lua (0.0.1)
package.cpath = os.getenv('Output')..[[\obj\?.dll]];
--print(package.cpath);
require 'luawin'
--------------------------------------------------------------------------------------------------
print('---VERSION:'..luawin.VERSION);
print('---WINVER:'..string.format('0x%04x', luawin.WINVER));
--------------------------------------------------------------------------------------------------
luawin.load_base();
luawin.load_dialog();
luawin.load_msg();
luawin.load_process();
luawin.load_snmp();
luawin.load_km();
luawin.load_ctrl();
luawin.load_nwm();
luawin.load_shl();
luawin.load_com();
--------------------------------------------------------------------------------------------------
function write(left,right)
    print(string.format('%32s : %s', left, right));
end

--------------------------------------------------------------------------------------------------
function printtable(t)
    for k,v in pairs(t) do
        print(string.format('%32s : %s', k, v))
    end
end
function printmetatable(ud)
    local mt = getmetatable(ud)
    print('metatable={')
    printtalbe(mt)
    print('}\n')
end

--------------------------------------------------------------------------------------------------
--print('---luawin.GetCurrentDirectory='..tostring(luawin.GetCurrentDirectory));

--print('W.CallWndProc='..tostring(luawin.CallWndProc));
--local CallWndProc = luawin.CallWndProc(function() return 0; end);
--print('W.CallWndProc='..tostring(CallWndProc));
--print('W.CallWndProc='..luawin.xlb_type(CallWndProc));


--local len = 1024;
--local s = string.rep('\0', len);
--local d = luawin.GetCurrentDirectory(len, s);
--print('W.GetCurrentDirectory=' .. string.sub(s,1,d));

--------------------------------------------------------------------------------------------------
function TerminateProcess(pid)
    local hProcess = luawin.OpenProcess(luawin.PROCESS_TERMINATE, false, pid);
    print(hProcess);
    print(luawin.TerminateProcess(hProcess, 0));
end

--------------------------------------------------------------------------------------------------
function EnumWindows()
    local len = 1024;
    local buff = string.rep('\0', len);
    local count = 0;

    local proc = function(hwnd, lParam) 
        local len = luawin.GetWindowText(hwnd, buff, len);
        local winText = string.sub(buff, 1, len)
        --if (winText == 'Default IME') then
        if (winText == '¼ÆËãÆ÷') then
            local ppid = luawin.malloc(4)
            local tid = luawin.GetWindowThreadProcessId(hwnd, ppid);
            print('--->' .. winText .. ',' .. luawin.xlb_type(ppid) .. ',' .. tostring(lParam));
            local pid = luawin.pvtointeger(ppid, 4);
            print("pid=" .. tostring(pid));
            TerminateProcess(pid)
            luawin.free(ppid);
            count = count+1;
            print('--->count=' .. count);
            print();
        end
        --return false; -- stop
        return true; -- continue
    end
    local callback = luawin.EnumWindowsProc(proc);
    luawin.EnumWindows(callback, 999);
    
end

--------------------------------------------------------------------------------------------------
function SNMP()
    print('luawin.SNMPAPI_CALLBACK='..tostring(luawin.SNMPAPI_CALLBACK));
    for k,v in pairs(luawin.SNMPAPI_CALLBACK) do print(k,v); end
end

--------------------------------------------------------------------------------------------------
function Dialog()
    local r = luawin.MessageBox(nil, 'ok?', 'luawin', luawin.MB_OKCANCEL | luawin.MB_ICONQUESTION);
    local choice = (r == luawin.IDOK) and 'OK' or 'NO'
    print(choice)
    --print(r);
end

--------------------------------------------------------------------------------------------------
function Malloc()
    print('---sizeof PRINTPAGERANGE=' .. luawin.PRINTPAGERANGE.typesize); 
    local place = luawin.malloc(luawin.PRINTPAGERANGE.typesize);
    print('---place=' .. luawin.xlb_type(place));
    local obj = luawin.PRINTPAGERANGE:newin(place);
    obj.nFromPage = 1;
    obj.nToPage = 2;
    print('---PRINTPAGERANGE.nFromPage=' .. obj.nFromPage);
    print('---PRINTPAGERANGE.nToPage=' .. obj.nToPage);
    print('---PRINTPAGERANGE=' .. luawin.xlb_type(obj));
    obj = nil;
    collectgarbage();
    print('--');
    luawin.free(place);
end

function guid2str(g)
    local d4 = g.Data4;
    local s = string.format("{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
    g.Data1,
    g.Data2,
    g.Data3,
    d4[1], d4[2],
    d4[3], d4[4], d4[5], d4[6], d4[7], d4[8]
    )
    return s;
end

function COM()
    local IAccessControl = luawin.IAccessControl;
    write('sizeof(IAccessControl)', IAccessControl.typesize); 
    write('IAccessControl.QueryInterface', tostring(IAccessControl.QueryInterface));
    write('IAccessControl.IID', tostring(IAccessControl.IID));
    write('IAccessControl.IID', luawin.xlb_type(IAccessControl.IID));
    write('IAccessControl.IID', guid2str(IAccessControl.IID));
    write('IAccessControl.CLSID', guid2str(IAccessControl.CLSID));
    printmetatable(IAccessControl);
end

--------------------------------------------------------------------------------------------------
function printBinded(luawin)
    local count = 0;
    for k,v in pairs(luawin) do
        print(string.format('%32s : %s', k, tostring(v)));
        count = count + 1;
    end
    print(string.format('%32s : %s', '---count', count));
end

--------------------------------------------------------------------------------------------------
function printGUID(luawin)
    local guid = luawin['FOLDERID_AdminTools']
    print(string.format('%32s : %s', 'GUID', tostring(luawin['GUID'])));
    print(string.format('%32s : %s', 'FOLDERID_AdminTools', tostring(guid)));
    printmetatable(guid);

    print(string.rep('-',97));
    if (guid.__getref) then
        local dr = guid:__getref();
        print(string.format('%32s : %s', '__getref', tostring(dr)));
        print(dr);
        local mt = getmetatable(dr)
        for k,v in pairs(mt) do print(k,v) end
    end

    print(string.rep('-',97));
    local len = 38*2; -- LPOLESTR
    local lpsz = string.rep('\0', len);
    local n = luawin['StringFromGUID2'](guid, lpsz, len);
    write('guid', lpsz);
    write('n', n);

    print(string.rep('-',97));
    print('guid='..guid2str(guid));
    
    local g2 = luawin.GUID();
    local d4 = g2.Data4;
    g2.Data1 = 0x12345678;
    --g2.Data4 = { 0x12, 0x34, 0x56, 0x78, 0x90, 0x01, 0x23, 0x34};
    for k,v in pairs{ 0x12, 0x34, 0x56, 0x78, 0x90, 0x01, 0x23, 0x34} do
        d4[k]=v;
    end
    print('guid={'..guid2str(g2)..'}');
    --g2.Data4 = { [3] = 0xff, [5] = 0xdd };
    --g2.Data4 = { [4] = 0xee };
    d4[3] = 0xff; d4[4] = 0xee; d4[5] = 0xdd;
    print('guid={'..guid2str(g2)..'}');
end

--------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------------------
--EnumWindows();
--RAS();
--SNMP();
Dialog();
--Malloc();
--printBinded(luawin);
--printGUID(luawin);
--COM();


print '---Done.'

