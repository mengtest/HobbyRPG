local START_FRIENDLY_POS_X = 400
local START_FRIENDLY_POS_Y = 200
local OFFSET_FRIENDLY_POS_X = 50
local OFFSET_FRIENDLY_POS_Y = 50

local START_ENEMY_POS_X = 200
local START_ENEMY_POS_Y = 200
local OFFSET_ENEMY_POS_X = 50
local OFFSET_ENEMY_POS_Y = 50

-- for calculation
local player_count = 0;
local enemy_count = 0;
function battle_calculate_entity_position(entity)
    local is_enemy = entity:getIsEnemy();
    if is_enemy == true then
        entity:setPosition(ccp(START_ENEMY_POS_X + OFFSET_ENEMY_POS_X * enemy_count, 
                               START_ENEMY_POS_Y + OFFSET_ENEMY_POS_Y * enemy_count)
        enemy_count = enemy_count + 1;
    else
        entity:setPosition(ccp(START_FRIENDLY_POS_X + OFFSET_FRIENDLY_POS_X * player_count, 
                               START_FRIENDLY_POS_Y + OFFSET_FRIENDLY_POS_Y * player_count)
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

