/*
 * NodeFactory.cpp
 *
 *  Created on: 30 mar 2014
 *      Author: przemek
 */

#include <syntax/NodeFactory.h>

NodeFactory::NodeFactory() { }

NodeFactory::~NodeFactory() { }

std::shared_ptr<Node> NodeFactory::makeNode(std::shared_ptr<Token> token) {

	if(token->isAlphabetSymbol()){
		return std::shared_ptr<TerminateNode>(new TerminateNode(token));
	}

	if(token->isOneOperandOperator()){
		return std::shared_ptr<OneOperandNode>(new OneOperandNode(token));
	}

	if(token->isTwoOperandOperator()){
		return std::shared_ptr<TwoOperandNode>(new TwoOperandNode(token));
	}

	return nullptr;
}
