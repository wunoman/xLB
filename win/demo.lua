-- demo for bind Windows API to Lua (0.0.1)
package.cpath = os.getenv('Output')..[[\obj\?.dll]];
print(package.cpath);
require 'luawin'
print('---version:'..luawin._version());
print('---luawin.GetCurrentDirectory='..tostring(luawin.GetCurrentDirectory));

--print('W.CallWndProc='..tostring(luawin.CallWndProc));
--local CallWndProc = luawin.CallWndProc(function() return 0; end);
--print('W.CallWndProc='..tostring(CallWndProc));
--print('W.CallWndProc='..luawin.type(CallWndProc));


--local len = 1024;
--local s = string.rep('\0', len);
--local d = luawin.GetCurrentDirectory(len, s);
--print('W.GetCurrentDirectory=' .. string.sub(s,1,d));

function EnumWindows()
    local len = 1024;
    local buff = string.rep('\0', len);
    local EnumWindowsProc = luawin.EnumWindowsProc(function(hwnd, lParam) 
        --print('---', hwnd, lParam, luawin.type(hwnd));
        local len = luawin.GetWindowText(hwnd, buff, len);
        print('---' .. string.sub(buff, 1, len));
        --return false; 
        return true; 
        --return 1; 
    end);

    luawin.EnumWindows(EnumWindowsProc, 999);
end

function SNMP()
    luawin.load_snmp();
    print('luawin.SNMPAPI_CALLBACK='..tostring(luawin.SNMPAPI_CALLBACK));
    for k,v in pairs(luawin.SNMPAPI_CALLBACK) do print(k,v); end
end

function Dialog()
    luawin.load_dialog();
    print('luawin.MessageBox='..tostring(luawin.MessageBox));
    local r = luawin.MessageBox(nil, 'ok?', 'luawin', 0x00000001 | 0x00000020);
    print(r);
end

--EnumWindows();
--RAS();
--SNMP();
Dialog();

print '---Done.'

