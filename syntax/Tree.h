/*
 * Tree.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <memory>

#include <syntax/Node.h>

class Tree {
private:
	std::shared_ptr<Node> root;
	int height;

public:
	Tree(std::shared_ptr<Node> root);
	~Tree();
};

#endif /* TREE_H_ */
