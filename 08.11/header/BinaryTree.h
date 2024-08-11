#pragma once
#include "TreeNode.h"
#include <iostream>
using namespace std;

class BinaryTree {
private:
	TreeNode* root;

	void insert(TreeNode*& node, int value) {
		if (node == nullptr)
			node = new TreeNode(value);

		else if (value < node->data)
			insert(node->left, value);

		else
			insert(node->right, value);
	}

	void inOrder(TreeNode* node) const {
		if (node != nullptr) {
			inOrder(node->left);
			cout << node->data << " ";
			inOrder(node->right);
		}
	}

	void preOrder(TreeNode* node) const {
		if (node != nullptr) {
			cout << node->data << " ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	void postOrder(TreeNode* node) const {
		if (node != nullptr) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->data << " ";
		}
	}

	TreeNode* search(TreeNode* node, int value) const {
		if (node == nullptr || node->data == value)
			return node;
		else if (value < node->data)
			return search(node->left, value);
		else
			return search(node->right, value);
	}
	 
	TreeNode* findMin(TreeNode* node) const {
		while (node->left != nullptr)
			node = node->left;
		return node;
	}

	TreeNode* remove(TreeNode* node, int value) {
		if (node == nullptr) return node;

		if (value < node->data)
			node->left = remove(node->left, value);
		else if (value > node->data)
			node->right = remove(node->right, value);
		else {
			if (node->left == nullptr) {
				TreeNode* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr) {
				TreeNode* temp = node->left;
				delete node;
				return temp;
			}

			TreeNode* temp = findMin(node->right);
			node->data = temp->data;
			node->right = remove(node->right, temp->data);
		}
		return node;
	}

	void clear(TreeNode* node) {
		if (node != nullptr) {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

public:
	BinaryTree() : root(nullptr) {}

	~BinaryTree() {
		clear();
	}

	void insert(int value) {
		insert(root, value);
	}

	void inOrder() const {
		inOrder(root);
		cout << endl;
	}

	void preOrder() const {
		preOrder(root);
		cout << endl;
	}

	void postOrder() const {
		postOrder(root);
		cout << endl;
	}

	TreeNode* search(int value) const {
		return search(root, value);
	}

	void remove(int value) {
		root = remove(root, value);
	}

	void clear() {
		clear(root);
		root = nullptr;
	}
};