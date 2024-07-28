#include <iostream>
using namespace std;

void process(int value) {
	try {
		if (value < 0)
			throw value;
		cout << value << endl;
	}

	catch(int i) {
		cout << "예외 발생!" << endl;
	}
	//value가 음수일 때 예외 던지기
	//예외 발생하면 "예외 발생!" 출력, 발생하지 않으면 value 출력
}

int main() {
	process(10);
	process(20);
	process(-5);
	return 0;
}