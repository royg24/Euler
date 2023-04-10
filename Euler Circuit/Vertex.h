#pragma once
class Vertex
{
protected:
	int numOfVertex;
	Vertex(int num) : numOfVertex(num) {}
	friend class Graph;
};