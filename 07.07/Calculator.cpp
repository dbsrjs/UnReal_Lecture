#include <iostream>
using namespace std;

class Adder {
protected:
	int add(int a, int b) { return a + b; }
};

class Subtactor {
protected:
	int minus(int a, int b) { return a - b; }
};

//다중 상속
class Calculator : public Adder, public Subtactor {
public:
	int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
	int res = 0;
	switch (op) {
	case '+' : res = add(a, b); break;
	case '-' : res = minus(a, b); break;
	}
	return res;
}

int main() {
	Calculator handCalculator;
	cout << "2 + 4 = " << handCalculator.calc('+', 2, 4) << endl;
	cout << "1- = 8 = " << handCalculator.calc('-', 100, 8) << endl;
}
