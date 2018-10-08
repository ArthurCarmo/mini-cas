#include "../include/polynomial.h"
#include "../include/template_ops.h"

monomial m_gcd(const monomial &a, const monomial &b){
	monomial res(q_gcd(a._coefficient, b._coefficient));
	if(a.is_null()) return b;
	if(b.is_null()) return a;
	std::map<std::string, num_z>::const_iterator it_a = a._literals.begin();
	std::map<std::string, num_z>::const_iterator it_b;
	
	while(it_a != a._literals.end()){
		if((it_b = b._literals.find(it_a->first)) != b._literals.end()){
			num_z _deg = g_min(it_a->second, it_b->second);
			res._literals.insert( std::pair<std::string, num_z> ( it_a->first, _deg ) );
			res._degree += _deg;
		}
		++it_a;
	}
	
	return res;
}


polynomial single_var_gcd(const polynomial &a, const polynomial &b){
	polynomial_tuple res;
	polynomial aux;
	if(a.is_null()) return b._terms.begin()->_coefficient.sign()?-b:b;
	if(b.is_null()) return a._terms.begin()->_coefficient.sign()?-a:a;
	
	res.r = b;
	res.q = a;
	while(!res.r.is_null()){
		aux = res.r;
		res = res.q / res.r;
		res.q = aux;
	}
	
	return res.q._terms.begin()->_coefficient.sign()?-res.q:res.q;
}

polynomial p_gcd(const polynomial &a, const polynomial &b){
	polynomial res;
	polynomial Sg(deg_based_max(a, b)), Sl(deg_based_min(a, b));
	polynomial g = m_gcd(*a._terms.begin(), *b._terms.begin());
	return res;
}


polynomial polynomial::content() const {
	monomial aux_mono;
	monomial acc_gcd;
	std::string var;
	bool found_x = false;
	
	std::set<monomial, monomial_comp_class>::const_iterator it;

	for(it = this->_terms.begin(); it != this->_terms.end(); it++){
		if(it->has_var("x")){
			var = "x";
			found_x = true;
			break;
		}
	}
	 
	if(!found_x){
		if((it = this->_terms.begin()) != this->_terms.end()){
			var = it->_literals.begin()->first;
		}else{
			return acc_gcd;
		}
	}
	
	while(it != this->_terms.end()) {
		aux_mono = *it;
		aux_mono.atr_remove(var);
		acc_gcd = m_gcd(acc_gcd, aux_mono);
		++it;
	}
	
	acc_gcd._coefficient = 1;
	return acc_gcd;	
}

polynomial polynomial::content(const std::string &var) const {
	monomial aux_mono;
	monomial acc_gcd;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();

	if(this->is_null()) return acc_gcd;

	while(it != this->_terms.end()) {
		aux_mono = *it;
		aux_mono.atr_remove(var);
		acc_gcd = m_gcd(acc_gcd, aux_mono);
		++it;
	}
	
	acc_gcd._coefficient = 1;
	return acc_gcd;	
}

polynomial polynomial::primitive_part() const {
	if(this->is_null()) return polynomial();
	return (*this / this->content());
}

polynomial polynomial::primitive_part(const std::string &var) const {
	if(this->is_null()) return polynomial();
	return (*this / this->content(var));
}

polynomial p_content(const polynomial &u){
	return u.content();
}


bool polynomial::multi_variable() const {
	std::set<monomial, monomial_comp_class>::const_iterator it;
	std::map<std::string, num_z>::const_iterator it_t;
	std::string prev = "\0";
	std::string var;
	
	for(it = this->_terms.begin(); it != this->_terms.end(); it++){
		if(it->_literals.size() > 1) return true;
		var = it->_literals.begin()->first;
		if(prev != "\0" && var != "\0" && var != prev)
			return true;
		prev = var;
	}
	
	return false;
}

bool polynomial::single_variable() const {
	std::set<monomial, monomial_comp_class>::const_iterator it;
	std::map<std::string, num_z>::const_iterator it_t;
	std::string prev = "\0";
	std::string var;
	
	for(it = this->_terms.begin(); it != this->_terms.end(); it++){
		if(it->_literals.size() > 1) return false;
		var = it->_literals.begin()->first;
		if(prev != "\0" && var != "\0" && var != prev)
			return false;
		prev = var;
	}
	
	return true;
}

polynomial p_content(const polynomial &u, const std::string &var){
	return u.content(var);
}

monomial deg_based_max(const monomial &a, const monomial &b){
	return a.degree() > b.degree()?a:b;
}

monomial deg_based_min(const monomial &a, const monomial &b){
	return a.degree() < b.degree()?a:b;
}

polynomial deg_based_max(const polynomial &a, const polynomial &b){
	return a.degree() > b.degree()?a:b;
}

polynomial deg_based_min(const polynomial &a, const polynomial &b){
	return a.degree() < b.degree()?a:b;
}

