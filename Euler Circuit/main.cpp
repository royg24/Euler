#include <iostream>
#include "DirectedGraph.h"
#include "UnDirectedGraph.h"
using namespace std;

void main()
{
	UnDirectedVertex v1(1);
	UnDirectedVertex v2(2);
	UnDirectedVertex v3(3);
	UnDirectedVertex v4(4);
	list<Vertex*> l1 = { &v2,&v3 };
	list<Vertex*> l2 = { &v3 };
	list<Vertex*> l3{ &v4 };
	list<Vertex*> l4{};
	vector<list<Vertex*>> v = { {}, l1, l2, l3, l4 };

	UnDirectedGraph g1(4, 4, v);
	bool b = g1.areAllDegreesEven();
}