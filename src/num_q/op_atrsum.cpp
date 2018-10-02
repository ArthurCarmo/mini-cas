#include "../include/num_q.h"

num_q & num_q::operator+=(const num_q &a){
	num_z b(a._numerator);
	
	this->_numerator._sign = this->_sign;
	b._sign = a._sign;
	
	if(this->_denominator == a._denominator){
		this->_numerator += b;
	}else{
		this->_numerator *= a._denominator;
		b *= this->_denominator;
		this->_numerator += b;
		this->_denominator *= a._denominator;
	}
	
	this->_sign = this->_numerator._sign;
	this->_numerator._sign = 0;
	
	this->_simplify();
	
	return *this;
}

num_q & num_q::operator+=(const num_z &a){
	num_z b(a);
	this->_numerator._sign = this->_sign;
	b *= this->_denominator;
	
	this->_numerator += b;
	
	this->_sign = this->_numerator._sign;
	this->_numerator._sign = 0;
	
	this->_simplify();
	
	return *this;
}

num_q & num_q::operator+=(const long long &a){
	num_z b(a);
	this->_numerator._sign = this->_sign;
	b *= this->_denominator;
	
	this->_numerator += b;
	
	this->_sign = this->_numerator._sign;
	this->_numerator._sign = 0;
	
	this->_simplify();
	
	return *this;
}
