/*
 * Constructors for the main symbolic class
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

Expr::Expr () {
	this->_left_side = NULL;
	this->_right_side = NULL;
	this->_op_id = _CAS_BASIC_;
	this->_basic_value = new term();
}

Expr::Expr (int x) {
	this->_left_side = NULL;
	this->_right_side = NULL;
	this->_op_id = _CAS_BASIC_;
	this->_basic_value = new term(x);
}

Expr::Expr (const Number &x) {
	this->_left_side = NULL;
	this->_right_side = NULL;
	this->_op_id = _CAS_BASIC_;
	this->_basic_value = new term(x);
}

Expr::Expr (const monomial &m) {
	this->_left_side = NULL;
	this->_right_side = NULL;
	this->_op_id = _CAS_BASIC_;
	this->_basic_value = new term(m);
}

Expr::Expr (const polynomial &p) {
	this->_left_side = NULL;
	this->_right_side = NULL;
	this->_op_id = _CAS_BASIC_;
	this->_basic_value = new term(p);
}

Expr::Expr (const function &F) {
	this->_left_side = NULL;
	this->_right_side = NULL;
	this->_op_id = _CAS_BASIC_;
	this->_basic_value = new term(F);
}

Expr::Expr (const term &T) {
	this->_left_side = NULL;
	this->_right_side = NULL;
	this->_op_id = _CAS_BASIC_;
	this->_basic_value = new term(T);
}

Expr::Expr (const Expr &E) {
	if(E._left_side == NULL) this->_left_side = NULL;
	else this->_left_side = new Expr(*E._left_side);
	
	if(E._right_side == NULL) this->_right_side = NULL;
	else this->_right_side = new Expr(*E._right_side);
	
	if(E._basic_value == NULL) this->_basic_value = NULL;
	else this->_basic_value = new term(*E._basic_value);
	
	this->_op_id = E._op_id;
}

Expr::~Expr () {
	if(this->_left_side != NULL)   delete this->_left_side;
	if(this->_right_side != NULL)  delete this->_right_side;
	if(this->_basic_value != NULL) delete this->_basic_value;
}
