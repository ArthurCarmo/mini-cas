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

bool polynomial::multi_variable() const {
	std::set<monomial, monomial_comp_class>::const_iterator it;
	std::map<std::string, num_z>::const_iterator it_t;
	std::string prev;
	std::string var;
	
	for(it = this->_terms.begin(); it != this->_terms.end(); it++){
		if(it->_literals.size() > 1) return true;
		var = it->_literals.begin()->first;
		if(!prev.empty() && var != prev)
			return true;
		prev = var;
	}
	
	return false;
}

bool polynomial::single_variable() const {
	std::set<monomial, monomial_comp_class>::const_iterator it;
	std::map<std::string, num_z>::const_iterator it_t;
	std::string prev;
	std::string var;
	
	for(it = this->_terms.begin(); it != this->_terms.end(); it++){
		if(it->_literals.size() > 1) return false;
		if(it->_literals.size() == 0) continue;
		var = it->_literals.begin()->first;
		if(!prev.empty() && var != prev)
			return false;
		prev = var;
	}
	
	return true;
}
