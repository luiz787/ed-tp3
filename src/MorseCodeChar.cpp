#include <utility>
#include "MorseCodeChar.hpp"

MorseCodeChar::MorseCodeChar(std::string repr) : repr(std::move(repr)) {}

MorseCodeChar::~MorseCodeChar() = default;

char MorseCodeChar::charAt(int pos) const {
	return this->repr[pos];
}

uint8_t MorseCodeChar::size() const {
    return this->repr.size();
}
