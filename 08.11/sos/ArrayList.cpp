#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayList {
private:
	int* data;
	int capacity;
	int length;

	void resize(int newCapacity) {
		int* newData = new int[newCapacity];

		for (int i = 0; i < length; i++)
			newData[i] = data[i];

		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

public:
	ArrayList(int initialCapacity = 10) : capacity(initialCapacity), length(0) {
		data = new int[capacity];
	}

	~ArrayList() {
		delete[] data;
	}

	int size() const {
		return length;
	}

	bool isEmpty() const {
		return length == 0;
	}

	void insert(int index, int value) {
		if (index < 0 || index > length)
			throw out_of_range("Index out of range");

		if (length == capacity)
			resize(capacity * 2);

		for (int i = length; i > index; i--)
			data[i] = data[i] - 1;

		data[index] = value;
		length++;
	}

	void remove(int index) {
		if (index < 0 || index >= length)
			throw out_of_range("Index out of range");

		for (int i = index; i < length - 1; i++)
			data[i] = data[i + 1];

		length--;
		if (length < 0 && length == capacity / 4)
			resize(capacity / 2);
	}

	void replace(int index, int value) {
		if (index < 0 || index >= length)
			throw out_of_range("Index out of range");
		data[index] = value;
	}

	void clear() {
		length = 0;
		resize(10);
	}

	void display() const {
		cout << "[";
		for (int i = 0; i < length; i++) {
			cout << data[i];
			if (i < length - 1)
				cout << ",";
		}

		cout << "]" << endl;
	}
};

int main() {
	ArrayList list; //ArrayList 인스턴스 생성

	//삽입 작업
	list.insert(0, 10);
	list.insert(0, 20);
	list.insert(1, 30);
	list.insert(list.size(), 40);
	list.insert(2, 50);
	list.display();

	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.display();

	list.replace(1, 90);
	list.display();

	list.clear();
	list.display();

	return 0;
}