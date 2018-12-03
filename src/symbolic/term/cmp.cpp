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
 
 #include "../../include/term.h"
 #include "../../include/function.h"
 
 bool term::__immediately_equal(const term &T) const {
 	if(this->_function == NULL)
 		return T._function == NULL && this->_basic_term == T._basic_term;
 	return T._function != NULL && this->_function->__immediately_equal(*T._function);
 }
