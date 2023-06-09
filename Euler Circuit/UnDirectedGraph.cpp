#include "UnDirectedGraph.h"
UnDirectedGraph::UnDirectedGraph(int numOfVertexes, int numOfEdges, const vector<list<int>>& neighbors) : Graph(numOfVertexes, numOfEdges)
{
	UnDirectedVertex* reverseVertexInVector;
	UnDirectedVertex* currentVertexInVector;
	UnDirectedVertex* reverseVertex;
	UnDirectedVertex* currentVertex;
	for (int i = 0; i <= numOfVertexes; i++)
	{
		vertexes[i] = new UnDirectedVertex(i);
	}
	for (int i = 0; i <= numOfVertexes; i++)
	{
		list<int>::const_iterator itr = neighbors[i].begin();
		for (int j = 0; j < neighbors[i].size(); j++, ++itr)
		{
			// turn vertex into undirected vertex for the array
			currentVertexInVector = dynamic_cast<UnDirectedVertex*>(vertexes[i]);
			reverseVertexInVector = dynamic_cast<UnDirectedVertex*>(vertexes[(*itr)]);
			//create the elements of the lists
			currentVertex = new UnDirectedVertex(i);
			reverseVertex = new UnDirectedVertex(*itr);
			//add each vertex to the other's neighbor
			vertexes[i]->neighbors.push_back(reverseVertex);
			vertexes[*itr]->neighbors.push_back(currentVertex);
			//update their degree
			currentVertexInVector->degree++;
			reverseVertexInVector->degree++;
			//make them point to each other
			(currentVertex->pReverseEdge) = reverseVertex;
			(reverseVertex->pReverseEdge) = currentVertex;
		}
		vertexes[i]->pos = vertexes[i]->neighbors.begin();
	}
}
bool UnDirectedGraph::isGraphConnected()
{
	bool res = isVisitAllVertexes();
	unUsedAllVertexes();
	return res;
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
void UnDirectedGraph::markEdge(Vertex& v, Vertex& u)
{
	Graph::markEdge(*vertexes[u.numOfVertex], v);
	dynamic_cast<UnDirectedVertex&>(u).pReverseEdge->used = true;
	dynamic_cast<UnDirectedVertex&>(v).pos++;
}