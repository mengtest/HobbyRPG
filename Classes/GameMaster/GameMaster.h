#ifndef __GameMaster_H__
#define __GameMaster_H__

class OverworldScene;
class GameMaster
{
public:
	static GameMaster& getInstance();
	static void destroy(); // MUST call this first AFTER using

	bool startGame();
	
	
private:
		


	// Singleton Stuff
	GameMaster();
	GameMaster( const GameMaster&  ) {};
	~GameMaster() {};
	void operator=( const GameMaster&  ) {};
};

#endif
