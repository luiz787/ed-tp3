#include "Node.hpp"

Node::Node(char data) {
	this->data = data;
}

Node::~Node() = default;

char Node::getData() const {
	return this->data;
}

Node* Node::getLeft() const {
	return this->left;
}

Node* Node::getRight() const {
	return this->right;
}

void Node::setLeft(Node* left) {
	this->left = left;
}

void Node::setRight(Node* right) {
	this->right = right;
}

bool Node::isLeaf() {
	return this->left == nullptr && this->right == nullptr;
}
