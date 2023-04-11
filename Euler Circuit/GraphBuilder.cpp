#include "GraphBuilder.h"

GraphBuilder::GraphBuilder(char type, int numOfVertexes, int numOfEdges) : type(type), numOfVertexes(numOfVertexes), numOfEdges(numOfEdges)
{
	try
	{
		isDataVaild();
	}
	catch (const char* msg)
	{
		throw msg;
	}
}
void GraphBuilder::isDataVaild()
{
	int maxNumOfEdgesForUnDirectedGraph = numOfVertexes * (numOfVertexes - 1) / 2; // nCr
	int maxNumOfEdgesForDirectedGraph = numOfVertexes * (numOfVertexes - 1);
	if (type != 'n' && type != 'y')
	{
		throw("type can be only n or y");
	}
	if (numOfVertexes < 0 || numOfEdges < 0)
	{
		throw("Amount of edges and vertexes cannot be a negative number!");
	}
	else if (type == Directed && numOfEdges > maxNumOfEdgesForDirectedGraph)
	{
		throw("This amount of edges is to big for a directed graph!");
	}
	else if (type == UnDirected && numOfEdges > maxNumOfEdgesForUnDirectedGraph)
	{
		throw("This amount of edges is to big for an undirected graph!");
	}
}
Graph* GraphBuilder::BuildGraph()
{
	pair<int, int> edge;
	vector<list<int>> neighbors;
	Graph* res;
	neighbors.resize(numOfVertexes + 1);
	for (int i = 0; i < numOfEdges; i++)
	{
		cin >> edge.first;
		cin >> edge.second;
		if (isEdgeValid(edge))
		{
			neighbors[edge.first].push_back(edge.second);
		}
		else
		{
			throw("Edge values cannot be bigger than the amount of vertexes");
		}
	}
	if (type == Directed)
	{
		res = new DirectedGraph(numOfVertexes, numOfEdges, neighbors);
	}
	else
	{
		res = new UnDirectedGraph(numOfVertexes, numOfEdges, neighbors);
	}
	return res;
}
bool GraphBuilder::isEdgeValid(pair<int, int> edge)
{
	if (edge.first > numOfVertexes || edge.second > numOfVertexes)
	{
		return false;
	}
	return true;
}
DirectedGraph* GraphBuilder::BuildDirectedGraph()
{
	DirectedGraph* res = dynamic_cast<DirectedGraph*>(BuildGraph());
	return res;
}
UnDirectedGraph* GraphBuilder::BuildUnDirectedGraph()
{
	UnDirectedGraph* res = dynamic_cast<UnDirectedGraph*>(BuildGraph());
	return res;
}