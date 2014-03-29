/*
 * TwoOperandNode.h
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#ifndef TWOOPERANDNODE_H_
#define TWOOPERANDNODE_H_

#include <syntax/Node.h>
#include <memory>

class TwoOperandNode: protected Node {
private:
	std::shared_ptr<Node> leftChild;
	std::shared_ptr<Node> rightChild;

public:
	TwoOperandNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent, std::shared_ptr<Node> leftChild, std::shared_ptr<Node> rightChild);
	virtual ~TwoOperandNode();

	bool addLeftChild(std::shared_ptr<Node> leftChild);
	bool addRightChild(std::shared_ptr<Node> rightChild);

	void nullable() const override;
	void first() const override;
	void last() const override;
	void follow() const override;
};

#endif /* TWOOPERANDNODE_H_ */
