#pragma once
#include<list>
using namespace std;
class Vertex
{
protected:
	int numOfVertex;
	list<Vertex*> neighbors;
	bool used = false;
	Vertex* pos = nullptr;
	Vertex(int num) : numOfVertex(num) {}
public:
	virtual ~Vertex(){}
	friend class UnDirectedGraph;
	friend class DirectedGraph;
};