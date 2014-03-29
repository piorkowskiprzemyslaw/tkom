/*
 * TwoOperandNode.cpp
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#include <syntax/TwoOperandNode.h>

/*
 * Konstruktor
 */
TwoOperandNode::TwoOperandNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent = nullptr, std::shared_ptr<Node> leftChild = nullptr, std::shared_ptr<Node> rightChild = nullptr) : Node(token,parent) {
	this->leftChild = leftChild;
	this->rightChild = rightChild;

}

/*
 * Destruktor
 */
TwoOperandNode::~TwoOperandNode() { }

/*
 * Dodanie lewego dziecka
 */
bool TwoOperandNode::addLeftChild(std::shared_ptr<Node> leftChild) {
	// TODO
	return false;
}

/*
 * Dodanie prawego dziecka
 */
bool TwoOperandNode::addRightChild(std::shared_ptr<Node> rightChild) {
	// TODO
	return false;
}

/*
 * Metoda nullable.
 */
void TwoOperandNode::nullable() const {
	// TODO
}

/*
 * Metoda first.
 */
void TwoOperandNode::first() const {
	// TODO
}

/*
 * Metoda last.
 */
void TwoOperandNode::last() const {
	// TODO
}

/*
 * Metoda follow.
 */
void TwoOperandNode::follow() const {
	// TODO
}
