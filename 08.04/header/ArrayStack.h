#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX_STACK_SIZE 100

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(EXIT_FAILURE);
}

class ArrayStack
{
	int data[MAX_STACK_SIZE];
	int top;

public:
	ArrayStack() : top(-1) {}
	~ArrayStack() {}

	bool isEmpty() const { return top == -1; }
	bool isFull() const { return top == MAX_STACK_SIZE - 1; }

	void push(int e) {
		if (isFull()) error("Stack Overflow Error");
		data[++top] = e;
	}

	int pop() {
		if (isEmpty()) error("StackUnderflow Error");
		return data[top--];
	}

	int peek() const {
		if (isEmpty()) error("Stack Underflow Errror");
		return data[top];
	}

	void display() const {
		printf("[Stack Size = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}
};
