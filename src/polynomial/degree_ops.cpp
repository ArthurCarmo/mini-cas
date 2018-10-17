/*
 * Methods related to the polynomial's degree
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */
 
#include "../include/polynomial.h"

num_z polynomial::degree(char v) const {
	return degree(std::string(1, v));
}

num_z polynomial::degree(const std::string &var) const {
	num_z m;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		m = g_max(m, it->var_degree(var));
		++it;
	}
	return m;
}

num_z polynomial::var_degree(const std::string &var) const {
	num_z m;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		m = g_max(m, it->var_degree(var));
		++it;
	}
	return m;
}

num_z polynomial::degree(const monomial &var) const {
	num_z m;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		m = g_max(m, it->var_degree(var));
		++it;
	}
	return m;
}

num_z polynomial::var_degree(const monomial &var) const {
	num_z m;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		m = g_max(m, it->var_degree(var));
		++it;
	}
	return m;
}

monomial deg_based_max(const monomial &a, const monomial &b){
	return a.degree() >= b.degree()?a:b;
}

monomial deg_based_min(const monomial &a, const monomial &b){
	return a.degree() < b.degree()?a:b;
}

monomial deg_based_max(const monomial &a, const monomial &b, const monomial &v){
	return a.degree(v) >= b.degree(v)?a:b;
}

monomial deg_based_min(const monomial &a, const monomial &b, const monomial &v){
	return a.degree(v) < b.degree(v)?a:b;
}

polynomial deg_based_max(const polynomial &a, const polynomial &b){
	return a.degree() >= b.degree()?a:b;
}

polynomial deg_based_min(const polynomial &a, const polynomial &b){
	return a.degree() < b.degree()?a:b;
}

polynomial deg_based_max(const polynomial &a, const polynomial &b, const monomial &v){
	return a.degree(v) >= b.degree(v)?a:b;
}

polynomial deg_based_min(const polynomial &a, const polynomial &b, const monomial &v){
	return a.degree(v) < b.degree(v)?a:b;
}
