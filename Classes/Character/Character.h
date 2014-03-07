#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <vector>
#include <string>

#include "..\Enum\StatsEnum.h"
#include "..\Enum\CharacterInfoEnum.h"
#include "..\Enum\ItemEnum.h"

class Character
{
public:
	Character();
	~Character();
	 
	bool init( const std::string& name );

	void setLevel( int level ); 

	bool equipWeapon( ItemEnum item );
	bool equipArmor( ItemEnum item );
	bool equipRing( ItemEnum item );

	bool unequipWeapon();
	bool unequipArmor();
	bool unequipRing();

	void heal( int amount );
	void damage( int amount );


	// gettors
	int getStat( StatsEnum type ) const;
	const std::vector< int > & getAllStats() const;
	std::string getInfo( CharacterInfoEnum type ) const { return m_info[0][type]; }
	const std::vector< std::string >& getAllInfo() const { return m_info[0]; }
	inline int getCurrentHP() { return m_currentHP; }
	inline ItemEnum getWeapon() { return m_weapon; }
	inline ItemEnum getArmor() { return m_armor; }
	inline ItemEnum getRing() { return m_ring; }
	
private:
	// stores all data in csv
	std::vector< std::vector < std::string > > m_data;
	std::vector < int > m_stats;
	std::vector< std::vector < std::string > >  m_info;

	int m_currentHP;

	void regulateHP();

	// Equipments
	ItemEnum m_weapon;
	ItemEnum m_armor;
	ItemEnum m_ring;
};


#endif