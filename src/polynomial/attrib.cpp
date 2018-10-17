/*
 * Overload of the attribution operator for the polynomials
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/polynomial.h"

polynomial & polynomial::operator=(const polynomial &p){
	this->_terms = p._terms;
	return *this;
}
