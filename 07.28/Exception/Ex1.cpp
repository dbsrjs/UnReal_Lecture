#include <iostream>
using namespace std;

void main() {
	int n, sum, avg;


	while (true) {
		cout << "합을 입력하세요>>";
		cin >> sum;
		cout << "인원수를 입력하세요>>";
		cin >> n;

		try {
			if (n <= 0)
				throw n;	//n 값을 catch로 넘겨줌
			else
				avg = sum / n;

		}

		catch (int x) {	//throw에서 값을 받으면 호출됨
			cout << "예외 발생!! " << x << "으로 나눌 수 없음" << endl;
			avg = 0;
			cout << endl;
			continue;
		}
		cout << "평균 : " << avg << endl;
	}
}
