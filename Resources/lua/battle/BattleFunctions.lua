local MAX_MEMBERS = 3;
local SCREEN_WIDTH = Common:getGameWidth()
local SCREEN_HEIGHT = Common:getGameHeight()

function BattleInitEnemies()

end

function BattleInitCharacters()
	local i = 0;
	local offset_y = SCREEN_HEIGHT * 0.15;
	while ( i < MAX_MEMBERS ) do
		local character = Player:getInstance():getParty():getCharacterAtSlot(i);
		local x = SCREEN_WIDTH * 0.75;
		local y = SCREEN_HEIGHT * 0.7 - offset_y * i;
		local character_sprite = character:getInfo(CHARACTER_INFO_ENUM_SPRITE);
		local character_name = character:getInfo(CHARACTER_INFO_ENUM_ALIAS);
		BattleManager:getInstance():addBattleCharacter( ccp(x,y), character_name, character_sprite .. "_left_2.png");
		i = i + 1;
	end
end

function BattleInit()
	BattleInitCharacters()
	BattleInitEnemies()
end