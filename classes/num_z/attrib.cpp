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
	uint32_t i = 0;
	uint32_t aux;
	this->_blocks = 0;
	this->_n_blocks = 0;	
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
	
	return *this;
}
