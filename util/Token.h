/*
 * Token.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>
#include <util/TokenType.h>

class Token {
private:
	TokenType type;
	std::string character;
public:
	Token();
	Token(const TokenType type,const std::string character = "");
	Token(const Token & token);
	Token & operator=(const Token & rhs);
	~Token();
	const std::string getCharacter();
	TokenType getType();
	bool isAlphabetSymbol();
	bool isOperator();
	int getOperatorPrio();
	bool isOneOperandOperator();
	bool isTwoOperandOperator();
	bool isRLOperator();
	bool isLROperator();
	bool isOpeningParenthesis();
	bool isClosingParenthesis();
	bool isTerminate();
	bool isConcatenation();
	bool isOr();
	bool isPlus();
	bool isMultiplication();

	friend std::ostream & operator<<(std::ostream & os, const Token & token)
	{
		os << token.character;
		return os;
	}
};

#endif /* TOKEN_H_ */
