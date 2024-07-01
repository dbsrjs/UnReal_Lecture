#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle circleArray[3];//Circle 배열 생성

	 //배열의 각 원소 객체의 멤버 접근
	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)//배열의 각 원소 객체의 멤버 접근
		cout << "Circle " << i << "의 면적은 : " << circleArray[i].getArea() << endl;

	Circle *p;
	p = circleArray;
	for (int i = 0; i < 3; i++) {//객체 포인터로 배열 접근
		cout << "Circle " << i << "의 면적은 : " << p->getArea() << endl;
		p++;
	}
}
