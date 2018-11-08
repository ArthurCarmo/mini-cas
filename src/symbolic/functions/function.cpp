/*
 * Constructors for the function class
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

function::function (const std::string &name) {
	this->_sign = 0;
	this->_name = name;
}

function::function (const function &F) {
	this->_sign = F._sign;
	this->_name = F._name;
	this->_arguments = F._arguments;
}


std::vector<Expr> function::arguments() const { return this->_arguments; }

bool function::is_simplified() const {
	for(std::vector<Expr>::const_iterator it = this->_arguments.begin(); it != this->_arguments.end(); ++it)
		if(!it->is_simplified())
			return false;
	return true;
}

void function::__auto_simplify_arguments(){
	for(std::vector<Expr>::iterator it = this->_arguments.begin(); it != this->_arguments.end(); ++it)
		it->__auto_simplify_basic_ops();
}
