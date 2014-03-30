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

class OneOperandNode : public Node {
private:
	std::shared_ptr<Node> child;

public:
	OneOperandNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent = nullptr, std::shared_ptr<Node> child = nullptr);
	virtual ~OneOperandNode();

	bool addChild(std::shared_ptr<Node> child, std::shared_ptr<OneOperandNode> parent);

	void nullable() const override;
	void first() const override;
	void last() const override;
	void follow() const override;
};

#endif /* ONEOPERANDNODE_H_ */
