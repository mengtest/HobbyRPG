#ifndef __GRAPH_2D_H__
#define __GRAPH_2D_H__

#include <vector>
#include "GraphNode.h"

//simple 2D graph
class Graph2D
{
public:
    Graph2D() {}
    ~Graph2D() {} 
    
    //returns id of the node
    int addNode(float x = 0.f, float y = 0.f, float z = 0.f);
    
    // returns the node itself
    GraphNode& getNode(int id);
    
    //removes node based on id
    //void removeNode(int id);
    
    void setAdj(int to, int from, bool double_sided);
    void setAdjAll();
    void clearAjd(int to, int from, bool double_sided);
    void clearAdjAll(); 

	const std::vector< std::vector< int > >& getAdjMatrix() { return m_adj; }
	const std::vector< GraphNode >& getGraph() { return m_nodes; }
    
private:
    std::vector< std::vector< int > > m_adj;
    
    // they are not that big so non-pointer is fine
    // note that userData in GraphNode is shallow copy though...
    std::vector< GraphNode > m_nodes; 
   
};

#endif