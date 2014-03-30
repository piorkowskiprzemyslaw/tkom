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
Syntax::Syntax(const std::list<std::shared_ptr<Token> > & detectedTokens) {
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
	initializeWorkingList();
	rpnToAST();
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

	for(auto it = workingList.begin() ; it != workingList.end() ; ++it ){

		if(std::shared_ptr<TerminateNode> tn = std::dynamic_pointer_cast<TerminateNode>(*it) ){
			//std::cout << "After TN" << std::endl;
			continue;
		}

		if(std::shared_ptr<OneOperandNode> oon = std::dynamic_pointer_cast<OneOperandNode>(*it) ) {
			auto oneBefore = it;
			oneBefore--;

			if(checkWorkingListIterator(oneBefore, oon->getToken()->getCharacter())){
				oon->addChild(*oneBefore, oon);
				workingList.erase(oneBefore);
			}
			//std::cout << "After OON" << std::endl;
			continue;
		}

		if(std::shared_ptr<TwoOperandNode> ton = std::dynamic_pointer_cast<TwoOperandNode>(*it) ){
			auto oneBefore = it, twoBefore = it;
			oneBefore--;
			twoBefore--;
			twoBefore--;

			if(checkWorkingListIterator(oneBefore, ton->getToken()->getCharacter() ) &&
			   checkWorkingListIterator(twoBefore, ton->getToken()->getCharacter() )
			   ){
				ton->addLeftChild(*twoBefore, ton);
				ton->addRightChild(*oneBefore, ton);
				workingList.erase(twoBefore);
				workingList.erase(oneBefore);
			}
			//std::cout << "After TON" << std::endl;
			continue;
		}

	}

}

/*
 * Sprawdza poprawność iteratora - czy nie przestawił się na koniec listy.
 */
bool Syntax::checkWorkingListIterator(std::list< std::shared_ptr<Node> >::iterator iterator, const std::string & operatorType){
	if(iterator == workingList.end()){
		std::string msg = "Missing operand for operator ";
		msg += operatorType;

		throw SyntaxException(msg);
	}
	return true;
}

/*
 * Inicjalizuje liste roboczą odpowiedniego typu nodami.
 */
void Syntax::initializeWorkingList() {
	for(auto token : rpn){
		workingList.push_back(NodeFactory::makeNode(token));
	}
}

/*
 * Pobiera drzewo.
 */
const std::shared_ptr<Tree> Syntax::getTree() {
	return tree;
}

/*
 * Pobiera liste tokenów w postaci rpn.
 */
const std::list<std::shared_ptr<Token> > Syntax::getRPNTokens() {
	return rpn;
}
