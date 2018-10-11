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
	
	res.q.make_unit();
	return res.q;
}

polynomial p_gcd(const polynomial &a, const polynomial &b){
	polynomial res;
	
	if(a.is_null()) return b.unit();
	if(b.is_null()) return a.unit();
	
	std::string X = a._terms.begin()->first_lex_var();
	if(X.empty()) return polynomial(1);
	
	polynomial Sl = a, Sg = b, Saux;
	polynomial beta;
	polynomial psi;
	polynomial d, g;
	num_z delta;
	
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
	
	return (d * (Sl * g / Sl.lc(X)).q.primitive_part(X)).make_unit();
}
