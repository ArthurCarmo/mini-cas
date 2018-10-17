/*
 * Compare two integers' absolute values
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_z.h"

//----------------ABS_BOOL------------------------------------------

bool num_z::abs_eq(const num_z &a) const {
	if(this->_blocks ^ a._blocks) return false;
	
	for(uint32_t i = this->_blocks; --i;)
		if(this->_num[i] ^ a._num[i]) return false;
	return this->_num[0] == a._num[0]; 
}

bool num_z::abs_neq(const num_z &a) const {
	if(this->_blocks ^ a._blocks) return true;
	
	for(uint32_t i = this->_blocks; --i;)
		if(this->_num[i] ^ a._num[i]) return true;
	return this->_num[0] != a._num[0]; 
}

bool num_z::abs_geq(const num_z &a) const {
	if(this->_blocks > a._blocks) return true;
	else if(a._blocks > this->_blocks) return false;

	for(uint32_t i = this->_blocks; --i;)
		if(this->_num[i] > a._num[i]) return true;
		else if(this->_num[i] < a._num[i]) return false;
	return this->_num[0] >= a._num[0];
}

bool num_z::abs_leq(const num_z &a) const {
	if(this->_blocks < a._blocks) return true;
	else if(a._blocks < this->_blocks) return false;

	for(uint32_t i = this->_blocks; --i;)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return this->_num[0] <= a._num[0];
}

bool num_z::abs_gt(const num_z &a) const {
	if(this->_blocks > a._blocks) return true;
	else if(a._blocks > this->_blocks) return false;

	for(uint32_t i = this->_blocks; --i;)
		if(this->_num[i] > a._num[i]) return true;
		else if(this->_num[i] < a._num[i]) return false;
	return this->_num[0] > a._num[0];
}

bool num_z::abs_lt(const num_z &a) const {
	if(this->_blocks < a._blocks) return true;
	else if(a._blocks < this->_blocks) return false;

	for(uint32_t i = this->_blocks; --i;)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return this->_num[0] < a._num[0];
}

