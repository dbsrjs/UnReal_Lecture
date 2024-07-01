#include <iostream>
#include <string>//string 클래스를 사용하기 위해 반드시 필요
using namespace std;

int main() {
	string str;
	string address("서울시 성북구 삼선동 389");
	string copyAddress(address);//address의 문자열을 복사한 스트링 객체 생성

	char text[] = { 'L','o','v','e', ' ', 'C','+','+','\0' };//C-스트링
	string title(text);//"Love C++"문자열을 가진 스트링 객체 생성

	//스트링 출력
	cout << str << endl;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
}
