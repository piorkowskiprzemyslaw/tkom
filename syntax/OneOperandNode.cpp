/*
 * OneOperandNode.cpp
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#include <syntax/OneOperandNode.h>

/*
 * Konstruktor
 */
OneOperandNode::OneOperandNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent, std::shared_ptr<Node> child) : Node(token, parent) {
	this->child = child;
}

/*
 * Destruktor
 */
OneOperandNode::~OneOperandNode() { }

/*
 * Dodaj dziecko. Jeśli wczesniej dziecko było już ustawione to
 * metoda zwraca false i nie zmienia ustawionego potomka.
 */
bool OneOperandNode::addChild(std::shared_ptr<Node> child, std::shared_ptr<OneOperandNode> parent) {
	if(this->child == nullptr){
		this->child = child;
		this->child->setParent( parent );
		return true;
	}
	return false;
}

/*
 * Zwraca shared_ptr na dziecko.
 */
std::shared_ptr<Node> OneOperandNode::getChild() const {
	return child;
}

/*
 * Zwraca wysokość drzewa zaczynającego się w tym węźle.
 */
int OneOperandNode::height() const {
	if(child != nullptr ){
		return child->height() + 1;
	}
	return 0;
}

/*
 * Metoda nullable.
 */
bool OneOperandNode::nullable() const {
	if( this->getToken()->isMultiplication() ){
		return true;
	}

	if( this->getToken()->isMultiplication() ){
		return false;
	}

	return false;
}

/*
 * Metoda first.
 */
std::set< std::shared_ptr<Position>, PositionComapre> OneOperandNode::first() const {
	return child->first();
}

/*
 * Metoda last.
 */
std::set< std::shared_ptr<Position>, PositionComapre> OneOperandNode::last() const {
	return child->last();
}

/*
 * Metoda follow.
 */
void OneOperandNode::follow(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const {
	for(auto position : last()){
		SetUtility::addSets(map[position], first());
	}
	child->follow(map);
}

/*
 * Inicjalizowanie mapy.
 */
void OneOperandNode::initializeMap(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const {
	child->initializeMap(map);
}
