/*
 * Division operators for the modulo arithmetic integers class
 * Division of U mod N and V mod N is the product U * (1 / V)
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/num_zm.h"

num_zm num_zm::operator/(const num_zm &a) const {
	if(this->_base == a._base)
		return *this * a.inverse();
	return *this / a._num;
}

num_zm num_zm::operator/(const num_z &a) const {
	num_zm res(this->_base, this->_num / a);
	return res;
}

num_zm num_zm::operator/(const div_tuple &a) const {
	num_zm res(this->_base, this->_num / a);
	return res;
}

num_zm num_zm::operator/(const mod_tuple &a) const {
	num_zm res(this->_base, this->_num / a);
	return res;
}

num_zm num_zm::operator/(const int &a) const {
	num_zm res(this->_base, this->_num / a);
	return res;
}

num_zm num_zm::operator/(const uint32_t &a) const {
	num_zm res(this->_base, this->_num / a);
	return res;
}

num_zm num_zm::operator/(const long long &a) const {
	num_zm res(this->_base, this->_num / a);
	return res;
}

num_zm num_zm::operator/(const unsigned long long &a) const {
	num_zm res(this->_base, this->_num / a);
	return res;
}

num_zm num_zm::operator/(const char *a) const {
	num_zm res(this->_base, this->_num / a);
	return res;
}

num_zm & num_zm::operator/=(const num_zm &a){
	if(this->_base == a._base)
		this->_num *= a.inverse();
	else {
		this->_num /= a._num;
		this->_num %= this->_base;
	}
	return *this;
}

num_zm & num_zm::operator/=(const num_z &a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

num_zm & num_zm::operator/=(const num_q &a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

num_zm & num_zm::operator/=(const div_tuple &a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

num_zm & num_zm::operator/=(const mod_tuple &a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

num_zm & num_zm::operator/=(const int &a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

num_zm & num_zm::operator/=(const uint32_t &a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

num_zm & num_zm::operator/=(long long a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

num_zm & num_zm::operator/=(const unsigned long long &a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

num_zm & num_zm::operator/=(const char *a){
	this->_num /= a;
	this->_num %= this->_base;
	return *this;
}

