#include <iostream>
#include "DirectedGraph.h"
#include "UnDirectedGraph.h"
using namespace std;

void main()
{
	list<int> l1 = { 2,3 };
	list<int> l2 = { 3 };
	list<int> l3{ 4 };
	list<int> l4{};
	vector<list<int>> v = { {}, l1, l2, l3, l4 };

	UnDirectedGraph g1(4, 4, v);
	bool b = g1.areAllDegreesEven();
}