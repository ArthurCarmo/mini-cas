/*
 * Input and output of arbitrary precision integers
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_z.h"
#include <iostream>

std::ostream& operator << (std::ostream &o, const num_z &a){
	if(a._base_repr == DECIMAL){
		char *output = (char *)malloc(_DIGITS_PER_BLOCK_*a._blocks + a._sign + 1);
		unsigned long long n_chars = a._sign;
		uint32_t i = a._blocks-1;

		if(a._sign) sprintf(output, "-");
		n_chars += sprintf(output + n_chars, "%d", a._num[i]);
		while(i--) n_chars += sprintf(output + n_chars, "%09d", a._num[i]);	//TROCAR %09 POR _DIGITS_PER_BLOCK_
		o << output;
		free(output);
	}else if(a._base_repr == HEX){
		o << hex_f(a);
	}else{
		o << bin_f(a);
	}
	
	return o;
}

std::istream& operator >> (std::istream &in, num_z &a){
	std::string s;
	in >> s;
	a = s;
	
	return in;
}

std::ostream& operator << (std::ostream &o, const div_tuple &a){
	o << a.q;
	return o;
}
	
std::ostream& operator << (std::ostream &o, const mod_tuple &a){
	o << a.r;
	return o;
}	
