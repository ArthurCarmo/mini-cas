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
#include "../../include/function.h"

std::ostream & operator<<(std::ostream &o, const function &F){
	if(F._sign) o << "-";
	o << F._name << "(" << *F._arguments << ")";
	return o;
}
