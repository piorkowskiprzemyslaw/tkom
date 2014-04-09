/*
 * TerminateNode.cpp
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#include <syntax/TerminateNode.h>

/*
 * Konstruktor
 */
TerminateNode::TerminateNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent) : Node(token,parent) {
	position = std::make_shared<Position>(this->getToken());
}

/*
 * Destruktor
 */
TerminateNode::~TerminateNode() { }

/*
 * Zwaraca wysokosc drzewa zaczynajacego się w tym węźle.
 */
int TerminateNode::height() const {
	return 0;
}

/*
 * Metoda nullable.
 */
bool TerminateNode::nullable() const {
	return false;
}

/*
 * Metoda first.
 */
std::set< std::shared_ptr<Position>, PositionComapre> TerminateNode::first() const {
	std::set<std::shared_ptr<Position>, PositionComapre> returned;
	returned.insert(this->position);
	return returned;
}

/*
 * Metoda last.
 */
std::set< std::shared_ptr<Position>, PositionComapre> TerminateNode::last() const {
	std::set<std::shared_ptr<Position>, PositionComapre> returned;
	returned.insert(this->position);
	return returned;
}

/*
 * Metoda follow.
 */
void TerminateNode::follow(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const {
	return;
}

/*
 * Inicjalizacja mapy follow/
 */
void TerminateNode::initializeMap(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const{
	map.insert( std::make_pair( position, std::set< std::shared_ptr<Position>, PositionComapre>() ) );
}

/*
 * Zwraca odpowiadającą stanowi pozycje.
 */
std::shared_ptr<Position> TerminateNode::getPosition() const {
	return position;
}
