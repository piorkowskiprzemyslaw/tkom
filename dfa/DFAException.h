/*
 * DFAException.h
 *
 *  Created on: 11 kwi 2014
 *      Author: przemek
 */

#ifndef DFAEXCEPTION_H_
#define DFAEXCEPTION_H_

#include <exception>
#include <string>

/*
 * Wyjątki rzucane przez klase Scanner.
 */
class DFAException: public std::exception {
private:
	std::string msg;

public:
	explicit DFAException(const std::string & msg);
	virtual ~DFAException();
	const char* what() const noexcept override;
};

#endif /* DFAEXCEPTION_H_ */
