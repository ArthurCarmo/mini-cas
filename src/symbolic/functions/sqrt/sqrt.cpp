/*
 * Constructors for the square root function class
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
#include "../../../include/sqrt.h"

function * sqrt::__copy_construct() const {
	function *ret;
	if(this->_arguments == NULL)
		return (ret = new sqrt(0));
	return ret = new sqrt(*this->_arguments);
}

sqrt::sqrt (int x) {
	this->_arguments = new Expr(x);
}

sqrt::sqrt (const Number &x) {
	this->_arguments = new Expr(x);
}

sqrt::sqrt (const monomial &m) {
	this->_arguments = new Expr(m);
}

sqrt::sqrt (const polynomial &p) {
	this->_arguments = new Expr(p);
}

sqrt::sqrt (const function &F) {
	this->_arguments = new Expr(F);
}

sqrt::sqrt (const term &T) {
	this->_arguments = new Expr(T);
}

sqrt::sqrt (const Expr &E) {
	this->_arguments = new Expr(E);
}

sqrt::~sqrt () {
	if(this->_arguments != NULL) delete this->_arguments;
}
