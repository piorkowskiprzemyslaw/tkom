/*
 * Tree.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <syntax/Tree.h>

/*
 * Konstruktor.
 */
Tree::Tree(std::shared_ptr<Node> root) {
	this->root = root;
	this->height = computeHeight(this->root);
}

/*
 * Destruktor.
 */
Tree::~Tree() { }

/*
 * Obliczenie wysokości drzewa.
 */
int Tree::computeHeight(std::shared_ptr<Node> begin) {

	if( std::shared_ptr<TerminateNode> tn = std::dynamic_pointer_cast<TerminateNode>(begin) ){
		return 0;
	} else if ( std::shared_ptr<OneOperandNode> oon = std::dynamic_pointer_cast<OneOperandNode>(begin) ){
		return 1 + computeHeight( oon->getChild() );
	} else if ( std::shared_ptr<TwoOperandNode> ton = std::dynamic_pointer_cast<TwoOperandNode>(begin) ){
		int leftChild = computeHeight( ton->getLeftChild() );
		int rightChild = computeHeight( ton->getRightChild() );

		return (leftChild > rightChild ? leftChild + 1 : rightChild + 1);
	}

	throw SyntaxException("Unresolved type of node");
}
