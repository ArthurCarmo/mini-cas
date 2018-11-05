/*
 * Constructors for the basic symbolic class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../../include/number.h"
#include "../../include/function.h"
#include "../../include/term.h"

term::term () {
	this->_basic_term = 0;
	this->_function = NULL;
}

term::term (int x) {
	this->_basic_term = x;
	this->_function = NULL;
}

term::term (const Number &x) {
	this->_basic_term = x;
	this->_function = NULL;
}

term::term (const monomial &m) {
	this->_basic_term = m;
	this->_function = NULL;
}

term::term (const polynomial &p) {
	this->_basic_term = p;
	this->_function = NULL;
}

term::term (const function &F) {
	this->_basic_term = 1;
	this->_function = new function(F);
}

term::term (const term &T) {
	this->_basic_term = T._basic_term;
	if(T._function == NULL) this->_function = NULL;
	else this->_function = new function(*T._function);
}

term::~term () {
	if(this->_function != NULL) delete this->_function;
	this->_function = NULL;
}

