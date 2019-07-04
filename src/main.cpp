#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include "BinaryTrie.hpp"


BinaryTrie* buildTrieFromMorseDefinitionFile();
void translate(BinaryTrie* trie);

int main(int argc, char** argv) {
    BinaryTrie* trie = nullptr;
    try {
        trie = buildTrieFromMorseDefinitionFile();
        translate(trie);
        if (argc > 1 && strncmp(argv[1], "-a", 2) == 0) {
            trie->preOrder();
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    delete trie;
    return 0;
}

/*
 * Builds a trie from a morse code definition file.
 * The lines of the file must comply to the following specification:
 *
 * [char] [morse]
 *
 * Where [char] is an alphanumeric character, and [morse] is a string of dots and dashes.
 *
 * @returns the newly constructed trie.
 */
BinaryTrie* buildTrieFromMorseDefinitionFile() {
    auto trie = new BinaryTrie();
	std::string line;
	std::ifstream morseDefinitionFile("morse.txt");
 	if (morseDefinitionFile.is_open()) {
    	while(getline(morseDefinitionFile,line)) {
      		auto spacePosition = line.find(' ');
      		auto character = line.substr(0, spacePosition);
      		auto morseCode = line.substr(spacePosition + 1, line.size());
            trie->insert(MorseCodeChar(morseCode), character[0]);
    	}
    	morseDefinitionFile.close();
  	} else {
  		throw std::runtime_error("Unable to open morse.txt file");
  	}
 	return trie;
}

/*
 * Translates messages from stdin, and outputs the decoded messages to stdout.
 *
 * @param trie - the tree in which the searches will be performed.
 */
void translate(BinaryTrie* trie) {
    std::string line;
    while(getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        std::string charCode;
        for (uint8_t i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                /*
                 * When a space is seen, it means that the morse code for a letter just ended, and the search for that
                 * letter can be performed.
                 */
                std::cout << trie->search(MorseCodeChar(charCode));
                charCode.clear();
            } else if (line[i] == '/') {
                std::cout << ' ';
                ++i;
                /*
                 * The variable i is incremented because before and after a slash always comes a space, and in this case,
                 * it is guaranteed that at this point the charCode variable is empty, so if the next character of line
                 * is processed, it will trigger a search for an empty key, so we want to avoid that. Incrementing i will
                 * guarantee that the next word will be properly processed.
                 */
            } else {
                charCode += line[i];
            }
        }
        /*
         * As the line ends with either a dot or a dash (not a space), we need to call search outside the for loop
         * to guarantee that the last letter of the line is decoded.
         */
        std::cout << trie->search(MorseCodeChar(charCode)) << std::endl;
    }
}
