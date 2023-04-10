#pragma once
#include "Graph.h"

class UnDirectedGraph : public Graph
{
public:
	UnDirectedGraph(int numOfVertexes, int numOfEdges, vector<list<Vertex>>& neighbor);
	bool isGraphConnected();
	bool areAllDegreesEven();
	virtual bool isGraphEulerian();
	virtual list<Vertex>& findEulerCircuit(Vertex v);
};
