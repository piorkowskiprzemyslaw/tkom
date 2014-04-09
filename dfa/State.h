/*
 * State.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef STATE_H_
#define STATE_H_

#include <iostream>
#include <map>
#include <set>
#include <memory>

#include <util/TokenType.h>
#include <util/PositionComapre.h>

class State {
private:
	static unsigned int idGenerator;
	int id;
	std::set< std::shared_ptr<Position>, PositionComapre > positions;
	std::map<TokenType, std::weak_ptr<State> > transitions;

public:
	explicit State(std::set< std::shared_ptr<Position>, PositionComapre > & set);
	explicit State(std::set< std::shared_ptr<Position>, PositionComapre > && set);
	~State();
	void addTransition(std::pair<TokenType, std::weak_ptr<State> > transition);
	bool operator==(const State & state) const;
	bool operator==(const std::set< std::shared_ptr<Position>, PositionComapre> & set) const;
	std::shared_ptr<State> goToState(TokenType token);
};

#endif /* STATE_H_ */
