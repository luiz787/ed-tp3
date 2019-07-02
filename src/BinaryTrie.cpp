#include <iostream>
#include "BinaryTrie.hpp"
#include "MorseCodeChar.hpp"

BinaryTrie::BinaryTrie() {
	this->root = new Node('#');
	this->root->setLeft(nullptr);
    this->root->setRight(nullptr);
}

BinaryTrie::~BinaryTrie() {
	delete this->root;
}

char BinaryTrie::search(const MorseCodeChar &key) {
    auto node = this->search(this->root, key);
    if (node != nullptr) {
        return node->getData();
    } else {
        throw std::runtime_error("Key not present in TRIE");
    }
}

Node* BinaryTrie::search(Node* node, const MorseCodeChar &key) {
	if (node == nullptr) {
	    return nullptr;
	}
	auto keySize = key.size();
	auto currentNode = node;
	for (auto i = 0; i < keySize; i++) {
	    auto currentSymbol = key.charAt(i);
        if (currentSymbol == '.') {
            currentNode = currentNode->getLeft();
        } else if (currentSymbol == '-') {
            currentNode = currentNode->getRight();
        }
	}
	// Now, currentNode either holds the node that contains the value represented by the key, or null.
    return currentNode;
}

void BinaryTrie::insert(const MorseCodeChar &key, char value) {
    this->insert(this->root, key, value);
}

Node* BinaryTrie::insert(Node *n, const MorseCodeChar &key, char value) {
    auto keySize = key.size();
    auto currentNode = n;
    for (auto i = 0; i < keySize; i++) {
        if (currentNode == nullptr) {
            currentNode = new Node();
        }
        auto currentSymbol = key.charAt(i);
        if (currentSymbol == '.') {
            if (currentNode->getLeft() == nullptr) {
                auto newNode = new Node();
                currentNode->setLeft(newNode);
                currentNode = newNode;
            } else {
                currentNode = currentNode->getLeft();
            }
        } else if (currentSymbol == '-') {
            if (currentNode->getRight() == nullptr) {
                auto newNode = new Node();
                currentNode->setRight(newNode);
                currentNode = newNode;
            } else {
                currentNode = currentNode->getRight();
            }
        }
    }

    currentNode->setData(value);
    return currentNode;
}

void BinaryTrie::preOrder(Node *node) {
    if (node != nullptr) {
        auto data = node->getData();
        if (data != '#') {
            std::cout << node->getData() << std::endl;
        }
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }
}

void BinaryTrie::preOrder() {
    this->preOrder(this->root);
}
