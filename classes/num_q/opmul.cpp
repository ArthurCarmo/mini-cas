#include "../include/num.q.h"

num_q num_q::operator*(const num_q &a){
	num_q res(*this);
	
	res._sign ^= a._sign;
	res._numerator *= a._numerator;
	res._denominator *= a._denominator;

	res._simplify();	
	return res;
}

num_q num_q::operator*(const num_z &a){
	num_q res(*this);
	
	res._sign ^= a._sign;
	res._numerator *= a._numerator;
	res._numerator._sign = 0;
	
	res._simplify();	
	return res;

}

num_q num_q::operator*(const int64_t &a){
	num_q res(*this);
	
	res._sign ^= a < 0;
	res._numerator *= a;
	res._numerator._sign = 0;
	
	res._simplify();
	return res;
}
