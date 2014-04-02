/*
 * TerminateNode.cpp
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#include <syntax/TerminateNode.h>

unsigned int TerminateNode::counter = 0;

/*
 * Konstruktor
 */
TerminateNode::TerminateNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent) : Node(token,parent) {
	id = ++counter;
}

/*
 * Destruktor
 */
TerminateNode::~TerminateNode() { }

/*
 * Metoda nullable.
 */
void TerminateNode::nullable() const {
	// TODO
}

/*
 * Metoda first.
 */
void TerminateNode::first() const {
	// TODO
}

/*
 * Metoda last.
 */
void TerminateNode::last() const {
	// TODO
}

/*
 * Metoda follow.
 */
void TerminateNode::follow() const {
	// TODO
}
