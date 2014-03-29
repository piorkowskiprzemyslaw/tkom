/*
 * Syntax.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <syntax/Syntax.h>

/*
 * Konstruktor
 */
Syntax::Syntax(const std::list<std::shared_ptr<Token> > & detectedTokens) noexcept {
	tokens = detectedTokens;
}

/*
 * Destruktor.
 */
Syntax::~Syntax() { }

/*
 * Meotda wykonująca budowe drzewa.
 */
void Syntax::buildTree() {
	runShutingYardAlgorithm();
}

/*
 * Uruchamia algorytm shuting yard dla listy tokenów.
 */
void Syntax::runShutingYardAlgorithm() {
	std::stack< std::shared_ptr<Token> > stack;

	for(auto token : tokens){

		if( token->isAlphabetSymbol() ){
			rpn.push_back(token);
			continue;
		}

		if( token->isLROperator() ){
			while ( !(stack.empty() || stack.top()->isOpeningParenthesis() || stack.top()->getOperatorPrio() < token->getOperatorPrio()) ){
				rpn.push_back(stack.top());
				stack.pop();
			}
			stack.push(token);
			continue;
		}

		if( token->isRLOperator() ) {
			while ( !(stack.empty() || stack.top()->isOpeningParenthesis() || stack.top()->getOperatorPrio() <= token->getOperatorPrio()) ){
				rpn.push_back(stack.top());
				stack.pop();
			}
			stack.push(token);
			continue;
		}

		if( token->isOpeningParenthesis() ) {
			stack.push(token);
			continue;
		}

		if( token->isClosingParenthesis() ) {
			while( !( stack.top()->isOpeningParenthesis() ) ){

				if(stack.empty()){
					throw SyntaxException("Opening parenthesis didn't found");
				}

				rpn.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}


	}

	while( !stack.empty() ){

		if ( stack.top()->isOpeningParenthesis() ){
			throw SyntaxException("Closing parenthesis didn't found");
		}

		rpn.push_back(stack.top());
		stack.pop();
	}
}

/*
 * Uruchamia przeksztalcenie listy tokenów zapisanych w rpn
 * do postaci drzewa skladniowego.
 */
void Syntax::rpnToAST() {
	// TODO
}

/*
 * Pobiera drzewo.
 */
const std::shared_ptr<Tree> Syntax::getTree() noexcept {
	return tree;
}

/*
 * Pobiera liste tokenów w postaci rpn.
 */
const std::list<std::shared_ptr<Token> > Syntax::getRPNTokens() noexcept {
	return rpn;
}
