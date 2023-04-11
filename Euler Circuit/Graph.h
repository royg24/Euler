#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Vertex.h"
using namespace std;
class Graph
{
protected:
	int numOfVertexes = 0;
	int numOfEdges = 0;
	vector<Vertex*> vertexes;
public:
	//gettim
	int getNumOfVertexes();
	int getNumOfEdges();
	vector<Vertex*>& getVertexes();

	void visit(Vertex& v);
	virtual bool isGraphEulerian() = 0;
	// assume that the graph is eulerian
	virtual list<Vertex*>& findEulerCircuit(Vertex& v) = 0;
	//finds a general circuit
	list<Vertex*>& findCircuit(Vertex& v);
	virtual void markEdge(const Vertex& v);
	
};
