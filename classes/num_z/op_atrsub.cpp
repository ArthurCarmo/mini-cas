#include "../include/num_z.h"


num_z & num_z::operator-=(const num_z &a){
	uint32_t i, j;
	if(this->_sign ^ a._sign){
		uint32_t sign = this->_sign;
		this->_sign = a._sign;
		*this += a;
		this->_sign = sign;
		return *this;
	}
	if(this->abs_geq(a)){
		for(i = 0; i < a._blocks; i++){
			if(this->_num[i] < a._num[i]){
				this->_num[i] += (_MAX_CONST_64_ - a._num[i]);
				j = i+1;
				while(this->_num[j] == 0){
					this->_num[j++] = _BLOCK_SIZE_64_;
				}
				--this->_num[j];
			}else{
				this->_num[i] -= a._num[i];
			}
		}
		
		while(this->_num[this->_blocks-1] == 0 && this->_blocks != 1)
			--this->_blocks;

	}else{
		
		num_z aux(*this);
		*this = a;
		this->_sign = 1-a._sign;
		for(i = 0; i < aux._blocks; i++){
			if(this->_num[i] < aux._num[i]){
				this->_num[i] += (_MAX_CONST_64_ - aux._num[i]);
				j = i+1;
				while(this->_num[j] == 0){
					this->_num[j++] = _BLOCK_SIZE_64_;
				}
				--this->_num[j];
			}else{
				this->_num[i] -= aux._num[i];
			}
		}
	
		while(this->_num[this->_blocks-1] == 0 && this->_blocks != 1)
			--this->_blocks;
	}
	
	if(*this == (uint32_t)0) this->_sign = 0;
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
