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
vector<Vertex*>& Graph::getVertexes()
{
	return vertexes;
}

bool Graph::visit(Vertex& v)
{
	return true;
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