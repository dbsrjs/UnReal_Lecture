#include <iostream>
using namespace std;

void process(int value) {
	try {
		if (value < 0)
			throw value;
		cout << value << endl;
	}

	catch(int i) {
		cout << "���� �߻�!" << endl;
	}
	//value�� ������ �� ���� ������
	//���� �߻��ϸ� "���� �߻�!" ���, �߻����� ������ value ���
}

int main() {
	process(10);
	process(20);
	process(-5);
	return 0;
}