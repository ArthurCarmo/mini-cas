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
				if(!m.is_null())
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
				if(!m.is_null())
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
		polynomial_tuple operator/(const polynomial &) const;
		
		bool operator==(const polynomial &) const;
		bool operator!=(const polynomial &) const;
		
		bool is_null() const { return this->_terms.empty(); }
		num_z degree() const { if(this->_terms.size()) return this->_terms.begin()->_degree; return num_z(0); }
		unsigned long long size() const { return this->_terms.size(); }
		monomial leading_term() const { if(this->_terms.size()) return *this->_terms.begin(); return monomial(); }
		
		//funções para avaliação do polinômio
		//avalia x ou primeira variável do monômio líder
		polynomial eval(const num_q &val) const {
			polynomial res;
			std::string eval_var;
			std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
			std::map<std::string, num_z>::const_iterator it_literals;
			
			if((it_literals = it->_literals.find("x")) != it->_literals.end()){
				eval_var = "x";
			}else{
				it_literals = it->_literals.begin();
				if(it_literals == it->_literals.end()) return *this;
				eval_var = it_literals->second;
			}
			
			while(it != this->_terms.end()){
				res += polynomial(it->eval(eval_var, val));
				++it;
			}	
			
			return res;
		}
		
		//avalia o polinômio para o valor especificado de uma variável
		polynomial eval(const std::string &var, const num_q &val) const {
			polynomial res;
			
			std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
			
			while(it != this->_terms.end()){
				res += polynomial(it->eval(var, val));
				++it;
			}	
			
			return res;
		}
		
		//avalia o polinômio para os valores especificados das variáveis
		template<class... Args>
		polynomial eval(const std::string &var, const num_q &val, Args... args) const {
			polynomial res;
			
			std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
			
			while(it != this->_terms.end()){
				res += polynomial(it->eval(var, val, args...));
				++it;
			}	
			
			return res;
		}	
		
		//derivada parcial do polinômio em relação a x ou à primeira variável do monômio líder
		polynomial derive() const {
			polynomial res;
			std::string eval_var;
			std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
			std::map<std::string, num_z>::const_iterator it_literals;
			
			if((it_literals = it->_literals.find("x")) != it->_literals.end()){
				eval_var = "x";
			}else{
				it_literals = it->_literals.begin();
				if(it_literals == it->_literals.end()) return *this;
				eval_var = it_literals->second;
			}
			
			while(it != this->_terms.end()){
				res += polynomial(it->derive(eval_var));
				++it;
			}	
			
			return res;
		}
		
		polynomial derive(const std::string &var) const {
			polynomial res;
			
			std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
			
			while(it != this->_terms.end()){
				res += polynomial(it->derive(var));
				++it;
			}	
			
			return res;
		}
		
		template<class... Args>
		polynomial derive(const std::string &var, Args... args){
			polynomial res;
			
			std::set<monomial, monomial_comp_class>::const_iterator it = this->_terms.begin();
			
			while(it != this->_terms.end()){
				res += polynomial(it->derive(var, args...));
				++it;
			}	
			
			return res;
		}
};

struct polynomial_tuple {
	polynomial q;
	polynomial r;
	polynomial_tuple() { }
	polynomial_tuple(const polynomial_tuple &pt) {
		this->q = pt.q;
		this->r = pt.r;
	}
	operator polynomial(){ return this->q; }
	friend std::ostream & operator<<(std::ostream &, const polynomial_tuple &);
	polynomial_tuple & operator=(const polynomial_tuple &pt){
		this->q = pt.q;
		this->r = pt.r;
		return *this;
	}
};

#endif 
