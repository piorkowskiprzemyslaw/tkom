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
	std::shared_ptr<Node> leftChild;
	std::shared_ptr<Node> rightChild;
	std::shared_ptr<Token> token;
	unsigned int id;
	unsigned int leftChildrenPlaces;

public:
	Node(std::shared_ptr<Node> parent, std::shared_ptr<Token> token);
	~Node();
	void nullable();
	void first();
	void last();
	void follow();
};
#endif /* NODE_H_ */
