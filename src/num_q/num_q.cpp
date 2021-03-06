/*
 * Constructors for the rational numbers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_q.h"

num_q::num_q(){
	this->_denominator = 1;
	this->_sign = 0;
	this->_type = _CAS_TYPE_Q_;
}

num_q::num_q(const num_q &a){
	this->_numerator = a._numerator;
	this->_denominator = a._denominator;
	this->_sign = a._sign;
	this->_type = _CAS_TYPE_Q_;
}

void num_q::_simplify(){
	num_z s(z_gcd(this->_numerator, this->_denominator));
	this->_numerator /= s;
	this->_denominator /= s;
}

num_q::num_q(const num_z &a){
	this->_numerator = a;
	this->_denominator = 1;
	this->_sign = a._sign;
	this->_numerator._sign = 0;
	this->_type = _CAS_TYPE_Q_;
}

num_q::num_q(const num_z &a, const num_z &b){
	this->_numerator = a;
	this->_denominator = b;
	this->_sign = a._sign ^ b._sign;
	this->_numerator._sign = 0;
	this->_denominator._sign = 0;
	this->_simplify();	
	this->_type = _CAS_TYPE_Q_;
}

num_q::num_q(const num_z &a, const long long &b){
	this->_numerator = a;
	this->_denominator = b;
	this->_sign = a._sign ^ (b < 0);
	this->_numerator._sign = 0;
	this->_denominator._sign = 0;
	this->_simplify();
	this->_type = _CAS_TYPE_Q_;
}

num_q::num_q(const long long &a, const num_z &b){
	this->_numerator = a;
	this->_denominator = b;
	this->_sign = b._sign ^ (a < 0);
	this->_numerator._sign = 0;
	this->_denominator._sign = 0;
	this->_simplify();
	this->_type = _CAS_TYPE_Q_;
}

num_q::num_q(const long long &a, const long long &b){
	this->_numerator = a;
	this->_denominator = b;
	this->_sign = (a < 0) ^ (b < 0);
	this->_numerator._sign = 0;
	this->_denominator._sign = 0;
	this->_simplify();
	this->_type = _CAS_TYPE_Q_;
}

num_q::num_q(int a){
	this->_numerator = a;
	this->_denominator = 1;
	this->_sign = (a < 0);
	this->_numerator._sign = 0;
	this->_type = _CAS_TYPE_Q_;
}
num_q::num_q(int a, int b){
	this->_numerator = a;
	this->_denominator = b;
	this->_sign = (a < 0) ^ (b < 0);
	this->_numerator._sign = 0;
	this->_denominator._sign = 0;
	this->_simplify();
	this->_type = _CAS_TYPE_Q_;
}
