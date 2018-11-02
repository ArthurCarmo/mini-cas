/*
 * Header for the cosine function class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __COSINE_H_
#define __COSINE_H_

#include <iosfwd>

#include "signatures.h"
#include "function.h"

class cos : function {
	private:
		function * __copy_construct() const;
	public:
		cos (int);
		cos (const Number &);
		cos (const monomial &);
		cos (const polynomial &);
		cos (const function &);
		cos (const term &);
		cos (const Expr &);
		~cos();
};

#endif
