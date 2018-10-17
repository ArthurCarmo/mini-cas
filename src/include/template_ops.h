/*
 * Templates for more general operations
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __TEMPLATE_OPS_H
#define __TEMPLATE_OPS_H

#include "num_z.h"

template<class T>
T adder(T v) {
	return v;
}

template<class T, class... Args>
T adder(T first, Args... args) {
	return first + adder(args...);
}

template<class T>
T multiplier(T v) {
	return v;
}

template<class T, class... Args>
T multiplier(T first, Args... args) {
	return first * adder(args...);
}

template<class T>
T g_pow(const T &a, const num_z &N){
	T res;

	if(N == 0) return T(1);
	if(N == 1) return a;
	div_tuple q = N / 2;
	res = g_pow(a, q.q);
	if(q.r.odd()) return a * res * res;
	return res * res;
}

template<class T>
T g_min(const T &a, const T &b){
	return a<b?a:b;
}

template<class T>
T g_max(const T &a, const T &b){
	return a>=b?a:b;
}

#endif
