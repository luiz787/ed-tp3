#ifndef ED_TP3_BINARY_TRIE
#define ED_TP3_BINARY_TRIE

#include "MorseCodeChar.hpp"
#include "Node.hpp"

class BinaryTrie {
public:
    /*
     * BinaryTrie constructor.
     */
	BinaryTrie();
	/*
	 * BinaryTrie destructor.
	 */
	~BinaryTrie();
    /*
     * Pre order traversal in the tree. Prints only non empty (value different than "#") nodes.
     */
	void preOrder();
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
	void insert(const MorseCodeChar &key, char value);
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
	char search(const MorseCodeChar &key);
private:
	Node* root; // the root of the tree.
	/*
	 * Helper method used to store the path of dots and dashes.
	 *
	 * @param node - the current node.
	 * @param path - the path taken so far.
	 */
    static void preOrder(Node *node, std::string path);
};

#endif // ED_TP3_BINARY_TRIE