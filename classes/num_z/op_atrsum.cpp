#include "../include/num_z.h"

num_z & num_z::operator+=(const num_z &a){
	if(this->_sign ^ a._sign){
		this->_sign = a._sign; 
		
		*this-=a; 
		
		this->_sign = *this==0?0:!this->_sign;
		return *this;	
	}
	
	uint32_t i = 0;
	int vai_um = 0;
	int adj_a = 0;
	
	if(this->_blocks < a._blocks){
		for(; i < this->_blocks; i++){
			this->_num[i] += vai_um;
			vai_um = 0;
			
			adj_a = a._num[i] > _BLOCK_HALF_64_;
			
			this->_num[i] += a._num[i] - (adj_a*_BLOCK_HALF_64_);
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
			
			if(!vai_um){
				while(++i < a._blocks){
					this->_num[i] = a._num[i];
				}
				return *this;
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
			if(this->_num[i] > _BLOCK_SIZE_64_){
				this->_num[i] = 0;
				vai_um = 1;
			}
			if(!vai_um)
				return *this;	
		}
		if(vai_um){
			if(i == this->_n_blocks) this->__resize(i+1);
			this->_num[this->_blocks++] = 1;
		}
	}
	return *this;
}

num_z & num_z::operator+=(const uint64_t &a){ //EXPANDIR
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(const int64_t &a){ //EXPANDIR
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(const int &a){ //EXPANDIR
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(const uint32_t &a){
	int vai_um = this->_num[0] > _BLOCK_SIZE_64_;
	uint32_t i = 1;
	
	this->_num[0] += a;
	
	this->_num[0] -= (vai_um?_MAX_CONST_64_:0);
	
	while(vai_um){
		vai_um = 0;
		this->_num[i] += 1;
		
		vai_um = this->_num[i] > _BLOCK_SIZE_64_;
		this->_num[i] -= (vai_um?_MAX_CONST_64_:0);
		
		if(vai_um & (++i == this->_n_blocks))
			this->__resize(++this->_blocks + 1);
	}
	return *this;
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
