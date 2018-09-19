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
		
		void __construct_from_monomials(const monomial &m){
			std::set<monomial, monomial_comp_class>::iterator it = this->_terms.find(m);
			if(it == this->_terms.end()){
				this->_terms.insert(m);
			}else{
				const_cast<num_q &>(it->_coeficient) += m._coeficient;
				if(it->_coeficient == 0){
					this->_terms.erase(it);
				}
			}
		}
		
		template<class... Args>
		void __construct_from_monomials(const monomial &m, Args... args){
			std::set<monomial, monomial_comp_class>::iterator it = this->_terms.find(m);
			if(it == this->_terms.end()){
				this->_terms.insert(m);
			}else{
				const_cast<num_q &>(it->_coeficient) += m._coeficient;
				if(it->_coeficient == 0){
					this->_terms.erase(it);
				}
			}
			this->__construct_from_monomials(args...);
		}
		
	public:
	
		//polinômio nulo
		polynomial(){
		}
		
		//polinômio constante
		polynomial(const Number &n){
			this->_terms.insert(monomial(n));
		}
		
		//polinômio como soma de monômios
		template<class... Args>
		polynomial(const monomial &m, Args... args){
			this->__construct_from_monomials(m, args...);
		}
		
		polynomial & operator=(const polynomial &);

		polynomial & operator+=(const polynomial &);
		polynomial & operator-=(const polynomial &);
		polynomial & operator*=(const polynomial &);
		polynomial & operator/=(const polynomial &);
		
		polynomial operator+(const polynomial &) const; 
		polynomial operator-(const polynomial &) const;
		polynomial operator*(const polynomial &) const; 
		polynomial operator/(const polynomial &) const;
		
		bool operator==(const polynomial &) const;
		bool operator!=(const polynomial &) const;
		
		bool is_null() const { return this->_terms.empty(); }
		num_z degree() const { return this->_terms.begin()->_degree; }
		
};

#endif 
