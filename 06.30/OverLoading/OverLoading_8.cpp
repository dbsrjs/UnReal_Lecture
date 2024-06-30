/*
#include <iostream>
using namespace std;

int add(int a, int b) {
	return a + b;
}

int add(int a, int& b) {
	b = b + a;
	return b;
}

int main() {
	int s = 10, t = 20;
	//cout add(s, t);//여기서 모호성이 발생할 수 있다.
}
*/