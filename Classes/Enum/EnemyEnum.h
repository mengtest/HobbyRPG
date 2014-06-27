#ifndef __ENEMY_ENUM_H__
#define __ENEMY_ENUM_H__

/* Auto Generated by Characters.xlsm */

class EnemyEnum {
public:
    const static EnemyEnum PORK;
    const static EnemyEnum NUM_ENEMIES;
    inline int getValue() const { return value; };
    static EnemyEnum getEnemyByIndex(int index);
private:
    int value;
    EnemyEnum(int i) : value(i) {}
};

#endif //__ENEMY_ENUM_H__