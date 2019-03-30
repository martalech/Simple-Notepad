#pragma once

class IndexPool
{
public:
	IndexPool();
	~IndexPool();

	void releaseIndex(int n);
	int takeIndex();
	int getNotTaken() { return notTaken; }
private:
	std::vector<bool> pool;
	int notTaken;
};

