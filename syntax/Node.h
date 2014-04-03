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

#include <util/Token.h>

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
	virtual void first() const  = 0;
	virtual void last() const = 0;
	virtual void follow() const = 0;

	friend std::ostream & operator<<(std::ostream & os, const Node & node)
	{
		os.operator<<( node.token->getCharacter().c_str());
		return os;
	}
};
#endif /* NODE_H_ */
