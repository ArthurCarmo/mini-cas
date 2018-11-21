/*
 * Main simplification function
 * Objective is to leave all sum/subtractions the more on the left
 * follow by products and then division
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../../include/Expr.h"

void Expr::__auto_simplify() {
//	this->__auto_simplify_immediate();
	this->__auto_simplify_merge();
}
