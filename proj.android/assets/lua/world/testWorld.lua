cclog = function(...)
    print(string.format(...))
end

function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end

local function main()
end

add = function ( a, b)
	cclog(a);
	cclog(b);
	return a + b;
end


xpcall(main, __G__TRACKBACK__)