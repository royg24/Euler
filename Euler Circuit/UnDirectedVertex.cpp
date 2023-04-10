#include "UnDirectedVertex.h"

UnDirectedVertex::UnDirectedVertex(int num) : Vertex(num)
{

}
bool UnDirectedVertex::isDegreeEven()
{
	return !(degree % 2);
}