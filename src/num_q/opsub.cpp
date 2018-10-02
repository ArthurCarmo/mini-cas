#include "../include/num_q.h"

num_q num_q::operator-(const num_q &b) const {
	num_q res(*this), a(b);
	
	res._numerator._sign = res._sign;
	a._numerator._sign = b._sign;
	
	if(this->_denominator == a._denominator){	
		res._numerator -= a._numerator;
	}else{
		res._numerator *= a._denominator;
		res._denominator *= a._numerator;
		res._numerator -= res._denominator;
		res._denominator = this->_denominator * a._denominator;
	}
	
	res._sign = res._numerator._sign;
	res._numerator._sign = 0;
	
	res._simplify();
	return res;
}

num_q num_q::operator-(const num_z &a) const {
	num_q res(*this);
	num_z aux;
	aux = this->_denominator * a;

	res._numerator._sign = res._sign;
	res._numerator -= aux;
	
	res._sign = res._numerator._sign;
	res._numerator._sign = 0;
	
	res._simplify();
	return res;
}

num_q num_q::operator-(const long long &a) const {
	num_q res(*this);
	num_z aux;
	
	aux = this->_denominator * a;

	res._numerator._sign = res._sign;
	res._numerator -= aux;
	
	res._sign = res._numerator._sign;
	res._numerator._sign = 0;
	
	res._simplify();
	return res;
}
