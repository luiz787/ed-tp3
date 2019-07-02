#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include "BinaryTrie.hpp"


BinaryTrie* buildTrieFromMorseDefinitionFile();
void translate(BinaryTrie* trie);

int main(int argc, char** argv) {
    BinaryTrie* trie = buildTrieFromMorseDefinitionFile();

    translate(trie);

    if (argc > 1 && strncmp(argv[1], "-a", 2) == 0) {
        trie->preOrder();
    }
    return 0;
}

BinaryTrie* buildTrieFromMorseDefinitionFile() {
    auto trie = new BinaryTrie();
	std::string line;
	std::ifstream morseDefinitionFile("../morse.txt");
 	if (morseDefinitionFile.is_open()) {
    	while(getline(morseDefinitionFile,line)) {
      		auto spacePosition = line.find(' ');
      		auto character = line.substr(0, spacePosition);
      		auto morseCode = line.substr(spacePosition + 1, line.size());
            trie->insert(MorseCodeChar(morseCode), character[0]);
    	}
    	morseDefinitionFile.close();
  	} else {
  		std::cout << "Unable to open file" << std::endl;
  	}
 	return trie;
}

void translate(BinaryTrie* trie) {
    std::string line;
    while(getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        std::string charCode;
        for (auto i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                std::cout << trie->search(MorseCodeChar(charCode));
                charCode.clear();
            } else if (line[i] == '/') {
                std::cout << ' ';
                ++i;
            } else {
                charCode += line[i];
            }
        }
        std::cout << trie->search(MorseCodeChar(charCode)) << std::endl;
    }
}
