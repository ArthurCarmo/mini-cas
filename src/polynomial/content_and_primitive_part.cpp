#include "../include/polynomial.h"

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

polynomial polynomial::content(const monomial &var) const {
	polynomial aux_p;
	polynomial acc_gcd;
	polynomial res(*this);
	polynomial independent_terms;
	num_z deg;
	
	std::set<monomial, monomial_comp_class>::const_iterator it = res._terms.begin();
	std::set<monomial, monomial_comp_class>::const_iterator it_t = res._terms.begin();
	
	if(this->is_null()) return acc_gcd;

	while(it != res._terms.end()) {
		aux_p = polynomial();
		if(!(deg = it->var_degree(var)).is_zero()){
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

polynomial polynomial::primitive_part(const monomial &var) const {
	if(this->is_null()) return polynomial();
	return (*this / this->content(var));
}
