/*
 * Syntax.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef SYNTAX_H_
#define SYNTAX_H_

#include <iostream>
#include <list>
#include <memory>
#include <stack>

#include <util/Token.h>
#include <syntax/Tree.h>

/*
 * Klasa odpowiedzialna za kontrolowanie poprawności składni przekazanych
 * tokenów reprezentujących wyrażenie regularne.
 */
class Syntax {
private:
	std::shared_ptr<Tree> tree;
	std::list<std::shared_ptr<Token> > tokens;
	std::list<std::shared_ptr<Token> > rpn;

	void runShutingYardAlgorithm();
	void rpnToAST();

public:
	Syntax(const std::list<std::shared_ptr<Token> > & detectedTokens) noexcept;
	~Syntax();
	void buildTree();
	const std::shared_ptr<Tree> getTree() noexcept;
	const std::list< std::shared_ptr<Token> > getRPNTokens() noexcept;

};

#endif /* SYNTAX_H_ */
