#include "Graph.h"

Graph::Graph(int numOfVertexes, int numOfEdges, const vector<list<int>>& neighbor)
{
	this->numOfVertexes = numOfVertexes;
	this->numOfEdges = numOfEdges;
	vertexes.resize(numOfVertexes + 1);
}
//gettim
int Graph::getNumOfVertexes()
{
	return numOfVertexes;
}
int Graph::getNumOfEdges()
{
	return numOfEdges;
}
vector<Vertex*>& Graph::getVertexes()
{
	return vertexes;
}

//TODO
//list<Vertex*>& Graph::findCircuit(const Vertex& v)
//{
//	
//}

//TODO
 void Graph::markEdge(Vertex& v, Vertex& u)
{
	 (u.used) = true;
}

 Graph::~Graph()
 {
	 for (int i = 0; i < numOfVertexes; i++)
	 {
		 list<Vertex*>::iterator itr = vertexes[i]->neighbors.begin();
		 	list<Vertex*>::iterator itrEnd = vertexes[i]->neighbors.end();
		 	for (; itr != itrEnd; ++itr)
		 	{
		 		delete(*itr);
		 	}
		 delete(vertexes[i]);
	 }
 }

 void Graph::findCircuit(Vertex& v, list<int>& res)
 {
	 //assume graph is eulerian and hence it always succeses
	 Vertex* u = (*v.pos);
	 res = { v.numOfVertex, u->numOfVertex };
	 markEdge(*vertexes[v.numOfVertex], *u);
	 findPath(*u, v, res);
 }
 void Graph::findPath(Vertex& start, Vertex& end, list<int>& L)
 {
	 if (start == end)
	 {
		 return;
	 }
	 else
	 {
		 list<Vertex*>::iterator next = vertexes[start.numOfVertex]->pos;
		 while ((*next)->used)
		 {
			 vertexes[start.numOfVertex]->pos++;
			 next++;
		 }
		 markEdge(*vertexes[start.numOfVertex], **next);
		 L.push_back((*next)->numOfVertex);
		 findPath((**next), end, L);
	 }
 }
 void Graph::visit(Vertex& v)
 {
	 //Vertex* curr = vertexes[v.numOfVertex];
	 vertexes[v.numOfVertex]->used = true;
	 //curr->used = true;
	 for (auto it = vertexes[v.numOfVertex]->neighbors.begin(); it != vertexes[v.numOfVertex]->neighbors.end(); ++it)
	 {
		 if (!(vertexes[(*it)->numOfVertex])->used)
		 {
			 visit(*vertexes[(*it)->numOfVertex]);
		 }
	 }
 }
 void Graph::findEulerCircuit(list<int>& EulerCircuit)
 {
	 findCircuit(*vertexes[1], EulerCircuit);
	 list<int>::const_iterator itr = EulerCircuit.begin();
	 list<int>::const_iterator itrEnd = EulerCircuit.end();
	 list<int>::const_iterator circuitBegin;
	 for (; itr != itrEnd; ++itr)
	 {
		 list<int> localCircuit = {};
		 if ((vertexes[*itr]->pos == vertexes[*itr]->neighbors.end()) ||!(*vertexes[*itr]->pos == vertexes[*itr]->neighbors.back()))
		 {
			 findCircuit(*vertexes[*itr], localCircuit);
			 localCircuit.erase(localCircuit.begin());
			 circuitBegin = itr;
			 EulerCircuit.splice(++circuitBegin, localCircuit);
			 if (EulerCircuit.size() == numOfEdges + 1)
			 {
				 break;
			 }
		 }
	 }
 }
 bool Graph::isVisitAllVertexes()
 {
	 visit(*vertexes[1]);
	 for (auto it = vertexes.begin() + 1; it != vertexes.end(); ++it)
	 {
		 if (!(*it)->used)
		 {
			 return false;

		 }
	 }
	 return true;
 }
 void Graph::unUsedAllVertexes()
 {
	 for (auto it = vertexes.begin(); it != vertexes.end(); ++it)
	 {
		 Vertex* v = *it;
		 v->used = false;
	 }
 }
 void Graph::printEulerCircuit(list<int> Euler)
 {
	 list<int>::iterator itr = Euler.begin();
	 list<int>::iterator itrEnd = Euler.end();
	 cout << "The graph is aulerian" << endl;
	 cout << "(";
	 for (int i = 0; i < Euler.size(); i++, ++itr)
	 {
		 cout << * itr;
		 if (i != Euler.size() - 1)
		 {
			 cout << ",";
		 }
	 }
	 cout << ")" << endl;;
 }