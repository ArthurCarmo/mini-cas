/*
 * Header for the term class, responsible for storing either a 
 * function or a primitive type (polynomial, monomial or number)
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __TERM_H_
#define __TERM_H_

#include <iosfwd>

#include "signatures.h"
#include "polynomial.h"
#include "function.h"
#include "Expr.h"

class term {
	
	friend std::ostream & operator<<(std::ostream &, const term &);
	friend class Expr;
	
	private:
		polynomial _basic_term;
		function * _function;
		
	public:
		term ();
		term (int);
		term (const Number &);
		term (const monomial &);
		term (const polynomial &);
		term (const function &);
		term (const term &);
		~term ();
		
		bool is_number() const { return this->_function == NULL && this->_basic_term.is_constant(); }
		bool is_variable() const { return this->_function == NULL && this->_basic_term.is_variable(); }
		bool is_polynomial() const { return this->_function == NULL; }
		bool is_function() const { return this->_function != NULL; }
		polynomial polynomial_value() const;
		function function_value() const;
};

#endif
