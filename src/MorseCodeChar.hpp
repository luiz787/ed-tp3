#ifndef ED_TP3_MORSE_CODE_CHAR_HPP
#define ED_TP3_MORSE_CODE_CHAR_HPP

#include <string>

class MorseCodeChar {
public:
	explicit MorseCodeChar(std::string repr);
	~MorseCodeChar();
	char charAt(int pos) const;
	uint8_t size() const;
private:
	std::string repr;
};

#endif