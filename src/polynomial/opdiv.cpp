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
