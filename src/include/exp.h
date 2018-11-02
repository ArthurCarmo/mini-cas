/*
 * Header for the exponential function class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __EXP_H_
#define __EXP_H_

#include <iosfwd>

#include "signatures.h"
#include "function.h"

class exp : function {
	private:
		function * __copy_construct() const;
	public:
		exp (int);
		exp (const Number &);
		exp (const monomial &);
		exp (const polynomial &);
		exp (const function &);
		exp (const term &);
		exp (const Expr &);
		~exp();
};

#endif
