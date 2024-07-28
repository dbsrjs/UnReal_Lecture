#include <iostream>
using namespace std;

int getExp(int base, int exp) {
	if (base <= 0 || exp <= 0) {
		return -1;
	}

	int value = 1;
	for (int n = 0; n < exp; n++) {
		value *= base;
	}
	return value;
}

int main() {
	int v = 0;
	v = getExp(2, 3);
	if (v != -1) {
		cout << "2의 3승은" << v << "입니다." << endl;
	}
	else
		cout << "오류. 2의 3승은 계산할 수 없습니다." << endl;

	int e = 0;
	e = getExp(2, -3);
	if (e != -1)
		cout << "2의 -3승은" << e << "입니다." << endl;
	else
		cout << "오류. 2의 -3승은 계산할 수 없습니다." << endl;
}