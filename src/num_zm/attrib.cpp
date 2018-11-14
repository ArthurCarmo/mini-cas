/*
 * Attributin operators for the modulo arithmetic integers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/num_zm.h"

num_zm & num_zm::operator=(const num_zm &a){
	this->_num = a._num;
	this->_valid = a._valid;
	this->_base = a._base;
	return *this;
}

num_zm & num_zm::operator=(const num_z &a){
	this->_num = num_z(a) % this->_base;
	this->_valid = 1;
	return *this;
}

num_zm & num_zm::operator=(const num_q &a){
	this->_num = num_z(a) % this->_base;
	this->_valid = 1;
	return *this;
}

num_zm & num_zm::operator=(const div_tuple &a){
	this->_num = num_z(a.q) % this->_base;
	this->_valid = 1;
	return *this;
}

num_zm & num_zm::operator=(const mod_tuple &a){
	this->_num = num_z(a.r) % this->_base;
	this->_valid = 1;
	return *this;
}

num_zm & num_zm::operator=(long long a){
	this->_num = num_z(a) % this->_base;
	this->_valid = 1;
	return *this;
}

num_zm & num_zm::operator=(const unsigned long long &a){
	this->_num = num_z(a) % this->_base;
	this->_valid = 1;
	return *this;
}


num_zm & num_zm::operator=(const int &a){
	this->_num = num_z(a) % this->_base;
	this->_valid = 1;
	return *this;
}


num_zm & num_zm::operator=(const uint32_t &a){
	this->_num = num_z(a) % this->_base;
	this->_valid = 1;
	return *this;
}


num_zm & num_zm::operator=(const char *a){
	this->_num = num_z(a) % this->_base;
	this->_valid = 1;
	return *this;
}

