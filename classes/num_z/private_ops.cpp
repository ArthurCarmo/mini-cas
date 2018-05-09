#include "../include/num_z.h"

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
	int64_t powten = 1;
	uint64_t prune_digits;
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
		i = this->_blocks;
		while(--i)
			this->_num[i+mv] = this->_num[i];
		this->_num[mv] = this->_num[0];

		this->_blocks += mv;	
		
		while(mv--)
			this->_num[mv] = 0;
		
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
	int64_t powten = 1;
	uint64_t prune_digits;
	uint32_t mv = n/_DIGITS_PER_BLOCK_;
	n %= _DIGITS_PER_BLOCK_;
	
	if(mv >= this->_blocks){
		*this = 0;
		return;
	}
	
	if(mv > 0)	
		for(; j - mv;)
			this->_num[j-- - mv] = this->_num[--this->_blocks];
	
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
	int32_t *aux = (int32_t *)realloc(this->_num, sizeof(int32_t) * n);
	uint32_t blocks = this->_blocks;
	
	while(blocks < n)
		aux[blocks++] = 0;
	
	this->_n_blocks = n;

	this->_num = aux;
}
