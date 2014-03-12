local currentMode = 0
local MENUMODE_GAME = 0
local MENUMODE_MENU = 1

local FONT = "fonts/testfont.fnt"
local SCREEN_WIDTH = Common:getGameWidth()
local SCREEN_HEIGHT = Common:getGameHeight()


local initMenuPage, initEntryPage, initItemPage, initEquipPage

local function checkWithin(sprite, x, y)
	width = sprite:getContentSize().width
	height = sprite:getContentSize().height
	rx = sprite:getPositionX() - width / 2
	ry = sprite:getPositionY() - height / 2

	rect = CCRectMake(rx, ry, width, height) 

	return rect:containsPoint( ccp(x,y) );
end

initItemPage = function()
	-- Variables just for this page
	local currentSelection = -1; 
	local itemList_overshot_y = 0;

	-- Constants
	local DESC_WIDTH = 640
	local DESC_HEIGHT = 48
	local BACK_WIDTH = 640
	local BACK_HEIGHT = 48	

	local ITEM_WIDTH = 256
	local ITEM_HEIGHT = 55
	local ITEM_START_X = 128
	local ITEM_START_Y = SCREEN_HEIGHT - DESC_HEIGHT - ITEM_HEIGHT / 2
	local ITEM_COLS = 2;
	local ITEM_ROWS = 5;
	local ITEM_WORD_OFFSET = 24

	--
	local gameMenuLayer = CCLayer:create()

	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end

	local itemButtonList = {}
	local max = Player:getInstance():getInventory():getInventorySize();
	local i = 0;
	local j = PLAIN_WATER;
	local itemListNode = CCNode:create();
	local itemListHeight = 0;
	itemListNode:setPosition(ITEM_START_X, ITEM_START_Y );
	while i < max do
		local itemBack = CCScale9Sprite:createWithSpriteFrameName("menu_background.png");
		itemBack:setContentSize( CCSizeMake(ITEM_WIDTH, ITEM_HEIGHT) );
		itemBack:setPosition( 0, -ITEM_HEIGHT * i );

		local itemName = ItemManager:getInstance():getItemStat( j,NAME );

		local itemFont = CCLabelBMFont:create("" .. itemName, FONT );	
		itemFont:setAnchorPoint(ccp(0, 0.5));
		itemFont:setPosition(-ITEM_WIDTH / 2 + ITEM_WORD_OFFSET, -ITEM_HEIGHT * i );

		itemListNode:addChild(itemBack)
		itemListNode:addChild(itemFont)

		i = i + 1;
		j = j + 1;
		itemListHeight = itemListHeight + ITEM_HEIGHT;

		table.insert(itemButtonList, itemBack)
	end

	gameMenuLayer:addChild(itemListNode);

	local backButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	backButton:setContentSize(CCSizeMake(BACK_WIDTH, BACK_HEIGHT));
	backButton:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));

	local backFont = CCLabelBMFont:create("Back", FONT );
	backFont:setPosition(ccp(BACK_WIDTH / 2, BACK_HEIGHT / 2));

	itemList_overshot_y = ( itemListHeight - ITEM_START_Y - ( backButton:getPositionY() + BACK_HEIGHT / 2 )) ;

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
	slider:setPosition(400, 200 );
	slider:setMinimumValue(0);
	slider:setMaximumValue(1);
	slider:setValue(0);
	slider:setScale(0.5);
	slider:setRotation(90);

	

	local function sliderCallback()
		local result = ( slider:getValue()  ) * ( ITEM_START_Y + itemList_overshot_y) + ( 1 - slider:getValue() ) * ITEM_START_Y ;
		itemListNode:setPositionY(result);
		cclog(""..itemList_overshot_y);
	end


	slider:addHandleOfControlEvent(sliderCallback, CCControlEventValueChanged) 
	gameMenuLayer:addChild(slider);	
	
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
		for k, v in pairs(itemButtonList) do
			if checkWithin( v, x, y ) then
				v:initWithSpriteFrameName("menu_background_selected.png");
				v:setContentSize( CCSizeMake(256, 48) );
				--v:setDisplayFrame(CCSpriteFrameCache:sharedSpriteFrameCache():spriteFrameByName("menu_background_selected.png"));
				return;
			end

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

