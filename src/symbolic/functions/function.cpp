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

#include "../../include/number.h"
#include "../../include/function.h"
#include "../../include/term.h"
#include "../../include/Expr.h"

function::function () {
	this->_name = "f";
	this->_arguments = NULL;
}

function::function(const std::string &name, const Expr &E) {
	this->_name = name;
	this->_arguments = new Expr(E);
}

function::function (const function &F) {
	this->_name = F._name;
	this->_arguments = new Expr(*F._arguments);
}

function::~function () {
	if(this->_arguments != NULL) delete this->_arguments;
	this->_arguments = NULL;
}
