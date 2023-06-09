#pragma once
#include "Graph.h"
#include "UnDirectedVertex.h"

class UnDirectedGraph : public Graph
{
public:
	UnDirectedGraph(int numOfVertexes = 0, int numOfEdges = 0, const vector<list<int>>& neighbor = {});
	bool isGraphConnected();
	bool areAllDegreesEven();
	virtual bool isGraphEulerian();
	virtual void markEdge(Vertex& v, Vertex& u);
	friend class GraphBuilder;
};
