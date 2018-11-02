/*
 * Constructors for the exponential function class
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
#include "../../../include/exp.h"

function * exp::__copy_construct() const {
	function *ret;
	if(this->_arguments == NULL)
		return (ret = new exp(0));
	return ret = new exp(*this->_arguments);
}

exp::exp (int x) {
	this->_arguments = new Expr(x);
}

exp::exp (const Number &x) {
	this->_arguments = new Expr(x);
}

exp::exp (const monomial &m) {
	this->_arguments = new Expr(m);
}

exp::exp (const polynomial &p) {
	this->_arguments = new Expr(p);
}

exp::exp (const function &F) {
	this->_arguments = new Expr(F);
}

exp::exp (const term &T) {
	this->_arguments = new Expr(T);
}

exp::exp (const Expr &E) {
	this->_arguments = new Expr(E);
}

exp::~exp () {
	if(this->_arguments != NULL) delete this->_arguments;
}
