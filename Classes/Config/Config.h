#ifndef __CONFIG_H__
#define __CONFIG_H__

class Config
{
public:
	static Config& getInstance();

	inline bool isDebug() { return m_bIsDebug; }
	inline bool isLogging() { return m_bIsLogging; }
	inline bool isOutputLog() { return m_bIsOutputLog; }

	inline int getDesignWidth() { return m_nDesignWidth; }
	inline int getDesignHeight() { return m_nDesignHeight; }

private:
	bool m_bIsDebug;
	bool m_bIsLogging;
	bool m_bIsOutputLog;

	int m_nDesignWidth;
	int m_nDesignHeight;
	

	// Singleton Stuff
	Config();
	Config( const Config&  ) {};
	~Config() {};
	void operator=( const Config&  ) {};
};

#endif