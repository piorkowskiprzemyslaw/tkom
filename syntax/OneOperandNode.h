/*
 * OneOperandNode.h
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#ifndef ONEOPERANDNODE_H_
#define ONEOPERANDNODE_H_

#include <syntax/Node.h>

#include <memory>

class OneOperandNode : protected Node {
private:
	std::shared_ptr<Node> child;

public:
	OneOperandNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent, std::shared_ptr<Node> child);
	virtual ~OneOperandNode();

	bool addChild(std::shared_ptr<Node> child);

	void nullable() const override;
	void first() const override;
	void last() const override;
	void follow() const override;
};

#endif /* ONEOPERANDNODE_H_ */
