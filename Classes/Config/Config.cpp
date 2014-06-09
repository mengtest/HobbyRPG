#include <string>
#include <stdlib.h>

#include "Config.h"
#include "ConfigReader.h"

using namespace std;

Config::Config()
{
	ConfigReader& config_reader = ConfigReader::getInstance();
	config_reader.load("HobbyRPG");
	
	// Initialize globals
	string tempStr = config_reader.get("HobbyRPG", "DEBUG");
	this->m_bIsDebug = ( tempStr.compare("TRUE") == 0 ) ? true : false;

	tempStr = config_reader.get("HobbyRPG", "LOG");
	this->m_bIsLogging = ( tempStr.compare("TRUE") == 0 ) ? true : false;

	tempStr = config_reader.get("HobbyRPG", "OUTPUT_LOG");
	this->m_bIsLogging = ( tempStr.compare("TRUE") == 0 ) ? true : false;

	tempStr = config_reader.get("HobbyRPG", "DESIGN_WIDTH");
	this->m_nDesignWidth = atoi(tempStr.c_str());

	tempStr = config_reader.get("HobbyRPG", "DESIGN_HEIGHT");
	this->m_nDesignHeight = atoi(tempStr.c_str());

	tempStr = config_reader.get("HobbyRPG", "ENCOUNTER_RATE");
	this->m_nEncounterRate = atoi(tempStr.c_str());

}

Config& Config::getInstance()
{
	static Config instance;
	return instance;
}

