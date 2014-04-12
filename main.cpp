//============================================================================
// Name        : tkom.cpp
// Author      : Przemysław Piórkowski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <list>
#include <memory>
#include <fstream>

#include <scanner/Scanner.h>
#include <scanner/ScannerException.h>
#include <syntax/Syntax.h>
#include <syntax/SyntaxException.h>
#include <dfa/DFA.h>

// print dfa information to specified file.
bool SHOW_DFA = false;
// print tree graph after creation.
bool SHOW_TREE = false;
// regex
bool REGEX = false;
// file with words to check
bool WORDS_FILE = false;
// help
bool HELP = false;


int main(int argc, char* argv[])
{
	std::string regex;
	std::string fileName;
	std::string dfaFileName;

	for( int i = 1 ; i < argc ; ++i){
		if( strcmp(argv[i], "-r") == 0 ){
			REGEX = true;
			regex = argv[++i];
			continue;
		}
		if( strcmp(argv[i], "-f") == 0 ) {
			WORDS_FILE = true;
			fileName = argv[++i];
			continue;
		}
		if( strcmp(argv[i], "-st") == 0 ) {
			SHOW_TREE = true;
			continue;
		}
		if( strcmp(argv[i], "-sa") == 0 ) {
			SHOW_DFA = true;
			dfaFileName = argv[++i];
			continue;
		}

		HELP = true;
		break;
	}

	if( HELP ) {
		std::cout << "HELP" << std::endl;
		std::cout << std::endl;
		std::cout << "OPCJE : " << std::endl;
		std::cout << " -f   po tej faldze podać nazwę pliku z lancuchami do sprawdzenia na" << std::endl;
		std::cout << "      przynaleznosc do języka generowanego przez wyrazenie regularne." << std::endl;
		std::cout << " -r   po tej faldze podac wyrazenie regularne." << std::endl;
		std::cout << " -st  flaga oznaczająca wygenerowanie pliku z graficznym przedstawieniem" << std::endl;
		std::cout << "      drzewa rozbioru wyrazenia regularnego." << std::endl;
		std::cout << " -sa  flaga oznaczająca wygenerowanie pliku z tekstowym przedstawieniem" << std::endl;
		std::cout << "      automatu wyrazenia regularnego." << std::endl;

		return 0;
	}

	if( !REGEX ) {
		std::cerr << "You have to specify regex to do anything!" << std::endl;
		exit(-1);
	}

	std::cout << "REGEX : " << regex << std::endl;

	Scanner scanner(regex);

	try {
		scanner.tokenize();
	} catch (ScannerException & e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	}

	Syntax syntax(scanner.getTokens());

	try {
		syntax.buildTree();
	} catch (SyntaxException & e) {
		std::cerr << e.what() << std::endl;
		exit(-1);
	}

	DFA dfa(syntax.getTree());

	if(WORDS_FILE){

		std::ifstream words;
		words.open(fileName);
		std::string chain;
		while(std::getline(words, chain)) {
			std::cout << chain << " => ";

			try {
				scanner.tokenize(chain);
			} catch (ScannerException & e) {
				std::cerr << e.what() << std::endl;
				continue;
			}

			if( dfa.checkWord(scanner.getTokens()) ){
				std::cout << "TRUE" << std::endl;
			} else {
				std::cout << "FALSE" << std::endl;
			}

		}
	}

	if(SHOW_TREE){
		syntax.showTree();
	}

	if(SHOW_DFA){
		std::ofstream file;
		file.open(dfaFileName);
		file << dfa;
		file.close();
	}

    return 0;
}
