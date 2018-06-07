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

num_q num_q::pow(int64_t N){
	num_q p(*this);
	num_z aux(this->_numerator);
	
	p._numerator.pow(N);
	p._denominator.pow(N);
	
	if(N < 0){
		p._numerator = p._denominator;
		p._denominator = aux;
	}
	return p;
}
