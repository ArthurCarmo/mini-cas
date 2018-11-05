/*
 * Exponential function
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../../include/signatures.h"
#include "../../include/number.h"
#include "../../include/function.h"
#include "../../include/term.h"

function exp(int x) {
	function EXP("exp", x);
	return EXP;
}

function exp(const Number &x) {
	function EXP("exp", x);
	return EXP;
}

function exp(const monomial &m) {
	function EXP("exp", m);
	return EXP;
}

function exp(const polynomial &p) {
	function EXP("exp", p);
	return EXP;
}

function exp(const function &F) {
	function EXP("exp", F);
	return EXP;
}

function exp(const term &T) {
	function EXP("exp", T);
	return EXP;
}

function exp(const Expr &E) {
	function EXP("exp", E);
	return EXP;
}
