/*
 * Substitution and evalution of variables methods for polynomials and monomials
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

monomial monomial::subs(const std::string &var, const monomial &m) const {
	monomial res(*this);
	std::map<std::string, num_z>::const_iterator it;
	
	if(m == monomial()) return m;
	if((it = res._literals.find(var)) != res._literals.end()){
		monomial m2(m.pow(it->second));
		res._degree -= it->second;
		res._literals.erase(it);
		res *= m2;
	}
	return res;
}

polynomial monomial::subs(const std::string &var, const polynomial &p) const {
	monomial res(*this);
	std::map<std::string, num_z>::const_iterator it;
	
	if(p == polynomial()) return p;
	if((it = res._literals.find(var)) != res._literals.end()){
		polynomial p2(g_pow(p, it->second));
		res._degree -= it->second;	
		res._literals.erase(it);
		p2 *= res;
		return p2;
	}
	return polynomial(res);
}


//monômio ref_eval

polynomial monomial::ref_eval(const std::string &var, const polynomial &p) const {
	monomial aux_this(*this);
	polynomial res;
	std::map<std::string, num_z>::iterator it;
	
	if(p == polynomial()) return p;
	if((it = aux_this._literals.find(var)) != aux_this._literals.end()){
		num_z exp(it->second);
		aux_this._degree -= exp;
		aux_this._literals.erase(it);
		res = g_pow(p, exp) * aux_this;
	}

	return res;
}


//substituição em polinômios
polynomial polynomial::subs(const std::string &var, const polynomial &p) const {
	polynomial res;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	
	if(p == polynomial()) return p;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++)
		res += it->subs(var, p);
	
	return res;
}

//wrappers
monomial monomial::eval(const std::string &v, const monomial &m) const {
	return this->subs(v, m);
}

polynomial monomial::eval(const std::string &v, const polynomial &p) const {
	return this->subs(v, p);
}

polynomial polynomial::eval(const std::string &v, const polynomial &p) const {
	return this->subs(v, p);
}

//friend funcs
monomial subs(monomial &res, const std::string &var, const monomial &m) {
	std::map<std::string, num_z>::const_iterator it;
	
	if(m == monomial()) return m;
	if((it = res._literals.find(var)) != res._literals.end()){
		monomial m2(m.pow(it->second));
		res._degree -= it->second;
		res._literals.erase(it);
		res *= m2;
	}
	return res;
}

polynomial subs(polynomial &a, const std::string &var, const polynomial &p) {
	polynomial res;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	
	if(p == polynomial()) return p;
	for(it = a._terms.begin(); it != a._terms.end(); it++)
		res += it->subs(var, p);
	
	return a = res;
}
