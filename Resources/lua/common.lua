
cclog = function(...)
    print(string.format(...))
end

function world_to_overworld(where)
	WorldManager:getInstance():gotoOverworld(where)
end

function overworld_to_world(node)
	OwManager:getInstance():gotoWorld(node);
end

function overworld_to_overworld(name, x, y)
	OwManager:getInstance():gotoOverworld(name, x, y);
end


function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end

main = function()
	local i = 0
	while ( i < ItemManager:getInstance():getItemTypeMax() ) do 
		Player:getInstance():getInventory():addItem(i);
		i = i + 1;
	end
end

add = function ( a, b)
	cclog(a);
	cclog(b);
	return a + b;
end


xpcall(main, __G__TRACKBACK__)