function MainWorld_node0()
	cclog("MainWorld_node0 executing");
	event = WorldEventDialog:new("Welcome to our town!\nThere's nothing much here now so...\nGET LOST!");
	WorldManager:getInstance():addEvent( event );
end

function MainWorld_node1()
	cclog("MainWorld_node1 executing");
	WorldManager:getInstance():gotoOverworld("testmap");
end