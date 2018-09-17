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
	if(q.r == 1) return a * res * res;
	return res * res;
}

#endif
