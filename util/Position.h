/*
 * Position.h
 *
 *  Created on: 4 kwi 2014
 *      Author: przemek
 */

#ifndef POSITION_H_
#define POSITION_H_

#include <memory>
#include <util/Token.h>

class Position {
private:
	unsigned int number;
	std::shared_ptr<Token> token;

public:
	Position(const unsigned int number, const std::shared_ptr<Token> token);
	~Position();
	bool operator<(const Position & rhs) const;
	bool operator==(const Position & rhs) const;
	unsigned int getNumber() const;
	std::shared_ptr<Token> getToken() const;

	friend std::ostream & operator<<(std::ostream & os, const Position & position)
	{
		os << "N: " << position.number << "  C: " << *(position.token);
		return os;
	}

};

#endif /* POSITION_H_ */
