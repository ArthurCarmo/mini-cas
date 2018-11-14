/*
 * Output for the Expr class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */
 
 #include <iostream>
 #include "../../include/term.h"
 
std:: ostream & operator<<(std::ostream &o, const Expr &E){
	char op = ' ';
	char l_open_brackets = '\0';
	char l_close_brackets = ' ';
	char r_open_brackets = ' ';
	char r_close_brackets = '\0';
	
	switch (E._op_id){
		case _CAS_BASIC_ :
			o << *E._basic_value;
			return o;
		case _CAS_OP_SUM_ :
			op = '+';
			break;
		case _CAS_OP_SUB_ :
			op = '-';
			break;
		case _CAS_OP_MUL_ :
			op = '*';
			break;
		case _CAS_OP_DIV_ :
			op = '/';
			break;
		case _CAS_OP_POW_ :
			op = '^';
			break;
	}
	
	if(E._op_id == _CAS_OP_MUL_ || E._op_id == _CAS_OP_DIV_ || E._op_id == _CAS_OP_POW_){
		if(!E._left_side->is_number() && !E._left_side->is_variable() && !E._left_side->is_function()){
			l_open_brackets = '(';
			l_close_brackets = ')';
		}
		
		r_open_brackets = '\0';
		if(l_close_brackets != ')') l_close_brackets = '\0';
	
		if(!E._right_side->is_number() && !E._right_side->is_variable() && !E._right_side->is_function()){
			r_open_brackets = '(';
			r_close_brackets = ')';
		}
	}
	
	o << l_open_brackets << *E._left_side << l_close_brackets << op << 
	r_open_brackets << *E._right_side << r_close_brackets;

	return o;
}
