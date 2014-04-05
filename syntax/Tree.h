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
#include <map>
#include <set>

#include <syntax/Node.h>
#include <syntax/TerminateNode.h>
#include <syntax/OneOperandNode.h>
#include <syntax/TwoOperandNode.h>
#include <util/Position.h>
#include <util/PositionComapre.h>

class Tree {
private:
	std::shared_ptr<Node> root;
	std::map< std::shared_ptr<Position>, std::set<std::shared_ptr<Position>, PositionComapre >, PositionComapre > follows;
	int height;

	void initializeFollows();
public:
	Tree(std::shared_ptr<Node> root);
	~Tree();
	void printFollows() const;
};

#endif /* TREE_H_ */
