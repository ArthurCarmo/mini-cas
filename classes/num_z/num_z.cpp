#include "../include/num_z.h"

num_z::num_z(){
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t)*_INIT_SIZE_);
	for(uint32_t i = this->_n_blocks; --i;)
		this->_num[i] = 0;
	this->_num[0] = 0;
	this->_blocks = 1;
	this->_sign = 0;
}

//----COPY CONSTRUCTORS---------

num_z::num_z(const num_z &a){
	this->_n_blocks =  a._n_blocks;
	this->_blocks = a._blocks;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t)*this->_n_blocks);
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
}

num_z::num_z(const num_z &a, const uint32_t &b){
	this->_n_blocks =  b;
	this->_blocks = a._blocks;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t)*b);
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
}


num_z::num_z(const int64_t &a){
	this->_n_blocks = _INIT_SIZE_;
	this->_blocks = 1;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t)*_INIT_SIZE_);
	if(a < 0){
		this->_num[0] = -a;
		this->_sign = 1;
	}else{
		this->_num[0] = a;
		this->_sign = 0;
	}
}

num_z::num_z(const uint64_t &a){
	this->_n_blocks = _INIT_SIZE_;
	this->_sign = 0;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t)*_INIT_SIZE_);
	this->_blocks = 1 + (a > _MAX_18_DIGIT_);
	this->_num[0] = a % _BLOCK_LAST_64_;
	this->_num[1] = a / _BLOCK_LAST_64_;
}

num_z::num_z(const int &a){
	this->_n_blocks = _INIT_SIZE_;
	this->_blocks = 1;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t)*_INIT_SIZE_);
	if(a < 0){
		this->_num[0] = -a;
		this->_sign = 1;
	}else{
		this->_num[0] = a;
		this->_sign = 0;
	}
}
num_z::num_z(const uint32_t &a){
	this->_n_blocks = _INIT_SIZE_;
	this->_blocks = 1;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t)*_INIT_SIZE_);
	this->_num[0] = a;
	this->_sign = 0;
}

num_z::num_z(const char *a){
	uint32_t i = 0, j = 0, k = 0;
	uint32_t n_blocks = 0;
	uint32_t size_last_block = 0;
	uint64_t block = 0;
	
	while(a[++i] ^ '\0');
	
	this->_sign = a[0] == '-';
	n_blocks = i/19;
	size_last_block = i%19;
	
	this->_n_blocks = ((n_blocks+2)>_INIT_SIZE_)?(n_blocks+2):_INIT_SIZE_;
	this->_num = (uint64_t *)malloc(sizeof(uint64_t)*this->_n_blocks);
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
}

//----DESTRUCTOR----------------

num_z::~num_z(){
	free(this->_num);
}
