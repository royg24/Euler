#include <iostream>
#include "DirectedGraph.h"
#include "UnDirectedGraph.h"
#include "GraphBuilder.h"
using namespace std;

int main(void)
{
	try
	{
		char type;
		int n, m;
		cout << "Is the graph directed: y/n" << endl;
		cin >> type;
		cin >> n;
		cin >> m;

		GraphBuilder gb(type, n, m);
		list<int> res;
		if (type == 'y')
		{
			//directed graph
			DirectedGraph* g = gb.BuildDirectedGraph();
			// check if graph eulerian
			if (g->isGraphEulerian())
			{
				g->findEulerCircuit(res);
				g->printEulerCircuit(res);
			}
			else
			{
				cout << "The graph is not aulerian" << endl;
			}
			delete(g);
		}
		else
		{
			//undirected graph
			UnDirectedGraph* ug = gb.BuildUnDirectedGraph();
			if (ug->isGraphEulerian())
			{
				ug->findEulerCircuit(res);
		
				ug->printEulerCircuit(res);
			}
			else
			{
				cout << "The graph is not aulerian" << endl;
			}
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
		cout << "invalid input" << endl;
		exit(1);
	}
	return 0;
}