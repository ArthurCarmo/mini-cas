#include "../include/polynomial.h"

#define __MAP_KEY_ first
#define __MAP_VALUE_ second

polynomial polynomial::operator+(const polynomial &p){
	polynomial res;
	const polynomial *most_terms, *least_terms;
	
	if(this->_n_terms >= p._n_terms){
		most_terms = this;
		least_terms = &p;
	}else{
		most_terms = &p;
		least_terms = this;	
	}
	
	res = *most_terms;
	std::unordered_map<std::string, monomial>::const_iterator it = least_terms->_terms.begin();
	
	while(it != least_terms->_terms.end()){
		if(res._terms.count(it->__MAP_KEY_) > 0){
			res._terms[it->__MAP_KEY_]._similar_atrsum(it->__MAP_VALUE_);
			if(res._terms[it->__MAP_KEY_]._coeficient == 0){
				res._terms.erase(it->__MAP_KEY_);
				--res._n_terms;
			}
		}else{
			res._terms.insert(std::pair<std::string, monomial> (it->__MAP_KEY_, it->__MAP_VALUE_));
			++res._n_terms;
		}
		
		++it;
	}
	
	return res;
}

polynomial & polynomial::operator+=(const polynomial &p){
	std::unordered_map<std::string, monomial>::const_iterator it = p._terms.begin();
	
	while(it != p._terms.end()){
		if(this->_terms.count(it->__MAP_KEY_) > 0){
			this->_terms[it->__MAP_KEY_]._similar_atrsum(it->__MAP_VALUE_);
			if(this->_terms[it->__MAP_KEY_]._coeficient == 0){
				this->_terms.erase(it->__MAP_KEY_);
				--this->_n_terms;
			}
		}else{
			this->_terms.insert(std::pair<std::string, monomial> (it->__MAP_KEY_, it->__MAP_VALUE_));
			++this->_n_terms;
		}
		
		++it;
	}
	
	return *this;
}
