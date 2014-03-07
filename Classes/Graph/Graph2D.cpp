#include "Graph2D.h"

#define FOREACH_ADJ for ( unsigned i = 0; i < m_adj.size(); ++i ) for ( unsigned j = 0; j < m_adj[i].size(); ++j )
    
//returns id of the node
int Graph2D::addNode(float x, float y, float z)
{
    m_nodes.push_back(GraphNode(x,y,z));

	// add column
	for ( unsigned i = 0; i < m_adj.size(); ++i ) {
		m_adj[i].push_back(0);
	}
	
	//add new row
	m_adj.push_back( std::vector< int >(m_adj.size()) );
	m_adj[m_adj.size()-1].resize(m_adj.size(), 0);


    return m_nodes.size() - 1;
}
    
// returns the node itself
GraphNode& Graph2D::getNode(int id)
{
    return m_nodes[id];
}
    
void Graph2D::setAdj(int to, int from, bool double_sided)
{
    m_adj[to][from] = 1;
    if ( double_sided ) {
        m_adj[from][to] = 1;
    }
}

void Graph2D::setAdjAll()
{
    FOREACH_ADJ
    {
        m_adj[i][j] = 1;
    }
}

void Graph2D::clearAjd(int to, int from, bool double_sided)
{
	m_adj[to][from] = 0;
	if ( double_sided ) {
        m_adj[from][to] = 0;
    }
}

void Graph2D::clearAdjAll()
{
    FOREACH_ADJ
    {
        m_adj[i][j] = 0;
    }
}
    
//removes node based on id
/*void Graph2D::removeNode(int id)
{
}*/