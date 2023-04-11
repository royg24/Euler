#include "UnDirectedGraph.h"
UnDirectedGraph::UnDirectedGraph(int numOfVertexes, int numOfEdges, const vector<list<Vertex*>>& neighbors) 
{
	UnDirectedVertex* reverseVertexInVector;
	UnDirectedVertex* currentVertexInVector;
	UnDirectedVertex* reverseVertex;
	UnDirectedVertex* currentVertex;
	this->numOfVertexes = numOfVertexes;
	this->numOfEdges = numOfEdges;
	vertexes.resize(numOfVertexes + 1);
	for (int i = 0; i <= numOfVertexes; i++)
	{
		vertexes[i] = new UnDirectedVertex(i);
	}
	for (int i = 0; i <= numOfVertexes; i++)
	{
		list<Vertex*>::const_iterator itr = neighbors[i].begin();
		for (int j = 0; j < neighbors[i].size(); j++)
		{
			// turn vertex into undirected vertex for the array
			currentVertexInVector = dynamic_cast<UnDirectedVertex*>(vertexes[i]);
			reverseVertexInVector = dynamic_cast<UnDirectedVertex*>(vertexes[(*itr)->numOfVertex]);
			//create the elements of the lists
			currentVertex = new UnDirectedVertex(currentVertexInVector->numOfVertex);
			reverseVertex = new UnDirectedVertex(reverseVertexInVector->numOfVertex);
			//add each vertex to the other's neighbor
			vertexes[i]->neighbors.push_back(reverseVertex);
			vertexes[reverseVertexInVector->numOfVertex]->neighbors.push_back(currentVertex);
			//make them point to each other
			currentVertex->pReverseEdge = reverseVertex;
			reverseVertex->pReverseEdge = currentVertex;
			++itr;
		}
		currentVertexInVector->degree = currentVertexInVector->neighbors.size();
	}
}
bool UnDirectedGraph::isGraphConnected()
{
	return visit(*vertexes[1]);
}
bool UnDirectedGraph::areAllDegreesEven()
{
	UnDirectedVertex* v;
	for (int i = 1; i < numOfVertexes; i++)
	{
		v = dynamic_cast<UnDirectedVertex*>(vertexes[i]);
		if (!v->isDegreeEven())
		{
			return false;
		}
	}
	return true;
}
bool UnDirectedGraph::isGraphEulerian()
{
	return (this->isGraphConnected() && this->areAllDegreesEven());
}
list<Vertex*>& UnDirectedGraph::findEulerCircuit(Vertex& v)
{
	//TODO
	//needs to program to compile, has no meaning
	list<Vertex*> vv = {};
	return vv;
}