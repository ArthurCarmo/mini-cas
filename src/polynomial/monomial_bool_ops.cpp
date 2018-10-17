/*
 * Boolean and comparation methods for monomials
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/monomial.h"

bool monomial::operator==(const monomial &m) const {
	return this->_degree == m._degree && this->_coefficient == m._coefficient && this->_literals == m._literals;
}
		
bool monomial::operator!=(const monomial &m) const {
	return this->_degree != m._degree || this->_coefficient != m._coefficient || this->_literals != m._literals;
}

//retorna true se monômio possui a variável var com grau maior que zero
bool monomial::has_var(const char &var) const {
	return this->_literals.find(std::string(1, var)) != this->_literals.end();
}

bool monomial::has_var(const std::string &var) const {
	return this->_literals.find(var) != this->_literals.end();
}

bool monomial::has_var(const monomial &var) const {
	return !this->var_degree(var).is_null();
}

//retorna true se monômio possui a variável var com grau especificado
bool monomial::has_var_deg(const std::string &var, const num_z &deg) const {
	std::map<std::string, num_z>::const_iterator it = this->_literals.find(var);
	if(it == this->_literals.end())
		return deg == 0;
	return it->second == deg;
}

bool monomial::has_var_deg(const char &var, const num_z &deg) const {
	std::map<std::string, num_z>::const_iterator it = this->_literals.find(std::string(1, var));
	if(it == this->_literals.end())
		return deg == 0;
	return it->second == deg;
}

bool monomial::has_var_deg(const monomial &var, const num_z &deg) const {
	return this->var_degree(var) == deg;
}
		
//um monômio u é divisível pelo monômio v se
//cada variável de u tem grau maior ou igual àquela variável em v;
bool monomial::is_divisible_by(const monomial &m) const {
	std::map<std::string, num_z>::const_iterator it = m._literals.begin();
	std::map<std::string, num_z>::const_iterator it_t;
			
	if(m._degree > this->_degree) return false;
	while(it != m._literals.end()){
		if((it_t = this->_literals.find(it->first)) == this->_literals.end() || it_t->second < it->second) 
			return false;
		++it;
	}
	return true;
}
		
//um monômio u é divide o monômio v se
//cada variável de u tem grau menor ou igual àquela variável em v;
bool monomial::divides(const monomial &m) const { 
	std::map<std::string, num_z>::const_iterator it;
	std::map<std::string, num_z>::const_iterator it_t = m._literals.begin();
	if(this->_degree > m._degree) return false;
	while(it_t != this->_literals.end()){
		if((it = m._literals.find(it_t->first)) != m._literals.end() || it->second < it_t->second) 
			return false;
		++it_t;
	}
	return true;
}
		
bool monomial::is_null() const {
	return this->_coefficient._numerator == 0;
}
		
bool monomial::multi_variable() const {
	return this->_literals.size() > 1;
}
	
bool monomial::single_variable() const {
	return this->_literals.size () < 2;
}

bool monomial::sign() const {
	return this->_coefficient._sign == 1;
}
		
//monômios são similares se possuem as variáveis com os mesmo coeficientes
bool monomial::is_similar(const monomial &m) const {
	return this->_degree == m._degree && this->_literals == m._literals;
} 
