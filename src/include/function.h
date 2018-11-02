/*
 * Header for the Function abstract class
 * All other function classes inherit from this one
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

#include "signatures.h"
#include "term.h"
#include "Expr.h"

class function {
	friend class term;

	protected:
		Expr * _arguments;
		virtual function * __copy_construct() const = 0;
	public:
		virtual ~function () { };
};

#endif
