//============================================================================
// Name        : tkom.cpp
// Author      : Przemysław Piórkowski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <scanner/Scanner.h>
#include <scanner/ScannerException.h>
#include <list>

// TODO :
//
// - przesunąć sprawdzanie zabalansowania nawiasów do modułu syntax
//	 liczenie od -1 i koniec tez musi być na -1.
//
// - statyczne pole z klasy node przenieść do klasy Position.
//   Tak na prawde to position powinno mieć id - w node jest ono niepotrzebne.

extern void scannerTest();
extern void syntaxTest();

int main(int argc, char* argv[])
{
	//scannerTest( );
	syntaxTest();
    return 0;
}
