/*
#include <iostream>
using namespace std;

//���� ����
void f(char c = ' ', int line = 1);

//�Լ� ����
void f(char c, int line) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++)
			cout << c;
		cout << endl;
	}
}

int main() {
	f();			//����� ��ĭ 10�� ����Ѵ�
	f('%');		//���ٿ� '%'�� 10�� ����Ѵ�
	f('@', 5);	//5 �⿡ '@' ���ڸ� 10�� ����Ѵ�
}
*/