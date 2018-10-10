#include "../include/polynomial.h"

polynomial polynomial::polynomial_coefficient(const std::string &var, const num_z &deg) const {
	polynomial res;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++)
		if(it->has_var_deg(var, deg))
			res += it->remove(var);
	
	return res;
}

polynomial polynomial::polynomial_coefficient(const monomial &v, const num_z &deg) const {
	polynomial res;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++)
		if(it->has_var_deg(v, deg))
			res += it->remove(v);
	return res;
}

polynomial polynomial::polynomial_coefficient(const monomial &v) const {
	polynomial res;
	monomial next;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++)
		if(!(next = *it / v).is_null())
			res += next;
	return res;
}

polynomial polynomial::polynomial_coefficient(const std::string &var) const {
	return this->polynomial_coefficient(monomial(var));
}

monomial polynomial::leading_coefficient(const std::string &var, const num_z &deg) const {
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		if(it->has_var_deg(var, deg))
			return *it;
		++it;
	}
	return monomial();
}

monomial polynomial::leading_coefficient(const std::string &var) const {
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

monomial polynomial::leading_coefficient(const monomial &v) const {
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

monomial polynomial::leading_coefficient(const monomial &v, const num_z &deg) const {
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
	
monomial polynomial::lc(const std::string &var, const num_z &deg) const {
	return this->leading_coefficient(var, deg);	
}

monomial polynomial::lc(const std::string &var) const {
	return this->leading_coefficient(var);
}		

monomial polynomial::lc(const monomial &v) const {
	return this->leading_coefficient(v);
}

monomial polynomial::lc(const monomial &v, const num_z &deg) const {
	return this->leading_coefficient(v);
}
