//#include <iostream>
//using namespace std;
//
//int main() {
//	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
//	int i = 1;
//	int n = 2;
//	int& refn = n;//���� ���� refn ����. refn�� n�� ���� ����
//	n = 4;
//	refn++;//refn = 5, n = 5
//	cout << i << '\t' << n << '\t' << refn << endl;
//
//	refn = i;
//	refn++;
//	cout << i << '\t' << n << '\t' << refn << endl;
//
//	int* p = &refn;//p�� n�� �ּҸ� ����
//	*p = 20;//refn = 20, n = 20
//	cout << i << '\t' << n << '\t' << refn << endl;
//}