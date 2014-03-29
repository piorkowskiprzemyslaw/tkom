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
#include <memory>

#include <util/TokenType.h>

class State {
private:
	std::map<TokenType, std::shared_ptr<State> > transitions;
	int id;

public:
	State(int id);
	~State();
	void addTransition(std::pair<TokenType, std::weak_ptr<State> > transition);
	std::shared_ptr<State> goToState(TokenType token);
};

#endif /* STATE_H_ */
