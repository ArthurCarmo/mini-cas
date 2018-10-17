/*
 * Input and output of rational numbers
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_q.h"
#include <iostream>

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
