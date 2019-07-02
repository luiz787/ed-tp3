#ifndef ED_TP3_MORSE_CODE_CHAR_HPP
#define ED_TP3_MORSE_CODE_CHAR_HPP

#include <string>
/*
 * This class encapsulates a morse code string, with up to five characters, that represents an alphanumeric
 * character.
 */
class MorseCodeChar {
public:
    /*
     * MorseCodeChar constructor.
     *
     * @param repr - the morse code string
     */
	explicit MorseCodeChar(std::string repr);
	/*
	 * MorseCodeChar destructor.
	 */
	~MorseCodeChar();
	/*
	 * Returns the character at pos of the repr string.
	 *
	 * @param pos - position of interest.
	 *
	 * @returns char - char at that position.
	 */
	char charAt(int pos) const;
    /*
     * Returns the size of the morse code string representation.
     *
     * @returns size - size of the morse code string representation.
    */
	uint8_t size() const;
private:
	std::string repr; // String that contains the morse code character representation.
};

#endif