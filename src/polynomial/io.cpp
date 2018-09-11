#include "../include/monomial.h"
#include "../include/polynomial.h"

std::ostream & operator<<(std::ostream &o, const monomial &m){
	int used_variables = 0;
	if(m._var_counter == 0)
		o << m._coeficient;
	else if(m._coeficient != 1)
		o << m._coeficient << " * ";
		
	for(int i = 'a'; i <= 'z'; i++){
		if(m._variables[i]){
			o << (char)i;
			++used_variables;
			if(m._exponent[i - 'a'] != 1){
				o << "^" << m._exponent[i - 'a'];
			}
			if(used_variables < m._var_counter)
				o << " * ";
		}
	}
	return o;
}

std::ostream & operator<<(std::ostream &o, const polynomial &p){
	std::unordered_map<std::string, monomial>::const_iterator it = p._terms.begin();

	if(p._n_terms == 0){
		o << 0;
		return o;
	}
	
	o << it->second;
	++it;
	
	while(it != p._terms.end()){
		if(it->second.coeficient().sign()){
			o << " - ";
			o << it->second.abs();
		}else{
			o << " + " << it->second;
		}
		++it;
	}
	
	return o;
}
