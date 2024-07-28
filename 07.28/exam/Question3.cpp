#include <iostream>
#include <assert.h>
using namespace std;

void divide(int a, int b) {
	//b가 0일 때 assert로 예외 처리
	assert(b != 0);// 조건식이 거짓일 경우 프로그램 실행 도중 프로그램을 중단시킴.
	cout << "a : " << a << ", b : " << b << endl;
}

int main() {
	divide(10, 2);
	divide(5, 0);
	return 0;
}