#include "../include/num_z.h"
#include "../include/num_q.h"

num_z & num_z::operator+=(const num_z &a){
	if(this->_sign ^ a._sign){
		this->_sign = a._sign; 
		
		*this-=a; 
		
		this->_sign = *this==0?0:!this->_sign;
		return *this;	
	}
	
	unsigned long long w = 0;
	uint32_t i = 0;
	uint32_t maior =  1 + ((this->_blocks>a._blocks)?this->_blocks:a._blocks);
	int vai_um = 0;
	
	num_z n(a, maior);
	
	if(this->_n_blocks < maior)
		this->__resize(maior);
//	else	
//		std::memset(this->_num + this->_blocks, 0, (maior - this->_blocks) * sizeof(uint32_t));
	
	this->_blocks = maior - 1;
	
	for(i = 0; i < this->_blocks; i++){
		w = (this->_num[i] + n._num[i] + vai_um);
		this->_num[i] = w % _BASE_;
		vai_um = (w >= _BASE_);
	}
	
	if(vai_um)
		this->_num[this->_blocks++] = 1;
	
	return *this;
}

num_z & num_z::operator+=(const num_q &a){
	num_q res(a);
	return *this = (res += *this);
}

num_z & num_z::operator+=(const unsigned long long &a){ //EXPANDIR
	num_z res(a);
	return *this += res;
}

num_z & num_z::operator+=(const long long &a){ //EXPANDIR
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
