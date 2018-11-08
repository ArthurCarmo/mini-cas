/*
 * Generic output for the function classes
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include <iostream>
#include <vector>

#include "../../include/function.h"

std::ostream & operator<<(std::ostream &o, const function &F){
	std::vector<Expr>::const_iterator it = F._arguments.begin();
	if(F._sign) o << "-";
	o << F._name << "(";
	if(it != F._arguments.end()){
		o << *it;
		++it;
	}
	
	while(it != F._arguments.end()){
		o << ", " << *it;
		++it;
	}
	
	o << ")";
	return o;
}
