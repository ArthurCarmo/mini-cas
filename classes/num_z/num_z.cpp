#include "../include/num_z.h"

num_z::num_z(){
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*_INIT_SIZE_);
	for(uint32_t i = this->_n_blocks; --i;)
		this->_num[i] = 0;
	this->_num[0] = 0;
	this->_blocks = 1;
	this->_sign = 0;
	this->_base_repr = DECIMAL;
}

//------ CONVERTER -------------

num_z::operator div_tuple(){div_tuple r; r.q = *this; return r.q;}
num_z::operator mod_tuple(){div_tuple q; q.r = *this; return q.r;}

//----COPY CONSTRUCTORS---------

num_z::num_z(const num_z &a){
	this->_n_blocks =  a._n_blocks;
	this->_blocks = a._blocks;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*this->_n_blocks);
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
	this->_base_repr = DECIMAL;
}

num_z::num_z(const num_z &a, const uint32_t &b){
	uint32_t i;
	this->_n_blocks =  b;
	this->_blocks = a._blocks;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*b);
	for(i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	
	for(i = this->_blocks; i < b; ++i)
		this->_num[i] = 0;
	
	this->_sign = a._sign;
	this->_base_repr = DECIMAL;
}

num_z::num_z(const div_tuple &a){
	this->_n_blocks =  a.q._n_blocks;
	this->_blocks = a.q._blocks;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*this->_n_blocks);
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a.q._num[i];
	this->_num[0] = a.q._num[0];
	this->_sign = a.q._sign;
	this->_base_repr = DECIMAL;
}

num_z::num_z(const mod_tuple &a){
	this->_n_blocks =  a.r._n_blocks;
	this->_blocks = a.r._blocks;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*this->_n_blocks);
	for(uint32_t i = this->_blocks; --i;)
		this->_num[i] = a.r._num[i];
	this->_num[0] = a.r._num[0];
	this->_sign = a.r._sign;
	this->_base_repr = DECIMAL;
}


num_z::num_z(const int64_t &a){
	int64_t b = a;
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*_INIT_SIZE_);
	this->_sign = 0;
	if(b < 0){
		this->_sign = 1;
		b = -b;
	}
	this->_blocks = 0;	
	do{
		this->_num[this->_blocks++] = b%_BASE_;
		b /= _BASE_; 
	}while(b);	
	
	for(b = this->_blocks; b < _INIT_SIZE_; b++)
		this->_num[b] = 0;
	
	this->_base_repr = DECIMAL;
}

num_z::num_z(const uint64_t &a){
	uint64_t b = a;
	this->_n_blocks = _INIT_SIZE_;
	this->_sign = 0;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*_INIT_SIZE_);
	this->_blocks = 0;
	do{
		this->_num[this->_blocks++] = b%_BASE_;
		b /= _BASE_; 
	}while(b);
	
	for(b = this->_blocks; b < _INIT_SIZE_; b++)
		this->_num[b] = 0;
	
	this->_base_repr = DECIMAL;
}

num_z::num_z(const int &a){
	int64_t b = a;
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*_INIT_SIZE_);
	this->_sign = 0;
	if(b < 0){
		this->_sign = 1;
		b = -b;
	}
	this->_blocks = 0;
	do{
		this->_num[this->_blocks++] = b%_BASE_;
		b /= _BASE_; 
	}while(b);
	
	for(b = this->_blocks; b < _INIT_SIZE_; b++)
		this->_num[b] = 0;
		
	this->_base_repr = DECIMAL;
}
num_z::num_z(const uint32_t &a){
	uint32_t b = a;
	this->_n_blocks = _INIT_SIZE_;
	this->_num = (uint32_t *)malloc(sizeof(uint32_t)*_INIT_SIZE_);
	this->_sign = 0;
	this->_blocks = 0;
	do{
		this->_num[this->_blocks++] = b%_BASE_;
		b /= _BASE_; 
	}while(b);
	
	for(b = this->_blocks; b < _INIT_SIZE_; b++)
		this->_num[b] = 0;
		
	this->_base_repr = DECIMAL;
}

num_z::num_z(const char *a){
	uint32_t i = 0;
	uint32_t aux;
	this->_blocks = 0;
	this->_n_blocks = 0;
	this->_num = (uint32_t *)malloc(_INIT_SIZE_ * sizeof(uint32_t));	
	*this = 0;

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
	}

	while(a[++i] ^ '\0'){
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
	}

	this->_base_repr = DECIMAL;
}

//----DESTRUCTOR----------------

num_z::~num_z(){
	free(this->_num);
}
