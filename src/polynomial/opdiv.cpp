/*
 * Overload of the division operator for the polynomial classes
 * Leading coefficient based division of polynomials
 * Monomial based divions of polynomials
 * Pseudo divison of polynomials
 *
 * All polynomial divsion algorithms are from J. S. Cohen's
 * Computer Algebra and Symbolic Computation: Mathematical Methods
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/polynomial.h"
#include "../include/template_ops.h"
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

polynomial_tuple polynomial::pseudo_division(const polynomial &v, const monomial &X) const {
	polynomial_tuple res;
	polynomial p;
	polynomial s(*this);
	polynomial v_coef = v.lc(X);
	polynomial s_coef;

	num_z v_var_deg = v.var_degree(X);
	num_z s_deg;
	num_z curr_exp;
	num_z delta(this->var_degree(X) - v_var_deg);
	num_z sigma;
	
	if(delta.sign()) delta = num_z();
	while((s_deg = s.var_degree(X)) >= v_var_deg){
		s_coef = s.lc(X);
		curr_exp = s_deg - v_var_deg;
		s_coef.unsafe_atrmul(X.pow(curr_exp));
		
		p = p * v_coef + s_coef;
		s_coef *= v;
		s = s * v_coef - s_coef;

		++sigma;
		if(sigma > 5) return res;
	}
	
	delta -= sigma;
	v_coef = g_pow(v.lc(X), delta);
	res.q =  v_coef * p;
	res.r =  v_coef * s;

	return res;
}
