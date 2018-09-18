#include "../include/num_q.h"

std::ostream& operator << (std::ostream &o, const num_q &a){
	if(a._sign) o << "-";
	o << a._numerator;
	if(a._denominator != 1)
		o << "/" << a._denominator;
	return o;
}

std::istream& operator >> (std::istream &i, num_q &a){
	i >> a._numerator;
	i.get();
	i >> a._denominator;
	
	a._sign = a._numerator.sign() ^ a._denominator.sign();
	
	a._numerator.make_abs();
	a._denominator.make_abs();
	
	a._simplify();
	return i;
}
