#include "../include/polynomial.h"

polynomial polynomial::operator*(const polynomial &p) const {
	polynomial res;
	monomial aux;
	
	if(p.is_null()) return polynomial();
	
	std::set<monomial, monomial_comp_class>::const_iterator factor_1;
	std::set<monomial, monomial_comp_class>::const_iterator factor_2;
	
	std::set<monomial, monomial_comp_class>::iterator find_me;
		
	for(factor_1 = this->_terms.begin(); factor_1 != this->_terms.end(); ++factor_1){
		for(factor_2 = p._terms.begin(); factor_2 != p._terms.end(); ++factor_2){
			aux = *factor_1 * *factor_2;
			if((find_me = res._terms.find(aux)) != res._terms.end()){
				const_cast<num_q &>(find_me->_coefficient) += aux._coefficient;
				if(find_me->_coefficient == 0){
					res._terms.erase(find_me);
				}
			}else{
				res._terms.insert(aux);
			}
		}
	}
	return res;
}

polynomial & polynomial::operator*=(const polynomial &p){
	polynomial res;
	monomial aux;
	
	if(p.is_null()) return *this = polynomial();
	
	std::set<monomial, monomial_comp_class>::const_iterator factor_1;
	std::set<monomial, monomial_comp_class>::const_iterator factor_2;
	
	std::set<monomial, monomial_comp_class>::iterator find_me;
		
	for(factor_1 = this->_terms.begin(); factor_1 != this->_terms.end(); ++factor_1){
		for(factor_2 = p._terms.begin(); factor_2 != p._terms.end(); ++factor_2){
			aux = *factor_1 * *factor_2;
			if((find_me = res._terms.find(aux)) != res._terms.end()){
				const_cast<num_q &>(find_me->_coefficient) += aux._coefficient;
				if(find_me->_coefficient == 0){
					res._terms.erase(find_me);
				}
			}else{
				res._terms.insert(aux);
			}
		}
	}
	return *this = res;
}

polynomial & polynomial::unsafe_atrmul(const monomial &m) {
	std::set<monomial, monomial_comp_class>::const_iterator it_this;
	
	for(it_this = this->_terms.begin(); it_this != this->_terms.end(); ++it_this)
		const_cast<monomial &>(*it_this) *= m;
	
	return *this;
}

polynomial & polynomial::unsafe_atrdiv(const monomial &m) {
	std::set<monomial, monomial_comp_class>::const_iterator it_this;
	
	for(it_this = this->_terms.begin(); it_this != this->_terms.end();){
		const_cast<monomial &>(*it_this) = *it_this / m;
		if(it_this->is_null()) {
			this->_terms.erase(it_this++);
		}else{
			 ++it_this;
		}
	}
	
	return *this;
}

monomial operator*(const Number &k, const monomial &m){
	monomial res(m);
	res *= monomial(k);
	return res;
}

monomial operator*(int k, const monomial &m){
	monomial res(m);
	res *= monomial(num_q(k));
	return res;
}
