#include "../include/polynomial.h"
#include "../include/template_ops.h"

monomial m_gcd(const monomial &a, const monomial &b){
	monomial res(q_gcd(a._coefficient, b._coefficient));
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
