#pragma once
#include "Graph.h"

class DirectedGraph : public Graph
{
public:
	DirectedGraph(int numOfVertexes, int numOfEdges, vector<list<Vertex>>& neighbor);
	bool isGraphStronglyConnected();
	bool isInDegreeEqualsToOutDegreeInEachVertex();
	virtual bool isGraphEulerian();
	virtual list<Vertex*>& findEulerCircuit(Vertex& v);
	DirectedGraph& createGT();
	
};