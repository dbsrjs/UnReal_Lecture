#include <iostream>
#include <string>
using namespace std;

void Type1(string msg, int no, double value) {
	cout << msg << ", ���� ��ȣ : " << no << ", ���� �� : " << value << endl;
}

void Type2(int no, double value) {
	cout << no << ", ������ : " << value << endl;
}

template<typename... T>
void PrintLog(T... arg8) {
	//�߰� �۾�
	Type1(arg8...);
	//Type(arg8...);
}

int main() {
	PrintLog<string, int, double>("Warning", 100, 22.5);

	return 0;
}