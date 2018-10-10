#include "../include/monomial.h"
#include "../include/template_ops.h"

//primeira variável do monômio em ordem lexicográfica
std::string monomial::first_lex_var() const {
	return this->_literals.begin()->first;
}
		
//expoente da variável var
num_z monomial::exponent(const std::string &var) const {
	std::map<std::string, num_z>::const_iterator it = this->_literals.find(var);
	if(it == this->_literals.end())
		return num_z(0);
	return it->second;
}
		
//coeficiente do monômio
num_q monomial::coefficient() const {
	return this->_coefficient;
}

//set contendo as variáveis com expoente não zero no polinômio
std::set<std::string> monomial::variables() const {
	std::set<std::string> vars;
	for(std::map<std::string, num_z>::const_iterator it = this->_literals.begin(); it != this->_literals.end(); ++it)
			vars.insert(it->first);
	return vars;
}
		
//grau do monômio
num_z monomial::degree() const {
	return this->_degree;
}
		
//grau da variável var no monômio
num_z monomial::degree(const std::string &var) const {
	std::map<std::string, num_z>::const_iterator it = this->_literals.find(var);
	if(it != this->_literals.end())
		return it->second;
	return num_z(0);
}
		
num_z monomial::var_degree(const std::string &var) const {
	std::map<std::string, num_z>::const_iterator it = this->_literals.find(var);
	if(it != this->_literals.end())
		return it->second;
	return num_z(0);
}
		
//grau do monômio v no monômio
num_z monomial::degree(const monomial &v) const {
	div_tuple deg;
	div_tuple next;
	std::map<std::string, num_z>::const_iterator it_v = v._literals.begin();
	std::map<std::string, num_z>::const_iterator it = this->_literals.find(it_v->first);	
	
	if(it_v == v._literals.end() || it == this->_literals.end()) return num_z();
	
	deg = it->second / it_v->second;
	
	if(!deg.r.is_zero() || deg.q.is_zero()) return num_z();
	++it_v;
	while(it_v != v._literals.end()){
		it = this->_literals.find(it_v->first);
		if(it == this->_literals.end()) return num_z();
		if(deg.q != (next = it->second / it_v->second).q || !next.r.is_null())
			return num_z();
		++it_v;	
	}

	return deg;
}

num_z monomial::var_degree(const monomial &v) const {
	div_tuple deg;
	div_tuple next;
	std::map<std::string, num_z>::const_iterator it_v = v._literals.begin();
	std::map<std::string, num_z>::const_iterator it = this->_literals.find(it_v->first);
	
	if(it_v == v._literals.end() || it == this->_literals.end()) return num_z();
	
	deg = it->second / it_v->second;
	
	if(!deg.r.is_zero() || deg.q.is_zero()) return num_z();
	++it_v;
	while(it_v != v._literals.end()){
		it = this->_literals.find(it_v->first);
		if(it == this->_literals.end()) return num_z();
		if(deg.q != (next = it->second / it_v->second).q || !next.r.is_null())
			return num_z();
		++it_v;	
	}

	return deg;
}

//remove a variável var do monômio
monomial monomial::remove(const std::string &var) const {
	monomial res(*this);
	std::map<std::string, num_z>::iterator it = res._literals.find(var);
	if(it != res._literals.end()){
		res._degree -= it->second;
		res._literals.erase(it);
	}
	return res;
}

monomial & monomial::atr_remove(const std::string &var) {
	std::map<std::string, num_z>::iterator it = this->_literals.find(var);
	if(it != this->_literals.end()){
		this->_degree -= it->second;
		this->_literals.erase(it);
	}
	return *this;
}


monomial monomial::remove(const monomial &m) const {
	monomial res(*this);
	return res.atr_remove(m);
}
monomial & monomial::atr_remove(const monomial &m) {
	std::map<std::string, num_z>::const_iterator it_m = m._literals.begin();
	std::map<std::string, num_z>::iterator it;
	if(!this->has_var(m)) return *this;
	while(it_m != m._literals.end()){
		it = this->_literals.find(it_m->first);
		if(it != this->_literals.end()){
			this->_degree -= it->second;
			this->_literals.erase(it);
		}
		++it_m;
	}
	return *this;
}

//monômio unitário semelhante
monomial monomial::unit() const { monomial res(*this); res._coefficient = 1; return res; }
		
monomial monomial::content() const {
	monomial cont(*this);
	std::string var;
	std::map<std::string, num_z>::iterator it;
	
	if(cont.is_null()) return cont;
	cont._coefficient = 1;
	if((it = cont._literals.find("x")) != cont._literals.end()){
		var = "x";
	}else{
		var = cont._literals.begin()->first;
	}
	cont.atr_remove(var);
	return cont;
}

monomial monomial::content(std::string &var) const {
	monomial cont(*this);
	std::map<std::string, num_z>::iterator it;
		
	if(cont.is_null()) return cont;
	cont._coefficient = 1;
	cont.atr_remove(var);
			
	return cont;
}
