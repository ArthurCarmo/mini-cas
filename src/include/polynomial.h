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
		
		void __construct_from_monomials(const monomial &m){
		
		}
		
		template<class... Args>
		void __construct_from_monomials(const monomial &m, Args... args){
			this->__construct_from_monomials(args...);
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
		
		polynomial & operator=(const polynomial &);

		polynomial & operator+=(const polynomial &);
		polynomial & operator-=(const polynomial &);
		polynomial & operator*=(const polynomial &);
		polynomial & operator/=(const polynomial &);
		
		polynomial operator+(const polynomial &); 
		polynomial operator-(const polynomial &);
		polynomial operator*(const polynomial &); 
		polynomial operator/(const polynomial &);
		
		bool operator==(const polynomial &);
		bool operator!=(const polynomial &);
				
};

#endif 
