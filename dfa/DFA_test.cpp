/*
 * DFA_test.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <dfa/DFA.h>

#include <syntax/Syntax.h>
#include <fstream>
#include <scanner/Scanner.h>
#include <scanner/ScannerException.h>
#include <syntax/SyntaxException.h>

extern std::string getInputTestDir(int number);
extern std::string getOutputTestDir(int number);

void dfaTest(){
	std::ifstream ifile;
	std::ofstream ofile;
	std::string regex;

	for(int i = 4; i < 5 ; ++i){
		ifile.open(getInputTestDir(i));
		ofile.open(getOutputTestDir(i), std::ofstream::trunc );

		std::getline(ifile,regex);
		Scanner scanner(regex);

		ofile << regex << std::endl;

		try{
		scanner.tokenize();
		} catch (ScannerException & e) {
			ofile << e.what() << std::endl;
			ofile.close();
			ifile.close();
			regex.clear();
			continue;
		}

		scanner.printTokenList(ofile);

		Syntax syntax(scanner.getTokens());

		try{
			syntax.buildTree();
		} catch ( SyntaxException & e) {
			ofile << e.what() << std::endl;
			ofile.close();
			ifile.close();
			regex.clear();
			continue;
		}

		for ( auto token : syntax.getRPNTokens( ) ) {
			ofile << ( token->getCharacter( ) ) << " ";
		}
		ofile << std::endl;

		DFA dfa(syntax.getTree());
		ofile << dfa;

		ofile.close();
		regex.clear();
		ifile.close();
	}
}
