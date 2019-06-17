#include "BinaryTrie.hpp"
#include "MorseCodeChar.hpp"

BinaryTrie::BinaryTrie() {
	this->root = new Node('#');
}

BinaryTrie::~BinaryTrie() {
	delete this->root;
}

char BinaryTrie::search(MorseCodeChar key) {
	return this->recursiveSearch(this->root, key, 0);
}

char BinaryTrie::recursiveSearch(Node* node, MorseCodeChar key, int pos) {
	if (node->isLeaf()) {
		char reg = node->getData();
		if (reg == 't') { // FIXME: compare with key, from dict.
			return node->getData();
		} else {
			return '#'; // TODO: nullptr
		}
	}
	if (key.charAt(pos) == '.') {
		return recursiveSearch(node->getLeft(), key, pos + 1);
	} else {
		return recursiveSearch(node->getRight(), key, pos + 1);
	}
	return '#'; // TODO: nullptr;
}