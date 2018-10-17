/*
 * Overload of the multiplication and attribution operator for the integer numbers
 *
 * Integer multiplication algorithm from Donald Knuth's
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

num_z & num_z::operator*=(const num_z &a){
	if((a == 0) | (*this == 0))return (*this = 0);
/*	if(a == 1) return *this;
	if(*this == 1) return (*this = a);
	if(a == -1) return (*this = -*this);
	if(*this == -1) { *this = -a; return *this;}
*/	
	int sign = this->_sign ^ a._sign;
	uint32_t i, j, m, n;
	unsigned long long k;
	unsigned long long t;
	num_z res(uint32_t(0));
	
	m = a._blocks;
	n = this->_blocks;
	k = 0;
	
	if(res._n_blocks < (m + n + 1))
		res.__resize(m + n + 1);
	
	for(j = 0; j < m; ++j){
		k = 0;
		for(i = 0; i < n; ++i){
			t = (unsigned long long)this->_num[i] * (unsigned long long)a._num[j] + res._num[i+j] + k;
			res._num[i + j] = t % _BASE_;
			k = t / _BASE_;
		}
		res._num[j+n] = k;
	}
	
	res._sign = sign;
	res._blocks = m + n;
	while(res._num[res._blocks - 1] == 0) --res._blocks;
	*this = res;
	return *this;
}

num_z & num_z::operator*=(const num_q &a){
	*this *= a.numerator();
	*this /= a.denominator();
	this->_sign ^= a.sign();
	return *this;
}

num_z & num_z::operator*=(const div_tuple &a){
	return *this *= a.q;
}

num_z & num_z::operator*=(const mod_tuple &a){
	return *this *= a.r;
}

num_z & num_z::operator*=(const long long &a){
	return *this *= (num_z)a;
}

num_z & num_z::operator*=(const unsigned long long &a){
	return *this *= (num_z)a;
}

num_z & num_z::operator*=(const int &a){
	return *this *= (num_z)a;
}

num_z & num_z::operator*=(const uint32_t &a){
	return *this *= (num_z)a;
}

num_z & num_z::operator*=(const char *a){
	return *this *= (num_z)a;
}

