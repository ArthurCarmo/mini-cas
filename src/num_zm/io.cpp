/*
 * I/O for the modulo arithmetic integers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/num_zm.h"
#include <iostream>

std::ostream& operator << (std::ostream &o, const num_zm &a){
	o << a._num;
	return o;
}

std::istream& operator >> (std::istream &i, num_zm &a){
	i >> a._num;
	a._num = a._num%a._base;
	return i;
}

