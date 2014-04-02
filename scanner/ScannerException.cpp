/*
 * ScannerException.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <scanner/ScannerException.h>

ScannerException::ScannerException(const std::string & msg) : msg(msg) {
	this->msg = "ScannerException : ";
	this->msg += msg;
}

ScannerException::~ScannerException() { }

const char* ScannerException::what() const noexcept {
	return msg.c_str();
}

