/*
 * Overload of the division and attribution operator for the rational numbers
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_q.h"

num_q & num_q::operator/=(const num_q &a){
	this->_sign ^= a._sign;
	this->_numerator *= a._denominator;
	this->_denominator *= a._numerator;
	
	this->_simplify();
	return *this;
}

num_q & num_q::operator/=(const num_z &a){
	this->_sign ^= a._sign;
	this->_denominator *= a;
	
	this->_denominator._sign = 0;
	this->_simplify();
	
	return *this;
}

num_q & num_q::operator/=(const long long &a){
	this->_sign ^= a < 0;
	this->_denominator *= a;
	
	this->_denominator._sign = 0;
	this->_simplify();
	
	return *this;
}
