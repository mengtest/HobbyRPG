function npc1_init()
	cclog("npc1_init executing");
	temp = OwManager:getInstance():getAICharacterByName("npc1");
	temp:addCommand( OwAIMove:new( LEFT, 5));
	temp:addCommand( OwAIMove:new( RIGHT, 5));
end


function npc1_interact()
	cclog("npc1_interact executing");
	temp = OwManager:getInstance():getAICharacterByName("npc1");
	OwManager:getInstance():addEvent( OwEventDialog:new("What do you want?",temp) );
	OwManager:getInstance():addEvent( OwEventDelay:new(2,temp) );
	OwManager:getInstance():addEvent( OwEventDialog:new("Er...go away?",temp) );

end