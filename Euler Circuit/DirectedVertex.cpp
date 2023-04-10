#include "DirectedVertex.h"
DirectedVertex::DirectedVertex(int num) : Vertex(num)
{
	
}
bool DirectedVertex::isInAndOutDegEqual()
{
	return (inDegree == outDegree);
}