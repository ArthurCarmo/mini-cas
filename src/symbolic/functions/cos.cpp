/*
 * Cosine trig function
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

function cos(int x) {
	function COS("cos", x);
	return COS;
}

function cos(const Number &x) {
	function COS("cos", x);
	return COS;
}

function cos(const monomial &m) {
	function COS("cos", m);
	return COS;
}

function cos(const polynomial &p) {
	function COS("cos", p);
	return COS;
}

function cos(const function &F) {
	function COS("cos", F);
	return COS;
}

function cos(const term &T) {
	function COS("cos", T);
	return COS;
}

function cos(const Expr &E) {
	function COS("cos", E);
	return COS;
}
