#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(const Circle& c);//���� ������ ����
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle(const Circle& c) {
	this->radius = c.radius;
	cout << "���� ������ ���� radius = " << radius << endl;
}

int main() {
	Circle src(30);
	Circle dest(src);

	cout << "������ ���� = " << src.getArea() << endl;
	cout << "�纻�� ���� = " << dest.getArea() << endl;
}