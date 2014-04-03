/*
 * Tree.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <syntax/Tree.h>

/*
 * Konstruktor.
 */
Tree::Tree(std::shared_ptr<Node> root) {
	this->root = root;
	this->height = root->height();
	std::cout << "Creating tree : Height = " << height << std::endl;
}

/*
 * Destruktor.
 */
Tree::~Tree() { }

