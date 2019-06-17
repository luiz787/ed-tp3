#ifndef ED_TP3_BINARY_TRIE
#define ED_TP3_BINARY_TRIE

#include "MorseCodeChar.hpp"
#include "Node.hpp"

class BinaryTrie {
public:
	BinaryTrie();
	~BinaryTrie();
	char search(MorseCodeChar key);
private:
	Node* root;
	char recursiveSearch(Node* node, MorseCodeChar key, int pos);
};

#endif // ED_TP3_BINARY_TRIE