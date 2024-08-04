#include "ArrayStack.h"
using namespace std;
void main() 
{
	ArrayStack stack;
	for (int i = 1; i < 10; i++)
		stack.push(i);

	stack.display();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.display();
}