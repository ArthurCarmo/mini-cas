/*
 * Constructors for the modulo arithmetic integers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/num_zm.h"
#include "../include/num_q.h"

num_zm::num_zm(const num_z &base){
	this->_base = base;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

num_zm::num_zm(const num_zm &a){
	this->_base = a._base;
	this->_num = a._num;
	this->_valid = a._valid;	
	this->_type = _CAS_TYPE_ZM_;
}

num_zm::num_zm(const num_z &base, const num_z &a){
	this->_base = base;
	this->_num = num_z(a)%this->_base;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

num_zm::num_zm(const num_z &base, const div_tuple &a){
	this->_base = base;
	this->_num = num_z(a.q) % this->_base;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

num_zm::num_zm(const num_z &base, const mod_tuple &a){
	this->_base = base;
	this->_num = num_z(a.r) % this->_base;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

num_q num_zm::q_value() const { return num_q(this->_num); }

