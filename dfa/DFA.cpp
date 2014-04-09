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

	for(auto state : states) {


		// dla każdego symbolu wejściowego 'a'
		// jeśli pozycja p w state zawiera 'a' to dodaj
		// follow(p) do tymzcasowego zbioru

		if(! workingSet.empty() ) {

			//state->addTransition(std::make_pair())

			workingSet.clear();
		}
	}

}

/*
 * Dodaj stan reprezentowany za pomocą set do zbioru stanów i zwróć shared_ptr na ten stan.
 * Jeśli istnieje już taki stan to nie dodawaj tylko zwróc shared_ptr na ten stan.
 */
std::shared_ptr<State> DFA::addToStates(const std::set< std::shared_ptr<Position>, PositionComapre > & set) {

	for(auto state : states){
		if( state == set ){
			return state;
		}
	}
	// nie ma takiego stanu w juz istniejącym zbiorze stanów.
	states.emplace_back(set);
	return states.back();
}
