/*
 * Functors for the function class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include <vector>

#include "../../include/number.h"
#include "../../include/function.h"
#include "../../include/term.h"
#include "../../include/Expr.h"

function function::operator()(int x) const {
	function f(this->_name);
	f._arguments.push_back(Expr(x));
	return f;
}

function function::operator()(const Number &x) const {
	function f(this->_name);
	f._arguments.push_back(Expr(x));
	return f;
}
		
function function::operator()(const monomial &m) const {
	function f(this->_name);
	f._arguments.push_back(Expr(m));
	return f;
}
		
function function::operator()(const polynomial &p) const {
	function f(this->_name);
	f._arguments.push_back(Expr(p));
	return f;
}
		
function function::operator()(const function &F) const {
	function f(this->_name);
	f._arguments.push_back(Expr(F));
	return f;
}
		
function function::operator()(const term &T) const {
	function f(this->_name);
	f._arguments.push_back(Expr(T));
	return f;
}
		
function function::operator()(const Expr &E) const {
	function f(this->_name);
	f._arguments.push_back(E);
	return f;
}

function sqrt("sqrt");
function exp("exp");
function ln("ln");
function log("log");
function sin("sin");
function cos("cos");
function tg("tg");
