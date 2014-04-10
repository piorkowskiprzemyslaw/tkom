/*
 * State.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <dfa/State.h>

unsigned int State::idGenerator = 0;

State::State(std::set< std::shared_ptr<Position>, PositionComapre > & set) {
	id = idGenerator++;
	std::swap(set,positions);
}

State::State(std::set< std::shared_ptr<Position>, PositionComapre > && set) {
	id = idGenerator++;
	positions = std::move(set);
}

State::~State() { }

bool State::operator==(const State & state) const {
	if(id == state.id)
		return true;
	return false;
}

bool State::operator==(const std::set< std::shared_ptr<Position>, PositionComapre> & set) const {
	if(positions.size() != set.size())
		return false;

	for(auto element : positions){
		if(set.find(element) == set.end())
			return false;
	}

	return true;
}

const std::set< std::shared_ptr<Position>, PositionComapre > & State::getFollowedPositions() const {
	return positions;
}

void State::addTransition( std::pair< TokenType, std::weak_ptr<State> > transition){
	transitions.emplace(transition);
}

std::shared_ptr<State> State::goToState(TokenType token) {
	auto iterator = transitions.find(token);

	if(iterator == transitions.end()){
		throw DFAException("Unhandled transistion");
	}

	return iterator->second.lock();
}

bool State::isTerminateState() const {

	for(auto position : positions){
		if(position->getToken()->isTerminate()){
			return true;
		}
	}

	return false;
}
