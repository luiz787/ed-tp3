#include <iostream>
#include "BinaryTrie.hpp"
#include "MorseCodeChar.hpp"

/*
 * BinaryTrie constructor.
 */
BinaryTrie::BinaryTrie() {
	this->root = new Node('#'); // Placeholder value, to represent an empty node.
	this->root->setLeft(nullptr);
    this->root->setRight(nullptr);
}

/*
 * BinaryTrie destructor.
 */
BinaryTrie::~BinaryTrie() {
	delete this->root; // Recursively deletes all nodes.
}

/*
 * API to perform a search in the trie, based on a MorseCodeChar key. This is a iterative function, that loops over the
 * length of the provided key, and walks down the TRIE, respecting the following convention: if the current char of
 * the key is a dot, it goes to the left child, otherwise, if the current char of the key is a dash, it goes to the
 * right child. By doing this, it is guaranteed that this function finds (if present) the value associated with the
 * key in at most m steps, where m is the key size (which means constant time).
 *
 * @param key - the MorseCodeChar key, which encapsulates a string of dots and dashes.
 * @returns char - the character encoded by that key.
 *
 * @throws runtime_error if the key is not present.
 */
char BinaryTrie::search(const MorseCodeChar &key) {
    if (this->root == nullptr) {
        throw std::runtime_error("TRIE is empty.");
    }
    auto keySize = key.size();
    auto currentNode = this->root;
    for (auto i = 0; i < keySize; i++) {
        if (currentNode == nullptr) {
            throw std::runtime_error("Key not present in TRIE");
        }
        auto currentSymbol = key.charAt(i);
        if (currentSymbol == '.') {
            currentNode = currentNode->getLeft();
        } else if (currentSymbol == '-') {
            currentNode = currentNode->getRight();
        }
    }
    // Now, currentNode must either hold the node that contains the value represented by the key, or null.
    if (currentNode != nullptr) {
        return currentNode->getData();
    } else {
        throw std::runtime_error("Key not present in TRIE");
    }
}

/*
 * API to insert a key-value pair in the trie. This method inserts the value by walking down the trie in a similar
 * fashion to the search method.
 *
 * @see search
 *
 * Note: this method does not insert values in "partial" paths, instead, if it finds a leaf node, it will create
 * an empty node and continue to iterate all over the key length, always inserting the value in the n-th level of the
 * trie, where n is the size of the key.
 *
 * @param key - the MorseCodeChar key that encodes the value.
 * @param value - the value to be stored in the trie.
 */
void BinaryTrie::insert(const MorseCodeChar &key, char value) {
    auto keySize = key.size();
    auto currentNode = this->root;
    for (auto i = 0; i < keySize; i++) {
        if (currentNode == nullptr) {
            currentNode = new Node();
        }
        auto currentSymbol = key.charAt(i);
        if (currentSymbol == '.') {
            if (currentNode->getLeft() == nullptr) {
                // If the left node is null, it creates a new node and continues.
                auto newNode = new Node();
                currentNode->setLeft(newNode);
                currentNode = newNode;
            } else {
                currentNode = currentNode->getLeft();
            }
        } else if (currentSymbol == '-') {
            if (currentNode->getRight() == nullptr) {
                // If the right node is null, it creates a new node and continues.
                auto newNode = new Node();
                currentNode->setRight(newNode);
                currentNode = newNode;
            } else {
                currentNode = currentNode->getRight();
            }
        }
    }
    currentNode->setData(value);
}

/*
 * Helper method used to store the path of dots and dashes.
 *
 * @param node - the current node.
 * @param path - the path taken so far.
 */
void BinaryTrie::preOrder(Node *node, std::string path) {
    if (node != nullptr) {
        auto data = node->getData();
        if (data != '#') {
            std::cout << node->getData() << " " << path << std::endl;
        }
        preOrder(node->getLeft(), path + ".");
        preOrder(node->getRight(), path + "-");
    }
}
/*
 * Pre order traversal in the tree. Prints only non empty (value different than "#") nodes.
 */
void BinaryTrie::preOrder() {
    this->preOrder(this->root, "");
}
