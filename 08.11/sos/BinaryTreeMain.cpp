#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree tree;

	tree.insert(50);
	tree.insert(30);
	tree.insert(20);
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	tree.insert(80);

	cout << "In-order traversal: ";
	tree.inOrder();

	cout << "Pre-order traversal: ";
	tree.preOrder();

	cout << "Post-order traversal: ";
	tree.postOrder();

	int value = 40;
	if (tree.search(value) != nullptr)
		cout << "Node" << value << "found in the tree." << endl;
	else
		cout << "Node" << value << "not found in the tree." << endl;

	tree.remove(50);
	cout << "In-order traversal after removing 50: ";
	tree.inOrder();

	tree.clear();
	cout << "Tree cleared.in - order traversal after clearing : ";
	tree.inOrder();

	return 0;
}