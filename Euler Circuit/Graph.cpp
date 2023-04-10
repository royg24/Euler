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
list<Vertex*>& Graph::findCircuit(Vertex& v)
{
	list<Vertex*> circuitFound = {&v};
	Vertex* pv = &v;
	return circuitFound;
}

 void Graph::markEdge(Vertex& v)
{
	 
}