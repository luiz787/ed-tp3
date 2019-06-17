#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTrie.hpp"


void readMorseDict();

int main() {
    std::cout << "Hello world" << std::endl;
    readMorseDict();
    return 0;
}

void readMorseDict() {
	std::string line;
	std::ifstream morse("morse.txt");
 	if (morse.is_open()) {
    	while(getline(morse,line)) {
      		std::cout << line << std::endl;
    	}
    	morse.close();
  	} else {
  		std::cout << "Unable to open file" << std::endl;
  	}
}