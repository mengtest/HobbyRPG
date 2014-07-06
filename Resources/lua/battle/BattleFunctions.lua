local START_FRIENDLY_POS_X = 400
local START_FRIENDLY_POS_Y = 200
local OFFSET_FRIENDLY_POS_X = 0
local OFFSET_FRIENDLY_POS_Y = 50

local START_ENEMY_POS_X = 200
local START_ENEMY_POS_Y = 200
local OFFSET_ENEMY_POS_X = 50
local OFFSET_ENEMY_POS_Y = 50

local FONT = "fonts/testfont.fnt"

local SCREEN_WIDTH = Common:getGameWidth()
local SCREEN_HEIGHT = Common:getGameHeight()



function battle_show_player_menu()
	local BUTTON_WIDTH = SCREEN_WIDTH / 5;
	local BUTTON_HEIGHT = SCREEN_WIDTH / 10;
	local BUTTON_START_X = SCREEN_WIDTH - BUTTON_WIDTH / 2;
	local BUTTON_START_Y = SCREEN_HEIGHT - BUTTON_HEIGHT / 2;
	local BUTTON_OFFSET = BUTTON_HEIGHT;

	local backBool = true;
	local playerMenuLayer = CCLayer:create()
	
	local function removeSelf()
		playerMenuLayer:unregisterScriptTouchHandler()
		BattleManager:getInstance():removeChildFromUILayer(playerMenuLayer)
	end

	local fightButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	fightButton:setContentSize(CCSizeMake(BUTTON_WIDTH, BUTTON_HEIGHT));
	fightButton:setPosition(ccp(BUTTON_START_X, BUTTON_START_Y));
	local fightFont = CCLabelBMFont:create("Fight", FONT );
	fightFont:setPosition(ccp(BUTTON_START_X, BUTTON_START_Y));
	playerMenuLayer:addChild(fightButton);	
	playerMenuLayer:addChild(fightFont);

	local skillButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	skillButton:setPosition(ccp(BUTTON_START_X, BUTTON_START_Y - BUTTON_OFFSET));
	skillButton:setContentSize(CCSizeMake(BUTTON_WIDTH, BUTTON_HEIGHT));
	local skillFont = CCLabelBMFont:create("Skill", FONT );
	skillFont:setPosition(ccp(BUTTON_START_X,BUTTON_START_Y - BUTTON_OFFSET));
	playerMenuLayer:addChild(skillButton);	
	playerMenuLayer:addChild(skillFont);

	
	local defendButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	defendButton:setPosition(ccp(BUTTON_START_X, BUTTON_START_Y  - BUTTON_OFFSET * 2));
	defendButton:setContentSize(CCSizeMake(BUTTON_WIDTH, BUTTON_HEIGHT));
	local defendFont = CCLabelBMFont:create("Defend", FONT );
	defendFont:setPosition(ccp(BUTTON_START_X,BUTTON_START_Y - BUTTON_OFFSET * 2 ));
	playerMenuLayer:addChild(defendButton);	
	playerMenuLayer:addChild(defendFont);

	local fleeButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	fleeButton:setPosition(ccp(BUTTON_START_X, BUTTON_START_Y  - BUTTON_OFFSET * 3));
	fleeButton:setContentSize(CCSizeMake(BUTTON_WIDTH, BUTTON_HEIGHT));
	local fleeFont = CCLabelBMFont:create("Flee", FONT );
	fleeFont:setPosition(ccp(BUTTON_START_X,BUTTON_START_Y - BUTTON_OFFSET * 3));
	playerMenuLayer:addChild(fleeButton);	
	playerMenuLayer:addChild(fleeFont);

	local itemButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	itemButton:setPosition(ccp(BUTTON_START_X, BUTTON_START_Y  - BUTTON_OFFSET * 4));
	itemButton:setContentSize(CCSizeMake(BUTTON_WIDTH, BUTTON_HEIGHT));
	local itemFont = CCLabelBMFont:create("Item", FONT );
	itemFont:setPosition(ccp(BUTTON_START_X,BUTTON_START_Y - BUTTON_OFFSET * 4));
	playerMenuLayer:addChild(itemButton);	
	playerMenuLayer:addChild(itemFont);
	
	

	local function processTouchBegan(x, y)
	end

	local function processTouchMoved(x, y)
	end

	local function processTouchEnded(x, y)
		if checkWithin(backButton, x, y) then

		end

	end

	local function onTouch(eventType, x, y)
        if eventType == "began" then
			processTouchBegan(x, y)
            return true
        elseif eventType == "moved" then
			processTouchMoved(x, y)
            return true
		else
			processTouchEnded(x, y)
            return true
        end
    end

	playerMenuLayer:setTouchEnabled(true)
	playerMenuLayer:registerScriptTouchHandler(onTouch)

	BattleManager:getInstance():addChildToUILayer(playerMenuLayer);
end

local initiativeLayer = null;
-- Assumes that the participant list is sorted already
function battle_create_init_images()
	if initiativeLayer == null then
		initiativeLayer = CCLayer:create()

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

