#include "../include/polynomial.h"

polynomial monomial::operator+(const monomial &m) const {
	return polynomial(*this, m);
}

polynomial operator+(int n, const monomial &m){
	return polynomial(monomial(n), m);
}

polynomial polynomial::operator+(const polynomial &p) const {
	polynomial res;
	const polynomial *most_terms = this, *least_terms = &p;
	
	if(this->_terms.size() < p._terms.size()){
		most_terms = &p;
		least_terms = this;	
	}
	
	res = *most_terms;
	std::set<monomial, monomial_comp_class>::const_iterator it = least_terms->_terms.begin();
	std::set<monomial, monomial_comp_class>::const_iterator it_res = res._terms.begin();
	
	while(it != least_terms->_terms.end()){
		it_res = res._terms.find(*it);
		if(it_res != res._terms.end()){
			const_cast<num_q &>(it_res->_coefficient) += it->_coefficient;
			if(it_res->_coefficient == 0){
				res._terms.erase(it_res);
			}
		}else{
			if(!it->is_null())
				res._terms.insert(*it);
		}
		
		++it;
	}
	
	return res;
}

polynomial & polynomial::operator+=(const polynomial &p){
	std::set<monomial, monomial_comp_class>::const_iterator it = p._terms.begin();
	std::set<monomial, monomial_comp_class>::const_iterator it_this = this->_terms.begin();
	
	while(it != p._terms.end()){
		it_this = this->_terms.find(*it);
		if(it_this != this->_terms.end()){
			const_cast<num_q &>(it_this->_coefficient) += it->_coefficient;
			if(it_this->_coefficient == 0){
				this->_terms.erase(it_this);
			}
		}else{
			if(!it->is_null())
				this->_terms.insert(*it);
		}
		++it;
	}
	
	return *this;
}
