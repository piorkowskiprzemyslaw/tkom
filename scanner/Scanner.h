/*
 * Scanner.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include <cstdio>
#include <cstdlib>

#include <util/Token.h>
#include <util/TokenType.h>
#include <scanner/ScannerException.h>

/*
 * Klasa umożliwiająca wyodrębnienie tokenów z wprowadzonego wyrażenia
 * regularnego.
 */
class Scanner {
private:
	std::string regex;
	std::list< std::shared_ptr<Token> > extractedTokens;

	Token getTokenizedCharacterType(const char & character) noexcept;
	void checkCharacter(const TokenType type, const int position);
	const std::string prepareExceptionMessage(const int position, const char character) noexcept;

public:
	explicit Scanner(const std::string & regex) noexcept;
	~Scanner();
	void tokenize();
	void tokenize(const std::string & sentence);
	const std::list< std::shared_ptr<Token> > & getTokens() noexcept;
	void printTokenList(std::ostream & os) noexcept;
};

#endif /* SCANNER_H_ */
