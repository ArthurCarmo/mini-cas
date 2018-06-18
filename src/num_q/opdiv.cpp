#include "../include/num_q.h"

num_q num_q::operator/(const num_q &a){
	num_q res(*this);
	res._sign ^= a._sign;
	
	res._numerator *= a._denominator;
	res._denominator *= a._numerator;
	
	res._simplify();
	return res;
}

num_q num_q::operator/(const num_z &a){
	num_q res(*this);
	res._sign ^= a._sign;
	
	res._denominator *= a;
	res._denominator._sign = 0;
	
	res._simplify();
	return res;
}

num_q num_q::operator/(const int64_t &a){
	num_q res(*this);
	res._sign ^= a < 0;
	
	res._denominator *= a;
	res._denominator._sign = 0;
	
	res._simplify();
	return res;
}