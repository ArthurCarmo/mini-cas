#include "../include/polynomial.h"

#define __MAP_KEY_ first
#define __MAP_VALUE_ second

bool polynomial::operator==(const polynomial &p){
	if(this->_n_terms != this->_n_terms) return false;
	std::unordered_map<std::string, monomial>::const_iterator it = p._terms.begin();
	
	while(it != p._terms.end()){
		if(this->_terms.count(it->__MAP_KEY_) == 0 || this->_terms[it->__MAP_KEY_] != it->__MAP_VALUE_) return false;
		++it;
	}
	return true;
}

bool polynomial::operator!=(const polynomial &p){
	if(this->_n_terms != this->_n_terms) return true;
	std::unordered_map<std::string, monomial>::const_iterator it = p._terms.begin();
	
	while(it != p._terms.end()){
		if(this->_terms.count(it->__MAP_KEY_) == 0 || this->_terms[it->__MAP_KEY_] != it->__MAP_VALUE_) return true;
		++it;
	}
	return false;
}
