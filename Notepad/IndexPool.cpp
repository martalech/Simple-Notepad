#include "stdafx.h"
#include "IndexPool.h"

IndexPool::IndexPool(): pool(1000, false), notTaken(0)
{
}

IndexPool::~IndexPool()
{
	pool.clear();
}

int IndexPool::takeIndex()
{
	if (notTaken == pool.size())
		pool.resize(pool.size() * 2, false);
	int index = notTaken;
	pool[notTaken] = true;
	std::vector<bool>::iterator currentPosition = pool.begin() + notTaken;
	notTaken = distance(pool.begin(), std::find(currentPosition, pool.end(), false));
	return index;
}

void IndexPool::releaseIndex(int n)
{
	pool[n] = false;
	if (n < notTaken)
		notTaken = n;
}

