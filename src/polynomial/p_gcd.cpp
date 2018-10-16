#include "../include/polynomial.h"
#include "../include/template_ops.h"

monomial m_gcd(const monomial &a, const monomial &b, bool normalize){
	monomial res(q_gcd(a._coefficient, b._coefficient));
	if(a.is_null()) return normalize==UNIT_NORMAL?b.unit():b;
	if(b.is_null()) return normalize==UNIT_NORMAL?a.unit():a;
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
	if(normalize == UNIT_NORMAL)
		res.make_unit();
	return res;
}


polynomial single_var_gcd(const polynomial &a, const polynomial &b, bool normalize){
	polynomial_tuple res;
	polynomial aux;
	if(a.is_null()) return normalize==UNIT_NORMAL?b.unit():b;
	if(b.is_null()) return normalize==UNIT_NORMAL?a.unit():a;
	
	res.r = b;
	res.q = a;
	while(!res.r.is_null()){
		aux = res.r;
		res = res.q / res.r;
		res.q = aux;
	}

	if(normalize == UNIT_NORMAL)	
		res.q.make_unit();
	return res.q;
}

polynomial p_gcd(const polynomial &a, const polynomial &b, bool normalize){
	polynomial res;
	monomial monomial_gcd;
	std::set<monomial, monomial_comp_class>::const_iterator it_a = a._terms.begin();
	std::set<monomial, monomial_comp_class>::const_iterator it_b = b._terms.begin();
			

	if(a.is_null()) return normalize==UNIT_NORMAL?b.unit():b;
	if(b.is_null()) return normalize==UNIT_NORMAL?a.unit():a;
	
	if(a._terms.size() < 2){
		if(b._terms.size() < 2){
			return m_gcd(a.leading_term(), b.leading_term(), normalize);
		}
		monomial_gcd = m_gcd(*it_b, *it_a, normalize);
		while(++it_b != b._terms.end()){
			monomial_gcd = m_gcd(*it_b, monomial_gcd, normalize);
		}
		return monomial_gcd;
	}else if(b._terms.size() < 2){
		monomial_gcd = m_gcd(*it_a, *it_b, normalize);
		while(++it_a != a._terms.end()){
			monomial_gcd = m_gcd(*it_a, monomial_gcd, normalize);
		}
		return monomial_gcd;
	}
	
	std::string X = a._terms.begin()->first_lex_var();	
	
	polynomial Sl = a, Sg = b, Saux;
	polynomial beta;
	polynomial psi;
	polynomial d, g;
	num_z delta;

	if(a.single_variable() && b.single_variable()){
		if(X == b._terms.begin()->first_lex_var()){
			return single_var_gcd(a, b, normalize);
		}else{
			if(normalize == UNIT_NORMAL)
				return polynomial(1);
			
			while(it_a != a._terms.end()){
				monomial_gcd = m_gcd(*it_a, monomial_gcd, NO_UNIT);
				++it_a;
			}
			
			while(it_b != b._terms.end()){
				monomial_gcd = m_gcd(*it_b, monomial_gcd, NO_UNIT);
				++it_b;
			}
			return monomial_gcd;
		}
	}
	
	if(a.degree(X) < b.degree(X)){
		Sl = b;
		Sg = a;
	}
	
	d = p_gcd(Sg.content(X), Sl.content(X));
	g = p_gcd(Sg.lc(X), Sl.lc(X));
	
	
	Sl = Sl.primitive_part(X);
	Sg = Sg.primitive_part(X);
	
	delta = Sl.degree(X) - Sg.degree(X) + 1;
	beta = delta.odd()?polynomial(1):polynomial(-1);
	psi = polynomial(-1);

	while(!Sg.is_null()){
		Saux = Sg;	
		Sg = Sl.pseudo_division(Sg, X).r / beta;
		psi = g_pow(Sl.lc(X), delta - 1) / g_pow(psi, delta-2);
		delta = Saux.degree(X) - Sg.degree(X) + 1;
		beta = -Sl.lc(X) * g_pow(psi, delta-1);
		Sl = Saux;
	}
	
	if(normalize == UNIT_NORMAL)	
		return (d * (Sl * g / Sl.lc(X)).q.primitive_part(X)).make_unit();
	return (d * (Sl * g / Sl.lc(X)).q.primitive_part(X));
}
