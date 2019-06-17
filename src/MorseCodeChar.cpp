#include "MorseCodeChar.hpp"

MorseCodeChar::MorseCodeChar(std::string repr) {
	this->repr = repr;
}

MorseCodeChar::~MorseCodeChar() = default;

char MorseCodeChar::charAt(int pos) const {
	return this->repr[pos];
}
