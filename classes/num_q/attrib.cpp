#include "../include/num_q.h"

num_q & num_q::operator=(const num_q &a){
	this->_numerator = a._numerator;
	this->_denominator = a._denominator;
	this->_sign = a._sign;
	return *this;
}

num_q & num_q::operator=(const num_z &a){
	this->_numerator = a;
	this->_denominator = 1;
	this->_sign = a._sign;
	this->_numerator._sign = 0;
	return *this;
}

num_q & num_q::operator=(const int64_t &a){
	this->_numerator = a;
	this->_denominator = 1;
	this->_sign = a < 0;
	this->_numerator._sign = 0;
	return *this;
}
