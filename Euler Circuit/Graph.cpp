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

void Graph::visit(Vertex& v)
{

}
list<Vertex*>& Graph::findCircuit(Vertex& v)
{
	list<Vertex*> circuitFound = {&v};
	Vertex* pv = &v;
}

 void Graph::markEdge(Vertex& v)
{
	 
}