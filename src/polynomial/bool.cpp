#include "../include/polynomial.h"

bool polynomial::operator==(const polynomial &p) const {
	if(this->_terms.size() != p._terms.size()) return false;
	std::set<monomial, monomial_comp_class>::const_iterator it = p._terms.begin();
	
	while(it != p._terms.end()){
		if(this->_terms.find(*it) == this->_terms.end()) return false;
		++it;
	}
	return true;
}

bool polynomial::operator!=(const polynomial &p) const {
	if(this->_terms.size() != p._terms.size()) return true;
	std::set<monomial, monomial_comp_class>::const_iterator it = p._terms.begin();
	
	while(it != p._terms.end()){
		if(this->_terms.find(*it) == this->_terms.end()) return true;
		++it;
	}
	return false;
}
