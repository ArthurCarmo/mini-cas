/*
 * Constructor for the integer numbers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_z.h"
#include "../include/num_zm.h"
#include "../include/num_q.h"

#include <cstdlib>
#include <cstring>

num_z::num_z(){
	this->_n_blocks = _INIT_SIZE_;
	
	this->_num = (uint32_t *)std::calloc(_INIT_SIZE_, sizeof(uint32_t));
		
	this->_blocks = 1;
	this->_sign = 0;
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

//------ CONVERTER -------------

num_zm num_z::zm_value(const num_z &a) const { return num_zm(a, *this); }
num_q num_z::q_value() const { return num_q(*this); }

//----COPY CONSTRUCTORS---------

num_z::num_z(const num_z &a){
	this->_n_blocks =  a._n_blocks;
	this->_blocks = a._blocks;
	
	this->_num = (uint32_t *)std::calloc(this->_n_blocks, sizeof(uint32_t));
	
	std::copy(a._num, a._num + a._blocks, this->_num);
	
	this->_sign = a._sign;
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

num_z::num_z(const num_q &a){
	num_z res(a.numerator() / a.denominator());
	
	this->_n_blocks = res._n_blocks;
	this->_blocks = res._blocks;
	
	this->_num = (uint32_t *)std::calloc(this->_n_blocks, sizeof(uint32_t));

	std::copy(res._num, res._num + res._blocks, this->_num);
	
	this->_sign = res._sign;
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

num_z::num_z(const num_z &a, uint32_t b){
	this->_n_blocks =  b;
	this->_blocks = a._blocks;
	this->_num = (uint32_t *)std::calloc(b, sizeof(uint32_t));

	std::copy(a._num, a._num + a._blocks, this->_num);
	
	this->_sign = a._sign;
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

num_z::num_z(const div_tuple &a){
	this->_n_blocks =  a.q._n_blocks;
	this->_blocks = a.q._blocks;
	
	this->_num = (uint32_t *)std::calloc(this->_n_blocks, sizeof(uint32_t));

	std::copy(a.q._num, a.q._num + a.q._blocks, this->_num);
	
	this->_sign = a.q._sign;
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

num_z::num_z(const mod_tuple &a){
	this->_n_blocks =  a.r._n_blocks;
	this->_blocks = a.r._blocks;
	this->_num = (uint32_t *)std::calloc(this->_n_blocks, sizeof(uint32_t));

	std::copy(a.r._num, a.r._num + a.r._blocks, this->_num);

	this->_sign = a.r._sign;
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}


num_z::num_z(long long a){
	unsigned long long b;
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (uint32_t *)std::calloc(_INIT_SIZE_, sizeof(uint32_t));
	this->_sign = 0;

	if(a < 0){
		this->_sign = 1;
		a = -a;
	}
	
	b = a;

	this->_blocks = 0;	
	do{
		this->_num[this->_blocks++] = b%_BASE_;
		b /= _BASE_; 
	}while(b);	
	
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

num_z::num_z(unsigned long long b){
	this->_n_blocks = _INIT_SIZE_;
	this->_sign = 0;
	this->_num = (uint32_t *)std::calloc(_INIT_SIZE_, sizeof(uint32_t));
	this->_blocks = 0;
	
	do{
		this->_num[this->_blocks++] = b%_BASE_;
		b /= _BASE_; 
	}while(b);
	
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

num_z::num_z(int a){
	unsigned int b;
	
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (uint32_t *)std::calloc(_INIT_SIZE_, sizeof(uint32_t));
	this->_sign = 0;

	if(a < 0){
		this->_sign = 1;
		a = -a;
	}

	b = a;

	this->_blocks = 0;

	do{
		this->_num[this->_blocks++] = b%_BASE_;
		b /= _BASE_; 
	}while(b);
	
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

num_z::num_z(uint32_t b){
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (uint32_t *)std::calloc(_INIT_SIZE_, sizeof(uint32_t));
	this->_sign = 0;
	this->_blocks = 0;
	
	do{
		this->_num[this->_blocks++] = b%_BASE_;
		b /= _BASE_; 
	}while(b);
		
	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

num_z::num_z(const char *a){
	uint32_t i = 0;
	uint32_t aux = 0;
	this->_blocks = 1;
	this->_n_blocks = std::strlen(a) / 9;
	
	this->_num = (uint32_t *)std::calloc(this->_n_blocks, sizeof(uint32_t));
	
	this->_sign = 0;
	this->_base_repr = DECIMAL;
	
	if(a[0] == '-'){
		this->_sign = 1;
		++i;
	}	
	
	if(a[i] == '0'){
		if(a[++i] == 'x')
			this->_base_repr = HEX;
		else if(a[i] == 'b')
			this->_base_repr = BIN;
		else --i;
		
		++i;
	}
	

	while(a[i] ^ '\0'){
		if(this->_base_repr == HEX){
			*this *= 16;
			if(a[i] >= 'a' && a[i] <= 'f')
				aux = 10 + a[i] - 'a';
			else
				aux = a[i] - '0';
		}else if(this->_base_repr == BIN){
			*this *= 2;			
			aux = a[i] - '0';
		}else{
			this->__left_shift();
			aux = a[i] - '0';
		}
		*this += aux;
		++i;	
	}

	this->_base_repr = DECIMAL;
	this->_type = _CAS_TYPE_Z_;
}

//----DESTRUCTOR----------------

num_z::~num_z(){
	std::free(this->_num);
}
