#pragma once
#include "Graph.h"

class DirectedGraph : public Graph
{
public:
	DirectedGraph(int numOfVertexes = 0, int numOfEdges = 0, const vector<list<int>>& neighbor = {});
	bool isGraphStronglyConnected();
	bool isInDegreeEqualsToOutDegreeInEachVertex();
	virtual bool isGraphEulerian();
	virtual list<Vertex*>& findEulerCircuit(Vertex& v);
	DirectedGraph& buildGT();
	void visit(Vertex& v);
	list<Vertex*> findCircuit(Vertex& v);

};