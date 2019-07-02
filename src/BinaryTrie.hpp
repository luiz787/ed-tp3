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
    static void preOrder(Node *node, std::string path);
};

#endif // ED_TP3_BINARY_TRIE