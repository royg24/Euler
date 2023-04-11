#pragma once
#include "DirectedGraph.h"
#include "UnDirectedGraph.h"
#include <utility>
#include <iostream>
#include <map>

class GraphBuilder
{
private:
	char type;
	int numOfVertexes;
	int numOfEdges;
	enum eGraphType
	{
		Directed = 'y',
		UnDirected = 'n'
	};
public:
	GraphBuilder(char type, int numOfVertexes, int numOfEdges) noexcept(false);
	void isDataVaild() noexcept(false);
	Graph* BuildGraph() noexcept(false);
	bool isEdgeValid(pair<int, int> edge);
	DirectedGraph* BuildDirectedGraph();
	UnDirectedGraph* BuildUnDirectedGraph();
};
