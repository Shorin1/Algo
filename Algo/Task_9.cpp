#include "pch.h"
#include <iostream>

using namespace std;

struct Tree {
	struct Node {
		Node* left = nullptr;
		Node* right = nullptr;
		double data;
	};

	Node* root = nullptr;
	unsigned int size = 0;

	void add(double data, Node* node) {
		if (data < node->data) {
			if (node->left == nullptr) {
				node->left = new Node();
				node->left->data = data;
			}
			else {
				add(data, node->left);
			}
		}
		else {
			if (node->right == nullptr) {
				node->right = new Node();
				node->right->data = data;
			}
			else {
				add(data, node->right);
			}
		}
	}

	void add(double data) {
		if (this->root == nullptr) {
			root = new Node();
			root->data = data;
		}
		else {
			add(data, root);
		}
	}

	Node* find(double key, Node* node) {
		if (node == nullptr) {
			return nullptr;
		}

		if (node->data == key) {
			return node;
		}
		else if (key > node->data) {
			find(key, node->right);
		}
		else {
			find(key, node->left);
		}
	}

	Node* remove(double data) {
		if (root == nullptr) {
			return root;
		}

		remove(root, data);
	}

	Node* remove(Node* node, double data) {
		if (node == nullptr) {
			return node;
		}

		if (data == node->data) {
			Node* temp;

			if (node->right == nullptr) {
				temp = node->left;
			}
			else {
				Node* ptr = node->right;

				if (ptr->left == nullptr) {
					ptr->left = node->left;
					temp = ptr;
				}
				else {
					Node* pmin = ptr->left;
					while (pmin->left != nullptr) {
						ptr = pmin;
						pmin = ptr->left;
					}
					ptr->left = pmin->right;
					pmin->left = node->left;
					pmin->right = node->right;
					temp = pmin;
				}

			}

			delete node;
			return temp;
		}
		else if (data < node->data) {
			node->left = remove(node->left, data);
		}
		else {
			node->right = remove(node->right, data);
		}

		return node;
	}

	void preorderPrint(Node* root) {
		if (root == nullptr) {
			return;
		}

		cout << root->data << endl;

		preorderPrint(root->left);
		preorderPrint(root->right);
	}

	void inorderPrint(Node* root) {
		if (root == nullptr) {
			return;
		}

		inorderPrint(root->left);

		cout << root->data << endl;

		inorderPrint(root->right);
	}

	void postorderPrint(Node* root) {
		if (root == nullptr) {
			return;
		}

		postorderPrint(root->left);
		postorderPrint(root->right);

		cout << root->data << endl;
	}

};

void main() {
	cout << "Test tree" << endl;

	Tree tree;
	double data;

	for (int i = 0; i < 5; i++) {
		cin >> data;
		tree.add(data);
	}

	cout << "First output" << endl;

	tree.preorderPrint(tree.root);
	cout << endl;
	tree.postorderPrint(tree.root);

	cout << "Remove element" << endl;

	cin >> data;
	tree.remove(data);

	cout << "Second output" << endl;

	tree.preorderPrint(tree.root);
	cout << endl;
	tree.postorderPrint(tree.root);



}
