#include <iostream>
#include <assert.h>
using namespace std;

void divide(int a, int b) {
	//b�� 0�� �� assert�� ���� ó��
	assert(b != 0);// ���ǽ��� ������ ��� ���α׷� ���� ���� ���α׷��� �ߴܽ�Ŵ.
	cout << "a : " << a << ", b : " << b << endl;
}

int main() {
	divide(10, 2);
	divide(5, 0);
	return 0;
}