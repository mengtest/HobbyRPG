#include "Common.h"
#include "cocos2d.h"

#include "CCLuaEngine.h"

USING_NS_CC;
using namespace std;

bool Common::openCSV( const string& filename, vector< vector< string > >& result )
{
	if ( !CCFileUtils::sharedFileUtils()->isFileExist( filename ) ) {
		return false;
	}

	string contents;
	unsigned long fileSize = 0;
	unsigned char * fileContents = CCFileUtils::sharedFileUtils()->getFileData( filename.c_str( ) , "r", &fileSize );
	contents.append( ( char * ) fileContents );
	
	istringstream file( contents );


	string line;
	line.append((char*)fileContents);
	while ( getline(file,line,'\n'))
	{
		result.push_back(explode(line, ','));
	} 
	return true;

}


vector<string> Common::explode(const string& str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}


float Common::getNormalizedPositionX( float norm )
{
	return CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width * norm;
}

float Common::getNormalizedPositionY( float norm )
{
	return CCEGLView::sharedOpenGLView()->getDesignResolutionSize().height * norm;
}


float Common::getGameWidth()
{
	return CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width;
}

float Common::getGameHeight()
{
	return CCEGLView::sharedOpenGLView()->getDesignResolutionSize().height;
}


int Common::loadGraphics()
{
	// Sprite loading
	// Sprite‚ð“Ç‚Ýž‚Ý‚Ü‚·
	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("sprites/chika.plist");
	cache->addSpriteFramesWithFile("sprites/laksa.plist");
	cache->addSpriteFramesWithFile("sprites/prata.plist");
	cache->addSpriteFramesWithFile("sprites/world_sheet.plist");
	cache->addSpriteFramesWithFile("ui/ui_type_b.plist");
	cache->addSpriteFramesWithFile("ui/ui_menu.plist");
	
	// Animation loading
	// Animation‚ð“Ç‚Ýž‚Ý‚Ü‚·
	CCAnimationCache::sharedAnimationCache()->addAnimationsWithFile("sprites/animations.plist");
	return 1;
}

int Common::init()
{
	int ret_val = 0;
	ret_val |= loadGraphics() & 
			   loadLuas();

	return ret_val;
}

int Common::loadLuas()
{
	int ret_val = 0;
	ret_val |= loadLua("lua/common.lua") &
			   loadLua("lua/world/MainWorld.lua") &
			   loadLua("lua/item/items.lua") &
			   loadLua("lua/menu/OverworldMenu.lua") & 
			   loadLua("lua/battle/BattleFunctions.lua");

	return ret_val;
}

int Common::loadLua( const std::string& filename )
{
	string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename.c_str());
	string errorMsg ( path + " cannot be found!" );
	CCAssert( (CCFileUtils::sharedFileUtils()->isFileExist( path ) ) , errorMsg.c_str()  );
	
	if (  CCLuaEngine::defaultEngine()->executeScriptFile(path.c_str()) != 0 )
	{
		CCLOG("[OwManager][init]LUA Error: %s", path.c_str() );
		return 0;
	}

	return 1;
}

