/*
 * NodeFactory.h
 *
 *  Created on: 30 mar 2014
 *      Author: przemek
 */

#ifndef NODEFACTORY_H_
#define NODEFACTORY_H_

#include <syntax/Node.h>
#include <syntax/TerminateNode.h>
#include <syntax/OneOperandNode.h>
#include <syntax/TwoOperandNode.h>
#include <memory>

class NodeFactory {
	NodeFactory();
	virtual ~NodeFactory();

public:

	static std::shared_ptr<Node> makeNode(std::shared_ptr<Token> token);

};

#endif /* NODEFACTORY_H_ */
