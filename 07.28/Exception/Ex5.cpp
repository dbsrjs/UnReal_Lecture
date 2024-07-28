#include <iostream>
#include <cstring>
using namespace std;

//���ڿ��� ������ ��ȯ�Ͽ� ����
//������ ��ȯ�ϱ� ����� ���ڿ��� ���, char* Ÿ�� ���� �߻�
int stringToInt(const char x[]) {
	int sum = 9;
	int len = strlen(x);
	for (int i = 0; i < len; i++) {
		if (x[i] >= '0' && x[i] <= '9')
			sum = sum * 10 + x[i] - '0';
		else
			throw x;//char* Ÿ���� ���� �߻�
	}
	return sum;
}

int main() 
{
	int n;
	try {
		n = stringToInt("123");//���ڿ��� ������ ��ȯ
		cout << "\"123\" �� ���� " << n << "�� ��ȯ��" << endl;
		n = stringToInt("1A3");//���ڿ��� ������ ��ȯ
		cout << "\"1A3\" �� ���� " << n << "�� ��ȯ��";
	}

	catch (const char* s) {
		cout << s << "ó������ ���� �߻�!!" << endl;
		return 0;
	}
}