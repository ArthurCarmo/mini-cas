/*
 * Overload of compare operators for rational numbers
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_q.h"

bool num_q::operator==(const num_q &a) const {
	return this->_sign == a._sign && this->_numerator == a._numerator && this->_denominator == a._denominator;
}

bool num_q::operator==(const num_z &a) const {
	return this->_denominator == 1 && this->_sign == a._sign && this->_numerator.abs_eq(a);
}

bool num_q::operator==(const long long &a) const {
	return this->_denominator == 1 && this->_sign == (a < 0) && this->_numerator == (1 - 2*(a < 0)) * a ;
}

bool num_q::operator>=(const num_q &a) const {
	num_q res(*this);
	res._numerator *= a._denominator;
	res._denominator *= a._numerator;
	
	res._numerator._sign = this->_sign;
	res._denominator._sign = a._sign;
	
	return res._numerator >= res._denominator;
}

bool num_q::operator>=(const num_z &a) const {
	num_q res(*this);
	res._numerator._sign = res._sign;
	res._denominator *= a;
	
	return res._numerator >= res._denominator;
}

bool num_q::operator>=(const long long &a) const {
	num_q res(*this);
	res._numerator._sign = res._sign;
	res._denominator *= a;
	
	return res._numerator >= res._denominator;
}

bool num_q::operator<=(const num_q &a) const {
	num_q res(*this);
	res._numerator *= a._denominator;
	res._denominator *= a._numerator;
	
	res._numerator._sign = this->_sign;
	res._denominator._sign = a._sign;
	
	return res._numerator <= res._denominator;
}

bool num_q::operator<=(const num_z &a) const {
	num_q res(*this);
	res._numerator._sign = res._sign;
	res._denominator *= a;
	
	return res._numerator <= res._denominator;
}

bool num_q::operator<=(const long long &a) const {
	num_q res(*this);
	res._numerator._sign = res._sign;
	res._denominator *= a;
	
	return res._numerator <= res._denominator;
}

bool num_q::operator!=(const num_q &a) const {
	return !(*this == a);
}

bool num_q::operator!=(const num_z &a) const {
	return !(*this == a);
}

bool num_q::operator!=(const long long &a) const {
	return !(*this == a);
}

bool num_q::operator>(const num_q &a) const {
	return !(*this <= a);
}

bool num_q::operator>(const num_z &a) const {
	return !(*this <= a);
}

bool num_q::operator>(const long long &a) const {
	return !(*this <= a);
}

bool num_q::operator<(const num_q &a) const {
	return !(*this >= a);
}

bool num_q::operator<(const num_z &a) const {
	return !(*this >= a);
}

bool num_q::operator<(const long long &a) const {
	return !(*this >= a);
}

