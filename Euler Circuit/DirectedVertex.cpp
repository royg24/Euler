#include "DirectedVertex.h"

bool DirectedVertex::isInAndOutDegEqual()
{
	bool res;
	if (inDegree == outDegree)
	{
		res = true;
	}
	else
	{
		res = false;
	}
	return res;
}