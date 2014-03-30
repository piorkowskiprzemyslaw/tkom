/*
 * Scanner_test.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <iostream>
#include <fstream>

#include <scanner/Scanner.h>

std::string getInputTestDir(int number){
	std::string path("/home/przemek/Dropbox/studia/przedmioty/sem_6/TKOM/projekt/testy/test");
	std::string path1( "C:\\Users\\Przemek\\Dropbox\\studia\\przedmioty\\sem_6\\TKOM\\projekt\\testy\\test" );
	std::string entirePath;
	char num[32];
	sprintf(num, "%d", number);
	entirePath = path1 + num;
	entirePath += ".txt";
	return entirePath;
}

std::string getOutputTestDir(int number){
	std::string path("/home/przemek/Dropbox/studia/przedmioty/sem_6/TKOM/projekt/testy/test");
	std::string path1( "C:\\Users\\Przemek\\Dropbox\\studia\\przedmioty\\sem_6\\TKOM\\projekt\\testy\\test" );
	std::string entirePath;
	char num[32];
	sprintf(num, "%d", number);
	entirePath = path1 + num;
	entirePath += "OUTPUT.txt";
	return entirePath;
}

void scannerTest() {

	std::ifstream ifile;
	std::ofstream ofile;
	std::string regex;
	for(int i = 1; i < 11 ; ++i){
		ifile.open(getInputTestDir(i));
		ofile.open(getOutputTestDir(i), std::ofstream::trunc );

		std::getline(ifile,regex);
		Scanner instance(regex);

		try{
		instance.tokenize();
		} catch (ScannerException & e) {
			std::cout << e.what() << std::endl;
			ifile.close();
			regex.clear();
			continue;
		}

		instance.printTokenList(ofile);

		while(std::getline(ifile, regex)){
			try{
			instance.tokenize(regex);
			} catch (ScannerException & e) {
				std::cout << e.what() << std::endl;
				regex.clear();
				continue;
			}
			instance.printTokenList(ofile);
		}

		regex.clear();
		ifile.close();
		ofile.close();
	}
}
