#include "../include/num_z.h"


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
	if(menor._n_blocks < maior._blocks) menor.__resize(maior._blocks);
	this->_blocks = maior._blocks;
		
	for(i = menor._blocks; i < maior._blocks; i++)
		menor._num[i] = 0;
	
	vai_um = 0;		
	for(i = 0; i < maior._blocks; i++){
		menor._num[i] += vai_um;
		this->_num[i] = (maior._num[i] >= menor._num[i])?(maior._num[i] - menor._num[i]):(_MAX_CONST_64_ + maior._num[i] - menor._num[i]);
		vai_um = (maior._num[i] < menor._num[i]);
	}
	
	while(this->_num[this->_blocks-1] == 0 && (this->_blocks ^ 1))
		--this->_blocks;
	
	if(this->_blocks == 1 && this->_num[0] == 0) this->_sign = 0;
	
	return *this;
}

num_z & num_z::operator-=(const div_tuple &a){
	return *this -= a.q;
}

num_z & num_z::operator-=(const mod_tuple &a){
	return *this -= a.r;
}

num_z & num_z::operator-=(const int64_t &a){
	return *this -= (num_z)a;
}

num_z & num_z::operator-=(const uint64_t &a){
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
