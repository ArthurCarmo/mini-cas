#include "../include/num_q.h"

num_q num_q::operator*(const num_q &a) const {
	num_q res(*this);
	
	res._sign ^= a._sign;
	res._numerator *= a._numerator;
	res._denominator *= a._denominator;

	res._simplify();	
	return res;
}

num_q num_q::operator*(const num_z &a) const {
	num_q res(*this);
	
	res._sign ^= a._sign;
	res._numerator *= a;
	res._numerator._sign = 0;
	
	res._simplify();	
	return res;

}

num_q num_q::operator*(const int64_t &a) const {
	num_q res(*this);
	
	res._sign ^= a < 0;
	res._numerator *= a;
	res._numerator._sign = 0;
	
	res._simplify();
	return res;
}

num_q num_q::pow(const num_z &N) const {
	num_q p(*this);
	num_z aux(N.abs());
	
	p._numerator = p._numerator.pow(aux);
	p._denominator = p._denominator.pow(aux);
	
	if(N < 0){
		aux = p._numerator;
		p._numerator = p._denominator;
		p._denominator = aux;
	}
	
	return p;
}
