#include "../headers/num_z.h"

num_z & num_z::operator+=(const num_z &a){
	if(this->_sign ^ a._sign){
		this->_sign = a._sign; 
		
//		*this-=a; 
		
		this->_sign = *this==0?0:!this->_sign;
	}
	unsigned int i = 0;
	bool vai_um = 0;
	bool adj_a = 0;
	if(this->_blocks < a._blocks){
		for(; i < this->_blocks; i++){
			this->_num[i] += vai_um;
			vai_um = 0;
			adj_a = a._num[i] > _BLOCK_HALF_64_;
			this->_num[i] += a._num[i] - (adj_a?_BLOCK_HALF_64_:0);
			if(this->_num[i] > _BLOCK_SIZE_64_) {this->_num[i] -= _MAX_CONST_64_; vai_um = 1;}
			this->_num[i] += (adj_a?_BLOCK_HALF_64_:0);
			if(this->_num[i] > _BLOCK_SIZE_64_) {this->_num[i] -= _MAX_CONST_64_; vai_um = 1;}
		}
		
		this->__resize(a._blocks+1);
		this->_blocks = a._blocks;
		
		for(; i < a._blocks; i++){
			this->_num[i] = vai_um + a._num[i];
			vai_um = 0;
			if(this->_num[i] > _BLOCK_SIZE_64_){
				this->_num[i] = 0;
				vai_um = 1;
			}
		}
		if(vai_um) this->_num[this->_blocks++] = 1;
	}else{
		for(; i < a._blocks; i++){
			adj_a = a._num[i] > _BLOCK_HALF_64_;
			this->_num[i] += a._num[i] - (adj_a?_BLOCK_HALF_64_:0) + vai_um;
			vai_um = 0;
			if(this->_num[i] > _BLOCK_SIZE_64_) {this->_num[i] -= _MAX_CONST_64_; vai_um = 1;}
			this->_num[i] += (adj_a?_BLOCK_HALF_64_:0);
			if(this->_num[i] > _BLOCK_SIZE_64_) {this->_num[i] -= _MAX_CONST_64_; vai_um = 1;}
		}
		
		for(; i < this->_blocks; i++){
			this->_num[i] += vai_um;
			vai_um = 0;
			if(this->_num[i++] > _BLOCK_SIZE_64_){
				this->_num[i-1] = 0;
				vai_um = 1;
			}	
		}
		if(vai_um){
			if(i == this->_n_blocks) this->__resize(i+1);
			this->_num[this->_blocks++] = 1;
		}
	}
	return *this;
}

num_z & num_z::operator+=(const unsigned long long &a){ //EXPANDIR
	num_z res;
	res = a;
	return *this += res;
}

/*
num_z & num_z::operator+=(const long long &a);
num_z & num_z::operator+=(const unsigned long long &a);
num_z & num_z::operator+=(const int &a);
num_z & num_z::operator+=(const unsigned int &a);
*/
