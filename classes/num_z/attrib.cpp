#include "../include/num_z.h"

num_z & num_z::operator=(const num_z &a){
	if(this->_n_blocks < a._blocks)
		this->__resize(a._blocks + 1);
	this->_blocks = a._blocks;
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
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

num_z & num_z::operator=(const int &a){
	this->_sign = 0;
	this->_blocks = 1;
		
	if(a < 0){
		this->_sign = 1;
		this->_num[0] = -a;
	}else{
		this->_num[0] = a;
	}
	return *this;
}

num_z & num_z::operator=(const uint32_t &a){
	this->_sign = 0;
	this->_blocks = 1;
	this->_num[0] = a;
	return *this;
}

num_z & num_z::operator=(const int64_t &b){
	int64_t a = b;
	this->_sign = 0;
	if(a < 0){
		this->_sign = 1;
		a = -a;
	}
	if((uint64_t)a <= _BLOCK_SIZE_64_){
		this->_blocks = 1;
		this->_num[0] = a;
	}else{
		this->_blocks = 2;
		this->_num[1] = 1;
		this->_num[0] = a - _BLOCK_SIZE_64_ - 1;
	}
	return *this;
}

num_z & num_z::operator=(const uint64_t &a){
	this->_sign = 0;

	if(a <= _BLOCK_SIZE_64_){
		this->_blocks = 1;
		this->_num[0] = a;
	}else{
		this->_blocks = 2;
		this->_num[1] = 1;
		this->_num[0] = a - _BLOCK_SIZE_64_ - 1;
	}
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
	n_blocks = i/19;
	size_last_block = i%19;
	
	this->_n_blocks = ((n_blocks+2)>_INIT_SIZE_)?(n_blocks+2):_INIT_SIZE_;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t) * this->_n_blocks);
	this->_blocks = n_blocks + 1;
	
	while(n_blocks--){
		block = 0;
		for(j = i - 19; j < i; j++){
			block *= 10;
			block += a[j] - '0';
		}
		i -= 19;
		this->_num[k++] = block;
	}
		
	block = 0;
	for(j = this->_sign; j < size_last_block; j++){
		block *= 10;
		block += a[j] - '0';
	}
	this->_num[k++] = block;
	
	return *this;
}
