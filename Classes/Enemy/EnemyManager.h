#ifndef __ENEMY_MANAGER_H__
#define __ENEMY_MANAGER_H__

#include <vector>

#include "../Enum/EnemyStatsEnum.h"

class EnemyManager {
public:
	static EnemyManager& getInstance();

	const std::vector< std::string >& getEnemyValues( EnemyStatsEnum type );

	// TODO: replace int with actual enum type
	const std::string& getEnemyStat( int type, EnemyStatsEnum stat ); 
private:
	// Singleton Stuff
	EnemyManager();
	EnemyManager( const EnemyManager&  ) {};
	~EnemyManager() {};
	void operator=( const EnemyManager&  ) {};
};


#endif