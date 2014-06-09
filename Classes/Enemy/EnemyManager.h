#ifndef __ENEMY_MANAGER_H__
#define __ENEMY_MANAGER_H__

#include <vector>

class EnemyManager {
public:
	static EnemyManager& getInstance();

	const std::vector< std::string >& getEnemyValues( int type );
	const std::string& getEnemyStat( int type, int stat ); 
private:
	int m_enemyTypeMax;
	std::vector< std::vector< std::string > > m_data;


	// Singleton Stuff
	EnemyManager();
	EnemyManager( const EnemyManager&  ) {};
	~EnemyManager();
	void operator=( const EnemyManager&  ) {};
};


#endif