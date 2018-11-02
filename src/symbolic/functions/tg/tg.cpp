/*
 * Constructors for the tangent trig function class
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
#include "../../../include/tg.h"

function * tg::__copy_construct() const {
	function *ret;
	if(this->_arguments == NULL)
		return (ret = new tg(0));
	return ret = new tg(*this->_arguments);
}

tg::tg (int x) {
	this->_arguments = new Expr(x);
}

tg::tg (const Number &x) {
	this->_arguments = new Expr(x);
}

tg::tg (const monomial &m) {
	this->_arguments = new Expr(m);
}

tg::tg (const polynomial &p) {
	this->_arguments = new Expr(p);
}

tg::tg (const function &F) {
	this->_arguments = new Expr(F);
}

tg::tg (const term &T) {
	this->_arguments = new Expr(T);
}

tg::tg (const Expr &E) {
	this->_arguments = new Expr(E);
}

tg::~tg () {
	if(this->_arguments != NULL) delete this->_arguments;
}
