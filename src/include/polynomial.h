#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H

#include <iostream>
#include <string>
#include <unordered_map>

#include "num_q.h"
#include "monomial.h"

class polynomial{

	friend std::ostream & operator<<(std::ostream &, const polynomial &);
	
	private:
		std::unordered_map<std::string, monomial> _terms;
		uint32_t _n_terms;
		
		polynomial & __construct_from_monomials(const monomial &m){
			std::string _similar_hash = m.__create_hash();
			if(this->_terms.count(_similar_hash) > 0){
				this->_terms[_similar_hash]._coeficient += m._coeficient;
				if(this->_terms[_similar_hash]._coeficient == 0){
					this->_terms.erase(_similar_hash);
					--this->_n_terms;
				}
			}else{
				if(m._coeficient != 0){
					this->_terms.insert(std::pair<std::string, monomial>(_similar_hash, m));
					++this->_n_terms;
				}
			}
			return *this;
		}
		
		template<class... Args>
		polynomial & __construct_from_monomials(const monomial &m, Args... args){
			std::string _similar_hash = m.__create_hash();
			if(this->_terms.count(_similar_hash) > 0){
				this->_terms[_similar_hash]._coeficient += m._coeficient;
				if(this->_terms[_similar_hash]._coeficient == 0){
					this->_terms.erase(_similar_hash);
					--this->_n_terms;
				}
			}else{
				if(m._coeficient != 0){
					this->_terms.insert(std::pair<std::string, monomial> (_similar_hash, m));
					++this->_n_terms;
				}
			}
			return this->__construct_from_monomials(args...);
		}
		
	public:
		//polinômio nulo
		polynomial(){
			this->_n_terms = 0;
		}
		
		//polinômio constante
		polynomial(const Number &n){
			std::string null_str = "";
			this->_n_terms = 1;
			this->_terms.insert(std::pair<std::string, monomial> ( null_str, monomial(n) ) );
		}
		
		//polinômio como soma de monômios
		template<class... Args>
		polynomial(const monomial &m, Args... args){
			this->_n_terms = 0;
			this->__construct_from_monomials(m, args...);
		}
		
};

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
			it->second.coeficient().make_abs();
			o << it->second;
			it->second.coeficient().make_negative();
		}else{
			o << " + " << it->second;
		}
		++it;
	}
	
	return o;
}

#endif 
