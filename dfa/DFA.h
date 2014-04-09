/*
 * DFA.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef DFA_H_
#define DFA_H_

#include <iostream>
#include <memory>
#include <list>

#include <dfa/State.h>
#include <syntax/Tree.h>
#include <syntax/Node.h>

class DFA {
private:
	std::shared_ptr<Tree> tree;
	std::shared_ptr<State> entrance;
	std::list< std::shared_ptr<State> > states;

	void buildDFA();
	std::shared_ptr<State> addToStates(const std::set<std::shared_ptr<Position>, PositionComapre> & set);

public:
	DFA(const std::shared_ptr<Tree> tree);
	~DFA();
	bool checkWord(const std::string word);
};

#endif /* DFA_H_ */
