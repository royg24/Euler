#include "DirectedGraph.h"
#include "DirectedVertex.h"


DirectedGraph::DirectedGraph(int numOfVertexes, int numOfEdges, const vector<list<int>>& neighbor) : Graph(numOfVertexes, numOfEdges)
{
	DirectedVertex* endVertex;
	DirectedVertex* startVertex;
	for (int i = 0; i <= numOfVertexes; i++)
	{
		vertexes[i] = new DirectedVertex(i);
	}
	for (int i = 1; i <= numOfVertexes; i++)
	{
		if (neighbor.empty())
		{
			break;
		}
		else
		{
			list<int>::const_iterator itr = neighbor[i].begin();
			//make vertex into directed vertex
			for (int j = 0; j < neighbor[i].size(); j++, ++itr)
			{
				startVertex = dynamic_cast<DirectedVertex*>(vertexes[i]);
				endVertex = dynamic_cast<DirectedVertex*>(vertexes[(*itr)]);
				//create neighbor for the vertex i
				vertexes[i]->neighbors.push_back(new DirectedVertex(*itr));
				//update indegree and outdegree
				(startVertex->outDegree)++;
				(endVertex->inDegree)++;
			}
			vertexes[i]->pos = vertexes[i]->neighbors.begin();
		}
	}
	
}
bool DirectedGraph::isGraphStronglyConnected()
{
	//DFS start from the first vertex
	if (!isVisitAllVertexes())
	{
		return false;
	}


	//create gT and initial all vertices
	DirectedGraph& GT = buildGT();
	unUsedAllVertexes();


	//DFS from the first vertex in GT
	if (!GT.isVisitAllVertexes())
	{
		return false;
	}


	//if we visit in both graphs vertices the graph is strongly conected
	return true;
}
bool DirectedGraph::isInDegreeEqualsToOutDegreeInEachVertex()
{
	for (auto it = vertexes.begin(); it != vertexes.end(); ++it)
	{
		if (!static_cast<DirectedVertex*>(*it)->isInAndOutDegEqual())
		{
			return false;
		}
	}
	return true;
}
bool DirectedGraph::isGraphEulerian()
{
	if (!isInDegreeEqualsToOutDegreeInEachVertex())
	{
		return false;
	}

	if (!isGraphStronglyConnected())
	{
		return false;
	}

	return true;
}
DirectedGraph& DirectedGraph::buildGT()
{
	DirectedGraph* GT = new DirectedGraph(numOfVertexes);

	for (auto it = vertexes.begin(); it != vertexes.end(); ++it)
	{
		DirectedVertex* v = dynamic_cast<DirectedVertex*>(*it);
		for (auto secondIt = v->neighbors.begin(); secondIt != v->neighbors.end(); ++secondIt)
		{
			DirectedVertex* neighbor = dynamic_cast<DirectedVertex*> (*secondIt);
			GT->vertexes[neighbor->numOfVertex]->neighbors.push_back(GT->vertexes[v->numOfVertex]);
			GT->numOfEdges++;
			neighbor = (DirectedVertex*)GT->vertexes[neighbor->numOfVertex];
			DirectedVertex* ver = dynamic_cast<DirectedVertex*> (*it);
			ver = (DirectedVertex*)GT->vertexes[v->numOfVertex];
			neighbor->outDegree++;
			ver->inDegree++;//indegree update
		}
	}
	return *GT;
}
void DirectedGraph::markEdge(Vertex& v, Vertex& u)
{
	Graph::markEdge(v, u);
	v.pos++;
}