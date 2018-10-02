#include "../include/num_q.h"

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

num_q q_gcd(const num_q &a, const num_q &b){
	return num_q(z_gcd(a._numerator * b._denominator, a._denominator * b._numerator), a._denominator * b._denominator);
}
