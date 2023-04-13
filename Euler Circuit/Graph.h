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
	//c'tor
	Graph(int numOfVertexes = 0, int numOfEdges = 0, const vector<list<int>>& neighbor = {});
	//gettim
	int getNumOfVertexes();
	int getNumOfEdges();
	vector<Vertex*>& getVertexes();
	void visit(Vertex& v);
	virtual bool isGraphEulerian() = 0;
	// assume that the graph is eulerian
	void findEulerCircuit(list<int>& EulerCircuit);
	//finds a general circuit
	void findCircuit(Vertex& v, list<int>& res);
	virtual void markEdge(Vertex& v, Vertex& u);
	void findPath(Vertex& v, Vertex& u, list<int>& L);
	bool isVisitAllVertexes();
	void unUsedAllVertexes();
	void printEulerCircuit(list<int> Euler);
	~Graph();
	
};
