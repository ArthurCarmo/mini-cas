/*
 * Overload of the addition operator for the integer numbers
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

num_z num_z::operator+(const num_z &a) const {
	num_z res(*this);
	if(this->_sign ^ a._sign){
		res._sign = a._sign; 
		res -= a; 
		res._sign = !res._sign;
		return res;
	}
	return res += a;	
	
}

num_q num_z::operator+(const num_q &a) const {
	num_q res(a);
	return(res += *this);
}

num_z num_z::operator+(const div_tuple &a) const {
	return *this+a.q;
}

num_z num_z::operator+(const mod_tuple &a) const {
	return *this+a.r;
}

num_z num_z::operator+(const int &a) const {
	num_z res(a);
	return res+=*this;
}

num_z num_z::operator+(const uint32_t &a) const {
	num_z res(a);
	return res+=*this;
}

num_z num_z::operator+(const long long &a) const {
	num_z res(a);
	return res+=*this;
}
num_z num_z::operator+(const unsigned long long &a) const {
	num_z res(a);
	return res+=*this;
}

num_z num_z::operator+(const char *a) const {
	num_z res(a);
	return res+=*this;
}
