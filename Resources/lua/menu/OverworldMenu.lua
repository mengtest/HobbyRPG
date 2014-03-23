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

local ITEM_WIDTH = 256
local ITEM_HEIGHT = 52.8
local ITEM_START_X = 128
local ITEM_START_Y = SCREEN_HEIGHT - DESC_HEIGHT - ITEM_HEIGHT / 2
local ITEM_COLS = 2;
local ITEM_MIN_ROWS = 5;
local ITEM_WORD_OFFSET = 24

local ITEM_STACK_START_Y = ITEM_START_Y;
local ITEM_STACK_OFFSET = 200

local SLIDER_X = SCREEN_WIDTH - 16;
local SLIDER_Y = SCREEN_HEIGHT / 2;
--

local initMenuPage, initEntryPage, initItemPage, initItemCharPage, initEquipPage

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

initItemCharPage = function( inventory_num )
	local gameMenuLayer = CCLayer:create()
	cclog("chosen: "..inventory_num)

	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end

	local descButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	descButton:setContentSize(CCSizeMake(DESC_WIDTH, DESC_HEIGHT));
	descButton:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));
	
	local descFont = CCLabelBMFont:create("Desc", FONT );
	descFont:setPosition(ccp(DESC_WIDTH / 2, SCREEN_HEIGHT - DESC_HEIGHT / 2));

	gameMenuLayer:addChild(descButton);
	gameMenuLayer:addChild(descFont);

	local function processTouchBegan(x, y)
	end

	local function processTouchMoved(x, y)
	end

	local function processTouchEnded(x, y)
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
	-- Variables just for this page
	local currentSelection = null; 
	--

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
				--table.insert(inventoryIndexList, j);
				inventoryIndexList[k] = j
				k = k + 1;			
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
	local gameMenuLayer = CCLayer:create()
	
	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end

	local backButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	backButton:setPosition(ccp(200, 100));
	backButton:setContentSize(CCSizeMake(128, 64));

	local backFont = CCLabelBMFont:create("Back", FONT );
	backFont:setPosition(ccp(200,100));

	gameMenuLayer:addChild(backButton);	
	gameMenuLayer:addChild(backFont);


	local itemButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	itemButton:setPosition(ccp(200, 200));
	itemButton:setContentSize(CCSizeMake(128, 64));

	local itemFont = CCLabelBMFont:create("Items", FONT );
	itemFont:setPosition(ccp(200,200));

	gameMenuLayer:addChild(itemButton);	
	gameMenuLayer:addChild(itemFont);

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

