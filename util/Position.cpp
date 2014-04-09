/*
 * Position.cpp
 *
 *  Created on: 4 kwi 2014
 *      Author: przemek
 */

#include <util/Position.h>

unsigned int Position::counter = 0;

Position::Position(const std::shared_ptr<Token> token) {
	this->number = counter++;
	this->token = token;
}

Position::~Position() { }

bool Position::operator<(const Position & rhs) const {
	if( (number == rhs.number) && (token->getType() != rhs.token->getType() ) ){
		throw "Position comapre CRITICAL ERROR!";
	}

	return ( number < rhs.number );
}

bool Position::operator==(const Position & rhs) const {
	if( (token->getType() == rhs.token->getType()) &&
		(number == rhs.number) ) {
		return true;
	}
	return false;
}

unsigned int Position::getNumber() const {
	return number;
}

std::shared_ptr<Token> Position::getToken() const {
	return token;
}
