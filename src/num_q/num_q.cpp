#include "../include/num_q.h"

num_q::num_q(){
	this->_denominator = 1;
	this->_sign = 0;
}

num_q::num_q(const num_q &a){
	this->_numerator = a._numerator;
	this->_denominator = a._denominator;
	this->_sign = a._sign;
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
}

num_q::num_q(const num_z &a, const num_z &b){
	this->_numerator = a;
	this->_denominator = b;
	this->_sign = a._sign ^ b._sign;
	this->_numerator._sign = 0;
	this->_denominator._sign = 0;
	this->_simplify();	
}

num_q::num_q(const num_z &a, const int64_t &b){
	this->_numerator = a;
	this->_denominator = b;
	this->_sign = a._sign ^ (b < 0);
	this->_numerator._sign = 0;
	this->_denominator._sign = 0;
	this->_simplify();
}

num_q::num_q(const int64_t &a, const num_z &b){
	this->_numerator = a;
	this->_denominator = b;
	this->_sign = b._sign ^ (a < 0);
	this->_numerator._sign = 0;
	this->_denominator._sign = 0;
	this->_simplify();
}
