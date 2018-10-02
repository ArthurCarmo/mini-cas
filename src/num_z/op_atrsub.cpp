#include "../include/num_z.h"
#include "../include/num_q.h"

num_z & num_z::operator-=(const num_z &a){
	uint32_t i;
	uint32_t vai_um;

	if(this->_sign ^ a._sign){
		uint32_t sign = this->_sign;
		this->_sign = a._sign;
		*this += a;
		this->_sign = sign;
		return *this;
	}

	num_z maior, menor;
	if(this->abs_gt(a)){
		maior = *this;
		menor = a;
	}else{
		maior = a;
		menor = *this;
		this->_sign = !a._sign;
	}
	
	if(this->_n_blocks < maior._blocks) this->__resize(maior._blocks);
	this->_blocks = maior._blocks;
		
//	for(i = menor._blocks; i < maior._blocks; i++)
//		menor._num[i] = 0;
	
	vai_um = 0;		
	for(i = 0; i < menor._blocks; i++){
		menor._num[i] += vai_um;
		this->_num[i] = (maior._num[i] >= menor._num[i])?(maior._num[i] - menor._num[i]):(_BASE_ + maior._num[i] - menor._num[i]);
		vai_um = (maior._num[i] < menor._num[i]);
	}
	
	for( ; i < maior._blocks; i++){
		if(!vai_um) break;
		this->_num[i] = (maior._num[i] != 0)?(maior._num[i] - 1):(_MAX_DIGIT_BASE_);
		vai_um = maior._num[i] == 0;
	}
	
	for( ; i < maior._blocks; i++)
		this->_num[i] = maior._num[i];
	
	while(this->_num[this->_blocks-1] == 0 && (this->_blocks ^ 1))
		--this->_blocks;
	
	if(this->_blocks == 1 && this->_num[0] == 0) this->_sign = 0;
	
	return *this;
}

num_z & num_z::operator-=(const num_q &a){
	num_q res(-a);
	return *this = (res += *this);
}

num_z & num_z::operator-=(const div_tuple &a){
	return *this -= a.q;
}

num_z & num_z::operator-=(const mod_tuple &a){
	return *this -= a.r;
}

num_z & num_z::operator-=(const long long &a){
	return *this -= (num_z)a;
}

num_z & num_z::operator-=(const unsigned long long &a){
	return *this -= (num_z)a;
}

num_z & num_z::operator-=(const int &a){
	return *this -= (num_z)a;
}

num_z & num_z::operator-=(const uint32_t &a){
	return *this -= (num_z)a;
}

num_z & num_z::operator-=(const char *a){
	return *this -= (num_z)a;
}
