local currentMode = 0

-- Constants
local MENUMODE_GAME = 0
local MENUMODE_MENU = 1

local FONT = "fonts/testfont.fnt"
local SCREEN_WIDTH = Common:getGameWidth()
local SCREEN_HEIGHT = Common:getGameHeight()

local DESC_WIDTH = 640
local DESC_HEIGHT = 48

local BACK_WIDTH = 640
local BACK_HEIGHT = 48	

local SLIDER_X = SCREEN_WIDTH - 16;
local SLIDER_Y = SCREEN_HEIGHT / 2;

--

local initMenuPage, initEntryPage, initItemPage, initItemCharPage, initEquipPage, initEquipCharPage

local function checkWithin(sprite, x, y, parent)
	local point = ccp(sprite:getPositionX(), sprite:getPositionY());
	
	if ( type(parent) ~= "nil" ) then 
		point.x = point.x + parent:getPositionX();
		point.y = point.y + parent:getPositionY();
	end

	local width = sprite:getContentSize().width
	local height = sprite:getContentSize().height
	local rx = point.x - width / 2
	local ry = point.y - height / 2

	local rect = CCRectMake(rx, ry, width, height) 

	return rect:containsPoint( ccp(x,y) );
end

initEquipCharPage = function(char_id)
	local CHARACTER_BACK_WIDTH = SCREEN_WIDTH / 2;
	local CHARACTER_BACK_HEIGHT = SCREEN_HEIGHT - DESC_HEIGHT - BACK_HEIGHT;
	local CHARACTER_BACK_X = SCREEN_WIDTH / 4;
	local CHARACTER_BACK_Y = SCREEN_HEIGHT - CHARACTER_BACK_HEIGHT / 2 - DESC_HEIGHT;
	local CHARACTER_HP_X = CHARACTER_BACK_X;
	local CHARACTER_HP_Y = CHARACTER_BACK_Y;
	local CHARACTER_NAME_X = CHARACTER_BACK_X - CHARACTER_BACK_WIDTH / 2 + 100;
	local CHARACTER_NAME_Y = CHARACTER_HP_Y + CHARACTER_BACK_HEIGHT / 2 - 40;
	local CHARACTER_BACK_OFFSET = CHARACTER_BACK_HEIGHT;
	local CHARACTER_SPRITE_X = CHARACTER_BACK_X - CHARACTER_BACK_WIDTH / 2 + 50;
	local CHARACTER_SPRITE_Y = CHARACTER_NAME_Y;

	local ITEM_WIDTH = 256
	local ITEM_HEIGHT = 52.8
	local ITEM_START_X = SCREEN_WIDTH * 3 / 4;
	local ITEM_START_Y = SCREEN_HEIGHT - DESC_HEIGHT - ITEM_HEIGHT / 2
	local ITEM_COLS = 2;
	local ITEM_MIN_ROWS = 5;
	local ITEM_WORD_OFFSET = 24
	local ITEM_STACK_OFFSET = 200

	local gameMenuLayer = CCLayer:create()

	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end


	local charBack = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	charBack:setContentSize( CCSizeMake(CHARACTER_BACK_WIDTH, CHARACTER_BACK_HEIGHT));
	charBack:setPosition(ccp( CHARACTER_BACK_X, CHARACTER_BACK_Y ));
	gameMenuLayer:addChild(charBack);
	
	local charName = CCLabelBMFont:create( "" .. Player:getInstance():getParty():getCharacterAtSlot(char_id):getInfo(ALIAS) , FONT );
	charName:setPosition(CHARACTER_NAME_X, CHARACTER_NAME_Y)
	charName:setAnchorPoint(ccp(0, 0.5));
	gameMenuLayer:addChild(charName);

	local spriteName = "" .. Player:getInstance():getParty():getCharacterAtSlot(char_id):getInfo(SPRITE) .. ".png";
	local charSprite = CCScale9Sprite:createWithSpriteFrameName( spriteName,  CCRectMake(0,0,0,0) );
	charSprite:setContentSize(CCSizeMake(32, 32));
	charSprite:setPosition(ccp(CHARACTER_SPRITE_X, CHARACTER_SPRITE_Y ));
	gameMenuLayer:addChild(charSprite);

	
	local refreshables = {}
	local refreshable_count = 0;
	local itemButtonList;
	local inventoryIndexList;

	local function refresh()
		currentSelection = null;
		local j = 0;
		-- kill all refreshables;
		while j < refreshable_count do
			gameMenuLayer:removeChild(refreshables[j], true);
			j = j + 1;
		end

		local equip_weapon = Player:getInstance():getParty():getCharacterAtSlot(char_id):getWeapon();
		local equip_armor = Player:getInstance():getParty():getCharacterAtSlot(char_id):getArmor();
		local equip_ring = Player:getInstance():getParty():getCharacterAtSlot(char_id):getRing();


		refreshable_count = 0;
		local weapon_name = CCLabelBMFont:create("Weapon: " .. ItemManager:getInstance():getItemStat(equip_weapon, NAME), FONT );
		weapon_name:setPosition(CHARACTER_SPRITE_X, CHARACTER_NAME_Y - 50)
		weapon_name:setAnchorPoint(ccp(0, 0.5));
		gameMenuLayer:addChild(weapon_name);
		refreshables[refreshable_count] = weapon_name;
		refreshable_count = refreshable_count + 1;

		local armor_name = CCLabelBMFont:create("Armor: " .. ItemManager:getInstance():getItemStat(equip_armor, NAME), FONT );
		armor_name:setPosition(CHARACTER_SPRITE_X, CHARACTER_NAME_Y - 100)
		armor_name:setAnchorPoint(ccp(0, 0.5));
		gameMenuLayer:addChild(armor_name);
		refreshables[refreshable_count] = armor_name;
		refreshable_count = refreshable_count + 1;

		local ring_name = CCLabelBMFont:create("Weapon: " .. ItemManager:getInstance():getItemStat(equip_ring, NAME), FONT );
		ring_name:setPosition(CHARACTER_SPRITE_X, CHARACTER_NAME_Y - 150)
		ring_name:setAnchorPoint(ccp(0, 0.5));
		gameMenuLayer:addChild(ring_name);
		refreshables[refreshable_count] = ring_name;
		refreshable_count = refreshable_count + 1;

		local itemListNode = CCNode:create();
		local itemListHeight = 0;
		local itemList_overshot_y = 0;
		itemButtonList = {} -- list of buttons
		inventoryIndexList = {} -- corresponding inventory index for each button in itemButtonList
		local max = Player:getInstance():getInventory():getInventorySize();
		if ( max < ITEM_MIN_ROWS ) then
			max = ITEM_MIN_ROWS;
		end

		local i = 0; -- main iterator
		local k = 0; -- 
		local j = PLAIN_WATER; -- enum iterator
		
		itemListNode:setPosition(ITEM_START_X, ITEM_START_Y );
		while i < max do
			local itemBack = CCScale9Sprite:createWithSpriteFrameName("menu_background.png");
			itemBack:setContentSize( CCSizeMake(ITEM_WIDTH, ITEM_HEIGHT) );
			itemBack:setPosition( 0, ITEM_HEIGHT * -i );
			itemListNode:addChild(itemBack);

			if ( j < NUM_ITEMS ) then
				local stacks = Player:getInstance():getInventory():getItemByIndex(j);
				if ( stacks > 0 ) then
					local itemType = ItemManager:getInstance():getItemStat( j, ITEM_TYPE );
					if ( itemType ~= "Item" ) then
						local itemName = ItemManager:getInstance():getItemStat( j,NAME );

						local font_x = ITEM_WIDTH * (k % 2);
						local font_y = -ITEM_HEIGHT * math.floor(k / 2);

						local itemFont = CCLabelBMFont:create("" .. itemName, FONT );	
						itemFont:setAnchorPoint(ccp(0, 0.5));
						itemFont:setPosition(-ITEM_WIDTH / 2 + ITEM_WORD_OFFSET + font_x, font_y );

						local itemStack = CCLabelBMFont:create("x" .. stacks, FONT );
						itemStack:setAnchorPoint(ccp(0, 0.5));
						itemStack:setPosition( -ITEM_WIDTH / 2 + ITEM_STACK_OFFSET + font_x, font_y);

						itemListNode:addChild(itemFont);
						itemListNode:addChild(itemStack);
						inventoryIndexList[k] = j
						k = k + 1;			
					end
				end

				j = j + 1;
			end
			itemListHeight = itemListHeight + ITEM_HEIGHT / 2;
			itemButtonList[i] = itemBack;
			i = i + 1;	
		end
	
		gameMenuLayer:addChild(itemListNode);
		refreshables[refreshable_count] = itemListNode;
		refreshable_count = refreshable_count + 1;
	end

	refresh();

	local descButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	descButton:setContentSize(CCSizeMake(DESC_WIDTH, DESC_HEIGHT));
	descButton:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));
	local descFont = CCLabelBMFont:create("Desc", FONT );
	descFont:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));
	gameMenuLayer:addChild(descButton);
	gameMenuLayer:addChild(descFont);

	local backButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	backButton:setContentSize(CCSizeMake(BACK_WIDTH, BACK_HEIGHT));
	backButton:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));
	local backFont = CCLabelBMFont:create("Back", FONT );
	backFont:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));
	gameMenuLayer:addChild(backButton);	
	gameMenuLayer:addChild(backFont);
	gameMenuLayer:reorderChild(backButton, 10); --reorder to prevent refresh() to overlap
	gameMenuLayer:reorderChild(backFont, 11);	--reorder to prevent refresh() to overlap
	
	-- ???? ---
	local function equip_weapon(party_slot, item)
		c = Player:getInstance():getParty():getCharacterAtSlot(party_slot);
		i = Player:getInstance():getInventory();
		rhs = c:getWeapon();
	
		if c:equipWeapon(item) == true then
			i:removeItem(item);
			if rhs ~= EMPTY then
				i:addItem(rhs);
			end
			return 1;
		else
			return 0;
		end
	end

	local function processTouchBegan(x, y)
		local i = 0;
		for k, v in pairs(itemButtonList) do
			if checkWithin( v, x, y, v:getParent() ) then
				if currentSelection ~= null then 
					currentSelection:initWithSpriteFrameName("menu_background.png");
					currentSelection:setContentSize( CCSizeMake( ITEM_WIDTH, ITEM_HEIGHT) );
				end

				if currentSelection == v then
					equip_weapon(char_id, inventoryIndexList[i]);
					refresh();
					return
				end

				if inventoryIndexList[i] == null then
					return
				end

				v:initWithSpriteFrameName("menu_background_selected.png");
				v:setContentSize( CCSizeMake( ITEM_WIDTH, ITEM_HEIGHT) );
				currentSelection = v;
				return;
			end

			i = i + 1;
		end
	end

	local function processTouchMoved(x, y)
	end

	local function processTouchEnded(x, y)
		if checkWithin(backButton, x, y) then
			removeSelf()
			initEquipPage();
			return;
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

	gameMenuLayer:setTouchEnabled(true)
	gameMenuLayer:registerScriptTouchHandler(onTouch)

	OwManager:getInstance():addChildToUILayer(gameMenuLayer);
end


initEquipPage = function()
	local gameMenuLayer = CCLayer:create()

	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end

	local PARTY_SIZE = 3
	
	local CHARACTER_BACK_WIDTH = SCREEN_WIDTH;
	local CHARACTER_BACK_HEIGHT = 90;
	local CHARACTER_BACK_X = SCREEN_WIDTH / 2;
	local CHARACTER_BACK_Y = SCREEN_HEIGHT - CHARACTER_BACK_HEIGHT / 2 - DESC_HEIGHT;
	local CHARACTER_HP_X = CHARACTER_BACK_X;
	local CHARACTER_HP_Y = CHARACTER_BACK_Y;
	local CHARACTER_NAME_X = CHARACTER_BACK_X - CHARACTER_BACK_WIDTH / 2 + 100;
	local CHARACTER_NAME_Y = CHARACTER_HP_Y;
	local CHARACTER_BACK_OFFSET = CHARACTER_BACK_HEIGHT;
	local CHARACTER_SPRITE_X = CHARACTER_BACK_X - CHARACTER_BACK_WIDTH / 2 + 50;
	local CHARACTER_SPRITE_Y = CHARACTER_HP_Y;

	local descButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	descButton:setContentSize(CCSizeMake(DESC_WIDTH, DESC_HEIGHT));
	descButton:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));
	local descFont = CCLabelBMFont:create("Desc", FONT );
	descFont:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));
	gameMenuLayer:addChild(descButton);
	gameMenuLayer:addChild(descFont);

	local backButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	backButton:setContentSize(CCSizeMake(BACK_WIDTH, BACK_HEIGHT));
	backButton:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));
	local backFont = CCLabelBMFont:create("Back", FONT );
	backFont:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));
	gameMenuLayer:addChild(backButton);	
	gameMenuLayer:addChild(backFont);


	local characterButtons = {} -- list of character buttons
	local refreshables = {}
	local refreshable_count = 0;
	local i = 0;
	
	local function refresh()
		local j = 0;
		-- kill all refreshables;
		while j < refreshable_count do
			gameMenuLayer:removeChild(refreshables[j], true);
			j = j + 1;
		end
		
		local k = 0;
		refreshable_count = 0;
		while k < PARTY_SIZE do
			local charHP = CCLabelBMFont:create("HP: " .. Player:getInstance():getParty():getCharacterAtSlot(k):getCurrentHP() .. "/" .. Player:getInstance():getParty():getCharacterAtSlot(0):getStat(HP), FONT );	
			charHP:setPosition(CHARACTER_HP_X, CHARACTER_HP_Y - CHARACTER_BACK_OFFSET * k);
			charHP:setAnchorPoint(ccp(0, 0.5));
			gameMenuLayer:addChild(charHP);
			refreshables[refreshable_count] = charHP;
			refreshable_count = refreshable_count + 1;
			k = k + 1;
		end
		
	end

	while i < PARTY_SIZE do
		local charBack = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
		charBack:setContentSize(CCSizeMake(CHARACTER_BACK_WIDTH, CHARACTER_BACK_HEIGHT));
		charBack:setPosition(ccp(CHARACTER_BACK_X , CHARACTER_BACK_Y - CHARACTER_BACK_OFFSET * i));
		characterButtons[i] = charBack;
		gameMenuLayer:addChild(charBack);	
		
		
		local charName = CCLabelBMFont:create( "" .. Player:getInstance():getParty():getCharacterAtSlot(i):getInfo(ALIAS) , FONT );
		charName:setPosition(CHARACTER_NAME_X, CHARACTER_NAME_Y - CHARACTER_BACK_OFFSET * i)
		charName:setAnchorPoint(ccp(0, 0.5));
		gameMenuLayer:addChild(charName);

		local spriteName = "" .. Player:getInstance():getParty():getCharacterAtSlot(i):getInfo(SPRITE) .. ".png";
		local charSprite = CCScale9Sprite:createWithSpriteFrameName( spriteName,  CCRectMake(0,0,0,0) );
		charSprite:setContentSize(CCSizeMake(32, 32));
		charSprite:setPosition(ccp(CHARACTER_SPRITE_X, CHARACTER_SPRITE_Y - CHARACTER_BACK_OFFSET * i));
		gameMenuLayer:addChild(charSprite);

		i = i + 1;
	end

	refresh();

	local function processTouchBegan(x, y)
	end

	local function processTouchMoved(x, y)
	end

	local function processTouchEnded(x, y)
		if checkWithin(backButton, x, y) then
			removeSelf();
			initMenuPage();
			return;
		end

		local i = 0;
		for k, v in pairs(characterButtons) do
			if checkWithin( v, x, y ) then
				removeSelf();
				initEquipCharPage(i)
			end
			i = i + 1;
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

	gameMenuLayer:setTouchEnabled(true)
	gameMenuLayer:registerScriptTouchHandler(onTouch)

	OwManager:getInstance():addChildToUILayer(gameMenuLayer);
end


initItemCharPage = function( inventory_num )
	local gameMenuLayer = CCLayer:create()

	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end

	local PARTY_SIZE = 3
	
	local CHARACTER_BACK_WIDTH = SCREEN_WIDTH;
	local CHARACTER_BACK_HEIGHT = 90;
	local CHARACTER_BACK_X = SCREEN_WIDTH / 2;
	local CHARACTER_BACK_Y = SCREEN_HEIGHT - CHARACTER_BACK_HEIGHT / 2 - DESC_HEIGHT;
	local CHARACTER_HP_X = CHARACTER_BACK_X;
	local CHARACTER_HP_Y = CHARACTER_BACK_Y;
	local CHARACTER_NAME_X = CHARACTER_BACK_X - CHARACTER_BACK_WIDTH / 2 + 100;
	local CHARACTER_NAME_Y = CHARACTER_HP_Y;
	local CHARACTER_BACK_OFFSET = CHARACTER_BACK_HEIGHT;
	local CHARACTER_SPRITE_X = CHARACTER_BACK_X - CHARACTER_BACK_WIDTH / 2 + 50;
	local CHARACTER_SPRITE_Y = CHARACTER_HP_Y;

	local descButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	descButton:setContentSize(CCSizeMake(DESC_WIDTH, DESC_HEIGHT));
	descButton:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));
	local descFont = CCLabelBMFont:create("Desc", FONT );
	descFont:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));
	gameMenuLayer:addChild(descButton);
	gameMenuLayer:addChild(descFont);

	local backButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	backButton:setContentSize(CCSizeMake(BACK_WIDTH, BACK_HEIGHT));
	backButton:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));
	local backFont = CCLabelBMFont:create("Back", FONT );
	backFont:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));
	gameMenuLayer:addChild(backButton);	
	gameMenuLayer:addChild(backFont);

	

	local characterButtons = {} -- list of character buttons
	local refreshables = {}
	local refreshable_count = 0;
	local i = 0;
	
	local function refresh()
		local j = 0;
		-- kill all refreshables;
		while j < refreshable_count do
			gameMenuLayer:removeChild(refreshables[j], true);
			j = j + 1;
		end
		
		local k = 0;
		refreshable_count = 0;
		while k < PARTY_SIZE do
			local charHP = CCLabelBMFont:create("HP: " .. Player:getInstance():getParty():getCharacterAtSlot(k):getCurrentHP() .. "/" .. Player:getInstance():getParty():getCharacterAtSlot(0):getStat(HP), FONT );	
			charHP:setPosition(CHARACTER_HP_X, CHARACTER_HP_Y - CHARACTER_BACK_OFFSET * k);
			charHP:setAnchorPoint(ccp(0, 0.5));
			gameMenuLayer:addChild(charHP);
			refreshables[refreshable_count] = charHP;
			refreshable_count = refreshable_count + 1;
			k = k + 1;
		end
		
	end

	while i < PARTY_SIZE do
		local charBack = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
		charBack:setContentSize(CCSizeMake(CHARACTER_BACK_WIDTH, CHARACTER_BACK_HEIGHT));
		charBack:setPosition(ccp(CHARACTER_BACK_X , CHARACTER_BACK_Y - CHARACTER_BACK_OFFSET * i));
		characterButtons[i] = charBack;
		gameMenuLayer:addChild(charBack);	
		
		
		local charName = CCLabelBMFont:create( "" .. Player:getInstance():getParty():getCharacterAtSlot(i):getInfo(ALIAS) , FONT );
		charName:setPosition(CHARACTER_NAME_X, CHARACTER_NAME_Y - CHARACTER_BACK_OFFSET * i)
		charName:setAnchorPoint(ccp(0, 0.5));
		gameMenuLayer:addChild(charName);

		local spriteName = "" .. Player:getInstance():getParty():getCharacterAtSlot(i):getInfo(SPRITE) .. ".png";
		local charSprite = CCScale9Sprite:createWithSpriteFrameName( spriteName,  CCRectMake(0,0,0,0) );
		charSprite:setContentSize(CCSizeMake(32, 32));
		charSprite:setPosition(ccp(CHARACTER_SPRITE_X, CHARACTER_SPRITE_Y - CHARACTER_BACK_OFFSET * i));
		gameMenuLayer:addChild(charSprite);

		i = i + 1;
	end

	refresh();

	local function processTouchBegan(x, y)
	end

	local function processTouchMoved(x, y)
	end

	local function processTouchEnded(x, y)
		if checkWithin(backButton, x, y) then
			OwManager:getInstance():unpause()
			gameMenuLayer:unregisterScriptTouchHandler()
			OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
			initMenuPage();
			return;
		end

		local i = 0;
		for k, v in pairs(characterButtons) do
			if checkWithin( v, x, y ) then
				local func = ItemManager:getInstance():getItemStat( inventory_num, USE );
				_G[func](i);
				refresh();
				return;
			end
			i = i + 1;
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

	gameMenuLayer:setTouchEnabled(true)
	gameMenuLayer:registerScriptTouchHandler(onTouch)

	OwManager:getInstance():addChildToUILayer(gameMenuLayer);

end

initItemPage = function()

	local currentSelection = null;

	local ITEM_WIDTH = 256
	local ITEM_HEIGHT = 52.8
	local ITEM_START_X = 128
	local ITEM_START_Y = SCREEN_HEIGHT - DESC_HEIGHT - ITEM_HEIGHT / 2
	local ITEM_COLS = 2;
	local ITEM_MIN_ROWS = 5;
	local ITEM_WORD_OFFSET = 24
	local ITEM_STACK_START_Y = ITEM_START_Y;
	local ITEM_STACK_OFFSET = 200

	local itemList_overshot_y = 0;
	local itemButtonList = {} -- list of buttons
	local inventoryIndexList = {} -- corresponding inventory index for each button in itemButtonList
	local gameMenuLayer = CCLayer:create()

	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end

	
	local max = Player:getInstance():getInventory():getInventorySize();
	if ( max < (ITEM_MIN_ROWS * 2) ) then
		max = ITEM_MIN_ROWS * 2;
	end

	local i = 0; -- main iterator
	local k = 0; -- 
	local j = PLAIN_WATER; -- enum iterator
	local itemListNode = CCNode:create();
	local itemListHeight = 0;

	itemListNode:setPosition(ITEM_START_X, ITEM_START_Y );
	while i < max do
		local x = ITEM_WIDTH * (i % 2);
		local y = -ITEM_HEIGHT * math.floor(i / 2);

		local itemBack = CCScale9Sprite:createWithSpriteFrameName("menu_background.png");
		itemBack:setContentSize( CCSizeMake(ITEM_WIDTH, ITEM_HEIGHT) );
		itemBack:setPosition( x, y );
		itemListNode:addChild(itemBack)

		
		if ( j < NUM_ITEMS ) then
			local stacks = Player:getInstance():getInventory():getItemByIndex(j);
			if ( stacks > 0 ) then
				local itemType = ItemManager:getInstance():getItemStat( j, ITEM_TYPE );
				if ( itemType == "Item" ) then
					local itemName = ItemManager:getInstance():getItemStat( j,NAME );

					local font_x = ITEM_WIDTH * (k % 2);
					local font_y = -ITEM_HEIGHT * math.floor(k / 2);

					local itemFont = CCLabelBMFont:create("" .. itemName, FONT );	
					itemFont:setAnchorPoint(ccp(0, 0.5));
					itemFont:setPosition(-ITEM_WIDTH / 2 + ITEM_WORD_OFFSET + font_x, font_y );

					local itemStack = CCLabelBMFont:create("x" .. stacks, FONT );
					itemStack:setAnchorPoint(ccp(0, 0.5));
					itemStack:setPosition( -ITEM_WIDTH / 2 + ITEM_STACK_OFFSET + font_x, font_y);

					itemListNode:addChild(itemFont);
					itemListNode:addChild(itemStack);
					inventoryIndexList[k] = j
					k = k + 1;			
				end
			end

			j = j + 1;
		end

			
		
		itemListHeight = itemListHeight + ITEM_HEIGHT / 2;

		--table.insert(itemButtonList, itemBack)
		itemButtonList[i] = itemBack;
		i = i + 1;	
	end


	gameMenuLayer:addChild(itemListNode);

	local backButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	backButton:setContentSize(CCSizeMake(BACK_WIDTH, BACK_HEIGHT));
	backButton:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));

	local backFont = CCLabelBMFont:create("Back", FONT );
	backFont:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));

	itemList_overshot_y = -( SCREEN_HEIGHT - BACK_HEIGHT - DESC_HEIGHT - itemListHeight ) ;

	gameMenuLayer:addChild(backButton);	
	gameMenuLayer:addChild(backFont);

	local descButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	descButton:setContentSize(CCSizeMake(DESC_WIDTH, DESC_HEIGHT));
	descButton:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));
	
	local descFont = CCLabelBMFont:create("Desc", FONT );
	descFont:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));

	gameMenuLayer:addChild(descButton);
	gameMenuLayer:addChild(descFont);

	
	--local sliderBackground = CCSprite:createWithSpriteFrameName("slider_thumb.png");
	--local sliderThumb = CCSprite:createWithSpriteFrameName("slider_background.png");
	--local sliderTrack = CCSprite:createWithSpriteFrameName("slider_background.png");
	local slider = CCControlSlider:create("sprites/sliderTrack.png", "sprites/sliderTrack.png", "sprites/sliderThumb.png");
	slider:setPosition(SLIDER_X, SLIDER_Y);
	slider:setMinimumValue(0);
	slider:setMaximumValue(1);
	slider:setValue(0);
	slider:setScale(0.5);
	slider:setRotation(90);

	

	local function sliderCallback()
		local result = ( slider:getValue()  ) * ( ITEM_START_Y + itemList_overshot_y) + ( 1 - slider:getValue() ) * ITEM_START_Y ;
		itemListNode:setPositionY(result);
		cclog("".. itemList_overshot_y );
	end


	slider:addHandleOfControlEvent(sliderCallback, CCControlEventValueChanged) 
	gameMenuLayer:addChild(slider);	
	
	local function processTouchBegan(x, y)
		local i = 0;
		for k, v in pairs(itemButtonList) do
			if checkWithin( v, x, y, v:getParent() ) then
				if currentSelection ~= null then 
					currentSelection:initWithSpriteFrameName("menu_background.png");
					currentSelection:setContentSize( CCSizeMake( ITEM_WIDTH, ITEM_HEIGHT) );
				end

				if currentSelection == v then
					gameMenuLayer:unregisterScriptTouchHandler()
					OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
					initItemCharPage(inventoryIndexList[i])
					return
				end

				if inventoryIndexList[i] == null then
					return
				end

				v:initWithSpriteFrameName("menu_background_selected.png");
				v:setContentSize( CCSizeMake( ITEM_WIDTH, ITEM_HEIGHT) );
				currentSelection = v;
				return;
			end

			i = i + 1;
		end
	end

	local function processTouchMoved(x, y)
	end

	local function processTouchEnded(x, y)
		
		if checkWithin(backButton, x, y) then
			OwManager:getInstance():unpause()
			gameMenuLayer:unregisterScriptTouchHandler()
			OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
			initMenuPage();
			return;
		end
		
		local i = 0 
		


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

	gameMenuLayer:setTouchEnabled(true)
	gameMenuLayer:registerScriptTouchHandler(onTouch)

	OwManager:getInstance():addChildToUILayer(gameMenuLayer);

end

initEntryPage = function()
	local gameMenuLayer = CCLayer:create()

	local startButton = CCSprite:createWithSpriteFrameName("menu_icon.png");
	x = Common:getGameWidth() - startButton:getContentSize().width / 2;
	y = Common:getGameHeight() - startButton:getContentSize().height / 2;
	startButton:setPosition(ccp(x,y));
	
	gameMenuLayer:addChild(startButton);	

	local function processTouchBegan(x, y)
	end

	local function processTouchMoved(x, y)
	end

	local function processTouchEnded(x, y)
		if checkWithin(startButton, x, y) then
			cclog("yay")
			OwManager:getInstance():pause()
			gameMenuLayer:unregisterScriptTouchHandler()
			OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
			initMenuPage()
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

	gameMenuLayer:setTouchEnabled(true)
	gameMenuLayer:registerScriptTouchHandler(onTouch)

	OwManager:getInstance():addChildToUILayer(gameMenuLayer);
end

initMenuPage = function()

	local BUTTON_WIDTH = 128;
	local BUTTON_HEIGHT = 64;
	local BUTTON_START_X = SCREEN_WIDTH - BUTTON_WIDTH / 2;
	local BUTTON_START_Y = SCREEN_HEIGHT - BUTTON_HEIGHT / 2;
	local BUTTON_OFFSET = BUTTON_HEIGHT;

	local gameMenuLayer = CCLayer:create()
	
	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end

	local backButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	backButton:setContentSize(CCSizeMake(BACK_WIDTH, BACK_HEIGHT));
	backButton:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));
	local backFont = CCLabelBMFont:create("Back", FONT );
	backFont:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));
	gameMenuLayer:addChild(backButton);	
	gameMenuLayer:addChild(backFont);

	local itemButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	itemButton:setPosition(ccp(BUTTON_START_X, BUTTON_START_Y));
	itemButton:setContentSize(CCSizeMake(BUTTON_WIDTH, BUTTON_HEIGHT));

	local itemFont = CCLabelBMFont:create("Items", FONT );
	itemFont:setPosition(ccp(BUTTON_START_X,BUTTON_START_Y));

	gameMenuLayer:addChild(itemButton);	
	gameMenuLayer:addChild(itemFont);


	local equipButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	equipButton:setPosition(ccp(BUTTON_START_X, BUTTON_START_Y  - BUTTON_OFFSET));
	equipButton:setContentSize(CCSizeMake(BUTTON_WIDTH, BUTTON_HEIGHT));

	local equipFont = CCLabelBMFont:create("Equip", FONT );
	equipFont:setPosition(ccp(BUTTON_START_X,BUTTON_START_Y - BUTTON_OFFSET ));

	gameMenuLayer:addChild(equipButton);	
	gameMenuLayer:addChild(equipFont);

	local function processTouchBegan(x, y)
	end

	local function processTouchMoved(x, y)
	end

	local function processTouchEnded(x, y)
		if checkWithin(backButton, x, y) then
			OwManager:getInstance():unpause()
			removeSelf()
			initEntryPage()
		elseif checkWithin(itemButton, x, y ) then
			removeSelf()
			initItemPage()
		elseif checkWithin(equipButton, x, y ) then
			removeSelf()
			initEquipPage();
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

	gameMenuLayer:setTouchEnabled(true)
	gameMenuLayer:registerScriptTouchHandler(onTouch)

	OwManager:getInstance():addChildToUILayer(gameMenuLayer);
end



function createOverworldMenu()
	initEntryPage()
end

