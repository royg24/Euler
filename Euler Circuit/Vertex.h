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
	friend class DirectedGraph;
	friend class UnDirectedGrapgh;
	void visit(Vertex& v)
	{
		v.used = true;
		for (auto it = v.neighbors.begin(); it != v.neighbors.end(); it++)
		{
			if (!(*it)->used)
			{
				visit(**it);
			}
		}
	}
};