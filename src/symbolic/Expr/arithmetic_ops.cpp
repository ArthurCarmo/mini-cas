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
	res.__auto_simplify();
	return res;
}

Expr Expr::operator-(const Expr &E) const {
	Expr res;
	res._op_id = _CAS_OP_SUB_;
	res._left_side = new Expr(*this);
	res._right_side = new Expr(E);
	res.__auto_simplify();
	return res;
}

Expr Expr::operator*(const Expr &E) const {
	Expr res;
	res._op_id = _CAS_OP_MUL_;
	res._left_side = new Expr(*this);
	res._right_side = new Expr(E);
	res.__auto_simplify();
	return res;
}

Expr Expr::operator/(const Expr &E) const {
	Expr res;
	res._op_id = _CAS_OP_DIV_;
	res._left_side = new Expr(*this);
	res._right_side = new Expr(E);
	res.__auto_simplify();
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

bool Expr::__immediately_equal(const Expr &E) const {
	if(this->_op_id == _CAS_BASIC_) {
		if(this->_op_id != E._op_id) return false;
		return this->_basic_value->__immediately_equal(*E._basic_value);
	}
	
	if(this->_op_id == _CAS_OP_SUM_ || this->_op_id == _CAS_OP_SUB_){
		if(E._op_id == _CAS_OP_MUL_ || E._op_id == _CAS_OP_DIV_) return false;
		if(this->_op_id != E._op_id)
			return this->_left_side->__immediately_equal(*E._left_side)
				&& this->_right_side->__immediately_equal(-*E._right_side);
		return this->_left_side->__immediately_equal(*E._left_side)
			&& this->_right_side->__immediately_equal(*E._right_side);
	}
	
	// Completar para multiplicação, divisão e potência
	
	return false;
}

Expr Expr::operator-() const {
	Expr f(*this);
	if(f._op_id == _CAS_BASIC_)
		if(f._basic_value->is_polynomial()) 
			f._basic_value->_basic_term = -f._basic_value->_basic_term;
		else f._basic_value->_function->flip_sign();
	
	else if(f._op_id == _CAS_OP_MUL_ || f._op_id == _CAS_OP_DIV_ || f._op_id == _CAS_OP_POW_)
		f._sign = 1 - f._sign;
	
	else {
		f._left_side->flip_sign();
		f._op_id = (f._op_id == _CAS_OP_SUM_)?_CAS_OP_SUB_:_CAS_OP_SUM_;
	}
	
	return f;
}

Expr & Expr::flip_sign() {
	if(this->_op_id == _CAS_BASIC_)
		if(this->_basic_value->is_polynomial()) 
			this->_basic_value->_basic_term = -this->_basic_value->_basic_term;
		else this->_basic_value->_function->flip_sign();
	
	else if(this->_op_id == _CAS_OP_MUL_ || this->_op_id == _CAS_OP_DIV_ || this->_op_id == _CAS_OP_POW_)
		this->_sign = 1 - this->_sign;
	
	else {
		this->_left_side->flip_sign();
		this->_op_id = (this->_op_id == _CAS_OP_SUM_)?_CAS_OP_SUB_:_CAS_OP_SUM_;
	}

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

