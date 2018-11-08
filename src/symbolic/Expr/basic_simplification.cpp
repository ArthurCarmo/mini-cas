/*
 * More basic simplification functions
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../../include/Expr.h"

bool Expr::is_simplified() const {
	if(this->is_polynomial()) return true;
	if(this->is_function()) return this->_basic_value->function_value().is_simplified();
	if(this->_left_side->is_polynomial() && this->_right_side->is_polynomial()) return false;
	else return this->_left_side->is_simplified() && this->_right_side->is_simplified();

}

void Expr::__auto_simplify_basic_ops(){
	if(this->is_polynomial()) return;
	if(this->is_function()) {
		this->_basic_value->_function->__auto_simplify_arguments();
		return;
	}
	if(!this->_left_side->is_polynomial() || !this->_right_side->is_polynomial()) return;
	
	switch(this->_op_id){
		case _CAS_OP_SUM_: 
			this->_basic_value = new term( this->_left_side->polynomial_value() 
							+ this->_right_side->polynomial_value() );
				this->_op_id = _CAS_BASIC_;
				this->__prune_members();
		break;
		
		case _CAS_OP_SUB_:
			this->_basic_value = new term( this->_left_side->polynomial_value() 
							- this->_right_side->polynomial_value() );
			this->_op_id = _CAS_BASIC_;
			this->__prune_members();
		break;
		
		case _CAS_OP_MUL_:
			if(!this->_left_side->is_number() || !this->_right_side->is_number()) return;
			this->_basic_value = new term( this->_left_side->polynomial_value() 
						* this->_right_side->polynomial_value() );
			this->_op_id = _CAS_BASIC_;
			this->__prune_members();
		break;
		
		case _CAS_OP_DIV_:
			polynomial_tuple ans = this->_left_side->polynomial_value() / this->_right_side->polynomial_value();
			if(ans.r.is_null()){
				this->_basic_value = new term( ans.q );
				this->_op_id = _CAS_BASIC_;
				this->__prune_members();
			}
		break;
	}
}

bool Expr::commute() {
	Expr *aux;
	bool equals = true;
	if(this->_op_id == _CAS_BASIC_ || this->_op_id == _CAS_OP_POW_ || this->_op_id == _CAS_OP_DIV_) equals = false;
	
	aux = this->_left_side;
	this->_left_side = this->_right_side;
	this->_right_side = aux;
	return equals;
}
