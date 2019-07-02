#ifndef ED_TP3_BINARY_TRIE
#define ED_TP3_BINARY_TRIE

#include "MorseCodeChar.hpp"
#include "Node.hpp"

class BinaryTrie {
public:
	BinaryTrie();
	~BinaryTrie();
	void preOrder();
	void insert(const MorseCodeChar &key, char value);
	char search(const MorseCodeChar &key);
private:
	Node* root;
	void preOrder(Node *node);
	Node* insert(Node* n, const MorseCodeChar &key, char value);
	Node* search(Node* node, const MorseCodeChar &key);
};

#endif // ED_TP3_BINARY_TRIE