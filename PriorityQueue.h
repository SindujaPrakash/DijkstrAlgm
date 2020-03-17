#pragma once
#include <queue>
#include <iostream>
#include <vector>

class PriorityQueue {
protected:
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

public:
	void minPriority();
	bool contains(int element);
	void insertElement(int element);
	int returnTop();
	int returnSize();
	void printElements();
};

