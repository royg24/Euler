#include "Graph.h"

Graph::Graph(int numOfVertexes, int numOfEdges, const vector<list<int>>& neighbor)
{
	this->numOfVertexes = numOfVertexes;
	this->numOfEdges = numOfEdges;
	vertexes.resize(numOfVertexes + 1);
}
//gettim
int Graph::getNumOfVertexes()
{
	return numOfVertexes;
}
int Graph::getNumOfEdges()
{
	return numOfEdges;
}
vector<Vertex*>& Graph::getVertexes()
{
	return vertexes;
}

//TODO
//list<Vertex*>& Graph::findCircuit(const Vertex& v)
//{
//	
//}

//TODO
 void Graph::markEdge(const Vertex& v)
{
	 
}