#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <vector>
#include <string>


class Character
{
public:
	Character();
	~Character();
	 
	bool init( const std::string& name );

	void setLevel( int level ); 

	inline void setCurrentHP(int hp) { m_currentHP = hp; }

	bool equipWeapon( int item );
	bool equipArmor( int item );
	bool equipRing( int item );

	bool unequipWeapon();
	bool unequipArmor();
	bool unequipRing();

	// gettors
	int getStat( int type ) const;
	const std::vector< int > & getAllStats() const;
	const std::string& getInfo( int type ) const { return m_info[0][type]; }
	const std::vector< std::string >& getAllInfo() const { return m_info[0]; }
	inline int getCurrentHP() { return m_currentHP; }
	inline int getWeapon() { return m_weapon; }
	inline int getArmor() { return m_armor; }
	inline int getRing() { return m_ring; }
	
private:
	// stores all data in csv
	std::vector< std::vector < std::string > > m_data;
	std::vector < int > m_stats;
	std::vector< std::vector < std::string > >  m_info;

	int m_currentHP;

	void regulateHP();

	// Equipments
	int m_weapon;
	int m_armor;
	int m_ring;
};


#endif