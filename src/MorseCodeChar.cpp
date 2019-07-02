#include <utility>
#include "MorseCodeChar.hpp"

/*
 * Default constructor.
 */
MorseCodeChar::MorseCodeChar(std::string repr) : repr(std::move(repr)) {}

/*
 * Default destructor.
 */
MorseCodeChar::~MorseCodeChar() = default;

/*
* Returns the character at pos of the repr string.
*
* @param pos - position of interest.
*
* @returns char - char at that position.
*/
char MorseCodeChar::charAt(int pos) const {
	return this->repr[pos];
}

/*
 * Returns the size of the morse code string representation.
 *
 * @returns size - size of the morse code string representation.
 */
uint8_t MorseCodeChar::size() const {
    return this->repr.size();
}
