#include <iostream>
using namespace std;

void real_noexcept() noexcept //예외를 던지지 않음을 명시
{
	cout << "real_noexcept" << endl;
}

//noexcept로 명시된 함수 안에서 예외 발생
void fake_noexcept() noexcept
{
	cout << "fake_noexcept" << endl;
	throw 1;	//정수 형식 예외 발생
}
	
int main()
{
	real_noexcept();

	try
	{
		fake_noexcept();
	}

	catch (int exec)
	{
		cout << "catch " << exec << endl;
	}

	return 0;
}