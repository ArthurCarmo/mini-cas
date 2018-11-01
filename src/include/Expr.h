/*
 * Header for the main symbolic class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __EXPR_H_
#define __EXPR_H_

#include <iosfwd>

#include "signatures.h"
#include "term.h"

#define _CAS_OP_SUM_ 1
#define _CAS_OP_SUB_ 2
#define _CAS_OP_MUL_ 3
#define _CAS_OP_DIV_ 4

class Expr {
	
	private:
		Expr * _left_side;
		Expr * _right_side;
		term * _basic_value;
		int _op_id;
	public:
		Expr ();
		Expr (int);
		Expr (const Number &);
		Expr (const monomial &);
		Expr (const polynomial &);
		Expr (const term &);
		Expr (const Expr &);
};

#endif
