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
	int height() const override;
	bool nullable() const override;
	std::set< std::shared_ptr<Position>, PositionComapre> first() const override;
	std::set< std::shared_ptr<Position>, PositionComapre> last() const override;
	void follow(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const override;
	void initializeMap(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const override;
	void createTreeReprezentation(ogdf::Graph & graph, ogdf::GraphAttributes & ga, ogdf::node * parent) const override;
};

#endif /* TWOOPERANDNODE_H_ */
