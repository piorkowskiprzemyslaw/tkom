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
TwoOperandNode::TwoOperandNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent, std::shared_ptr<Node> leftChild, std::shared_ptr<Node> rightChild) : Node(token,parent) {
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
	if(this->leftChild == nullptr){
		this->leftChild = leftChild;
		this->leftChild->setParent( std::shared_ptr<TwoOperandNode>(this) );
		return true;
	}
	return false;
}

/*
 * Dodanie prawego dziecka
 */
bool TwoOperandNode::addRightChild(std::shared_ptr<Node> rightChild) {
	if(this->rightChild == nullptr){
		this->rightChild = rightChild;
		this->rightChild->setParent( std::shared_ptr<TwoOperandNode>(this) );
		return true;
	}
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
