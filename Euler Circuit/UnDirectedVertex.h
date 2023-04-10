#pragma once
#include "Vertex.h"

class UnDirectedVertex : public Vertex
{
private:
	int degree = 0;
	UnDirectedVertex* pReverseEdge = nullptr;
public:
	UnDirectedVertex(int num);
	virtual bool isDegreeEven();
	friend class UnDirectedGraph;
};
