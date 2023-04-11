#pragma once
#include "Graph.h"

class DirectedGraph : public Graph
{
public:
	DirectedGraph(int numOfVertexes, int numOfEdges, const vector<list<Vertex*>>& neighbor);
	bool isGraphStronglyConnected();
	bool isInDegreeEqualsToOutDegreeInEachVertex();
	virtual bool isGraphEulerian();
	virtual list<Vertex*>& findEulerCircuit(Vertex& v);
	DirectedGraph& buildGT();
	void visit(Vertex& v);
	list<Vertex*> findCircuit(Vertex& v);

};