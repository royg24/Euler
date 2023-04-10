#include "Graph.h"

//gettim
int Graph::getNumOfVertexes()
{
	return numOfVertexes;
}
int Graph::getNumOfEdges()
{
	return numOfEdges;
}
vector<list<Vertex*>>& Graph::getNeighbors()
{
	return neighbors;
}

void Graph::visit(Vertex& v)
{

}
list<Vertex*>& Graph::findCircuit(Vertex& v)
{
	
}