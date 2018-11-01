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
	
	public:
		tg();
		tg(const tg &);
		tg(const Expr &);
		~tg();
};

#endif
