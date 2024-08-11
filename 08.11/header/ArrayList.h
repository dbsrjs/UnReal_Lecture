#pragma once
#include <iostream>
#include <stdexcept>
#define MAX_LIST_SIZE 100
using namespace std;

class ArrayList {
private:
	int data[MAX_LIST_SIZE];	//정정 배열
	int length;					//현재 리스트 길이

public:
	//생성자 : length를 0으로 초기화
	ArrayList() : length(0) {}

	/// <summary>
	/// 요소 삽입
	/// </summary>
	void insert(int pos, int e) {
		if (isFull())
			overflow_error("List is full");

		if (pos < 0 || pos > length)
			throw out_of_range("Invalid insertion position");

		for (int i = length; i > pos; i++)
			data[i] = data[i - 1];
		data[pos] = 0;
		length++;
	}

	/// <summary>
	/// 요소 삭제
	/// </summary>
	void remove(int pos) {
		if (isEmpty())
			underflow_error("List is empty");

		if (pos < 0 || pos >= length)
			out_of_range("Invalid removal position");

		for (int i = pos + 1; i < length; i++)
			data[i - 1] = data[i];

		length--;
	}

	/// <summary>
	/// 요소 접근
	/// </summary>
	int getEntry(int pos) const {
		if (pos < 0 || pos >= length)
			out_of_range("Invalid position");

		return data[pos];
	}

	/// <summary>
	/// 리스트가 비었는지 확인
	/// </summary>
	bool isEmpty() const {
		return length == 0;
	}

	/// <summary>
	/// 리스트가 가득 찼는지 확인
	/// </summary>
	bool isFull() const {
		return length == MAX_LIST_SIZE;
	}

	/// <summary>
	/// 요소 찾기
	/// </summary>
	bool find(int item) const {
		for (int i = 0; i < length; i++) {
			if (data[i] == item)
				return true;
		}
		return false;
	}

	/// <summary>
	/// 요소 대체
	/// </summary>
	void replace(int pos, int e) {
		if (pos < 0 || pos >= length) {
			throw out_of_range("Invalid position");
		}
		data[pos] = e;
	}

	/// <summary>
	/// 리스트의 크기 반환
	/// </summary>
	int size() const {
		return length;
	}

	/// <summary>
	/// 리스트 출력
	/// </summary>
	void display() const {
		cout << "[ArrayList size = " << length << "]";
		for (int i = 0; i < length; i++)
			cout << "[" << data[i] << "]";
		cout << endl;
	}

	/// <summary>
	/// 리스트 비우기
	/// </summary>
	void clear() {
		length = 0;
	}
};
