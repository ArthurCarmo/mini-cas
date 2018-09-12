#include "../include/monomial.h"
#include "../include/polynomial.h"

std::ostream & operator<<(std::ostream &o, const monomial &m){
	int used_variables = 0;
	if(m._var_counter == 0)
		o << m._coeficient;
	else if(m._coeficient != 1)
		o << m._coeficient << " * ";
		
	for(std::map<std::string, num_z>::const_iterator it = m._literals.begin(); it != m._literals.end(); ++it){
		o << it->first;
		++used_variables;
		if(it->second != 1)
			o << "^" << it->second;
		if(used_variables < m._var_counter)
			o << " * ";
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
