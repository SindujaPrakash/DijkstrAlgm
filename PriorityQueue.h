// Class containing the Priority Queue Data

#include <queue>
#include <iostream>
#include <vector>
#include <utility>

class PriorityQueue {
protected:
	typedef std::pair <int, char> vertextDist;
	std::priority_queue<vertextDist, std::vector<vertextDist>, std::greater<vertextDist>> pq;

public:
	void minPriority();
	bool contains(int element);
	void insertElement(int element, int distance);
	int returnTop();
	int returnSize();
	void printElements();
	void popElement();
};

