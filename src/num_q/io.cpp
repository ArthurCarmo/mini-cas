#include "../include/num_q.h"

std::ostream& operator << (std::ostream &o, const num_q &a){
	o << a._numerator << "\\" << a._denominator;
	return o;
}

std::istream& operator >> (std::istream &i, num_q &a){
	i >> a._numerator;
	i.get();
	i >> a._denominator;
	return i;
}
