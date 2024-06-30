/*
#include <iostream>
using namespace std;

//원형 선언
void f(char c = ' ', int line = 1);

//함수 구현
void f(char c, int line) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++)
			cout << c;
		cout << endl;
	}
}

int main() {
	f();			//헌쥴애 빈칸 10개 출력한다
	f('%');		//한줄에 '%'를 10개 출력한다
	f('@', 5);	//5 출에 '@' 문자를 10개 출력한다
}
*/