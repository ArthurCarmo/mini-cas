#include "../include/monomial.h"
#include "../include/polynomial.h"

std::ostream & operator<<(std::ostream &o, const monomial &m){
	unsigned long long used_variables = 0;
	if(m._degree == 0)
		o << m._coeficient;
	else if(m._coeficient != 1)
		o << m._coeficient << " * ";
		
	for(std::map<std::string, num_z>::const_iterator it = m._literals.begin(); it != m._literals.end(); ++it){
		o << it->first;
		++used_variables;
		if(it->second != 1)
			o << "^" << it->second;
		if(used_variables < m._literals.size())
			o << " * ";
	}
	return o;
}

std::ostream & operator<<(std::ostream &o, const polynomial &p){
	std::set<monomial, monomial_comp_class>::const_iterator it = p._terms.begin();

	if(p._terms.size() == 0){
		o << 0;
		return o;
	}
	
	o << *it;
	++it;
	
	while(it != p._terms.end()){
		if(it->coeficient().sign()){
			o << " - ";
			o << it->abs();
		}else{
			o << " + " << *it;
		}
		++it;
	}
	
	return o;
}
