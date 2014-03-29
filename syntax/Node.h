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

protected:
	void setParent(std::shared_ptr<Node> newParent);
	const std::shared_ptr<Token> getToken() const;

public:
	Node(std::shared_ptr<Token> token, std::shared_ptr<Node> parent);
	virtual ~Node();

	virtual void nullable() const = 0;
	virtual void first() const  = 0;
	virtual void last() const = 0;
	virtual void follow() const = 0;
};
#endif /* NODE_H_ */
