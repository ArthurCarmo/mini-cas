/*
 * Constructors for the sine function class
 * All other function classes inherit from this one
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../../../include/number.h"
#include "../../../include/function.h"
#include "../../../include/term.h"
#include "../../../include/sin.h"

function * sin::__copy_construct() const {
	function *ret;
	if(this->_arguments == NULL)
		return (ret = new sin(0));
	return ret = new sin(*this->_arguments);
}

sin::sin (int x) {
	this->_arguments = new Expr(x);
}

sin::sin (const Number &x) {
	this->_arguments = new Expr(x);
}

sin::sin (const monomial &m) {
	this->_arguments = new Expr(m);
}

sin::sin (const polynomial &p) {
	this->_arguments = new Expr(p);
}

sin::sin (const function &F) {
	this->_arguments = new Expr(F);
}

sin::sin (const term &T) {
	this->_arguments = new Expr(T);
}

sin::sin (const Expr &E) {
	this->_arguments = new Expr(E);
}

sin::~sin () {
	if(this->_arguments != NULL) delete this->_arguments;
}
