#include <iostream>
using namespace std;

int main() {
	int month, day; //a : ��, b : ��

	cout << "���� �Է��ϼ��� : ";
	cin >> month;

	if (month <= 0 || 13 <= month) {
		cout << "�ùٸ� ���� �Է����ּ���." << endl;
		return 0;
	}

	cout << "���� �Է��ϼ��� : ";
	cin >> day;
	

	cout << "�Է��Ͻ� ��¥�� ������";

	if (3 <= month && month <= 5)
		cout << " ��";
	else if (6 <= month && month <= 8)
		cout << " ����";
	else if (9 <= month && month <= 11)
		cout << " ����";
	else if (month <= 2 || month == 12)
		cout << " �ܿ�";

	cout << "�Դϴ�.";
	return 0;
}