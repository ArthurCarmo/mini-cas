/*
 * Compares for immediate equality
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */
 
 #include <vector>
 #include "../../include/function.h"
 
 bool function::__immediately_equal(const function &F) const {
 	if(this->_sign != F._sign || this->_name != F._name || this->_arguments.size() != F._arguments.size())
 		return false;
 	
 	for(unsigned long i = 0; i < this->_arguments.size(); i++)
 		if(this->_arguments[i].__immediately_equal(F._arguments[i])) return false;
 	
 	return true;
 }
