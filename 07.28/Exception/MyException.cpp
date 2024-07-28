#include <iostream>
#include <string>
using namespace std;

class MyException {//����ڰ� ����� �⺻ ���� Ŭ���� ����
	int lineNo;
	string func, msg;
public:
	MyException(int n, string f, string m) {
		lineNo = n; func = f, msg = m;
	}

	void print() {
		cout << func << ":" <<lineNo << ", " << msg << endl;
	}
};

class DivideByZeroException : public MyException {//0���� ������ ���� Ŭ���� ����
public:
	DivideByZeroException(int lineNo, string func, string msg) : MyException(lineNo, func, msg) {}
};

class InvaludInputException : public MyException {//�߸��� �Է� ���� Ŭ���� ����
public:
	InvaludInputException(int lineNo, string func, string msg) : MyException(lineNo, func, msg) {}
};

int main() {
	int x, y;
	try {
		cout << "�������� �մϴ�. �� ���� ���� ������ �Է��ϼ��� >> ";
		cin >> x >> y;
		if (x < 0 || y < 0)
			throw InvaludInputException(34, "main()", "���� �Է� ���� �߻�");
		if (y == 0)
			throw DivideByZeroException(36, "main()", "0���� ������ ���� �߻�");
		cout << (double)x / (double)y;
	}

	catch (DivideByZeroException& e) {
		e.print();
	}

	catch (InvaludInputException& e) {
		e.print();
	}
}