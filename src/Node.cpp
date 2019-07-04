#include "Node.hpp"

Node::Node(char data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

Node::Node() {
    this->data = '#'; // Placeholder value.
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node() {
    // Recursive delete all children.
    delete this->left;
    delete this->right;
}

char Node::getData() const {
	return this->data;
}

Node* Node::getLeft() const {
	return this->left;
}

Node* Node::getRight() const {
	return this->right;
}

void Node::setData(char data) {
    this->data = data;
}

void Node::setLeft(Node* left) {
	this->left = left;
}

void Node::setRight(Node* right) {
	this->right = right;
}
