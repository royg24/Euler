#include "DirectedGraph.h"
#include "DirectedVertex.h"


DirectedGraph::DirectedGraph(int numOfVertexes, int numOfEdges, const vector<list<int>>& neighbor) 
{
	//TODO
}
bool DirectedGraph::isGraphStronglyConnected()
{
	//DFS start from the first vertex
	visit(*vertexes[0]);
	for (auto it = vertexes.begin(); it != vertexes.end(); ++it)
	{
		if (!(*it)->used)
			return false;
	}


	//create gT and initial all vertices
	DirectedGraph GT = buildGT();
	for (auto it = vertexes.begin(); it != vertexes.end(); ++it)
	{
		Vertex* v = *it;
		v->used = false;
	}


	//DFS from the first vertex in GT
	GT.visit(*GT.vertexes[0]);
	for (auto it = GT.vertexes.begin(); it != GT.vertexes.end(); ++it)
	{
		if (!(*it)->used)
			return false;
	}

	
	//if we visit in both graphs vertices the graph is strongly conected
	return true;
}
bool DirectedGraph::isInDegreeEqualsToOutDegreeInEachVertex()
{
	for (auto it = vertexes.begin(); it != vertexes.end(); ++it)
	{
		if (!static_cast<DirectedVertex*>(*it)->isInAndOutDegEqual())
		{
			return false;
		}
	}
}
bool DirectedGraph::isGraphEulerian()
{
	if (!isInDegreeEqualsToOutDegreeInEachVertex())
	{
		return false;
	}

	if (!isGraphStronglyConnected())
	{
		return false;
	}

	return true;
}
list<Vertex*>& DirectedGraph::findEulerCircuit(Vertex& v)
{
	//find circuit on the first vertex
	list<Vertex*> L = findCircuit(*vertexes[0]);

	//while there is vertex in L with unused edges
	while (true)
	{
		Vertex* v = nullptr;
		for(auto it= L.begin(); it != L.end(); ++it)
		{

		}
	}


}
DirectedGraph& DirectedGraph::buildGT()
{
	DirectedGraph* GT = new DirectedGraph(numOfVertexes, 0, vector<list<int>>(numOfVertexes));

	for (auto it = vertexes.begin(); it != vertexes.end(); ++it)
	{
		DirectedVertex* v = dynamic_cast<DirectedVertex*>(*it);
		for (auto secondIt = v->neighbors.begin(); secondIt != v->neighbors.end(); ++secondIt)
		{
			DirectedVertex* neighbor = dynamic_cast<DirectedVertex*> (*secondIt);
			GT->vertexes[neighbor->numOfVertex]->neighbors.push_back(GT->vertexes[v->numOfVertex]);
			GT->numOfEdges++;
			neighbor->outDegree++;
		}
		return *GT;
	}
}
list<Vertex*> DirectedGraph::findCircuit(Vertex& v)
{
	//L list will start with the first vertex
	list<Vertex*> L = { &v };
	v.used = true;


	//continue until we reach the starting vertex again
	while (L.front() != L.back())
	{
		for (auto it = L.back()->neighbors.begin(); it != L.back()->neighbors.end(); ++it)
		{
			Vertex* next = *it;
			if (!next->used)
			{
				next->used = true;
				L.push_back(next);
				break;
			}
		}
	}
	return L;
}
void DirectedGraph::visit(Vertex& v)
{

}