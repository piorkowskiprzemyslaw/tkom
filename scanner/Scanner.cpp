/*
 * Scanner.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <scanner/Scanner.h>

/*
 * Kostruktor.
 */
Scanner::Scanner(const std::string & regex) {
	this->regex = regex;
}

/*
 * Destrutkor.
 */
Scanner::~Scanner() { }

/*
 * Zwraca odpowiedni TokenType dla danego znaku. Jesli zostanie podany zły
 * znak to metoda rzuca wyjątek.
 */
Token Scanner::getTokenizedCharacterType(const char & character) {
	switch(character) {
	case 'a' : return Token(TokenType::a,"a");
	case 'b' : return Token(TokenType::b,"b");
	case 'c' : return Token(TokenType::c,"c");
	case 'd' : return Token(TokenType::d,"d");
	case 'e' : return Token(TokenType::e,"e");
	case 'f' : return Token(TokenType::f,"f");
	case 'g' : return Token(TokenType::g,"g");
	case 'h' : return Token(TokenType::h,"h");
	case 'i' : return Token(TokenType::i,"i");
	case 'j' : return Token(TokenType::j,"j");
	case 'k' : return Token(TokenType::k,"k");
	case 'l' : return Token(TokenType::l,"l");
	case 'm' : return Token(TokenType::m,"m");
	case 'n' : return Token(TokenType::n,"n");
	case 'o' : return Token(TokenType::o,"o");
	case 'p' : return Token(TokenType::p,"p");
	case 'r' : return Token(TokenType::r,"r");
	case 's' : return Token(TokenType::s,"s");
	case 't' : return Token(TokenType::t,"t");
	case 'u' : return Token(TokenType::u,"u");
	case 'w' : return Token(TokenType::w,"w");
	case 'x' : return Token(TokenType::x,"x");
	case 'y' : return Token(TokenType::y,"y");
	case 'z' : return Token(TokenType::z,"z");
	case '.' : return Token(TokenType::DOT,".");
	case '|' : return Token(TokenType::OR,"|");
	case '+' : return Token(TokenType::PLUS,"+");
	case '*' : return Token(TokenType::MULTIPLICATION,"*");
	case '(' : return Token(TokenType::PARENTHESIS_LEFT,"(");
	case ')' : return Token(TokenType::PARENTHESIS_RIGHT,")");
	case '#' : return Token(TokenType::TERMINATE,"#");
	default:
			return Token(TokenType::WRONG_TYPE);
	}
}

/*
 * Sprawdza poprawnosc tokenu. Jeśli nieporawny rzuca wyjątek.
 */
void Scanner::checkCharacter(const TokenType type, const int position){
	if(type == TokenType::WRONG_TYPE || ( type == TokenType::TERMINATE && (position + 1) != regex.length() )){
		throw ScannerException(prepareExceptionMessage(position, regex[position]));
	}
}

/*
 * Przygotowuje wiadomośc o złym znaku character na pozycji position.
 */
const std::string Scanner::prepareExceptionMessage(const int position, const char character) {
	std::string message("Wrong character found at position ");
	char number[32];
	sprintf(number, "%d", position);
	message += number;
	message += " = \'";
	message += character;
	message += "\'";
	return message;
}

/*
 * Tworzy listę tokenów z wyrażenia regularnego podanego w argumencie konstruktora.
 *
 * Rzuca wyjątek gdy nieobslugiwany symbol pojawia się w wyrażeniu regularnym.
 */
void Scanner::tokenize(){
	Token actual;
	Token next;

	checkParenthesesInRegex( );
	addExtrernalParentheses( );

	extractedTokens.clear();

	for(size_t i = 0 ; i < regex.length() - 1  ; ++i){
		actual = getTokenizedCharacterType(regex[i]);
		next = getTokenizedCharacterType(regex[i+1]);

		checkCharacter(actual.getType(), i);
		checkCharacter(next.getType(), i+1);

		extractedTokens.emplace_back(new Token(actual));

		if( ( actual.isAlphabetSymbol() && next.isAlphabetSymbol() ) ||
			( actual.isAlphabetSymbol() && next.isOpeningParenthesis() ) ||
			( actual.isAlphabetSymbol() && next.isTerminate() ) ||
			( actual.isClosingParenthesis() && next.isAlphabetSymbol() ) ||
			( actual.isClosingParenthesis() && next.isTerminate() ) ||
			( actual.isOneOperandOperator() && next.isAlphabetSymbol() ) ||
			( actual.isOneOperandOperator() && next.isOpeningParenthesis() ) ||
			( actual.isOneOperandOperator() && next.isTerminate() )
		  ) {
			extractedTokens.emplace_back(new Token(TokenType::CONCATENATION,"@"));
		}
	}

	extractedTokens.emplace_back(new Token(TokenType::TERMINATE,"#"));
}

/*
 * Tworzy liste tokenów z podanego w argumencie slowa.
 *
 * Rzuca wyjątek gdy nieobslugiwany symbol pojawia się w slowie.
 */
void Scanner::tokenize(const std::string & sentence){
	extractedTokens.clear();
	Token actual;

	for(int i = 0 ; i < sentence.length() ; ++i){
		actual = getTokenizedCharacterType(sentence[i]);

		if(! actual.isAlphabetSymbol()){
			throw ScannerException(prepareExceptionMessage(i, sentence[i]));
		}

		extractedTokens.emplace_back(new Token(actual));
	}
}

/*
 * Pobranie listy
 */
const std::list<std::shared_ptr<Token> > & Scanner::getTokens() {
	return extractedTokens;
}

/*
 * Drukuje liste tokenów.
 */
void Scanner::printTokenList(std::ostream & os) {
	for(auto token : extractedTokens){
		os << (*token).getCharacter() << " ";
	}
	os << std::endl;
}

/*
 * Metoda sprawdzająca zbilansowanie nawiasów.
 */
void Scanner::checkParenthesesInRegex( ){
	int counter = 0;

	for ( int i = 0; i < regex.length( ); ++i ) {
		if ( regex[i] == '(' ) ++counter;
		if ( regex[i] == ')' ) --counter;

		if ( counter < 0 ) {
			throw ScannerException( "Not balanced parentheses!" );
		}
	}

	if ( counter != 0 ) {
		throw ScannerException( "Not balanced parentheses!" );
	}
}

/*
 * Dodaje zewnętrzne nawiasy do wyrażenia regularnego aby mogło odbyć się dalsze przetwarzanie.
 */
void Scanner::addExtrernalParentheses( )
{
	std::string tmpRegex = regex;
	regex.clear( );
	regex += '(';
	regex += tmpRegex;
	regex += ")#";
}
