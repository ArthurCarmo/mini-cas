/*
 * Output for the polynomial and monomial classes
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/monomial.h"
#include "../include/polynomial.h"
#include <iostream>

std::ostream & operator<<(std::ostream &o, const monomial &m){
	unsigned long long used_variables = 0;
	if(m._degree == 0)
		o << m._coefficient;
	else if(m._coefficient != 1 && m._coefficient != -1)
		o << m._coefficient << "*";
		
	for(std::map<std::string, num_z>::const_iterator it = m._literals.begin(); it != m._literals.end(); ++it){
		o << it->first;
		++used_variables;
		if(it->second != 1 && it->second != -1)
			o << "^" << it->second;
		if(used_variables < m._literals.size())
			o << "*";
	}
	return o;
}

std::ostream & operator<<(std::ostream &o, const polynomial &p){
	std::set<monomial, monomial_comp_class>::const_iterator it = p._terms.begin();

	if(p._terms.size() == 0){
		o << 0;
		return o;
	}
	
	o << *it;
	++it;
	
	while(it != p._terms.end()){
		if(it->sign()){
			o << " - ";
			o << it->abs();
		}else{
			o << " + " << *it;
		}
		++it;
	}
	
	return o;
}

std::ostream & operator<<(std::ostream &o, const polynomial_tuple &pt){
	o << pt.q;
	return o;
}
