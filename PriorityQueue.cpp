#include "PriorityQueue.h"

using namespace std;

// Pops out the queue item at top
void PriorityQueue::minPriority() {
	pq.pop();
}

// Instert an item to Queue
void PriorityQueue::insertElement(int element, int distance) {
	pq.push(make_pair(element,distance));
}

// Return the top element in the Queue
int PriorityQueue::returnTop() {
	return pq.top().second;
}


//Returns the size of the queue
int PriorityQueue::returnSize() {
	return pq.size();
}


// Prints the elements in the queue
void PriorityQueue::printElements() {
	while (!pq.empty()) {
		cout << pq.top().second << "\n";
		pq.pop();
	}
}

// Pops an element from the queue
void PriorityQueue::popElement()
{
	pq.pop();
}


