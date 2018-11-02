/*
 * Constructors for the cosine function class
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
#include "../../../include/cos.h"

function * cos::__copy_construct() const {
	function *ret;
	if(this->_arguments == NULL)
		return (ret = new cos(0));
	return ret = new cos(*this->_arguments);
}

cos::cos (int x) {
	this->_arguments = new Expr(x);
}

cos::cos (const Number &x) {
	this->_arguments = new Expr(x);
}

cos::cos (const monomial &m) {
	this->_arguments = new Expr(m);
}

cos::cos (const polynomial &p) {
	this->_arguments = new Expr(p);
}

cos::cos (const function &F) {
	this->_arguments = new Expr(F);
}

cos::cos (const term &T) {
	this->_arguments = new Expr(T);
}

cos::cos (const Expr &E) {
	this->_arguments = new Expr(E);
}

cos::~cos () {
	if(this->_arguments != NULL) delete this->_arguments;
}
