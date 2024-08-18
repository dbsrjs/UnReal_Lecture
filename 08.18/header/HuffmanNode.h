#pragma once
#include <memory>
using namespace std;


struct HuffmanNode {
	char data;
	unsigned frequency;
	shared_ptr<HuffmanNode> left, right;

	HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}

	//노드 비교를 위한 함수
	struct Compare {
		bool operator() (const shared_ptr<HuffmanNode>& l, const shared_ptr<HuffmanNode>& r) {
			return l->frequency > r->frequency;
		}
	};
};
