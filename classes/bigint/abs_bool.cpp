#include "bigint.h"

//----------------ABS_BOOL------------------------------------------

bool BigInt::abs_eq(const BigInt &a){
	if(this->_blocks ^ a._blocks) return false;
	
	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] ^ a._num[i]) return false;
	return this->_num[0] == a._num[0]; 
}

bool BigInt::abs_neq(const BigInt &a){
	if(this->_blocks ^ a._blocks) return true;
	
	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] ^ a._num[i]) return true;
	return this->_num[0] != a._num[0]; 
}

bool BigInt::abs_geq(const BigInt &a){
	if(this->_blocks > a._blocks) return true;
	else if(a._blocks > this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] > a._num[i]) return true;
		else if(this->_num[i] < a._num[i]) return false;
	return this->_num[0] >= a._num[0];
}

bool BigInt::abs_leq(const BigInt &a){
	if(this->_blocks < a._blocks) return true;
	else if(a._blocks < this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return this->_num[0] <= a._num[0];
}

bool BigInt::abs_gt(const BigInt &a){
	if(this->_blocks > a._blocks) return true;
	else if(a._blocks > this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] > a._num[i]) return true;
		else if(this->_num[i] < a._num[i]) return false;
	return this->_num[0] > a._num[0];
}

bool BigInt::abs_lt(const BigInt &a){
	if(this->_blocks < a._blocks) return true;
	else if(a._blocks < this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return this->_num[0] < a._num[0];
}

