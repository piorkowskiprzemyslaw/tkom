/*
 * Token.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <util/Token.h>

/*
 * Konstruktor.
 */
Token::Token() noexcept : type( TokenType::WRONG_TYPE ) {}

/*
 * Konstruktor w oparciu o TokenType.
 */
Token::Token(const TokenType type, const std::string character ) noexcept : type(type), character(character) {}

/*
 * Desktruktor
 */
Token::~Token(){}

/*
 * Konstrutkor kopiujący.
 */
Token::Token(const Token & token) noexcept : type(token.type), character(token.character) { }

/*
 * Operator przypisania.
 */
Token & Token::operator=(const Token & rhs) noexcept{
	this->type = rhs.type;
	this->character = rhs.character;
	return *this;
}

/*
 * Pobiera typ tokenu.
 */
TokenType Token::getType() noexcept{
	return type;
}

/*
 * Sprawdzenie czy token jest symbolem alfabetu.
 */
bool Token::isAlphabetSymbol() noexcept {
	if ( type >= TokenType::a && type <= TokenType::DOT){
		return true;
	}
	return false;
}

/*
 * Sprawdzenie czy token jest operatorem.
 */
bool Token::isOperator() noexcept {
	if(type >= TokenType::CONCATENATION && type <= TokenType::MULTIPLICATION){
		return true;
	}
	return false;
}

/*
 * Zwraca prio opertaora. Jeśli token nie jest operatorem zwraca -1.
 */
int Token::getOperatorPrio() noexcept {

	if(type == TokenType::PARENTHESIS_LEFT || type == TokenType::PARENTHESIS_RIGHT){
		return 4;
	}

	if(type == TokenType::MULTIPLICATION || type == TokenType::PLUS){
		return 3;
	}

	if(type == TokenType::OR){
		return 2;
	}

	if(type == TokenType::CONCATENATION){
		return 1;
	}

	return -1;
}

/*
 * Czy operator jest jedno-argumentowy.
 */
bool Token::isOneOperandOperator() noexcept {
	if(type == TokenType::MULTIPLICATION || type == TokenType::PLUS ){
		return true;
	}
	return false;
}

/*
 * Czy operator jest dwu-argumentowy.
 */
bool Token::isTwoOperandOperator() noexcept {
	if(type == TokenType::OR || type == TokenType::CONCATENATION){
		return true;
	}
	return false;
}

/*
 * Czy operator ma wiazanie RL
 */
bool Token::isRLOperator() noexcept {
	if(type == TokenType::MULTIPLICATION || type == TokenType::PLUS){
		return true;
	}

	return false;
}

/*
 * Czy operator ma wiązanie LR.
 */
bool Token::isLROperator() noexcept{
	if(type == TokenType::OR || type == TokenType::CONCATENATION){
		return true;
	}
	return false;
}

/*
 * Czy operator jest nawiasem otwierajacym.
 */
bool Token::isOpeningParenthesis() noexcept{
	if(type == TokenType::PARENTHESIS_LEFT)
		return true;
	return false;
}

/*
 * Czy operator jest nawiasem zamykającym.
 */
bool Token::isClosingParenthesis() noexcept {
	if(type == TokenType::PARENTHESIS_RIGHT)
		return true;
	return false;
}

/*
 * Czy jest symbolem terminalnym.
 */
bool Token::isTerminate() noexcept {
	if(type == TokenType::TERMINATE){
		return true;
	}
	return false;
}
