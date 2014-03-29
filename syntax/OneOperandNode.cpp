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
OneOperandNode::OneOperandNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent = nullptr, std::shared_ptr<Node> child = nullptr) : Node(token, parent) {
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
bool OneOperandNode::addChild(std::shared_ptr<Node> child) {
	// TODO
	return false;
}

/*
 * Metoda nullable.
 */
void OneOperandNode::nullable() const {
	// TODO
}

/*
 * Metoda first.
 */
void OneOperandNode::first() const {
	// TODO
}

/*
 * Metoda last.
 */
void OneOperandNode::last() const {
	// TODO
}

/*
 * Metoda follow.
 */
void OneOperandNode::follow() const {
	// TODO
}
