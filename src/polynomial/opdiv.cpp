#include "../include/polynomial.h"

monomial monomial::operator/(const monomial &m) const {
	monomial res(*this);
	res._coefficient /= m._coefficient;
		
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

polynomial_tuple polynomial::operator/(const polynomial &v) const {
	polynomial_tuple res;
	polynomial f;
	
	res.r = *this;
	std::set<monomial, monomial_comp_class>::const_iterator v_it = v._terms.begin();
	
	do{
		f = res.r.G_and_R(*v_it);
		if(f.is_null())
			break;
	
		res.q += f;
		f *= v;
		res.r -= f;
		
	} while(v_it != v._terms.end());
	
	return res;
}

polynomial & polynomial::operator/=(const polynomial &v){ 
	polynomial r = *this;
	polynomial f;
	
	this->_terms = std::set<monomial, monomial_comp_class>();
	std::set<monomial, monomial_comp_class>::const_iterator v_it = v._terms.begin();
	
	do{
		f = r.G_and_R(*v_it);
		if(f.is_null())
			break;
	
		*this += f;
		f *= v;
		r -= f;
		
	} while(v_it != v._terms.end());
	
	return *this;
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
		f *= v;
		res.r -= f;
		
	} while(v_it != v._terms.end());
	
	return res;
}

polynomial_tuple lc_based_div(const polynomial &u, const polynomial &v){
	polynomial_tuple res;
	polynomial subtractor;
	monomial next_coef;
	res.r = u;
	
	while( ( v.degree() <= res.r.degree() ) && (( next_coef = res.r.leading_term() / v.leading_term() ) != monomial() ) ) {
		res.q += next_coef;
		subtractor = v * next_coef;
		res.r -= subtractor;
	}
	return res;
}
