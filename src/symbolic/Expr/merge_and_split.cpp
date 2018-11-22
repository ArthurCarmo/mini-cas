/*
 * Merge and split operations for the expression class
 * The operations associate or disassociate expressions
 *
 * The idea of merging is to leave the expressions in a
 * normalized easy to manipulate pattern
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

	// Do nothing if not an operation
	if(this->_op_id == _CAS_BASIC_) return;

	// for any operation, both it's operands should be merged
	this->_left_side->__auto_simplify_merge();
	this->_right_side->__auto_simplify_merge();
	
	// sums and subtractions just shift the association order to be leftmost
	if(this->_op_id == _CAS_OP_SUM_ || this->_op_id == _CAS_OP_SUB_){
		if(this->_right_side->_op_id == _CAS_OP_SUM_ || this->_right_side->_op_id == _CAS_OP_SUB_){
			// a ++ (b -- c)
			std::swap(this->_right_side->_right_side, this->_right_side->_left_side);	// a ++ ( c -- b)
			std::swap(this->_right_side->_left_side, this->_left_side);			// c ++ ( a -- b);
			std::swap(this->_right_side, this->_left_side);					// (a -- b) ++ c
			std::swap(this->_left_side->_op_id, this->_op_id);				// (a ++ b) -- c
		}
	
	}
	
	// Multiplication merges with multiplication
	if(this->_op_id == _CAS_OP_MUL_){
		
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
		// rotation is the same as above, but the op "hierarchy" changes
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
			// change op type in object
			this->_left_side->_op_id = _CAS_OP_MUL_;
			this->_op_id = _CAS_OP_DIV_;
			
			std::swap(this->_left_side->_right_side, this->_right_side);
		}
		
	// goal is to make it so there is no division in a chain of multiplications/divisions
	// and the division will be at the root of the multiplication chain subtree
	}else if(this->_op_id == _CAS_OP_DIV_){
		// when left side is a division
		// we use that (a / b) / c == b / (a * c)
		if(this->_left_side->_op_id == _CAS_OP_DIV_){
			std::swap(this->_left_side, this->_right_side); 				// c / (a / b)
			std::swap(this->_right_side->_left_side, this->_right_side->_right_side);	// c / (b / a)
			std::swap(this->_right_side->_right_side, this->_left_side);			// a / (b / c)
			
			//and change the op
			this->_right_side->_op_id = _CAS_OP_MUL_;					// a / (b * c)
		}
		// when right side is a division
		// we use that a / (b / c) == (a * c) / b
		if(this->_right_side->_op_id == _CAS_OP_DIV_){
			std::swap(this->_left_side, this->_right_side); 				// (b / c) / a
			std::swap(this->_left_side->_left_side, this->_right_side);			// (a / c) / b
			
			//and change the op
			this->_left_side->_op_id = _CAS_OP_MUL_;					// (a * c) / b
		}
	}
}

void Expr::__auto_simplify_split() {
	
}
