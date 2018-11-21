/*
 * Merge and split operations for the expression class
 * The operations associate or disassociate expressions
 * Ideally there will be no multiplications to the right
 * of another multiplication, and no consecutive divisions
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include <algorithm>

#include "../../include/Expr.h"

void Expr::__auto_simplify_merge() {

	// Do nothing if not expression
	if(this->_op_id == _CAS_BASIC_) return;

	// Multiplication merges with multiplication
	if(this->_op_id == _CAS_OP_MUL_){
		this->_left_side->__auto_simplify_merge();
		this->_right_side->__auto_simplify_merge();
		
		/* If there is a multiplication on the right side, a rotation is made 
		   as to leave the current multipliaction more to the right, e.g.:
		
		
					[*]
					/ \
				       a  [*]
				          / \
				         b   c
			
				Becomes
			
					[*]
					/ \
				      [*]  c
				      / | 
				     a  b
			
		*/
		if(this->_right_side->_op_id == _CAS_OP_MUL_){
			std::swap(this->_right_side->_right_side, this->_right_side->_left_side);
			std::swap(this->_right_side->_left_side, this->_left_side);
			std::swap(this->_right_side, this->_left_side);
		}
		
		// If right side is a division
		// the rotation is the same as above, but the op hierarchy changes
		if(this->_right_side->_op_id == _CAS_OP_DIV_){
			std::swap(this->_right_side->_right_side, this->_right_side->_left_side);
			std::swap(this->_right_side->_left_side, this->_left_side);
			std::swap(this->_right_side, this->_left_side);
			
			this->_op_id = _CAS_OP_DIV_;
			this->_left_side->_op_id = _CAS_OP_MUL_;
		}
		
		/* If there is a division on the left side, a rotation is made 
		   as to leave the multiplication more to the left, e.g.:
		
		
					[*]
					/ \
				      [/]  b
				      / | 
				     a  c
			
				Becomes
			
					[/]
					/ \
				      [*]  c
				      / | 
				     a  b
			
		*/
		
		if(this->_left_side->_op_id == _CAS_OP_DIV_)
		{
			//change op type in object
			this->_left_side->_op_id = _CAS_OP_MUL_;
			this->_op_id = _CAS_OP_DIV_;
			
			std::swap(this->_left_side->_right_side, this->_right_side);
		}
		
	}else if(this->_op_id == _CAS_OP_DIV_){
	
	}
}

void Expr::__auto_simplify_split() {
	
}
