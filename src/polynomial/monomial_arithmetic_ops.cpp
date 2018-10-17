/*
 * Arithmetic operations for monomials
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/monomial.h"

//atribuição
monomial & monomial::operator=(const monomial &m){
	this->_coefficient = m._coefficient;
	this->_degree = m._degree;
	this->_literals = m._literals;
	return *this;
}

//funções de manipulação de sinal
monomial monomial::abs() const {
	monomial res(*this);
	res._coefficient._sign = 0;
	return res;
}

monomial monomial::operator-() const {
	monomial res(*this);
	res._coefficient.flip_sign();
	return res;
}
		
monomial monomial::negative() const { 
	monomial res(*this); 
	res._coefficient._sign = 1;
	return res;
};
		
monomial & monomial::make_abs(){
	this->_coefficient._sign = 0;
	return *this;
};
		
monomial & monomial::flip_sign(){
	this->_coefficient._sign = 1 - this->_coefficient._sign;
	return *this;
};
	
monomial & monomial::make_negative(){
	this->_coefficient._sign = 1;
	return *this;
};

//produto de dois monômios é um monômio
monomial monomial::operator*(const monomial &m) const {
	if(this->_coefficient == 0 || m._coefficient == 0) return monomial();
	const monomial * maior = this, * menor = &m;
	
	if(this->_literals.size() < m._literals.size()){
		maior = &m;
		menor = this;
	}
	
	monomial res(*maior);
	
	std::map<std::string, num_z>::const_iterator it_maior;
	std::map<std::string, num_z>::const_iterator it_menor;
	
	for(it_menor = menor->_literals.begin(); it_menor != menor->_literals.end(); ++it_menor){
		it_maior = maior->_literals.find(it_menor->first);
		if(it_maior == maior->_literals.end()){
			res._literals.insert( std::pair<std::string, num_z> (it_menor->first, it_menor->second) );
		}else{
			res._literals[it_menor->first] += it_menor->second;
		}
	}
		
	res._coefficient *= menor->_coefficient;
	res._degree = this->_degree + m._degree;
	return res;
}
		
monomial & monomial::operator*=(const monomial &m){
	if(this->_coefficient == 0 || m._coefficient == 0) return *this = monomial();			
	
	std::map<std::string, num_z>::iterator it_this;
	std::map<std::string, num_z>::const_iterator it_m;
	
	for(it_m = m._literals.begin(); it_m != m._literals.end(); ++it_m){
		it_this = this->_literals.find(it_m->first);
		if(it_this == this->_literals.end()){
			this->_literals.insert( std::pair<std::string, num_z> (it_m->first, it_m->second) );
		}else{
			this->_literals[it_m->first] += it_m->second;
		}
	}	
	
	this->_coefficient *= m._coefficient;
	this->_degree += m._degree;
	return *this;
}
		
//potência de um monômio por um número inteiro maior ou igual a zero
monomial monomial::pow(const num_z &N) const {
	monomial res(*this);
	if(N == 0) return monomial(1);
	res._coefficient = this->_coefficient.pow(N);
	res._degree *= N;
	for(std::map<std::string, num_z>::iterator it = res._literals.begin(); it != res._literals.end(); ++it)
		it->second *= N;
	
	return res;
}
		
//operador sobrecarregado para representar a exponenciação (para facilitar a notação)
monomial monomial::operator^(const num_z &N) const {
	monomial res(*this);
	if(N == 0) return monomial(1);
	res._coefficient = this->_coefficient.pow(N);
	res._degree *= N;
	for(std::map<std::string, num_z>::iterator it = res._literals.begin(); it != res._literals.end(); ++it)
		it->second *= N;
	
	return res;
}
		
monomial & monomial::operator^=(const num_z &N){
	if(N == 0) return *this = monomial(1);
	this->_coefficient = this->_coefficient.pow(N);
	this->_degree *= N;
	for(std::map<std::string, num_z>::iterator it = this->_literals.begin(); it != this->_literals.end(); ++it)
		it->second *= N;
	
	return *this;
}
