/*
 * SyntaxException.cpp
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#include <syntax/SyntaxException.h>

/*
 * Konstruktor.
 */
SyntaxException::SyntaxException(const std::string & msg) {
	message = "SyntaxExepction : " ;
	message += msg;
}

/*
 * Desktruktor.
 */
SyntaxException::~SyntaxException() { }

/*
 * Nadpisana metoda what klasy exception.
 */
const char * SyntaxException::what() const noexcept {
	return message.c_str();
}
