// collection of helper functions

#ifndef __COMMON_H__
#define __COMMON_H__

#include <vector>
#include <string>
#include <fstream>

class Common
{
public:
	static bool openCSV( const std::string& filename, std::vector< std::vector< std::string > >& result );
	static std::vector<std::string> explode( const std::string& str, const char& ch );

	static float getNormalizedPositionX( float norm );
	static float getNormalizedPositionY( float norm );

	static float getGameWidth();
	static float getGameHeight();

	template <typename T> 
	static T linearLerp( T start, T end, float time, float duration )
	{
		float alpha = time/duration;
		return (1 - alpha) * start + alpha * end;
	}

	static int init();


private:
	static int loadGraphics();
	static int loadLuas();
		static int loadLua(const std::string& filename);

};


#endif //__COMMON_H__