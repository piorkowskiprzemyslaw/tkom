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
extern std::string getOutputTestDir(int number);

void syntaxTest(){
	std::ifstream ifile;
	std::ofstream ofile;
	std::string regex;

	for(int i = 1; i < 16 ; ++i){
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

		ofile.close();
		regex.clear();
		ifile.close();
	}
}
