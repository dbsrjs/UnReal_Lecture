#include <iostream>
using namespace std;

class MyVector {
	int* p;
	int size;
public:
	//위임 생성자
	MyVector() : MyVector(100) {}
	MyVector(int n) {
		p = new int[n];
		size = n;
	}

	/*MyVector(int n = 100) {
		p = new int[n];
		size = n;
	}
	~MyVector() { delete[] p; }
};

int main() {
	MyVector* v1, * v2;
	v1 = new MyVector();			//디폴트로 정수 100개의 배열 동적 할당
	v2 = new MyVector(1024);	//정수 1024개의 배열 동적 할당

	delete v1;
	delete v2;
}
