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
	initializeFollows();
	this->root->follow(follows);
}

/*
 * Destruktor.
 */
Tree::~Tree() { }

/*
 * Inicjalizacja mapy follows dla każdego z nodów.
 */
void Tree::initializeFollows() {
	root->initializeMap(follows);
}

/*
 * Wydrukowanie mapy follows.
 */
void Tree::printFollows() const {

	for(auto position : follows){
		std::cout << (*position.first) << " => ";
		for(auto setElem : position.second ){
			std::cout << (*setElem) << "; ";
		}
		std::cout << std::endl;
	}
}

/*
 * Pobranie korzenia drzewa.
 */
std::shared_ptr<Node> Tree::getRoot() const {
	return root;
}

/*
 * Pobranie referencji do follows.
 */
std::map< std::shared_ptr<Position>, std::set<std::shared_ptr<Position>, PositionComapre >, PositionComapre > & Tree::getFollows() {
	return follows;
}
