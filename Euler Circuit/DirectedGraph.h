#pragma once
#include "Graph.h"

class DirectedGraph : public Graph
{
public:
	DirectedGraph(int numOfVertexes = 0, int numOfEdges = 0, const vector<list<int>>& neighbor = {});
	bool isGraphStronglyConnected();
	bool isInDegreeEqualsToOutDegreeInEachVertex();
	virtual bool isGraphEulerian();
	DirectedGraph& buildGT();
	void markEdge(Vertex& v, Vertex& u);
	friend class GraphBuilder;
};