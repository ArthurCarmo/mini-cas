#include "../include/polynomial.h"

polynomial polynomial::operator+(const polynomial &p){
	polynomial res;
	const polynomial *most_terms = this, *least_terms = &p;
	
	if(this->_n_terms < p._n_terms){
		most_terms = &p;
		least_terms = this;	
	}
	
	res = *most_terms;
	std::set<monomial, monomial_comp_class>::const_iterator it = least_terms->_terms.begin();
	std::set<monomial, monomial_comp_class>::iterator it_res = res._terms.begin();
	
	while(it != least_terms->_terms.end()){
		it_res = res._terms.find(*it);
		if(it_res != most_terms->_terms.end()){
			const_cast<num_q &>(it_res->_coeficient) += it->_coeficient;
			if(it_res->_coeficient == 0){
				res._terms.erase(it_res);
				--res._n_terms;
			}
		}else{
			res._terms.insert(*it);
			++res._n_terms;
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
			const_cast<num_q &>(it_this->_coeficient) += it->_coeficient;
			if(it_this->_coeficient == 0){
				this->_terms.erase(it_this);
				--this->_n_terms;
			}
		}else{
			this->_terms.insert(*it);
			++this->_n_terms;
		}
		++it;
	}
	
	return *this;
}
