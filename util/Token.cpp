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
Token::Token() : type( TokenType::WRONG_TYPE ) {}

/*
 * Konstruktor w oparciu o TokenType.
 */
Token::Token(const TokenType type, const std::string character ) : type(type), character(character) {}

/*
 * Desktruktor
 */
Token::~Token(){}

/*
 * Konstrutkor kopiujący.
 */
Token::Token(const Token & token) : type(token.type), character(token.character) { }

/*
 * Operator przypisania.
 */
Token & Token::operator=(const Token & rhs) {
	this->type = rhs.type;
	this->character = rhs.character;
	return *this;
}

/*
 * Pobiera znak związany z tokenem.
 */
const std::string Token::getCharacter() {
	return character;
}

/*
 * Pobiera typ tokenu.
 */
TokenType Token::getType(){
	return type;
}

/*
 * Sprawdzenie czy token jest symbolem alfabetu.
 */
bool Token::isAlphabetSymbol() {
	if ( type >= TokenType::a && type <= TokenType::TERMINATE){
		return true;
	}
	return false;
}

/*
 * Sprawdzenie czy token jest operatorem.
 */
bool Token::isOperator() {
	if(type >= TokenType::CONCATENATION && type <= TokenType::MULTIPLICATION){
		return true;
	}
	return false;
}

/*
 * Zwraca prio opertaora. Jeśli token nie jest operatorem zwraca -1.
 */
int Token::getOperatorPrio() {

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
bool Token::isOneOperandOperator() {
	if(type == TokenType::MULTIPLICATION || type == TokenType::PLUS ){
		return true;
	}
	return false;
}

/*
 * Czy operator jest dwu-argumentowy.
 */
bool Token::isTwoOperandOperator() {
	if(type == TokenType::OR || type == TokenType::CONCATENATION){
		return true;
	}
	return false;
}

/*
 * Czy operator ma wiazanie RL
 */
bool Token::isRLOperator() {
	if(type == TokenType::MULTIPLICATION || type == TokenType::PLUS){
		return true;
	}

	return false;
}

/*
 * Czy operator ma wiązanie LR.
 */
bool Token::isLROperator() {
	if(type == TokenType::OR || type == TokenType::CONCATENATION){
		return true;
	}
	return false;
}

/*
 * Czy operator jest nawiasem otwierajacym.
 */
bool Token::isOpeningParenthesis(){
	if(type == TokenType::PARENTHESIS_LEFT)
		return true;
	return false;
}

/*
 * Czy operator jest nawiasem zamykającym.
 */
bool Token::isClosingParenthesis() {
	if(type == TokenType::PARENTHESIS_RIGHT)
		return true;
	return false;
}

/*
 * Czy jest symbolem terminalnym.
 */
bool Token::isTerminate() {
	if(type == TokenType::TERMINATE){
		return true;
	}
	return false;
}

/*
 * Czy jest symbolem konkatenacji.
 */
bool Token::isConcatenation() {
	if(type == TokenType::CONCATENATION){
		return true;
	}
	return false;
}

/*
 * Czy jest symbolem or.
 */
bool Token::isOr() {
	if(type == TokenType::OR){
		return true;
	}
	return false;
}

/*
 * Czy jest symbolem plus.
 */
bool Token::isPlus() {
	if(type == TokenType::PLUS){
		return true;
	}
	return false;
}

/*
 * Czy jest symbolem multiplication
 */
bool Token::isMultiplication() {
	if(type == TokenType::MULTIPLICATION ){
		return true;
	}
	return false;
}
