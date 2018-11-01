/*
 * Header for the square root function class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __SQROOT_H_
#define __SQROOT_H_

#include <iosfwd>

#include "signatures.h"
#include "function.h"

class sqrt : function {
	private:
	
	public:
		sqrt();
		sqrt(const sqrt &);
		sqrt(const Expr &);
		~sqrt();
};

#endif
