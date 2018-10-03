#include "../include/polynomial.h"

monomial monomial::operator/(const monomial &m) const {
	monomial res(*this);
	res._coeficient /= m._coeficient;
		
	std::map<std::string, num_z>::const_iterator it = m._literals.begin();
	std::map<std::string, num_z>::iterator it_res;
	
	while(it != m._literals.end()){
		if((it_res = res._literals.find(it->first)) == res._literals.end() || it_res->second < it->second )
			return monomial();
		it_res->second -= it->second;
		res._degree -= it->second;
		if(!it_res->second){
			res._literals.erase(it_res);
		}
		++it;
	}
	
	return res;
}

polynomial_tuple polynomial::operator/(const polynomial &p) const {
	polynomial_tuple res;
	polynomial subtractor;
	monomial next_coef;
	res.r = *this;
	
	while( ( p.degree() <= res.r.degree() ) && (( next_coef = res.r.leading_term() / p.leading_term() ) != monomial() ) ) {
		res.q += next_coef;
		subtractor = p * next_coef;
		res.r -= subtractor;
	}
	return res;
}

polynomial & polynomial::operator/=(const polynomial &p){ 
	polynomial quotient;
	polynomial subtractor;
	monomial next_coef;
	
	while( ( p.degree() <= this->degree() ) && (( next_coef = this->leading_term() / p.leading_term() ) != monomial() ) ) {
		quotient += next_coef;
		subtractor = p * next_coef;
		*this -= subtractor;
	}
	
	return *this = quotient;
}

polynomial_tuple polynomial::G_and_R(const monomial &v) const {
	polynomial_tuple res;
	monomial next_coef;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	
	for(it = this->_terms.begin(); it != this->_terms.end(); it++)
		if( ( next_coef = *it / v ) != monomial() )
			res.q._terms.insert(next_coef);
		else
			res.r._terms.insert(*it);
	return res;
}

polynomial_tuple polynomial::monomial_based_div(const polynomial &v) const {
	polynomial_tuple res;
	polynomial f;
	
	res.r = *this;
	std::set<monomial, monomial_comp_class>::const_iterator v_it = v._terms.begin();
	
	do{
		f = res.r.G_and_R(*v_it);
		
		if(f.is_null())
			break;
		
		res.q += f;
		f.unsafe_atrmul(*v_it);
		res.r -= f;
		
		++v_it;
	} while(v_it != v._terms.end());
	
	return res;
}

polynomial_tuple monomial_based_div(const polynomial &u, const polynomial &v){
	polynomial_tuple res;
	polynomial f;
	
	res.r = u;
	std::set<monomial, monomial_comp_class>::const_iterator v_it = v._terms.begin();
	
	do{
		f = res.r.G_and_R(*v_it);
		
		if(f.is_null())
			break;
		
		res.q += f;
		f.unsafe_atrmul(*v_it);
		res.r -= f;
		
		++v_it;
	} while(v_it != v._terms.end());
	
	return res;
}
