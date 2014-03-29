/*
 * ScannerException.cpp
 *
 *  Created on: 28 mar 2014
 *      Author: przemek
 */

#include <scanner/ScannerException.h>

ScannerException::ScannerException(const std::string & msg) noexcept : msg(msg) {
	this->msg = "ScannerException : ";
	this->msg += msg;
}

ScannerException::~ScannerException() noexcept { }

const char* ScannerException::what() const noexcept {
	return msg.c_str();
}

