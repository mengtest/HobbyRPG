local START_FRIENDLY_POS_X = 400
local START_FRIENDLY_POS_Y = 200
local OFFSET_FRIENDLY_POS_X = 0
local OFFSET_FRIENDLY_POS_Y = 50

local START_ENEMY_POS_X = 200
local START_ENEMY_POS_Y = 200
local OFFSET_ENEMY_POS_X = 50
local OFFSET_ENEMY_POS_Y = 50

local FONT = "fonts/testfont.fnt"

-- Assumes that the participant list is sorted already
function battle_create_init_images()
	local initiativeLayer = CCLayer:create()
	
	local total = BattleManager:getInstance():getParticipantCount();
    local i = 0;
    while i < total do
        local entity = BattleManager:getInstance():getParticipant(i);
        local charinitButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
		charinitButton:setPosition(ccp( 50 + 100 * i, 100 ) );
		charinitButton:setContentSize( CCSizeMake(100, 40) );
		initiativeLayer:addChild(charinitButton);

		local text = entity:getName();
		local itemFont = CCLabelBMFont:create("" .. text, FONT );	
		itemFont:setAnchorPoint(ccp(0, 0.5));
		itemFont:setPosition(ccp( 15 + 100 * i, 100 ) );
		itemFont:setScale(0.75)
		initiativeLayer:addChild(itemFont);
        i = i + 1;
    end

	BattleManager:getInstance():addChildToUILayer(initiativeLayer);
end


function battle_show_player_menu() 
end

-- for calculation
local player_count = 0;
local enemy_count = 0;
function battle_calculate_entity_position(entity)
    local is_enemy = entity:getIsEnemy();
    if is_enemy == true then
        entity:setPosition(ccp(START_ENEMY_POS_X + OFFSET_ENEMY_POS_X * enemy_count, 
                               START_ENEMY_POS_Y + OFFSET_ENEMY_POS_Y * enemy_count));
        enemy_count = enemy_count + 1;
    else
        entity:setPosition(ccp(START_FRIENDLY_POS_X + OFFSET_FRIENDLY_POS_X * player_count, 
                               START_FRIENDLY_POS_Y + OFFSET_FRIENDLY_POS_Y * player_count));
        player_count = player_count + 1;
    end
end
 
battle_calculate_positions = function()
    local total = BattleManager:getInstance():getParticipantCount();
    local i = 0;
    player_count = 0;
    enemy_count = 0;
    while i < total do
        local entity = BattleManager:getInstance():getParticipant(i);
        battle_calculate_entity_position(entity);
        i = i + 1;
    end
end

