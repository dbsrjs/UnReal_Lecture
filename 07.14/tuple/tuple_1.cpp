#include <iostream>
#include <tuple>
#include <string>
using namespace std;

int main() {
	typedef tuple < string, int, double> Data;

	Data data1("문자열", 10, 1.2);
	auto data2 = make_tuple("문자열", 10, 1.2);

	cout << get<0>(data1) << ", " << get<1>(data1) << " ," << get<2>(data1) << endl;

	return 0;
}
