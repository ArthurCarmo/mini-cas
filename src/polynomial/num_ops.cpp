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
	if(a.is_null()) return b.unit();
	if(b.is_null()) return a.unit();
	
	res.r = b;
	res.q = a;
	while(!res.r.is_null()){
		aux = res.r;
		res = res.q / res.r;
		res.q = aux;
	}
	
	return res.q.unit();
}

polynomial p_gcd(const polynomial &a, const polynomial &b){
	polynomial res;
	polynomial Sg(deg_based_max(a, b)), Sl(deg_based_min(a, b));
	
	if(a.is_null()) return b.unit();
	if(b.is_null()) return a.unit();
	
	if(a.single_variable() && b.single_variable()){
		
		if(a._terms.begin()->_literals.begin()->first == b._terms.begin()->_literals.begin()->first){
			return single_var_gcd(a, b);
		}else{
			return polynomial(1);
		}
	}
	
	if(a._terms.size() < 2 && b._terms.size() < 2){
		return m_gcd(a.leading_term(), b.leading_term());
	}
	
	return res;
}

polynomial polynomial::unit() const {
	polynomial res(*this);
	res /= this->_terms.begin()->_coefficient;
	return res;
}

polynomial polynomial::polynomial_coefficient(const std::string &var, const num_z &deg) const {
	polynomial res;
	std::set<monomial, monomial_comp_class>::const_iterator it;
	for(it = this->_terms.begin(); it != this->_terms.end(); it++)
		if(it->has_var_deg(var, deg))
			res += *it;
	
	return res;
}

monomial polynomial::leading_coefficient(const std::string &var, const num_z &deg) const {
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		if(it->has_var_deg(var, deg))
			return *it;
		++it;
	}
	return monomial();
}

polynomial polynomial::content() const {
	polynomial aux_p;
	polynomial acc_gcd;
	polynomial res(*this);
	polynomial independent_terms;
	std::string var;
	num_z deg;
	bool found_x = false;
	
	std::set<monomial, monomial_comp_class>::const_iterator it;
	std::set<monomial, monomial_comp_class>::const_iterator it_t;
	std::map<std::string, num_z>::const_iterator it_l;
	

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

	if(this->is_null()) return acc_gcd;
	
	it = res._terms.begin();
	while(it != res._terms.end()) {
		aux_p = polynomial();
		it_l = it->_literals.find(var);
		
		if(it_l != it->_literals.end()){
			deg = it_l->second;
			for(it_t = res._terms.begin(); it_t != res._terms.end();){
				if(it_t->has_var_deg(var, deg)){
					aux_p += it_t->remove(var);
					res._terms.erase(it_t++);
				}else{
					++it_t;
				}
			}
			acc_gcd = p_gcd(acc_gcd, aux_p);
		}else{
			independent_terms += *it;
			res._terms.erase(it);
		}
		it = res._terms.begin();		
	}
	
	acc_gcd = p_gcd(acc_gcd, independent_terms);

	
	return acc_gcd;	
}

polynomial polynomial::content(const std::string &var) const {
	polynomial aux_p;
	polynomial acc_gcd;
	polynomial res(*this);
	polynomial independent_terms;
	num_z deg;
	
	std::set<monomial, monomial_comp_class>::const_iterator it = res._terms.begin();
	std::set<monomial, monomial_comp_class>::const_iterator it_t = res._terms.begin();
	std::map<std::string, num_z>::const_iterator it_l;
	
	if(this->is_null()) return acc_gcd;

	while(it != res._terms.end()) {
		aux_p = polynomial();
		it_l = it->_literals.find(var);
		
		if(it_l != it->_literals.end()){
			deg = it_l->second;
			for(it_t = res._terms.begin(); it_t != res._terms.end();){
				if(it_t->has_var_deg(var, deg)){
					aux_p += it_t->remove(var);
					res._terms.erase(it_t++);
				}else{
					++it_t;
				}
			}
			acc_gcd = p_gcd(acc_gcd, aux_p);
		}else{
			independent_terms += *it;
			res._terms.erase(it);
		}
		it = res._terms.begin();		
	}
	
	acc_gcd = p_gcd(acc_gcd, independent_terms);
	
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
	std::string prev = "";
	std::string var;
	
	for(it = this->_terms.begin(); it != this->_terms.end(); it++){
		if(it->_literals.size() > 1) return false;
		if(it->_literals.size() == 0) continue;
		var = it->_literals.begin()->first;
		if(prev != "" && var != "" && var != prev)
			return false;
		prev = var;
	}
	
	return true;
}

polynomial p_content(const polynomial &u, const std::string &var){
	return u.content(var);
}

num_z polynomial::degree(char v) const {
	return degree(std::string(1, v));
}

num_z polynomial::degree(const std::string &var) const {
	num_z m;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		m = g_max(m, it->var_degree(var));
		++it;
	}
	return m;
}

num_z polynomial::var_degree(const std::string &var) const {
	num_z m;
	std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
	while(it != this->_terms.end()){
		m = g_max(m, it->var_degree(var));
		++it;
	}
	return m;
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

