#include "num_z.h"

//----------------ABS_BOOL------------------------------------------

bool num_z::abs_eq(const num_z &a){
	if(this->_blocks ^ a._blocks) return false;
	
	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] ^ a._num[i]) return false;
	return this->_num[0] == a._num[0]; 
}

bool num_z::abs_neq(const num_z &a){
	if(this->_blocks ^ a._blocks) return true;
	
	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] ^ a._num[i]) return true;
	return this->_num[0] != a._num[0]; 
}

bool num_z::abs_geq(const num_z &a){
	if(this->_blocks > a._blocks) return true;
	else if(a._blocks > this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] > a._num[i]) return true;
		else if(this->_num[i] < a._num[i]) return false;
	return this->_num[0] >= a._num[0];
}

bool num_z::abs_leq(const num_z &a){
	if(this->_blocks < a._blocks) return true;
	else if(a._blocks < this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return this->_num[0] <= a._num[0];
}

bool num_z::abs_gt(const num_z &a){
	if(this->_blocks > a._blocks) return true;
	else if(a._blocks > this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] > a._num[i]) return true;
		else if(this->_num[i] < a._num[i]) return false;
	return this->_num[0] > a._num[0];
}

bool num_z::abs_lt(const num_z &a){
	if(this->_blocks < a._blocks) return true;
	else if(a._blocks < this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return this->_num[0] < a._num[0];
}

