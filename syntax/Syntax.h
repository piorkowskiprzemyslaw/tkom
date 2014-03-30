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
#include <vector>

#include <util/Token.h>
#include <syntax/Tree.h>
#include <syntax/SyntaxException.h>
#include <syntax/NodeFactory.h>
#include <syntax/TerminateNode.h>
#include <syntax/OneOperandNode.h>
#include <syntax/TwoOperandNode.h>

/*
 * Klasa odpowiedzialna za kontrolowanie poprawności składni przekazanych
 * tokenów reprezentujących wyrażenie regularne.
 */
class Syntax {
private:
	std::shared_ptr<Tree> tree;
	std::list<std::shared_ptr<Token> > tokens;
	std::list<std::shared_ptr<Token> > rpn;
	std::list<std::shared_ptr<Node> > workingList;

	void runShutingYardAlgorithm();
	void rpnToAST();
	void initializeWorkingList();
	bool checkWorkingListIterator(std::list< std::shared_ptr<Node> >::iterator iterator, const std::string & operatorType);

public:
	Syntax(const std::list<std::shared_ptr<Token> > & detectedTokens);
	~Syntax();
	void buildTree();
	const std::shared_ptr<Tree> getTree();
	const std::list< std::shared_ptr<Token> > getRPNTokens();

};

#endif /* SYNTAX_H_ */
