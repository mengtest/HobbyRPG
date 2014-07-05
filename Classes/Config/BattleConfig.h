#ifndef __BATTLE_CONFIG_H__
#define __BATTLE_CONFIG_H__

class BattleConfig
{
public:
	static BattleConfig& getInstance();

	inline bool isDebug() { return m_bIsDebug; }
	inline bool isLogging() { return m_bIsLogging; }
	inline bool isOutputLog() { return m_bIsOutputLog; }

	inline int getDesignWidth() { return m_nDesignWidth; }
	inline int getDesignHeight() { return m_nDesignHeight; }
    
    inline int getEncounterRate() { return m_nEncounterRate; }

private:
	bool m_bIsDebug;
	bool m_bIsLogging;
	bool m_bIsOutputLog;

	int m_nDesignWidth;
	int m_nDesignHeight;
	
    int m_nEncounterRate;

	// Singleton Stuff
	BattleConfig();
	BattleConfig( const BattleConfig&  ) {};
	~BattleConfig() {};
	void operator=( const BattleConfig&  ) {};
};

#endif