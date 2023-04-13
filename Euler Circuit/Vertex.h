#pragma once
#include<list>
using namespace std;
class Vertex
{
protected:
	int numOfVertex;
	list<Vertex*> neighbors;
	list<Vertex*>::iterator pos;
	bool used = false;
	Vertex(int num) : numOfVertex(num) {}
public:
	virtual ~Vertex(){}
	int getNumOfVertex() { return numOfVertex; }
	bool operator==(const Vertex& v) { return numOfVertex == v.numOfVertex; }
	friend class DirectedGraph;
	friend class UnDirectedGraph;
	friend class Graph;
};