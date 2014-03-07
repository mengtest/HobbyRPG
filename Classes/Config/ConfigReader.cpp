#include <time.h>
#include <fstream>

#include "cocos2d.h"
#include "ConfigReader.h"

using namespace std;
USING_NS_CC;

ConfigReader::ConfigReader()
{
	
}

ConfigReader::~ConfigReader()
{
}

ConfigReader& ConfigReader::getInstance()
{
	static ConfigReader instance;
	return instance;
}

void ConfigReader::load( const string& filename, const string& directory )
{
	CCFileUtils *fileUtils = CCFileUtils::sharedFileUtils();
	
	string fileStr = directory + filename + ".config";
	
	


	std::stringstream data;

	unsigned long fileSize;
	std::string path = fileUtils->fullPathForFilename(fileStr.c_str());

	std::string errorMsg ( path + " cannot be found!" );
	CCAssert( (fileUtils->isFileExist( path ) ) , errorMsg.c_str()  );

	std::stringstream fileData;
	fileData << fileUtils->getFileData(path.c_str(), "rb", &fileSize);

	string str;
	ConfigReaderContainer tb_inserted;
	
	while ( !fileData.eof() )
	{
		getline(fileData, str);
		if ( str.empty() || str[0] == '#' || str[0] == '\r')
			continue;

		// find '='
		size_t found = str.find('=');
		CCAssert( (found != std::string::npos), "ConfigReader: '=' cannot be found");

		string key = str.substr(0, found);
		string value = str.substr(found+1, str.length() - key.length());
		tb_inserted.insert(make_pair(key, value));		
	}

	m_ConfigReaders.insert(make_pair(filename, tb_inserted));
}

const string& ConfigReader::get(const string& file, const string& key)
{
	return m_ConfigReaders.find(file)->second.find(key)->second;
}