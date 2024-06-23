//#include <iostream>
//using namespace std;
//
//class Circle {
//	int radius;
//public:
//	Circle();
//	~Circle() {}
//	void  setRadius(int r) { radius = r; }
//	double getArea() { return 3.124 * radius * radius; }
//};
//
//Circle::Circle() {
//	radius = 1;
//}
//
//int main() {
//	cout << "생성하고자 하는 원의 개수?";
//	int n = 0, radius = 0;
//	cin >> n;
//
//	Circle* pArray = new Circle[n];
//	for (int i = 0; i < n; i++) {
//		cout << "원" << i + 1 << ": ";//프롬프트 출력
//		cin >> radius;//반지름 입력
//		pArray[i].setRadius(radius);//각 Circle 객체를 반지름으로 초기화
//	}
//
//	int count = 0;
//	Circle* p = pArray;
//	for (int i = 0; i < n; i++) {
//		cout << p->getArea() << ' ';
//		if (p->getArea() >= 100 && p->getArea() <= 200)
//			count++;
//		p++;
//	}
//	cout << endl << "면적이 100에서 200 사이인 원의 개수는 " << count << endl;
//
//	delete[] pArray;//객체 배열 소멸
//}