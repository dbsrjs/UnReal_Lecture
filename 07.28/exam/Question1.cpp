#include <iostream>
using namespace std;

int main() {
	int divisor = 0;

	//이곳에 예외 처리
	try {
		if (divisor == 0)
			throw divisor;

		int result = 10 / divisor;
		cout << "결과 : " << result << endl;
	}

	catch (int i) {
		cout << "예외 발생!" << endl;
		return 0;
	}
	
	return 0;
}
