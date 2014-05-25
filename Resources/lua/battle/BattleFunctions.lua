local MAX_MEMBERS = 3;
local SCREEN_WIDTH = Common:getGameWidth()
local SCREEN_HEIGHT = Common:getGameHeight()

function BattleInitCharacters()
	local i = 0;
	local offset_y = SCREEN_HEIGHT * 0.15;
	while ( i < MAX_MEMBERS ) do
		local test = Player:getInstance():getParty():getCharacterAtSlot(i);
		local x = SCREEN_WIDTH * 0.75;
		local y = SCREEN_HEIGHT * 0.7 - offset_y * i;
		BattleManager:getInstance():addBattleCharacter( ccp(x,y), test, LEFT);
		i = i + 1;
	end
end

function BattleInit()
	BattleInitCharacters()

end