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
#include <syntax/OneOperandNode.h>
#include <syntax/TwoOperandNode.h>
#include <syntax/TerminateNode.h>
#include <syntax/SyntaxException.h>

class Tree {
private:
	std::shared_ptr<Node> root;
	int height;

	int computeHeight(std::shared_ptr<Node> begin);

public:
	Tree(std::shared_ptr<Node> root);
	~Tree();
};

#endif /* TREE_H_ */
