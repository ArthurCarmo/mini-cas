#ifndef __MONONOMIAL_H
#define __MONONOMIAL_H

#include "signatures.h"
#include "number.h"
#include "num_z.h"
#include "num_q.h"

#include <iosfwd>
#include <string>
#include <set>
#include <map>

class monomial{
	
	friend class lex;
	friend class glex;
	friend class grevlex;
	friend class monomial_comp_class;
	friend class polynomial;
	
	friend std::ostream & operator<<(std::ostream &, const monomial &);
	friend monomial m_gcd(const monomial &, const monomial &);
	friend monomial subs(monomial &, const std::string &, const monomial &);
	
	friend monomial deg_based_max(const monomial &, const monomial &);
	friend monomial deg_based_min(const monomial &, const monomial &);
	friend polynomial p_gcd(const polynomial &, const polynomial &);
	friend polynomial single_var_gcd(const polynomial &, const polynomial &);
	
	private:
		num_q _coefficient;
		std::map<std::string, num_z> _literals;
		num_z _degree;
		
		//auxiliar para construtor
		void __construct_monomial(const std::string &v, const num_z &exp){
			this->_degree += exp;
			std::map<std::string, num_z>::iterator it;
			if((it = this->_literals.find(v)) != this->_literals.end()){
				it->second += exp;
			}else{
				this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			}
		}

		template<class... Args>
		void __construct_monomial(const std::string &v, const num_z &exp, Args... args){
			this->_degree += exp;
			std::map<std::string, num_z>::iterator it;
			if((it = this->_literals.find(v)) != this->_literals.end()){
				it->second += exp;
			}else{
				this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			}
			this->__construct_monomial(args...);
		}
		
		void __construct_monomial(const char &v, const num_z &exp){
			std::string var(std::string(1, v));
			this->_degree += exp;
			std::map<std::string, num_z>::iterator it;
			if((it = this->_literals.find(var)) != this->_literals.end()){
				it->second += exp;
			}else{
				this->_literals.insert( std::pair<std::string, num_z> (var, exp) );
			}
		}

		template<class... Args>
		void __construct_monomial(const char &v, const num_z &exp, Args... args){
			std::string var(std::string(1, v));
			this->_degree += exp;
			std::map<std::string, num_z>::iterator it;
			if((it = this->_literals.find(var)) != this->_literals.end()){
				it->second += exp;
			}else{
				this->_literals.insert( std::pair<std::string, num_z> (var, exp) );
			}
			this->__construct_monomial(args...);
		}
		
		//auxiliar para derivada
		monomial & __derive_with_respect_to(const std::string &v){
			if(this->_literals.find(v) != this->_literals.end()){
				this->_coefficient *= this->_literals[v];
				this->_literals[v] -= 1;
				--this->_degree;
				if(this->_literals[v] == 0){
					this->_literals.erase(v);
				}
				return *this;
			}
			return (*this = monomial());
		}
		
		template<class... Args>
		monomial & __derive_with_respect_to(const std::string &v, Args... args){
			if(this->_literals.find(v) != this->_literals.end()){
				this->_coefficient *= this->_literals[v];
				this->_literals[v] -= 1;
				--this->_degree;
				if(this->_literals[v] == 0){
					this->_literals.erase(v);
				}
				return this->__derive_with_respect_to(args...);
			}			
			return (*this = monomial());
		}
		
		monomial & __derive_with_respect_to(const char &var){
			std::string v(1, var);
			if(this->_literals.find(v) != this->_literals.end()){
				this->_coefficient *= this->_literals[v];
				this->_literals[v] -= 1;
				--this->_degree;
				if(this->_literals[v] == 0){
					this->_literals.erase(v);
				}
				return *this;
			}
			return (*this = monomial());
		}
		
		template<class... Args>
		monomial & __derive_with_respect_to(const char &var, Args... args){
			std::string v(1, var);
			if(this->_literals.find(v) != this->_literals.end()){
				this->_coefficient *= this->_literals[v];
				this->_literals[v] -= 1;
				--this->_degree;
				if(this->_literals[v] == 0){
					this->_literals.erase(v);
				}
				return this->__derive_with_respect_to(args...);
			}			
			return (*this = monomial());
		}
		
		//soma monômios semelhantes
		monomial & _similar_atrsum(const monomial &m){
			this->_coefficient += m._coefficient;
			if(this->_coefficient == 0){
				this->_literals.clear();
				this->_degree = 0;
			}
			return *this;
		}
		
	public:
		
		//monômio nulo
		monomial(){ }
		
		//construtor de cópia
		monomial(const monomial &m){
			this->_coefficient = m._coefficient;
			this->_degree = m._degree;
			this->_literals = m._literals;
		}
		
		//monômio constante
		monomial(const Number &coef){
			this->_coefficient = coef.q_value();
		}
		
		monomial(int coef){
			this->_coefficient._numerator = coef;
			this->_coefficient._sign = coef < 0;
			this->_coefficient._numerator.make_abs();
		}
		
		//monômio unitário com uma variável
		monomial(const std::string &v, const num_z &exp = 1){
			this->_coefficient = 1;
			this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			this->_degree = 1;
		}
		
		monomial(const char &v, const num_z &exp = 1){
			this->_coefficient = 1;
			this->_literals.insert( std::pair<std::string, num_z> (std::string(1, v), exp) );
			this->_degree = exp;
		}
		
		//monômio com uma variável
		monomial(const Number &coef, const std::string &v, const num_z &exp = 1){
			this->_coefficient = coef.q_value();
			this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			this->_degree = exp;
		}
		
		monomial(const Number &coef, const char &v, const num_z &exp = 1){
			this->_coefficient = coef.q_value();
			this->_literals.insert( std::pair<std::string, num_z> (std::string(1, v), exp) );
			this->_degree = exp;
		}
		
	/* 
		monômio genérico
			
		Uso: (coeficiente, var1, exp1, var2, exp2, ..., varN, expN);	
	*/
		template<class... Args>
		monomial(const Number &coef, Args... args) {
			this->_coefficient = coef.q_value();
			if(this->_coefficient != 0)
				this->__construct_monomial(args...);
		}
		
		//atribuição
		monomial & operator=(const monomial &);
		
		//set contendo as variáveis com expoente não zero no polinômio
		std::set<std::string> variables() const;
		
		//retorna true se monômio possui a variável var com grau maior que zero
		bool has_var(const std::string &) const;
		bool has_var(const char &) const;
		bool has_var(const monomial &) const;
		
		//retorna true se monômio possui a variável var com grau especificado
		bool has_var_deg(const std::string &, const num_z &) const;
		bool has_var_deg(const char &, const num_z &) const;
		bool has_var_deg(const monomial &, const num_z &) const;
		
		//primeira variável do monômio em ordem lexicográfica
		std::string first_lex_var() const;
		
		//expoente da variável var
		num_z exponent(const std::string &) const;
		
		//coeficiente do monômio
		num_q coefficient() const;
		
		//grau do monômio
		num_z degree() const;
		
		//grau da variável var no monômio
		num_z degree(const std::string &) const;
		num_z var_degree(const std::string &) const;
		
		//grau do monômio v no monômio
		num_z degree(const monomial &) const;
		num_z var_degree(const monomial &) const;
		
		//funções de manipulação de sinal
		monomial abs() const;
		monomial operator-() const;
		monomial negative() const;
		
		monomial & make_abs();
		monomial & flip_sign();
		monomial & make_negative();
		
		bool sign() const;
		
		//monômios são similares se possuem as variáveis com os mesmo coeficientes
		bool is_similar(const monomial &) const;
		
		//primeira derivada parcial em relação a x ou à primeira variável por ordem alfabética
		monomial derive() const {
			monomial res(*this);
			if(this->_degree == 0)
				return monomial();
			if(this->_literals.find("x") != this->_literals.end())
				return res.__derive_with_respect_to("x");
			return res.__derive_with_respect_to(this->_literals.begin()->first);
		}
		
		//primeira derivada parcial do monômio iterativamente em relação às variáveis especificadas
		template<class... Args>
		monomial derive(const std::string &v, Args... args) const {
			monomial res(*this);
			return res.__derive_with_respect_to(v, args...);
		}
		
		template<class... Args>
		monomial derive(const char &v, Args... args) const {
			monomial res(*this);
			return res.__derive_with_respect_to(v, args...);
		}

		//avalia x ou primeira variável do monômio
		monomial eval(const num_q &val) const {
			monomial res(*this);
			std::map<std::string, num_z>::const_iterator it;
			
			if(val == 0) return monomial();
			if(this->_degree == 0) return res;
			
			if((it = res._literals.find("x")) != res._literals.end()){
				res._coefficient *= val.pow(it->second);
				res._degree -= it->second;
				res._literals.erase(it);
				return res;
			}
			
			it = res._literals.begin();
			res._coefficient *= val.pow(it->second);
			res._degree -= it->second;
			res._literals.erase(it);
			return res;
		}
	
		//substitui a variável var pelo monômio m
		monomial subs(const std::string &, const monomial &) const;
		
		//substitui a variável var pelo polinômio p
		polynomial subs(const std::string &, const polynomial &) const;
		
		//wrappers para avaliação de variáveis como outros polinômios
		monomial eval(const std::string &, const monomial &) const;
		
		//função de múltiplos argumentos de avaliação por monômios
		template<class... Args>
		monomial eval(const std::string &var, const monomial &m, Args... args) const {
			monomial res(*this);
			std::map<std::string, num_z>::iterator it;
			if(m.is_null()) return m;
			if((it = res._literals.find(var)) != res._literals.end()){
				num_z exp(it->second);
				res._degree -= exp;
				res._literals.erase(it);
				res *= m.pow(exp);
			}
			return res.ref_eval(args...);
		}
		
		//Declarações das funções de avaliação por polinômios
		polynomial eval(const std::string &, const polynomial &) const;
	
		template<class... Args>
		polynomial eval(const std::string &, const polynomial &, Args... args) const;
		
		polynomial ref_eval(const std::string &, const polynomial &) const;
		
		template<class... Args>
		polynomial ref_eval(const std::string &, const polynomial &, Args... args) const;
		
		//avalia o monômio para o valor especificado de uma variável
		monomial eval(const std::string &var, const num_q &val) const {
			monomial res(*this);
			std::map<std::string, num_z>::const_iterator it;
			
			if(val == 0) return monomial();
			if((it = res._literals.find(var)) != res._literals.end()){
				res._coefficient *= val.pow(it->second);
				res._degree -= it->second;
				res._literals.erase(it);
			}
			return res;
		}
		
		//avalia o monômio para os valores especificados de suas variáveis
		template<class... Args>
		monomial eval(const std::string &var, const num_q &val, Args... args) const {
			monomial res(*this);
			std::map<std::string, num_z>::const_iterator it;
			
			if(val == 0) return monomial();
			if((it = res._literals.find(var)) != res._literals.end()){
				res._coefficient *= val.pow(it->second);
				res._degree -= it->second;
				res._literals.erase(it);
			}
			res.ref_eval(args...);
			return res;
		}
		
		//avalia e modifica o valor do monômio
		monomial & ref_eval(const std::string &var, const num_q &val){
			std::map<std::string, num_z>::const_iterator it;	
			if(val == 0) return *this = monomial();
			if((it = this->_literals.find(var)) != this->_literals.end()){
				this->_coefficient *= val.pow(it->second);
				this->_degree -= it->second;
				this->_literals.erase(it);
			}
			return *this;
		}
		
		template<class... Args>
		monomial & ref_eval(const std::string &var, const num_q &val, Args... args){
			std::map<std::string, num_z>::const_iterator it;	
			if(val == 0) return *this = monomial();
			if((it = this->_literals.find(var)) != this->_literals.end()){
				this->_coefficient *= val.pow(it->second);
				this->_degree -= it->second;
				this->_literals.erase(it);
			}
			return this->ref_eval(args...);
		}	
		
		monomial & ref_eval(const std::string &var, const monomial &m){
			std::map<std::string, num_z>::iterator it;
			if(m.is_null()) return *this = monomial();
			if((it = this->_literals.find(var)) != this->_literals.end()){
				num_z exp(it->second);
				this->_degree -= exp;
				this->_literals.erase(it);
				*this *= m.pow(exp);	
			}
			return *this;
		}
		
		template<class... Args>
		monomial & ref_eval(const std::string &var, const monomial &m, Args... args){
			std::map<std::string, num_z>::iterator it;
			if(m.is_null()) return *this = monomial();
			if((it = this->_literals.find(var)) != this->_literals.end()){
				num_z exp(it->second);
				this->_degree -= exp;
				this->_literals.erase(it);
				*this *= m.pow(exp);	
			}
			return this->ref_eval(args...);
		}
		
		//produto de dois monômios é um monômio
		monomial operator*(const monomial &) const;
		monomial & operator*=(const monomial &);
		
		//potência de um monômio por um número inteiro maior ou igual a zero
		monomial pow(const num_z &) const;
		
		//operador sobrecarregado para representar a exponenciação (para facilitar a notação)
		monomial operator^(const num_z &) const;
		monomial & operator^=(const num_z &);
		
		polynomial operator+(const monomial &) const;
		polynomial operator-(const monomial &) const;
		monomial operator/(const monomial &) const;
		
		bool operator==(const monomial &m) const;
		bool operator!=(const monomial &) const;
		
		//um monômio u é divisível pelo monômio v se
		//cada variável de u tem grau maior ou igual àquela variável em v;
		bool is_divisible_by(const monomial &) const;
		
		//um monômio u é divide o monômio v se
		//cada variável de u tem grau menor ou igual àquela variável em v;
		bool divides(const monomial &) const;
		
		bool is_null() const;
		bool multi_variable() const;
		bool single_variable() const;
		
		//remove a variável var do monômio
		monomial remove(const std::string &) const;
		monomial & atr_remove(const std::string &);
		
		monomial remove(const monomial &) const;
		monomial & atr_remove(const monomial &);

		//monômio unitário semelhante
		monomial unit() const;
		
		monomial content() const;
		
		monomial content(std::string &) const;
};

extern monomial operator*(const Number &, const monomial &);
extern monomial operator*(int, const monomial &);
extern polynomial operator+(int, const monomial &);
extern polynomial operator-(int, const monomial &);

#endif
