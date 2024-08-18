#include "HuffmanNode.h"
#include <queue>
#include <vector>
#include <map>
#include <iostream>
class HuffmanTree {
private:
	shared_ptr<HuffmanNode> root;
	map<char, string> codes;

	void buildCodes(std::shared_ptr<HuffmanNode> node, const string& str) {
		if (!node) return;
		if (node->data != "$") codes[node->data] = str;
		buildCodes(node->left, str + "0");
	}
};