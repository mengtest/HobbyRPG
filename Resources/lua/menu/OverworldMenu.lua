local currentMode = 0
local MENUMODE_GAME = 0
local MENUMODE_MENU = 1

local FONT = "fonts/testfont.fnt"

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
	local gameMenuLayer = CCLayer:create()

	local function removeSelf()
		gameMenuLayer:unregisterScriptTouchHandler()
		OwManager:getInstance():removeChildFromUILayer(gameMenuLayer)
	end

	local itemButtonList = {}
	local max = Player:getInstance():getInventory():getInventorySize();
	local i = 1;
	local j = PLAIN_WATER;
	while i <= max do
		local itemBack = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
		itemBack:setContentSize( CCSizeMake(256, 48) );
		itemBack:setPosition( 128 , 336 - 48 * i  );

		local itemName = ItemManager:getInstance():getItemStat( j,NAME );

		local itemFont = CCLabelBMFont:create("" .. itemName, FONT );	
		itemFont:setAnchorPoint(ccp(0, 0.5));
		itemFont:setPosition(32 , 336 - 48 * i);

		gameMenuLayer:addChild(itemBack)
		gameMenuLayer:addChild(itemFont)
		i = i + 1;
		j = j + 1;

		table.insert(itemButtonList, itemBack)
	end



	local backButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	backButton:setContentSize(CCSizeMake(640, 48));
	backButton:setPosition(ccp(320, 24));

	local backFont = CCLabelBMFont:create("Back", FONT );
	backFont:setPosition(ccp(320,24));


	gameMenuLayer:addChild(backButton);	
	gameMenuLayer:addChild(backFont);

	local descButton = CCScale9Sprite:createWithSpriteFrameName("menu_background.png", CCRectMake(32,32,32,32));
	descButton:setContentSize(CCSizeMake(640, 48));
	descButton:setPosition(ccp(320, 336));
	
	local descFont = CCLabelBMFont:create("Desc", FONT );
	descFont:setPosition(ccp(320,336));

	gameMenuLayer:addChild(descButton);
	gameMenuLayer:addChild(descFont);

	
	--local sliderBackground = CCSprite:createWithSpriteFrameName("slider_thumb.png");
	--local sliderThumb = CCSprite:createWithSpriteFrameName("slider_background.png");
	--local sliderTrack = CCSprite:createWithSpriteFrameName("slider_background.png");
	local slider = CCControlSlider:create("sprites/sliderTrack.png", "sprites/sliderTrack.png", "sprites/sliderThumb.png");
	slider:setPosition(400, 200 );
	slider:setMinimumValue(0);
	slider:setMaximumValue(10);
	slider:setValue(0);
	slider:setScale(0.5);
	slider:setRotation(90);

	

	local function sliderCallback()
		cclog("hey");
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
			initMenuPage()
		end
		for k, v in pairs(itemButtonList) do
			if checkWithin( v, x, y ) then
				cclog("test");
				--v:setDisplayFrame(CCSpriteFrameCache:sharedSpriteFrameCache():spriteFrameByName("menu_background_selected.png"));
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

