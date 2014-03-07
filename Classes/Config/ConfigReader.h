#ifndef __CONFIGREADER_H__
#define __CONFIGREADER_H__

#include <string>
#include <fstream>
#include <map>

const std::string DEFAULT_DIR = "config/";
class ConfigReader
{
public:
	static ConfigReader& getInstance();

	void load( const std::string& file, const std::string& directory = DEFAULT_DIR);

	// Never EVER call this function on update loops or render loops.
	// Instead, store it somewhere else and then use it.
	const std::string& get(const std::string& file, const std::string& key);
private:
	ConfigReader();
	ConfigReader( const ConfigReader&  ) {};
	~ConfigReader();
	void operator=( const ConfigReader&  ) {};

	// m_ConfigReader stuff should NEVER be changed at all
	typedef std::map< std::string, std::string> ConfigReaderContainer;
	
	std::map< std::string, ConfigReaderContainer > m_ConfigReaders;

	
};


#endif //__CONFIGREADER_H__