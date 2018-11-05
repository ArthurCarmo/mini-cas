/*
 * Sine trig function
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

function sin(int x) {
	function SIN("sin", x);
	return SIN;
}

function sin(const Number &x) {
	function SIN("sin", x);
	return SIN;
}

function sin(const monomial &m) {
	function SIN("sin", m);
	return SIN;
}

function sin(const polynomial &p) {
	function SIN("sin", p);
	return SIN;
}

function sin(const function &F) {
	function SIN("sin", F);
	return SIN;
}

function sin(const term &T) {
	function SIN("sin", T);
	return SIN;
}

function sin(const Expr &E) {
	function SIN("sin", E);
	return SIN;
}
