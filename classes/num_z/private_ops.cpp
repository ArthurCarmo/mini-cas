#include "../headers/num_z.h"

void num_z::__left_shift(){
	if(this->_num[this->_blocks - 1] > _MAX_18_DIGIT_ ){ 
		if(this->_blocks == this->_n_blocks) 
			this->__resize(this->_n_blocks+1); 
		this->_num[this->_blocks++] = 0;
	}
	unsigned int i = this->_blocks;
	while(i--){
		this->_num[i] %= _BLOCK_LAST_64_;
		this->_num[i] *= 10;
		this->_num[i] += i==0?0:(_num[i-1] / _BLOCK_LAST_64_);
	}
}

void num_z::__left_shift(unsigned int n){
	unsigned int i = this->_blocks;
	unsigned int j = 0;
	unsigned long long powten = 1;
	unsigned long long prune_digits;
	unsigned int mv = n/19;
	n %= 19;

	if(n){
		while(++j < n) powten *= 10;
		prune_digits = _BLOCK_LAST_64_ / powten;
		
		if(this->_num[this->_blocks - 1] > (_MAX_18_DIGIT_ /powten)){ 	
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

void num_z::__right_shift(){
	unsigned int i = 0;
	unsigned int j = this->_blocks - 1;
	for(; i < j; i++){
		this->_num[i] /= 10;
		this->_num[i] += (this->_num[i+1] % 10) * _BLOCK_LAST_64_;
	}
	this->_num[i] /= 10;
	if((this->_num[i] == 0) && (this->_blocks ^ 1))
		this->_blocks--;
}

void num_z::__right_shift(unsigned int n){
	unsigned int i = 0;
	unsigned int j = this->_blocks - 1;
	unsigned int mv = n/19;
	n %= 19;
	if(mv >= this->_blocks){
		*this = 0;
		return;
	}
	
	while(n--){
		for(i = 0; i < j; i++){
			this->_num[i] /= 10;
			this->_num[i] += (this->_num[i+1] % 10) * _BLOCK_LAST_64_;
		}
		this->_num[i] /= 10;
		if((this->_num[i--] == 0) && (this->_blocks ^ 1))
			this->_blocks--;
		j = this->_blocks - 1;
	}
	
	if(mv >= this->_blocks){
		*this = 0;
		return;
	}
	if(mv > 0)	
		for(; j - mv;)
			this->_num[j-- - mv] = this->_num[--this->_blocks];
}

void num_z::__resize(unsigned int n){
	unsigned long long *aux = new unsigned long long[n];
	unsigned int blocks = this->_blocks;
	
	for(unsigned int i = blocks; --i;)
		 aux[i] = this->_num[i];		
	
	aux[0] = this->_num[0];
	
	while(blocks < n)
		aux[blocks++] = 0;
	
	this->_n_blocks = n;
	delete[] this->_num;
	this->_num = aux;
}