/*
 * Overload of attribution operator for the integer numbers
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

num_z & num_z::operator=(const num_z &a){
	if(this->_n_blocks < a._blocks)
		this->__resize(a._blocks + 1);
		
	this->_blocks = a._blocks;
	
	std::copy(a._num, a._num + a._blocks, this->_num);
	
	for(long long i = this->_blocks; i < this->_n_blocks; i++)
		this->_num[i] = 0;
	
	this->_sign = a._sign;
	
	return *this;
}

num_z & num_z::operator=(const num_q &a){
	*this = a.numerator() / a.denominator();
	return *this;
}

num_z & num_z::operator=(const div_tuple &a){
	*this = a.q;
	return *this;
}

num_z & num_z::operator=(const mod_tuple &a){
	*this = a.r;
	return *this;
}

num_z & num_z::operator=(int a){
	uint32_t i;
	this->_sign = 0;
	if(a < 0){
		a = -a;
		this->_sign = 1;
	}
	this->_blocks = 0;
	
	do{
		this->_num[this->_blocks++] = a%_BASE_;
		a /= _BASE_; 
	}while(a);
	
	for(i = this->_blocks; i < this->_n_blocks; i++)
		this->_num[i] = 0;
	
	return *this;
}

num_z & num_z::operator=(uint32_t a){
	this->_sign = 0;
	this->_blocks = 0;
	
	do{
		this->_num[this->_blocks++] = a%_BASE_;
		a /= _BASE_; 
	}while(a);
	
	for(a = this->_blocks; a < this->_n_blocks; a++)
		this->_num[a] = 0;
	
	return *this;
}

num_z & num_z::operator=(long long a){
	uint32_t i;
	this->_sign = 0;
	if(a < 0){
		this->_sign = 1;
		a = -a;
	}
	this->_blocks = 0;
	
	do{
		this->_num[this->_blocks++] = a%_BASE_;
		a /= _BASE_; 
	}while(a);
	
	for(i = this->_blocks; i < this->_n_blocks; i++)
		this->_num[i] = 0;
	
	return *this;
}

num_z & num_z::operator=(unsigned long long a){
	this->_sign = 0;
	this->_blocks = 0;
	
	do{
		this->_num[this->_blocks++] = a%_BASE_;
		a /= _BASE_; 
	}while(a);
	
	for(a = this->_blocks; a < this->_n_blocks; a++)
		this->_num[a] = 0;
	
	return *this;
}

num_z & num_z::operator=(const char *a){
	*this = std::string(a);
	return *this;
}

num_z & num_z::operator=(const std::string &a){
	uint32_t i, j, blocks, parcial, offset;
	unsigned long long l = a.length();
	this->_base_repr = DECIMAL;
	this->_sign = 0;
	
	i = 0;
	
	if(a[0] == '-'){
		this->_sign = 1;
		++i;
	}	

	if(a[i] == '0'){
		if(a[++i] == 'x'){
			*this = 0;
			while(++i < l){
				*this *= 16;
				if(a[i] >= 'a' && a[i] <= 'f')
					*this += 10 + a[i] - 'a';
				else
					*this += a[i] - '0';
			}
			return *this;
		}else if(a[i] == 'b'){
			*this = 0;
			while(++i < l){	
				*this *= 2;			
				*this += a[i] - '0';
			}
			return *this;
		}else --i;
	}
	
	blocks = (l - this->_sign) / _DIGITS_PER_BLOCK_;
	
	if(this->_n_blocks <= blocks){
		this->_num = (uint32_t *) std::realloc(this->_num, (blocks+1) * sizeof(uint32_t));
		this->_n_blocks = blocks+1;
	}
	else if(blocks < this->_blocks) for(i = blocks; i < this->_blocks; ++i) this->_num[i] = 0;
	
	offset = 0;
	for(i = 0; i < blocks; ++i){
		parcial = 0;
		for(j = _DIGITS_PER_BLOCK_ + offset; j > offset; --j){
			parcial *= 10;
			parcial += a[l - j] - '0';
		}
		this->_num[i] = parcial;
		offset += _DIGITS_PER_BLOCK_;
	}
	l = (l - this->_sign) % _DIGITS_PER_BLOCK_;
	
	this->_blocks = blocks;
	if(l){
		l += this->_sign;
		parcial = 0;
		for(i = this->_sign; i < l; ++i){
			parcial *= 10;
			parcial += a[i] - '0';
		}
		this->_num[this->_blocks++] = parcial;
	}
	return *this;
}
