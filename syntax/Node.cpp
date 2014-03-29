/*
 * Node.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <syntax/Node.h>

Node::Node(std::shared_ptr<Token> token, std::shared_ptr<Node> parent) : parent(parent) , token(token) { }

Node::~Node() { }

void Node::setParent(std::shared_ptr<Node> newParent) {
	parent = newParent;
}

const std::shared_ptr<Token> Node::getToken() const {
	return token;
}
