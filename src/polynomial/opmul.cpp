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
				const_cast<num_q &>(find_me->_coeficient) += aux._coeficient;
				if(find_me->_coeficient == 0){
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
				const_cast<num_q &>(find_me->_coeficient) += aux._coeficient;
				if(find_me->_coeficient == 0){
					res._terms.erase(find_me);
				}
			}else{
				res._terms.insert(aux);
			}
		}
	}
	return *this = res;
}
