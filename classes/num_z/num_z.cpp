#include "../include/num_z.h"

num_z::num_z(){
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*_INIT_SIZE_);
	for(uint32_t i = this->_n_blocks; --i;)
		this->_num[i] = 0;
	this->_num[0] = 0;
	this->_blocks = 1;
	this->_sign = 0;
}

//------ CONVERTER -------------

num_z::operator div_tuple(){div_tuple r; r.q = *this; return r.q;}
num_z::operator mod_tuple(){div_tuple q; q.r = *this; return q.r;}

//----COPY CONSTRUCTORS---------

num_z::num_z(const num_z &a){
	this->_n_blocks =  a._n_blocks;
	this->_blocks = a._blocks;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*this->_n_blocks);
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
}

num_z::num_z(const num_z &a, const uint32_t &b){
	uint32_t i;
	this->_n_blocks =  b;
	this->_blocks = a._blocks;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*b);
	for(i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	
	for(i = this->_blocks; i < b; ++i)
		this->_num[i] = 0;
	
	this->_sign = a._sign;
}

num_z::num_z(const div_tuple &a){
	this->_n_blocks =  a.q._n_blocks;
	this->_blocks = a.q._blocks;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*this->_n_blocks);
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a.q._num[i];
	this->_num[0] = a.q._num[0];
	this->_sign = a.q._sign;
}

num_z::num_z(const mod_tuple &a){
	this->_n_blocks =  a.r._n_blocks;
	this->_blocks = a.r._blocks;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*this->_n_blocks);
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a.r._num[i];
	this->_num[0] = a.r._num[0];
	this->_sign = a.r._sign;
}


num_z::num_z(const int64_t &a){
	int64_t b = a;
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*_INIT_SIZE_);
	this->_sign = 0;
	if(b < 0){
		this->_sign = 1;
		b = -b;
	}
	this->_blocks = 0;	
	do{
		this->_num[this->_blocks++] = b%_MAX_CONST_64_;
		b /= _MAX_CONST_64_; 
	}while(b);	
	
	for(b = this->_blocks; b < _INIT_SIZE_; b++)
		this->_num[b] = 0;
}

num_z::num_z(const uint64_t &a){
	uint64_t b = a;
	this->_n_blocks = _INIT_SIZE_;
	this->_sign = 0;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*_INIT_SIZE_);
	this->_blocks = 0;
	do{
		this->_num[this->_blocks++] = b%_MAX_CONST_64_;
		b /= _MAX_CONST_64_; 
	}while(b);
	
	for(b = this->_blocks; b < _INIT_SIZE_; b++)
		this->_num[b] = 0;
}

num_z::num_z(const int &a){
	int64_t b = a;
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*_INIT_SIZE_);
	this->_sign = 0;
	if(b < 0){
		this->_sign = 1;
		b = -b;
	}
	this->_blocks = 0;
	do{
		this->_num[this->_blocks++] = b%_MAX_CONST_64_;
		b /= _MAX_CONST_64_; 
	}while(b);
	
	for(b = this->_blocks; b < _INIT_SIZE_; b++)
		this->_num[b] = 0;
}
num_z::num_z(const uint32_t &a){
	uint32_t b = a;
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*_INIT_SIZE_);
	this->_sign = 0;
	this->_blocks = 0;
	do{
		this->_num[this->_blocks++] = b%_MAX_CONST_64_;
		b /= _MAX_CONST_64_; 
	}while(b);
	
	for(b = this->_blocks; b < _INIT_SIZE_; b++)
		this->_num[b] = 0;
}

num_z::num_z(const char *a){
	uint32_t i = 0, j = 0, k = 0;
	uint32_t n_blocks = 0;
	uint32_t size_last_block = 0;
	uint64_t block = 0;
	
	while(a[++i] ^ '\0');
	
	this->_sign = a[0] == '-';
	n_blocks = i/_DIGITS_PER_BLOCK_;
	size_last_block = i%_DIGITS_PER_BLOCK_;
	
	this->_n_blocks = ((n_blocks+1)>_INIT_SIZE_)?(n_blocks+1):_INIT_SIZE_;
	this->_num = (int32_t *)malloc(sizeof(int32_t)*this->_n_blocks);
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
}

//----DESTRUCTOR----------------

num_z::~num_z(){
	free(this->_num);
}
