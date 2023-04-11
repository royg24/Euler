#include <iostream>
#include "DirectedGraph.h"
#include "UnDirectedGraph.h"
#include "GraphBuilder.h"
using namespace std;

int main(void)
{
	//list<int> l1 = { 2,3 };
	//list<int> l2 = { 3 };
	//list<int> l3{ 4 };
	//list<int> l4{ 1 };
	//vector<list<int>> v = { {}, l1, l2, l3, l4 };
	//DirectedGraph g1(4, 4, v);
	try
	{
		char type;
		int n, m;
		cout << "Is graph directec y/n" << endl;
		cin >> type;
		cout << "Enter the number of vertexes in graph" << endl;
		cin >> n;
		cout << "Enter the number of edges in graph" << endl;
		cin >> m;

		GraphBuilder gb(type, n, m);
		if (type == 'y')
		{
			//directed graph
			DirectedGraph* g = gb.BuildDirectedGraph();

			delete(g);
		}
		else
		{
			//undirected graph
			UnDirectedGraph* ug = gb.BuildUnDirectedGraph();

			delete(ug);
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		exit(1);
	}
	catch (...)
	{
		cout << "invalid input!" << endl;
		exit(1);
	}
	return 0;
}