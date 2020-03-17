#include "PriorityQueue.h"

using namespace std;

void PriorityQueue::minPriority() {
	pq.pop();
}

bool PriorityQueue::contains(int element) {
	return true;
}

void PriorityQueue::insertElement(int element) {
	pq.push(element);
}

int PriorityQueue::returnTop() {
	return pq.top();
}

int PriorityQueue::returnSize() {
	return pq.size();
}

void PriorityQueue::printElements() {
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}


