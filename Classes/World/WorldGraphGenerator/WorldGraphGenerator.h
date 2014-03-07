#ifndef __WORLD_GRAPH_GENERATOR_H__
#define __WORLD_GRAPH_GENERATOR_H__

#include "..\..\Graph\Graph2D.h"

// class used to auto generate graph for the world
// in case you don't really want to design your class 
class WorldGraphGenerator
{
public:
	static Graph2D GenerateGraph(int width, int height);

private:
	WorldGraphGenerator() {}
	WorldGraphGenerator(const WorldGraphGenerator& ) {}
	~WorldGraphGenerator() {}

};



#endif