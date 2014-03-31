/*
 * Syntax_test.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <syntax/Syntax.h>

#include <fstream>
#include <scanner/Scanner.h>
#include <scanner/ScannerException.h>
#include <syntax/SyntaxException.h>

extern std::string getInputTestDir(int number);

void syntaxTest(){
	std::ifstream ifile;
	std::string regex;

	for(int i = 1; i < 11 ; ++i){
		ifile.open(getInputTestDir(i));

		std::getline(ifile,regex);
		Scanner scanner(regex);

		std::cout << regex << std::endl;

		try{
		scanner.tokenize();
		} catch (ScannerException & e) {
			std::cout << e.what() << std::endl;
			ifile.close();
			regex.clear();
			continue;
		}

		Syntax syntax(scanner.getTokens());

		try{
			syntax.buildTree();
		} catch ( SyntaxException & e) {
			std::cout << e.what() << std::endl;
			ifile.close();
			regex.clear();
			continue;
		}

		for ( auto token : syntax.getRPNTokens( ) ) {
			std::cout << ( token->getCharacter( ) ) << " ";
		}
		std::cout << std::endl;

		regex.clear();
		ifile.close();
	}
}
