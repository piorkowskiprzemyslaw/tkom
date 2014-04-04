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
bool TwoOperandNode::addLeftChild(std::shared_ptr<Node> leftChild, std::shared_ptr<TwoOperandNode> parent) {
	if(this->leftChild == nullptr){
		this->leftChild = leftChild;
		this->leftChild->setParent( parent );
		return true;
	}
	return false;
}

/*
 * Pobranie shared_ptr'a na lewe dziecko.
 */
std::shared_ptr<Node> TwoOperandNode::getLeftChild() const {
	return leftChild;
}

/*
 * Dodanie prawego dziecka
 */
bool TwoOperandNode::addRightChild(std::shared_ptr<Node> rightChild, std::shared_ptr<TwoOperandNode> parent) {
	if(this->rightChild == nullptr){
		this->rightChild = rightChild;
		this->rightChild->setParent( parent );
		return true;
	}
	return false;
}

/*
 * Pobranie shared_ptr'a na prawe dziecko.
 */
std::shared_ptr<Node> TwoOperandNode::getRightChild() const {
	return rightChild;
}

/*
 * Wysokość drzewa rozpoczynającego się w tym węźle.
 */
int TwoOperandNode::height() const {
	int lChild = 0;
	int rChild = 0;

	if(leftChild != nullptr){
		lChild = leftChild->height();
	}
	if(rightChild != nullptr){
		rChild = rightChild->height();
	}
	if(leftChild == nullptr && rightChild == nullptr){
		return 0;
	}

	return (lChild > rChild ? lChild + 1 : rChild + 1);
}

/*
 * Metoda nullable.
 */
bool TwoOperandNode::nullable() const {
	if(getToken()->isOr()){
		return (leftChild->nullable() || rightChild->nullable());
	}

	if(getToken()->isConcatenation()){
		return (leftChild->nullable() && rightChild->nullable());
	}

	return false;
}

/*
 * Metoda first.
 */
std::set< std::shared_ptr<Position>, PositionComapre> TwoOperandNode::first() const {
	std::set< std::shared_ptr<Position>, PositionComapre > returned;
	if(getToken()->isOr()){
		SetUtility::addSets(returned, leftChild->first());
		SetUtility::addSets(returned,rightChild->first());
	} else if( getToken()->isConcatenation()){
		if(leftChild->nullable()){
			SetUtility::addSets(returned, leftChild->first());
			SetUtility::addSets(returned, rightChild->first());
		} else {
			SetUtility::addSets(returned, leftChild->first());
		}
	}

	return returned;
}

/*
 * Metoda last.
 */
std::set< std::shared_ptr<Position>, PositionComapre> TwoOperandNode::last() const {
	std::set< std::shared_ptr<Position>, PositionComapre > returned;
	if(getToken()->isOr()){
		SetUtility::addSets(returned, leftChild->last());
		SetUtility::addSets(returned,rightChild->last());
	} else if( getToken()->isConcatenation()){
		if(leftChild->nullable()){
			SetUtility::addSets(returned, rightChild->last());
			SetUtility::addSets(returned, leftChild->last());
		} else {
			SetUtility::addSets(returned, rightChild->last());
		}
	}
	return returned;
}

/*
 * Metoda follow.
 */
void TwoOperandNode::follow(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const {
	if(getToken()->isConcatenation()){
		auto rightChildFirstSet = rightChild->first();
		for(auto position : leftChild->last()){
			SetUtility::addSets(map[position], rightChildFirstSet);
		}
	}
	leftChild->follow(map);
	rightChild->follow(map);
}

/*
 * Inicjalizacja mapy follow.
 */
void TwoOperandNode::initializeMap(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const {
	leftChild->initializeMap(map);
	rightChild->initializeMap(map);
}
