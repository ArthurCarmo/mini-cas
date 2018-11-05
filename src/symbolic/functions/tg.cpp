/*
 * Tangent trig function
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

function tg(int x) {
	function TG("tg", x);
	return TG;
}

function tg(const Number &x) {
	function TG("tg", x);
	return TG;
}

function tg(const monomial &m) {
	function TG("tg", m);
	return TG;
}

function tg(const polynomial &p) {
	function TG("tg", p);
	return TG;
}

function tg(const function &F) {
	function TG("tg", F);
	return TG;
}

function tg(const term &T) {
	function TG("tg", T);
	return TG;
}

function tg(const Expr &E) {
	function TG("tg", E);
	return TG;
}
