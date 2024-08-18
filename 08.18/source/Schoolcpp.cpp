#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct Student {
	int id;
	int math, eng;
	Student(int num, int m, int e) : id(num), math(m), eng(e) {} //������ ����
};

struct cmp {
	bool operator()(Student a, Student b) {
		return a.id < b.id;
	}
};

int main()
{
	//������ ���� cmp ����ü�� �־� �ش�.
	priority_queue<Student, vector<Student>, cmp> pq;

	pq.push(Student(3, 100, 50));
	pq.push(Student(1, 60, 50));
	pq.push(Student(2, 80, 50));
	pq.push(Student(4, 90, 50));
	pq.push(Student(5, 70, 40));

	while (!pq.empty()) {
		Student ts = pq.top(); pq.pop();
		cout << "(�й�, ����, ����) : " << ts.id << ts.math << ' ' << ts.eng << '\n';
	}

	return 0;
}