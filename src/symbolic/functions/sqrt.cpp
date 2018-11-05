/*
 * Square root function
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../../include/number.h"
#include "../../include/function.h"
#include "../../include/term.h"

function sqrt(int x) {
	function SQRT("sqrt", x);
	return SQRT;
}

function sqrt(const Number &x) {
	function SQRT("sqrt", x);
	return SQRT;
}

function sqrt(const monomial &m) {
	function SQRT("sqrt", m);
	return SQRT;
}

function sqrt(const polynomial &p) {
	function SQRT("sqrt", p);
	return SQRT;
}

function sqrt(const function &F) {
	function SQRT("sqrt", F);
	return SQRT;
}

function sqrt(const term &T) {
	function SQRT("sqrt", T);
	return SQRT;
}

function sqrt(const Expr &E) {
	function SQRT("sqrt", E);
	return SQRT;
}
