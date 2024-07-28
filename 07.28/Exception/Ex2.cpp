#include <iostream>
using namespace std;

int getExp(int base, int exp) {
	if (base <= 0 || exp <= 0) {
		cout << "예외 발생!! ";
		throw "음수 사용 불가";
	}
		

	int value = 1;
	for (int n = 0; n < exp; n++)
		value *= base;
	return value;
}

int main() {
	int v = 0;
	try {
		v = getExp(2, 3);
		cout << "2의 3승은 " << v << "입니다." << endl;

		v = getExp(2, -3);
		cout << "2dml -3승은" << v << "입니다." << endl;
	}

	catch (const char* s) {
		cout << s << endl;
	}
}