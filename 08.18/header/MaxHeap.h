#pragma once
#include "HeapNode.h"
const int max_element = 200;

class MaxHeap {
	HeapNode node[200];
	int size;

public:
	MaxHeap() : size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == 200; }

	HeapNode getParent(int i) { return node[(i - 1) / 2]; }
	
	HeapNode getLeft(int i) { return node[i * 2 + 1]; }
	HeapNode getRight(int i) { return node[i * 2 + 2]; }

	void insert(const int key);
	HeapNode remove();
	void display();
};

void MaxHeap::insert(const int key) {
	if (isFull()) return;
	int i = size++;
	while (i != 0 && key > getParent(i).getKey()) {
		node[i] = getParent(i);
		i = (i - 1) / 2;
	}
	node[i].setKey(key);
}

HeapNode MaxHeap::remove() {
	if (isEmpty()) return NULL;

	HeapNode temp = node[0];
	node[0] = node[--size];
	int parent = 0;
	int child = 1;
	while (child < size) {
		if (child + 1 < size && getLeft(parent).getKey() < getRight(parent).getKey())
			child++;
		if (node[child].getKey() <= node[parent].getKey()) break;
		node[parent] = node[child];
		parent = child;
		child = child * 2 + 1;
	}
	node[parent] = temp;
	return temp;
}

void MaxHeap::display() {
	for (int i = 0, level = 1; i < size; i++) {
		printf("%4d", node[i].getKey());
		if (i + 1 == level) {
			printf("\n");
			level = level * 2 + 1;
		}
	}
	printf("\n-------------------------\n");
}