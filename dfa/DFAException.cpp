/*
 * DFAException.cpp
 *
 *  Created on: 11 kwi 2014
 *      Author: przemek
 */

#include <dfa/DFAException.h>

DFAException::DFAException(const std::string & msg) : msg(msg) {
	this->msg = "ScannerException : ";
	this->msg += msg;
}

DFAException::~DFAException() { }

const char* DFAException::what() const noexcept {
	return msg.c_str();
}

