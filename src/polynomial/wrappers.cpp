/*
 * Wrappers for the more common monomial and polynomial methods
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/polynomial.h"

num_z deg(const monomial &u){
	return u.degree();
}

num_z deg(const monomial &u, const monomial &v){
	return u.degree(v);
}

num_z deg(const polynomial &u){
	return u.degree();
}

num_z deg(const polynomial &u, const monomial &v){
	return u.degree(v);
}

polynomial lc(const polynomial &u){
	return u.lc();
}

polynomial lc(const polynomial &u, const monomial &v){
	return u.lc(v);
}

polynomial lc(const polynomial &u, const monomial &v, const num_z &deg){
	return u.lc(v, deg);
}

monomial lm(const polynomial &u){
	return u.lm();
}

monomial lm(const polynomial &u, const monomial &v){
	return u.lm(v);
}

monomial lm(const polynomial &u, const monomial &v, const num_z &deg){
	return u.lm(v, deg);
}

polynomial cont(const polynomial &u){
	return u.content();
}

polynomial cont(const polynomial &u, const monomial &v){
	return u.content(v);
}

polynomial pp(const polynomial &u){
	return u.primitive_part();
}

polynomial pp(const polynomial &u, const monomial &v){
	return u.primitive_part(v);
}

polynomial psrem(const polynomial &u, const polynomial &v, const monomial &l){
	return u.pseudo_division(v, l).r;
}

polynomial psquot(const polynomial &u, const polynomial &v, const monomial &l){
	return u.pseudo_division(v, l).q;
}
