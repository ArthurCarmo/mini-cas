#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H

#include <iostream>
#include <string>
#include <set>

#include "num_q.h"
#include "monomial.h"
#include "monomial_comp_class.h"

class polynomial{

	friend std::ostream & operator<<(std::ostream &, const polynomial &);
	
	private:
		std::set<monomial, monomial_comp_class> _terms;
		int _n_terms;
		
		void __construct_from_monomials(const monomial &m){
			std::set<monomial, monomial_comp_class>::iterator it = this->_terms.find(m);
			if(it == this->_terms.end()){
				this->_terms.insert(m);
				++this->_n_terms;
			}else{
				const_cast<num_q &>(it->_coeficient) += m._coeficient;
				if(it->_coeficient == 0){
					this->_terms.erase(it);
					--this->_n_terms;
				}
			}
		}
		
		template<class... Args>
		void __construct_from_monomials(const monomial &m, Args... args){
			std::set<monomial, monomial_comp_class>::iterator it = this->_terms.find(m);
			if(it == this->_terms.end()){
				this->_terms.insert(m);
				++this->_n_terms;
			}else{
				const_cast<num_q &>(it->_coeficient) += m._coeficient;
				if(it->_coeficient == 0){
					this->_terms.erase(it);
					--this->_n_terms;
				}
			}
			this->__construct_from_monomials(args...);
		}
		
	public:
	
		//polinômio nulo
		polynomial(){
			this->_n_terms = 0;
		}
		
		//polinômio constante
		polynomial(const Number &n){
			this->_n_terms = 1;
			this->_terms.insert(monomial(n));
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
