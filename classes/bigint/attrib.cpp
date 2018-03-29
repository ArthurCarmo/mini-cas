#include "bigint.h"

BigInt & BigInt::operator=(const BigInt &a){
	if(this->_n_blocks < a._blocks)
		this->__resize(a._blocks + 1);
	this->_blocks = a._blocks;
	for(unsigned int i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
	return *this;
}

BigInt & BigInt::operator=(const int &a){
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

BigInt & BigInt::operator=(const unsigned int &a){
	this->_sign = 0;
	this->_blocks = 1;
	this->_num[0] = a;
	return *this;
}

BigInt & BigInt::operator=(const long long &b){
	long long a = b;
	this->_sign = 0;
	if(a < 0){
		this->_sign = 1;
		a *= -1;
	}
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

BigInt & BigInt::operator=(const unsigned long long &a){
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
