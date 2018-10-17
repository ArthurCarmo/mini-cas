/*
 * Methods that relate to a polynomials coefficients
 * normalize
 * leading coefficient
 * leading monomial
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/polynomial.h"

polynomial polynomial::unit() const {
	polynomial res(*this);
	res /= this->_terms.begin()->_coefficient;
	return res;
}

polynomial & polynomial::make_unit() {
	*this /= this->_terms.begin()->_coefficient;
	return *this;
}

polynomial polynomial::leading_coefficient(const std::string &var, const num_z &deg) const {
	polynomial res;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++)
		if(it->has_var_deg(var, deg))
			res += it->remove(var);
	return res;
}

polynomial polynomial::leading_coefficient(const monomial &v, const num_z &deg) const {
	polynomial res;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++)
		if(it->has_var_deg(v, deg))
			res += it->remove(v);
	return res;
}

polynomial polynomial::leading_coefficient(const std::string &var) const {
	polynomial res;
	num_z curr_deg;
	num_z next_deg;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++){
		if((next_deg = it->var_degree(var)).abs_gt(curr_deg)){
			res = it->remove(var);
			curr_deg = next_deg;
		}else if(next_deg.abs_eq(curr_deg)){
			res += it->remove(var);
		}
	}
	return res;
}

polynomial polynomial::leading_coefficient(const monomial &v) const {
	polynomial res;
	num_z curr_deg;
	num_z next_deg;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++){
		if((next_deg = it->var_degree(v)).abs_gt(curr_deg)){
			res = it->remove(v);
			curr_deg = next_deg;
		}else if(next_deg.abs_eq(curr_deg)){
			res += it->remove(v);
		}
	}
	return res;
}

polynomial polynomial::lc(const std::string &var, const num_z &deg) const {
	return this->leading_coefficient(var, deg);
}

polynomial polynomial::lc(const monomial &v, const num_z &deg) const {
	return this->leading_coefficient(v, deg);
}

polynomial polynomial::lc(const std::string &var) const {
	return this->leading_coefficient(var);
}

polynomial polynomial::lc(const monomial &v) const {
	return this->leading_coefficient(v);
}

monomial polynomial::leading_monomial(const std::string &var, const num_z &deg) const {
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		if(it->has_var_deg(var, deg))
			return *it;
		++it;
	}
	return monomial();
}

monomial polynomial::leading_monomial(const std::string &var) const {
	monomial res;
	num_z curr_deg;
	num_z next_deg;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		if((next_deg = it->var_degree(var)).abs_gt(curr_deg)){
			res = *it;
			curr_deg = next_deg;
		}
		++it;
	}
	return res;
}

monomial polynomial::leading_monomial(const monomial &v) const {
	monomial res;
	num_z curr_deg;
	num_z next_deg;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		if((next_deg = it->var_degree(v)).abs_gt(curr_deg)){
			res = *it;
			curr_deg = next_deg;
		}
		++it;
	}
	return res;
}

monomial polynomial::leading_monomial(const monomial &v, const num_z &deg) const {
	monomial res;
	monomial nv = v.pow(deg);
	num_z curr_deg;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		if(it->var_degree(nv) > curr_deg){
			res = *it;
			curr_deg = it->var_degree(nv);
		}
		++it;
	}
	return res;
}
	
monomial polynomial::lm(const std::string &var, const num_z &deg) const {
	return this->leading_monomial(var, deg);	
}

monomial polynomial::lm(const std::string &var) const {
	return this->leading_monomial(var);
}		

monomial polynomial::lm(const monomial &v) const {
	return this->leading_monomial(v);
}

monomial polynomial::lm(const monomial &v, const num_z &deg) const {
	return this->leading_monomial(v);
}
