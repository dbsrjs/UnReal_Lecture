#include <iostream>
#include <cstdlib>
using namespace std;

//���� ó�� �Լ�
void myerminate()
{
	cout << "myterminate called" << endl;
	exit(-1);	//���α׷��� ���������� ����
}

int main(void)
{
	set_terminate(myerminate);//���� ó�� �Լ� ����
	throw 1;//���� �߻�

	return 0;//throw�� ���ܸ� �������Ƿ� ������� ����
}