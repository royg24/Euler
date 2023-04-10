#pragma once
#include  "Vertex.h"
class DirectedVertex : public Vertex
{
private:
	int inDegree = 0;
	int outDegree = 0;
public:
	DirectedVertex(int num);
	bool isInAndOutDegEqual();
	friend class DirectedGraph;
};