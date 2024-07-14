#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> number1({ 1, 2, 3, 4, 5 });
	vector<int> number2;

	copy(number1.begin(), number1.end(), back_inserter(number2));

	for (auto i : number2)
		cout << i << endl;

	double number3[5] = { 1.2, 3.4, 4.5, 5.6, 6.77 };
	double number4[5];

	copy(begin(number3), end(number3), begin(number4));

	for (auto i : number4)
		cout << i << endl;

	return 0;
}