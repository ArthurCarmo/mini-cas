/*
 * Header for the tanget function class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __TANGENT_H_
#define __TANGENT_H_

#include <iosfwd>

#include "signatures.h"
#include "function.h"

class tg : function {
	private:
		function * __copy_construct() const;
	public:
		tg (int);
		tg (const Number &);
		tg (const monomial &);
		tg (const polynomial &);
		tg (const function &);
		tg (const term &);
		tg (const Expr &);
		~tg();
};

#endif
