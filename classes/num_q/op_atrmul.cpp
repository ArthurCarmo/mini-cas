#include "../include/num_q.h"

num_q & num_q::operator*=(const num_q &a){
	this->_sign ^= a._sign;
	this->_numerator *= a._numerator;
	this->_denominator *= a._denominator;
	
	this->_simplify();
	return *this;
}

num_q & num_q::operator*=(const num_z &a){
	this->_sign ^= a._sign;
	this->_numerator *= a;
	
	this->_numerator._sign = 0;
	this->_simplify();
	
	return *this;
}

num_q & num_q::operator*=(const int64_t &a){
	this->_sign ^= a < 0;
	this->_numerator *= a;
	
	this->_numerator._sign = 0;
	this->_simplify();
	
	return *this;
}
