#include <iostream>
using namespace std;

bool getExp(int base, int exp, int& ret) {
	if (base <= 0 || exp <= 0) {
		return false;
	}
	int value = 1;
	for (int n = 0; n < exp; n++)
		value *= base;
	ret = value;
	return true;
}

int main() {
	int v = 0;
	if (getExp(2, 3, v))
		cout << "2�� 3���� " << v << "�Դϴ�." << endl;
	else
		cout << "����. 2�� 3���� ����� �� �����ϴ�." << endl;

	int e = 0;
	if (getExp(2, -3, e))
		cout << "2�� -3���� " << e << "�Դϴ�." << endl;
	else
		cout << "����. 2�� -3���� ����� �� �����ϴ�." << endl;
}