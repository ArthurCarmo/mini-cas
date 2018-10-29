/*
 * General number operations for the modulo arithmetic class
 * Multiplicative inverse algorithm is the Extended Euclid Algorithm
 * Pow algorithm is fast mod pow algorithm, both easily found in wikipedia
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/num_zm.h"

bool num_zm::has_inverse() const {
	num_z t(0), r(this->_base), newt(1), newr(this->_num), q, aux;
	r._sign = 0;
	newr._sign = 0;

	while(newr != 0){
	q = r / newr;

	aux = newt;
	newt = t - (q * newt);
	t = aux;

	aux = newr;
	newr = r - (q * newr);
	r = aux;
	}
	if(t._sign)
	t += this->_base;

	return r > 1;
}


num_zm num_zm::inverse() const {
	num_zm res(this->_base);
	num_z t(0), r(this->_base), newt(1), newr(this->_num), q, aux;
	r._sign = 0;
	newr._sign = 0;

	while(newr != 0){
		q = r / newr;

		aux = newt;
		newt = t - (q * newt);
		t = aux;

		aux = newr;
		newr = r - (q * newr);
		r = aux;
	}
	if(t._sign)
		t += this->_base;

	t._sign = this->_base < 0;
	res._num = t;
	if(r > 1) { int k = 0; printf("%d", 1 / k); }

	return res;
}

num_zm num_zm::operator-() const{
	return num_z(this->_base)-this->_num;
}

num_zm num_zm::operator+() const{
	return *this;
}

num_zm & num_zm::operator++(){
	this->_num += 1;
	if(this->_base._sign){
		if(this->_num == 1) this->_num = this->_base + 1;
	}else{
		if(this->_num == this->_base) this->_num = 0;
	}
	return *this;
}

num_zm & num_zm::operator--(){
	this->_num -= 1;
	if(this->_base._sign){
		if(this->_num == this->_base) this->_num = 0;
	}else{
		if(this->_num == -1) this->_num = this->_base - 1;
	}
	return *this;
}

num_zm num_zm::operator++(int){
	num_zm res(this->_base, *this);
	this->_num += 1;
	if(this->_base._sign){
		if(this->_num == 1) this->_num = this->_base + 1;
	}else{
		if(this->_num == this->_base) this->_num = 0;
	}
	return res;
}


num_zm num_zm::operator--(int){
	num_zm res(this->_base, *this);
	this->_num -= 1;
	if(this->_base._sign){
		if(this->_num == this->_base) this->_num = 0;
	}else{
		if(this->_num == -1) this->_num = this->_base - 1;
	}
	return res;
}

num_zm num_zm::pow(num_z exp) const {
	num_zm res(*this);
	num_zm result(this->_base, 1);
	
	while (!exp.is_zero()) {
		if (exp._num[0] & 1) result *= res;
		res *= res;
		exp.__bit_rshift();
	}
	return result;
}

