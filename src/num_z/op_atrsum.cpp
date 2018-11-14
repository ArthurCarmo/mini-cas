/*
 * Overload of the addition and attribution operator for the integer numbers
 *
 * Integer addition algorithm from Donald Knuth's
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

num_z & num_z::operator+=(num_z n){
	if(this->_sign ^ n._sign){
		this->_sign = n._sign; 
		
		*this-=n; 
		
		this->_sign = *this==0?0:!this->_sign;
		return *this;	
	}
	
	unsigned long long w = 0;
	uint32_t i = 0;
	uint32_t maior =  1 + ((this->_blocks>n._blocks)?this->_blocks:n._blocks);
	int vai_um = 0;
	
	if(n._n_blocks < maior)
		n.__resize(maior);
	
	if(this->_n_blocks < maior)
		this->__resize(maior);
//	else	
//		std::memset(this->_num + this->_blocks, 0, (maior - this->_blocks) * sizeof(uint32_t));
	
	this->_blocks = maior - 1;
	
	for(i = 0; i < this->_blocks; i++){
		w = (this->_num[i] + n._num[i] + vai_um);
		this->_num[i] = w % _BASE_;
		vai_um = (w >= _BASE_);
	}
	
	if(vai_um)
		this->_num[this->_blocks++] = 1;
	
	return *this;
}

num_z & num_z::operator+=(const num_q &b){
	num_q a(b);
	return *this = (a += *this);
}

num_z & num_z::operator+=(unsigned long long a){ //EXPANDIR
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(long long a){ //EXPANDIR
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(int a){ //EXPANDIR
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(uint32_t a){
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(const char *a){
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(const div_tuple &a){
	return *this += a.q;
}

num_z & num_z::operator+=(const mod_tuple &a){
	return *this += a.r;
}
