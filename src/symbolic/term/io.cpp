/*
 * Output for the term class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */
 
 #include <iostream>
 #include "../../include/term.h"
 
std:: ostream & operator<<(std::ostream &o, const term &T){
	if(T._function != NULL){
		o << *T._function;
	}else{
		o << T._basic_term;
	}
	return o;
}
