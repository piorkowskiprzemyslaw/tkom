/*
 * Node.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <vector>
#include <ogdf/basic/Graph.h>
#include <ogdf/basic/GraphAttributes.h>

#include <util/Token.h>
#include <util/Position.h>
#include <util/PositionComapre.h>
#include <util/SetUtility.h>

class Node {
private:
	std::weak_ptr<Node> parent;
	std::shared_ptr<Token> token;

public:
	Node(std::shared_ptr<Token> token, std::shared_ptr<Node> parent);
	virtual ~Node();
	void setParent(std::shared_ptr<Node> newParent);
	const std::shared_ptr<Token> getToken() const;
	virtual int height() const = 0;
	virtual bool nullable() const = 0;
	virtual std::set<std::shared_ptr<Position>, PositionComapre> first() const  = 0;
	virtual std::set<std::shared_ptr<Position>, PositionComapre> last() const = 0;
	virtual void follow(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const = 0;
	virtual void initializeMap(std::map< std::shared_ptr<Position>, std::set< std::shared_ptr<Position>, PositionComapre>, PositionComapre > & map) const = 0;
	virtual void createTreeReprezentation(ogdf::Graph & graph, ogdf::GraphAttributes & ga, ogdf::node * parent) const = 0;

	friend std::ostream & operator<<(std::ostream & os, const Node & node)
	{
		os.operator<<( node.token->getCharacter().c_str());
		return os;
	}
};
#endif /* NODE_H_ */
