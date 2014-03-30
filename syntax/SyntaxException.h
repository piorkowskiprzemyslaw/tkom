/*
 * SyntaxException.h
 *
 *  Created on: 29 mar 2014
 *      Author: przemek
 */

#ifndef SYNTAXEXCEPTION_H_
#define SYNTAXEXCEPTION_H_

#include <string>
#include <exception>

class SyntaxException: public std::exception {
private:
	std::string message;
public:
	explicit SyntaxException(const std::string & msg);
	virtual ~SyntaxException();
	const char* what() const override;
};

#endif /* SYNTAXEXCEPTION_H_ */
