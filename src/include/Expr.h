/*
 * Header for the main symbolic class
 * An expression consists either of a basic term or
 * a binary operation with each side being an expression
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

#define _CAS_BASIC_  0
#define _CAS_OP_SUM_ 1
#define _CAS_OP_SUB_ 2
#define _CAS_OP_MUL_ 3
#define _CAS_OP_DIV_ 4
#define _CAS_OP_POW_ 5

class Expr {

	friend std::ostream & operator<<(std::ostream &, const Expr &);
	friend class function;
	
	private:
		Expr * _left_side;
		Expr * _right_side;
		term * _basic_value;
		int _op_id;
		int _sign;
		
		void __auto_simplify();
		void __auto_simplify_immediate();
		void __auto_simplify_merge();
		void __auto_simplify_split();
		void __auto_simplify_add_simpler_to_the_left();
		void __auto_simplify_add_chains();
		void __auto_simplify_mul_chains();
		void __auto_simplify_mul_simpler_to_the_left();
		
		// Commute operations but mantaining equity
		// e.g.: a - b = -b + a
		void __auto_simplify_equiv_commute();
		bool __immediately_equal(const Expr &) const;
		void __prune_members();
	public:
		Expr ();
		Expr (int);
		Expr (const Number &);
		Expr (const monomial &);
		Expr (const polynomial &);
		Expr (const function &);
		Expr (const term &);
		Expr (const Expr &);
		~Expr ();
		
		//returns false if the result changes when commuted
		bool commute();
		bool distribute();
		
		bool is_number() const;
		bool is_variable() const;
		bool is_polynomial() const;
		bool is_function() const;
		bool is_simplified() const;
		
		polynomial polynomial_value() const;
		function function_value() const;
		Expr left_side() const;
		Expr right_side() const;
		
		Expr & operator=(const Expr &);
		
		Expr operator+(const Expr &) const;
		Expr operator-(const Expr &) const;
		Expr operator*(const Expr &) const;
		Expr operator/(const Expr &) const;
		Expr pow(const Expr &) const;
		Expr operator-() const;
		
		Expr & flip_sign();
};

extern Expr operator+(const term &, const Expr &);
extern Expr operator-(const term &, const Expr &);
extern Expr operator*(const term &, const Expr &);
extern Expr operator/(const term &, const Expr &);
extern Expr pow(const term &, const Expr &);

#endif
