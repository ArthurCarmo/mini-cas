/*
 * Arithmetic operators for the Expr class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../../include/term.h"
#include "../../include/Expr.h"

Expr Expr::operator+(const Expr &E) const {
	Expr res;
	res._op_id = _CAS_OP_SUM_;
	res._left_side = new Expr(*this);
	res._right_side = new Expr(E);
	res.__auto_simplify_basic_ops();
	return res;
}

Expr Expr::operator-(const Expr &E) const {
	Expr res;
	res._op_id = _CAS_OP_SUB_;
	res._left_side = new Expr(*this);
	res._right_side = new Expr(E);
	res.__auto_simplify_basic_ops();
	return res;
}

Expr Expr::operator*(const Expr &E) const {
	Expr res;
	res._op_id = _CAS_OP_MUL_;
	res._left_side = new Expr(*this);
	res._right_side = new Expr(E);
	res.__auto_simplify_basic_ops();
	return res;
}

Expr Expr::operator/(const Expr &E) const {
	Expr res;
	res._op_id = _CAS_OP_DIV_;
	res._left_side = new Expr(*this);
	res._right_side = new Expr(E);
	res.__auto_simplify_basic_ops();
	return res;
}

Expr Expr::pow(const Expr &E) const {
	Expr res;
	res._op_id = _CAS_OP_POW_;
	res._left_side = new Expr(*this);
	res._right_side = new Expr(E);
	return res;
}

Expr & Expr::operator=(const Expr &E){
	this->__prune_members();
	this->_op_id = E._op_id;
	
	if(E._left_side != NULL) this->_left_side = new Expr(*E._left_side);
	if(E._right_side != NULL) this->_right_side = new Expr(*E._right_side);
	if(E._basic_value != NULL) this->_basic_value = new term(*E._basic_value);
	
	return *this;
}

// Operators with expressions on the right side
Expr operator+(const term &T, const Expr &E) {
	return E + T;
}

Expr operator-(const term &T, const Expr &E) {
	return E - T;
}

Expr operator*(const term &T, const Expr &E) {
	return E * T;
}

Expr operator/(const term &T, const Expr &E) {
	return Expr(T) / E;
}

Expr pow(const term &T, const Expr &E) {
	return Expr(T).pow(E);
}

