/*
 * Overload of the multiplication operator for the integer numbers
 *
 * Integer division algorithm from Donald Knuth's
 * The Art of Computer Programming, vol. 2: Seminumerical Algorithms
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/num_z.h"
#include "../include/num_q.h"

num_z num_z::operator*(const num_z &a) const { 
	num_z res;
	//Produtos triviais
	if((a == 0) | (*this == 0))return num_z(0);
/*	if(a == 1) return *this;
	if(*this == 1) return a;
	if(a == -1) return -*this;
	if(*this == -1) { res = -a; return res;}
*/	
	int sign = this->_sign ^ a._sign;
	uint32_t i, j, m, n;
	unsigned long long k;
	unsigned long long t;
	
	m = a._blocks;
	n = this->_blocks;
	res._sign = sign;
	if(res._n_blocks < (m+n)) res.__resize(m + n);
	res._blocks = m + n;
	
	k = 0;
	
	for(j = 0; j < m; ++j){
		k = 0;
		for(i = 0; i < n; ++i){
			t = ((unsigned long long)this->_num[i] * (unsigned long long)a._num[j]) + res._num[i+j] + k;
			res._num[i + j] = t % _BASE_;
			k = t / _BASE_;
		}
		res._num[j+n] = k;
	}

	while(res._num[res._blocks - 1] == 0) --res._blocks;

	return res;
}

num_q num_z::operator*(const num_q &a) const {
	num_q res(a);
	return res * *this;
}

num_z num_z::operator*(const div_tuple &a) const {
	return *this * a.q;
}

num_z num_z::operator*(const mod_tuple &a) const {
	return *this * a.r;
}

num_z num_z::operator*(const int &a) const {
	num_z res(a);
	return *this*res;
}

num_z num_z::operator*(const uint32_t &a) const {
	num_z res(a);
	return *this*res;
}

num_z num_z::operator*(const long long &a) const {
	num_z res(a);
	return *this*res;
}

num_z num_z::operator*(const unsigned long long &a) const {
	num_z res(a);
	return *this*res;
}

num_z num_z::operator*(const char *a) const {
	num_z res(a);
	return *this*res;
}
