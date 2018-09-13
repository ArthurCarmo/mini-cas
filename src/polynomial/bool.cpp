#include "../include/polynomial.h"

bool polynomial::operator==(const polynomial &p){
	if(this->_n_terms != this->_n_terms) return false;
	std::set<monomial, monomial_comp_class>::const_iterator it = p._terms.begin();
	
	while(it != p._terms.end()){
		if(this->_terms.find(*it) == this->_terms.end()) return false;
		++it;
	}
	return true;
}

bool polynomial::operator!=(const polynomial &p){
	if(this->_n_terms != this->_n_terms) return true;
	std::set<monomial, monomial_comp_class>::const_iterator it = p._terms.begin();
	
	while(it != p._terms.end()){
		if(this->_terms.find(*it) == this->_terms.end()) return true;
		++it;
	}
	return false;
}
