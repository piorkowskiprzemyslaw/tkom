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
