#include "../include/num_z.h"

num_z & num_z::operator=(const num_z &a){
	uint32_t i;
	if(this->_n_blocks < a._blocks)
		this->__resize(a._blocks + 1);
	this->_blocks = a._blocks;
	for(i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
	
	for(i = this->_blocks; i < this->_n_blocks; i++)
		this->_num[i] = 0;
	
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

num_z & num_z::operator=(const int &b){
	int32_t a = b;
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

num_z & num_z::operator=(const uint32_t &b){
	uint32_t a = b;
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

num_z & num_z::operator=(const int64_t &b){
	int64_t a = b;
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

num_z & num_z::operator=(const uint64_t &b){
	uint64_t a = b;
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
	
	delete []this->_num;	
	
	uint32_t i = 0, j = 0, k = 0;
	uint32_t n_blocks = 0;
	uint32_t size_last_block = 0;
	uint64_t block = 0;
	
	while(a[++i] ^ '\0');
	
	this->_sign = a[0] == '-';
	n_blocks = i/_DIGITS_PER_BLOCK_;
	size_last_block = i%_DIGITS_PER_BLOCK_;
	
	this->_n_blocks = ((n_blocks+2)>_INIT_SIZE_)?(n_blocks+2):_INIT_SIZE_;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t) * this->_n_blocks);
	this->_blocks = n_blocks + 1;
	
	while(n_blocks--){
		block = 0;
		for(j = i - _DIGITS_PER_BLOCK_; j < i; j++){
			block *= 10;
			block += a[j] - '0';
		}
		i -= _DIGITS_PER_BLOCK_;
		this->_num[k++] = block;
	}
		
	block = 0;
	for(j = this->_sign; j < size_last_block; j++){
		block *= 10;
		block += a[j] - '0';
	}
	this->_num[k++] = block;
	
	for(i = this->_blocks; i < this->_n_blocks; i++)
		this->_num[i] = 0;
	
	return *this;
}
