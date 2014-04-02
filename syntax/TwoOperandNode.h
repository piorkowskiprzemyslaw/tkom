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

class TwoOperandNode: public Node {
private:
	std::shared_ptr<Node> leftChild;
	std::shared_ptr<Node> rightChild;

public:
	TwoOperandNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent = nullptr, std::shared_ptr<Node> leftChild = nullptr, std::shared_ptr<Node> rightChild = nullptr);
	virtual ~TwoOperandNode();

	bool addLeftChild(std::shared_ptr<Node> leftChild, std::shared_ptr<TwoOperandNode> parent);
	std::shared_ptr<Node> getLeftChild() const;
	bool addRightChild(std::shared_ptr<Node> rightChild, std::shared_ptr<TwoOperandNode> parent);
	std::shared_ptr<Node> getRightChild() const;

	void nullable() const override;
	void first() const override;
	void last() const override;
	void follow() const override;
};

#endif /* TWOOPERANDNODE_H_ */
