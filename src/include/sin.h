/*
 * Header for the sine function class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __SINE_H_
#define __SINE_H_

#include <iosfwd>

#include "signatures.h"
#include "function.h"

class sin : function {
	private:
		function * __copy_construct() const;
	public:
		sin (int);
		sin (const Number &);
		sin (const monomial &);
		sin (const polynomial &);
		sin (const function &);
		sin (const term &);
		sin (const Expr &);
		~sin();
};

#endif
