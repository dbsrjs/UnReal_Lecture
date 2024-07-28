#include <iostream>
using namespace std;

int main() {
	int month, day; //a : 월, b : 일

	cout << "월을 입력하세요 : ";
	cin >> month;

	if (month <= 0 || 13 <= month) {
		cout << "올바른 월을 입력해주세요." << endl;
		return 0;
	}

	cout << "일을 입력하세요 : ";
	cin >> day;
	

	cout << "입력하신 날짜의 계절은";

	if (3 <= month && month <= 5)
		cout << " 봄";
	else if (6 <= month && month <= 8)
		cout << " 여름";
	else if (9 <= month && month <= 11)
		cout << " 가을";
	else if (month <= 2 || month == 12)
		cout << " 겨울";

	cout << "입니다.";
	return 0;
}