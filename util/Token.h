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
	Token() noexcept;
	Token(const TokenType type,const std::string character = "") noexcept;
	Token(const Token & token) noexcept;
	Token & operator=(const Token & rhs) noexcept;
	~Token();

	TokenType getType() noexcept;
	bool isAlphabetSymbol() noexcept;
	bool isOperator() noexcept;
	int getOperatorPrio() noexcept;
	bool isOneOperandOperator() noexcept;
	bool isTwoOperandOperator() noexcept;
	bool isRLOperator() noexcept;
	bool isLROperator() noexcept;
	bool isOpeningParenthesis() noexcept;
	bool isClosingParenthesis() noexcept;
	bool isTerminate() noexcept;

	friend std::ostream & operator<<(std::ostream & os, const Token & token)
	{
		os<<token.character;
		return os;
	}
};

#endif /* TOKEN_H_ */
