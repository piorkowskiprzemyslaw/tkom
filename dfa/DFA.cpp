/*
 * DFA.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <dfa/DFA.h>

DFA::DFA(const std::shared_ptr<Tree> tree) {
	this->tree = tree;
	buildDFA();
}

DFA::~DFA() { }

void DFA::buildDFA() {
	states.emplace_back( std::make_shared<State>( tree->getRoot()->first() ) );
	std::set<std::shared_ptr<Position>, PositionComapre> workingSet;
	auto & follows = tree->getFollows();

	for(auto state : states) {
		for(auto token = 0 ; token <= static_cast<int>(TokenType::DOT) ; ++token) {

			for(auto pos : state->getFollowedPositions()) {
				if(pos->getToken()->getType() == static_cast<TokenType>(token) || pos->getToken()->isDot() ) {
					SetUtility::addSets(workingSet, follows[pos]);
				}
			}

			if(! workingSet.empty() ) {
				state->addTransition( std::make_pair(static_cast<TokenType>(token), addToStates(workingSet)));
				workingSet.clear();
			}

		}

	}
}

/*
 * Dodaj stan reprezentowany za pomocą set do zbioru stanów i zwróć shared_ptr na ten stan.
 * Jeśli istnieje już taki stan to nie dodawaj tylko zwróc shared_ptr na ten stan.
 */
std::shared_ptr<State> DFA::addToStates(std::set< std::shared_ptr<Position>, PositionComapre > & set) {

	for(auto state : states){
		if( *state == set ){
			return state;
		}
	}
	// nie ma takiego stanu w juz istniejącym zbiorze stanów.
	states.emplace_back( std::make_shared<State>(set) );
	return states.back();
}

/*
 * Sprawdza czy sekwencja tokenów nalezy do jezyka opisywanego przez automat.
 */
bool DFA::checkWord(const std::list<std::shared_ptr<Token> > & tokens) {
	auto actualState = states.front();

	for(auto token : tokens){

		try {
			actualState = actualState->goToState(token->getType());
		} catch (DFAException & e) {
			return false;
		}
	}

	if(actualState->isTerminateState()){
		return true;
	}

	return false;
}
