#pragma once
#include  "Vertex.h"
class DirectedVertex : public Vertex
{
private:
	int inDegree = 0;
	int outDegree = 0;
public:
	DirectedVertex(int num) : Vertex(num), inDegree(0), outDegree(0) {}
	bool isInAndOutDegEqual();
	friend class DirectedGraph;
};