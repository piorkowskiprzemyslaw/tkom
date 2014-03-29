/*
 * ScannerException.h
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#ifndef SCANNEREXCEPTION_H_
#define SCANNEREXCEPTION_H_

#include <exception>
#include <string>

/*
 * Wyjątki rzucane przez klase Scanner.
 */
class ScannerException: public std::exception {
private:
	std::string msg;

public:
	explicit ScannerException(const std::string & msg) noexcept;
	virtual ~ScannerException() noexcept;
	const char* what() const noexcept override;
};

#endif /* SCANNEREXCEPTION_H_ */
