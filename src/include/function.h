/*
 * Header for the symbolic function class
 * Stores the function name and the expression passed as argument to it
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __FUNCTION_H_
#define __FUNCTION_H_

#include <iosfwd>
#include <string>
#include <vector>

#include "signatures.h"
#include "term.h"
#include "Expr.h"

class function {
	
	friend class term;
	friend class Expr;
	friend std::ostream & operator<<(std::ostream &, const function &);
	
	protected:
		int _sign;
		std::string _name;
		std::vector<Expr> _arguments;
		
		
		void __auto_simplify_arguments();
		void __construct_from_arguments(const Expr &E) {
			this->_arguments.push_back(E);
		}
		
		template<class... Args>
		void __construct_from_arguments(const Expr &E, Args... args) {
			this->_arguments.push_back(E);
			this->__construct_from_arguments(args...);
		}
		
		bool __immediately_equal(const function &) const;
		
	public:
		function (const std::string &);
		function (const function &);
		
		template<class... Args>
		function (const std::string &name, const Expr &E, Args... args) {
			this->_name = name;
			this->_arguments.push_back(E);
			this->__construct_from_arguments(args...);
		}
		
		std::vector<Expr> arguments() const;
		bool is_simplified() const;
		
		function & flip_sign() { this->_sign = 1 - this->_sign; return *this; }
		function operator-() const { function f(*this); f._sign = 1 - f._sign; return f; }
		
		
		/*
		 * Functors so users can create their own functions
		 */
		 
		function operator()(int) const;
		function operator()(const Number &) const;
		function operator()(const monomial &) const;
		function operator()(const polynomial &) const;
		function operator()(const function &) const;
		function operator()(const term &) const;
		function operator()(const Expr &) const;
		 
		template<class... Args>
		function operator()(int x, Args... args) const {
			function f(this->_name);
			f._arguments.push_back(Expr(x));
			f.__construct_from_arguments(args...);
			return f;
		}
		
		template<class... Args>
		function operator()(const Number &x, Args... args) const {
			function f(this->_name);
			f._arguments.push_back(Expr(x));
			f.__construct_from_arguments(args...);
			return f;
		}
		
		template<class... Args>
		function operator()(const monomial &m, Args... args) const {
			function f(this->_name);
			f._arguments.push_back(Expr(m));
			f.__construct_from_arguments(args...);
			return f;
		}
		
		template<class... Args>
		function operator()(const polynomial &p, Args... args) const {
			function f(this->_name);
			f._arguments.push_back(Expr(p));
			f.__construct_from_arguments(args...);
			return f;
		}
		
		template<class... Args>
		function operator()(const function &F, Args... args) const {
			function f(this->_name);
			f._arguments.push_back(Expr(F));
			f.__construct_from_arguments(args...);
			return f;
		}
		
		template<class... Args>
		function operator()(const term &T, Args... args) const {
			function f(this->_name);
			f._arguments.push_back(Expr(T));
			f.__construct_from_arguments(args...);
			return f;
		}
		
		template<class... Args>
		function operator()(const Expr &E, Args... args) const {
			function f(this->_name);
			f._arguments.push_back(E);
			f.__construct_from_arguments(args...);
			return f;
		}
};

extern function sqrt;
extern function exp;
extern function ln;
extern function log;
extern function sin;
extern function cos;
extern function tg;

#endif
