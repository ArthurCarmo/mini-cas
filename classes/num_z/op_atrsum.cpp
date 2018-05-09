#include "../include/num_z.h"

num_z & num_z::operator+=(const num_z &a){
	if(this->_sign ^ a._sign){
		this->_sign = a._sign; 
		
		*this-=a; 
		
		this->_sign = *this==0?0:!this->_sign;
		return *this;	
	}
	uint64_t w = 0;
	uint32_t i = 0;
	int vai_um = 0;
	uint32_t maior =  1 + ((this->_blocks>a._blocks)?this->_blocks:a._blocks);
	
	num_z n(a, maior);
	
	if(this->_n_blocks < maior)
		this->__resize(maior);
	else
		for(i = this->_blocks; i < maior; i++)
			this->_num[i] = 0;
	
	for(i = 0; i < this->_blocks; i++){
		w = (this->_num[i] + n._num[i] + vai_um);
		this->_num[i] = w % _BASE_;
		vai_um = (w >= _BASE_);
	}
	
	if(vai_um)
		this->_num[this->_blocks++] = 1;
	
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
	num_z res(a);
	return *this += res;
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
