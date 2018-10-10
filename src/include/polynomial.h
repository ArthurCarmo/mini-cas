#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H

#include <iostream>
#include <string>
#include <set>

#include "num_q.h"
#include "monomial.h"
#include "monomial_comp_class.h"
#include "template_ops.h"

class polynomial{

	friend std::ostream & operator<<(std::ostream &, const polynomial &);
	
	
	friend polynomial_tuple monomial_based_div(const polynomial &, const polynomial &);
	friend polynomial_tuple lc_based_div(const polynomial &, const polynomial &);
	friend polynomial subs(polynomial &, const std::string &, const polynomial &);
	friend polynomial p_gcd(const polynomial &, const polynomial &);
	
	friend polynomial p_content(const polynomial &);
	friend polynomial p_content(const polynomial &, const std::string &);
	friend polynomial deg_based_max(const polynomial &, const polynomial &);
	friend polynomial deg_based_min(const polynomial &, const polynomial &);
	friend polynomial single_var_gcd(const polynomial &, const polynomial &);
	friend polynomial p_gcd(const polynomial &, const polynomial &);

	private:
		std::set<monomial, monomial_comp_class> _terms;
		
		//Função base da construção do polinômio a partir de monômios
		void __construct_from_monomials(const monomial &m){
			std::set<monomial, monomial_comp_class>::iterator it = this->_terms.find(m);
			if(it == this->_terms.end()){
				if(!m.is_null())
					this->_terms.insert(m);
			}else{
				const_cast<num_q &>(it->_coefficient) += m._coefficient;
				if(it->_coefficient == 0){
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
				const_cast<num_q &>(it->_coefficient) += m._coefficient;
				if(it->_coefficient == 0){
					this->_terms.erase(it);
				}
			}
			this->__construct_from_monomials(args...);
		}
		
		
		//Funções que auxiliam na divisão baseada em monômios
		//Na divisão de um polinômio u por um monômio v
		//G(u, v) é o somatório da divisão por v de todos os termos de u divisíveis por v
		//R(u, v) é o somatório de todos os termos de u não divisíveis por v
		polynomial_tuple G_and_R(const monomial &) const ;
		
		//A multiplicação por um monômio não deve alterar a ordenação dos termos
		polynomial & unsafe_atrmul(const monomial &);
	
	public:
	
		//polinômio nulo
		polynomial(){
		}
		
		//polinômio constante
		polynomial(const Number &n){
			this->_terms.insert(monomial(n));
		}
		
		polynomial(int n){
			this->_terms.insert(monomial(n));
		}
		
		//polinômio como soma de monômios
		template<class... Args>
		polynomial(const monomial &m, Args... args){
			this->__construct_from_monomials(m, args...);
		}
		
		//Sobrecargas de operadores aritméticos
		polynomial & operator=(const polynomial &);

		polynomial & operator+=(const polynomial &);
		polynomial & operator-=(const polynomial &);
		polynomial & operator*=(const polynomial &);
		polynomial & operator/=(const polynomial &);
		
		polynomial operator+(const polynomial &) const; 
		polynomial operator-(const polynomial &) const;
		polynomial operator*(const polynomial &) const; 
		polynomial_tuple operator/(const polynomial &) const;
		polynomial_tuple monomial_based_div(const polynomial &) const;
		
		bool operator==(const polynomial &) const;
		bool operator!=(const polynomial &) const;
		
		bool is_null() const { return this->_terms.empty(); }
		bool multi_variable() const;
		bool single_variable() const;
		
		//grau do polinômio
		num_z degree() const { if(this->_terms.size()) return this->_terms.begin()->_degree; return num_z(0); }
		num_z degree(char) const;
		num_z degree(const std::string &) const ;
		
		//maior grau da variável no polinômio
		num_z var_degree(const std::string &) const ;
		
		unsigned long long size() const { return this->_terms.size(); }
		
		//termo líder do monômio de acordo com a função
		//de comparação definida em monomial_comp_class
		monomial leading_term() const { if(this->_terms.size()) return *this->_terms.begin(); return monomial(); }
		monomial leading_coefficient() const { if(this->_terms.size()) return *this->_terms.begin(); return monomial(); }
		monomial lc() const { if(this->_terms.size()) return *this->_terms.begin(); return monomial(); }
		
		//polynômio dividido pelo coeficiente racional do monômio líder
		//definido pela monomial_comp_class
		polynomial unit() const;
		
		polynomial operator-() const {
			polynomial res;
			std::set<monomial, monomial_comp_class>::const_iterator it;
			for(it = this->_terms.begin(); it != this->_terms.end(); it++)
				res -= *it;
			return res;
		}
		
		
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
		
		//substitui a variável var pelo polinômio p
		//subs somente para polinômios
		//eval para números ou polinômios
		polynomial subs(const std::string &, const polynomial &) const;
		polynomial eval(const std::string &, const polynomial &) const;

		template<class... Args>
		polynomial eval(const std::string &var, const polynomial &p, Args... args) const {
			polynomial res;
			std::set<monomial, monomial_comp_class>::iterator it;
			for(it = this->_terms.begin(); it != this->_terms.end(); it++)
				res += it->subs(var, p);
			
			return res.ref_eval(args...);
		}
		
		polynomial & ref_eval(const std::string &var, const polynomial &p) {
			polynomial res(*this);
			this->_terms.clear();
			std::set<monomial, monomial_comp_class>::iterator it;
			for(it = res._terms.begin(); it != res._terms.end(); it++)
				*this += it->subs(var, p);
			
			return *this;
		}
		
		template<class... Args>
		polynomial & ref_eval(const std::string &var, const polynomial &p, Args... args) {
			polynomial res(*this);
			this->_terms.clear();
			std::set<monomial, monomial_comp_class>::iterator it;
			for(it = res._terms.begin(); it != res._terms.end(); it++)
				*this += it->subs(var, p);
			
			return this->ref_eval(args...);
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
		
		//termos que multiplicam uma variável com determinado grau
		//ex: para u = (y² + 2y + 2)x² + (y² - 2)x + 3
		//u.polynomial_coefficient(x, 2) = y² + 2y + 2
		//u.polynomial_coefficient(x, 0) = 3
		//u.polynomial_coefficient(y, 0) = 2x² - 2x + 3
		//u.polynomial_coefficient(xy,0) = (2y + 2)x² + (y² - 2)x + 3
		//u.polynomial_coefficient(xy,1) = 0
		//u.polynomial_coefficient(xy,2) = 1
		polynomial polynomial_coefficient(const std::string &, const num_z &) const;
		polynomial polynomial_coefficient(const monomial &, const num_z &) const;
		
		//termos que são divisíveis pela variável, de forma que 
		// u = u.polynomial_coefficient(X) * X + r
		//ex: para u = (y² + 2y + 2)x² + (y² - 2)x + 3
		//u.polynomial_coefficient(x) = (y² + 2y + 2)x + y² - 2
		//u.polynomial_coefficient(y) = (x² + x)y + 2x²
		//u.polynomial_coefficient(xy) = xy + 2x + y
		polynomial polynomial_coefficient(const std::string &) const;
		polynomial polynomial_coefficient(const monomial &) const;
		
		//monômio com maior grau que contém a variável var com grau exatamente deg
		monomial leading_monomial(const std::string &, const num_z &) const;
		monomial leading_monomial(const monomial &, const num_z &) const;
		monomial lm(const std::string &, const num_z &) const;
		monomial lm(const monomial &, const num_z &) const;
		
		//monômio que contém a variável var com maior grau
		monomial leading_monomial(const std::string &) const;
		monomial leading_monomial(const monomial &) const;
		monomial lm(const std::string &) const;
		monomial lm(const monomial &) const;
		
		//coeficiente da variável var com grau exatamente deg
		//ex: para u = (y² + 2y + 2)x² + (y² - 2)x + 3
		//u.lc(x, 2) = (y² + 2y + 2)
		//u.lc(x, 0) = 3
		//u.lc(y, 0) = 2x² - 2x + 3
		polynomial leading_coefficient(const std::string &, const num_z &) const;
		polynomial lc(const std::string &, const num_z &) const;
		
		//coeficiente da variável var com maior grau no polinômio
		//ex: para u = (2y + 2)x² + (y² - 2)x + 3
		//u.lc(x) = 2y + 2
		//u.lc(y) = x
		polynomial leading_coefficient(const std::string &) const;
		polynomial lc(const std::string &) const;
		
		//termo líder que divide o monômio
		//ex: para u = (y² + 2y + 2)x² + (y² - 2)x + 3
		//u.polynomial_coefficient(x) = y² + 2y + 2
		//u.polynomial_coefficient(y) = x
		//u.polynomial_coefficient(xy) = 1
		polynomial leading_coefficient(const monomial &) const;
		polynomial lc(const monomial &) const;
		
		//coeficiente do monômio com determinado grau
		polynomial leading_coefficient(const monomial &, const num_z &) const;
		polynomial lc(const monomial &, const num_z &) const;
		
		//sobre o campo dos números racionais, o conteúdo de um polinômio
		//em relação a uma variável x é o monômio unitário sem a variável x
		//que divide o polinômio
		polynomial content(const std::string &) const;

		//conteúdo do polinômio em relação à variável x ou à primeira variável
		//do termo líder do polinômio
		polynomial content() const;
		
		//polinômio primitivo é um polinômio cujo conteúdo é 1
		//a parte primitiva de um polinômio u é o polinômio primitivo v
		//tal que u = c*v e c é uma unidade normal na variável líder de u
		polynomial primitive_part() const;
		polynomial primitive_part(const std::string &) const;
		
		//algoritmo auxilia o gcd de polinômios com mais de uma variável
		//o pseudo-quociente s e o pseudo-resto r da divisão de p por q são de forma que
		//p*u = s*v + r
		polynomial_tuple pseudo_division(const polynomial &) const;
};

//tupla para armazenar o quociente e resto das divisões de polinômios
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

/*

FUNÇÕES DA CLASSE MONOMIAL QUE PRECISAM DA IMPLEMENTAÇÃO DA CLASSE POLYNOMIAL

*/

//avaliação de monômios por polinômios
template<class... Args>
polynomial monomial::eval(const std::string &var, const polynomial &p, Args... args) const {
	monomial aux_this(*this);
	polynomial res;
	std::map<std::string, num_z>::iterator it;
	
	if(p == polynomial()) return p;
	if((it = aux_this._literals.find(var)) != aux_this._literals.end()){
		num_z exp(it->second);
		aux_this._degree -= exp;
		aux_this._literals.erase(it);
		res = g_pow(p, exp) * aux_this;
	}

	return res.ref_eval(args...);
}

template<class... Args>
polynomial monomial::ref_eval(const std::string &var, const polynomial &p, Args... args) const {
	monomial aux_this(*this);
	polynomial res;
	std::map<std::string, num_z>::iterator it;
	
	if(p == polynomial()) return p;
	if((it = aux_this._literals.find(var)) != aux_this._literals.end()){
		num_z exp(it->second);
		aux_this._degree -= exp;
		aux_this._literals.erase(it);
		res = g_pow(p, exp) * aux_this;
	}

	return res.ref_eval(args...);
}

#endif 
