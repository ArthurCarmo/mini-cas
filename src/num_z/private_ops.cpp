/*
 * Memory management function for the integer numbers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_z.h"
#include <cstdlib>

void num_z::__left_shift(){
	if(this->_num[this->_blocks - 1] > _MAX_NO_CARRY_ON_SHIFT_ ){ 
		if(this->_blocks == this->_n_blocks) 
			this->__resize(this->_n_blocks+1); 
		this->_num[this->_blocks++] = 0;
	}
	uint32_t i = this->_blocks;
	while(i--){
		this->_num[i] %= _MIN_ALL_DIGITS_;
		this->_num[i] *= 10;
		this->_num[i] += i==0?0:(_num[i-1] / _MIN_ALL_DIGITS_);
	}
}

void num_z::__left_shift(uint32_t n){
	uint32_t i = this->_blocks;
	long long powten = 1;
	unsigned long long prune_digits;
	uint32_t mv = n/_DIGITS_PER_BLOCK_;
	n %= _DIGITS_PER_BLOCK_;

	if(n){
		while(--n) powten *= 10;
		prune_digits = _MIN_ALL_DIGITS_ / powten;
		
		if(this->_num[this->_blocks - 1] > (_MAX_NO_CARRY_ON_SHIFT_ /powten)){ 	
			if(this->_blocks == this->_n_blocks) 
				this->__resize(this->_n_blocks + mv + 1); 
			this->_num[this->_blocks++] = 0;
		}
		powten *= 10;
		i = this->_blocks;
		while(i--){
			this->_num[i] %= prune_digits;
			this->_num[i] *= powten;
			this->_num[i] += i==0?0:(_num[i-1] / prune_digits);
		}
	}
	if(mv > 0){
		if(this->_n_blocks <= this->_blocks + mv){
			this->__resize(this->_blocks + mv + 1);
		}
		
		for(uint32_t i = this->_blocks + mv - 1; i >= mv; i--)
			this->_num[i] = this->_num[i - mv];
		
		for(uint32_t i = 0; i < mv; i++)
			this->_num[i] = 0;
				
		this->_blocks += mv;	
	}
	
}


//------------- RIGHT SHIFT -------------

void num_z::__right_shift(){
	uint32_t i = 0;
	uint32_t j = this->_blocks - 1;
	for(; i < j; i++){
		this->_num[i] /= 10;
		this->_num[i] += (this->_num[i+1] % 10) * _MIN_ALL_DIGITS_;
	}
	this->_num[i] /= 10;
	if((this->_num[i] == 0) && (this->_blocks ^ 1))
		this->_blocks--;
}

void num_z::__right_shift(uint32_t n){
	uint32_t i = 0;
	uint32_t j = this->_blocks - 1;
	long long powten = 1;
	unsigned long long prune_digits;
	uint32_t mv = n/_DIGITS_PER_BLOCK_;
	n %= _DIGITS_PER_BLOCK_;
	
	if(mv >= this->_blocks){
		*this = 0;
		return;
	}
	this->_blocks -= mv;
	
	if(mv > 0){
		for(uint32_t i = 0; i < this->_blocks; i++)
			this->_num[i] = this->_num[i + mv];

		for(; i < this->_n_blocks; i++)
			this->_num[i] = 0;
	}
	
	if(n){
		while(--n) powten *= 10;
		prune_digits = _MIN_ALL_DIGITS_ / powten;
		powten *= 10;
		for(i = 0; i < j; i++){
			this->_num[i] /= powten;
			this->_num[i] += (this->_num[i+1] % powten) * prune_digits;
		}
		this->_num[i] /= powten;
		if((this->_num[i--] == 0) && (this->_blocks ^ 1))
			this->_blocks--;
		j = this->_blocks - 1;
	}
}

//------------- RESIZE ----------------------

void num_z::__resize(uint32_t n){
	this->_num = (uint32_t *)std::realloc(this->_num, sizeof(uint32_t) * n);
	
	if(this->_blocks < n)
		std::fill(this->_num + this->_blocks, this->_num + n, 0);
	else
		this->_blocks = n;
	
	this->_n_blocks = n;
}
