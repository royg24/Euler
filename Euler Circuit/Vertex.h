#pragma once
#include<list>
using namespace std;
class Vertex
{
protected:
	int numOfVertex;
	list<Vertex*> neighbors;
	Vertex* pos = nullptr;
	bool used = false;
	Vertex(int num) : numOfVertex(num) {}
public:
	virtual ~Vertex(){}
	friend class DirectedGraph;
	friend class UnDirectedGraph;
};