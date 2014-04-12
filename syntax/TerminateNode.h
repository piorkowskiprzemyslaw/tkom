/*
 * TerminateNode.h
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#ifndef TERMINATENODE_H_
#define TERMINATENODE_H_

#include <memory>
#include <utility>
#include <syntax/Node.h>
#include <util/Position.h>

class TerminateNode: public Node {
private:
	std::shared_ptr<Position> position;
public:
	TerminateNode(std::shared_ptr<Token> token, std::shared_ptr<Node> parent = nullptr);
	virtual ~TerminateNode();
	int height() const override;
	bool nullable() const override;
	std::set< std::shared_ptr<Position>, PositionComapre> first() const override;
	std::set< std::shared_ptr<Position>, PositionComapre> last() const override;
	void follow(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const override;
	void initializeMap(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const override;
	void createTreeReprezentation(ogdf::Graph & graph, ogdf::GraphAttributes & ga, ogdf::node * parent) const override;
	std::shared_ptr<Position> getPosition() const;
};

#endif /* TERMINATENODE_H_ */
