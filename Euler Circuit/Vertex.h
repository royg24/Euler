#pragma once
#include<list>
using namespace std;
class Vertex
{
protected:
	int numOfVertex;
	list<Vertex*> neighbors;
	Vertex* pos = nullptr;
	Vertex(int num) : numOfVertex(num) {}
public:
	bool used = false;

	virtual ~Vertex(){}
	friend class Graph;
};