function npc0_init()
	cclog("npc0_init executing");
	temp = OwManager:getInstance():getAICharacterByName("npc0");
	temp:addCommand( OwAIMove:new( LEFT, 5));
	temp:addCommand( OwAIMove:new( RIGHT, 5));
end

function npc0_interact()
	cclog("npc0_interact executing");
	temp = OwManager:getInstance():getAICharacterByName("npc0");
	event = OwEventDialog:new("Welcome to our town!\nThere's nothing much here now so...\nGET LOST!", temp);
	event:addPage("I'm so hungry!");
	OwManager:getInstance():addEvent( event );
end
