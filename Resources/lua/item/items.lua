function use_potion(party_slot, item_bag, item_slot)
	cclog("use_potion executing");
	Player:getInstance():getParty():getCharacterAtSlot(party_slot):heal(10);
	Player:getInstance():getInventory():discardItem(item_bag, item_slot);
end

function use_plain_water(party_slot, item_bag, item_slot)
	cclog("plain_water executing");
	Player:getInstance():getParty():getCharacterAtSlot(party_slot):damage(10);
	Player:getInstance():getInventory():discardItem(item_bag, item_slot);
end

function equip_armor(party_slot, item_bag, item_slot)
	c = Player:getInstance():getParty():getCharacterAtSlot(party_slot);
	i = Player:getInstance():getInventory();
	lhs = i:getItemByIndex(item_bag, item_slot);
	rhs = c:getArmor();
	cclog("plain_water executing");
	if c:equipArmor(lhs) == 1 then
		i:discardItem(item_bag, item_slot);
		i:addItem(rhs, item_bag, item_slot);
		return 1;
	else
		return 0;
	end
end

function equip_weapon(party_slot, item_bag, item_slot)
	c = Player:getInstance():getParty():getCharacterAtSlot(party_slot);
	i = Player:getInstance():getInventory();
	lhs = i:getItemByIndex(item_bag, item_slot);
	rhs = c:getWeapon();
	
	if c:equipWeapon(lhs) == true then
		i:discardItem(item_bag, item_slot);
		i:addItem(rhs, item_bag, item_slot);
		return 1;
	else
		return 0;
	end
end