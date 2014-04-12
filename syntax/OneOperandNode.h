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
	std::shared_ptr<Node> getChild() const;
	int height() const override;
	bool nullable() const override;
	std::set< std::shared_ptr<Position>, PositionComapre> first() const override;
	std::set< std::shared_ptr<Position>, PositionComapre> last() const override;
	void follow(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const override;
	void initializeMap(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const override;
	void createTreeReprezentation(ogdf::Graph & graph, ogdf::GraphAttributes & ga, ogdf::node * parent) const override;
};

#endif /* ONEOPERANDNODE_H_ */
