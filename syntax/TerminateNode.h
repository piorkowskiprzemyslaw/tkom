/*
 * TerminateNode.h
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#ifndef TERMINATENODE_H_
#define TERMINATENODE_H_

#include <syntax/Node.h>
#include <memory>

class TerminateNode: protected Node {
public:
	TerminateNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent);
	virtual ~TerminateNode();

	void nullable() const override;
	void first() const override;
	void last() const override;
	void follow() const override;
};

#endif /* TERMINATENODE_H_ */
