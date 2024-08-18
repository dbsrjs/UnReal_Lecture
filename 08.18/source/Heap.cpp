#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main()
{
	MaxHeap heap;

	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(8);
	heap.insert(0);
	heap.insert(3);
	heap.insert(7);
	heap.display();

	heap.remove();
	heap.display();
	heap.remove();
	heap.display();

	cout << endl;
	return 0;
}
