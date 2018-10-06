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
	
	private:
		num_q _coeficient;
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
				this->_coeficient *= this->_literals[v];
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
				this->_coeficient *= this->_literals[v];
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
				this->_coeficient *= this->_literals[v];
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
				this->_coeficient *= this->_literals[v];
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
			this->_coeficient += m._coeficient;
			if(this->_coeficient == 0){
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
			this->_coeficient = m._coeficient;
			this->_degree = m._degree;
			this->_literals = m._literals;
		}
		
		//monômio constante
		monomial(const Number &coef){
			this->_coeficient = coef.q_value();
		}
		
		monomial(int coef){
			this->_coeficient._numerator = coef;
			this->_coeficient._sign = coef < 0;
			this->_coeficient._numerator.make_abs();
		}
		
		//monômio unitário com uma variável
		monomial(const std::string &v, const num_z &exp = 1){
			this->_coeficient = 1;
			this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			this->_degree = 1;
		}
		
		monomial(const char &v, const num_z &exp = 1){
			this->_coeficient = 1;
			this->_literals.insert( std::pair<std::string, num_z> (std::string(1, v), exp) );
			this->_degree = exp;
		}
		
		//monômio com uma variável
		monomial(const Number &coef, const std::string &v, const num_z &exp = 1){
			this->_coeficient = coef.q_value();
			this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			this->_degree = exp;
		}
		
		monomial(const Number &coef, const char &v, const num_z &exp = 1){
			this->_coeficient = coef.q_value();
			this->_literals.insert( std::pair<std::string, num_z> (std::string(1, v), exp) );
			this->_degree = exp;
		}
		
	/* 
		monômio genérico
			
		Uso: (coeficiente, var1, exp1, var2, exp2, ..., varN, expN);	
	*/
		template<class... Args>
		monomial(const Number &coef, Args... args) {
			this->_coeficient = coef.q_value();
			if(this->_coeficient != 0)
				this->__construct_monomial(args...);
		}
		
		//atribuição
		monomial & operator=(const monomial &m){
			this->_coeficient = m._coeficient;
			this->_degree = m._degree;
			this->_literals = m._literals;
			return *this;
		}
		
		//set contendo as variáveis com expoente não zero no polinômio
		std::set<std::string> variables() const {
			std::set<std::string> vars;
			for(std::map<std::string, num_z>::const_iterator it = this->_literals.begin(); it != this->_literals.end(); ++it)
					vars.insert(it->first);
			return vars;
		}
		
		//retorna true se monômio possui a variável var com grau maior que zero
		bool has_var(const std::string &var){
			return this->_literals.find(var) != this->_literals.end();
		}
		
		bool has_var(const char &var){
			return this->_literals.find(std::string(1, var)) != this->_literals.end();
		}
		
		//primeira variável do monômio em ordem lexicográfica
		std::string first_lex_var(){
			return this->_literals.begin()->first;
		}
		
		//expoente da variável var
		num_z exponent(const std::string &var) const {
			std::map<std::string, num_z>::const_iterator it = this->_literals.find(var);
			if(it == this->_literals.end())
				return num_z(0);
			return it->second;
		}
		
		//coeficiente do monômio
		num_q coeficient() const {
			return this->_coeficient;
		}
		
		//grau do monômio
		num_z degree() const {
			return this->_degree;
		}
		
		//grau da variável var no monômio
		num_z var_degree(const std::string &var){
			std::map<std::string, num_z>::const_iterator it = this->_literals.find(var);
			if(it != this->_literals.end())
				return it->second;
			return num_z(0);
		}
		
		//funções de manipulação de sinal
		monomial abs() const {
			monomial res(*this);
			res._coeficient._sign = 0;
			return res;
		}
		
		monomial operator-() const {
			monomial res(*this);
			res._coeficient.flip_sign();
			return res;
		}
		
		monomial negative() const { 
			monomial res(*this); 
			res._coeficient._sign = 1;
			return res;
		};
		
		monomial & make_abs(){
			this->_coeficient._sign = 0;
			return *this;
		};
		
		monomial & flip_sign(){
			this->_coeficient._sign = 1 - this->_coeficient._sign;
			return *this;
		};
		
		monomial & make_negative(){
			this->_coeficient._sign = 1;
			return *this;
		};
		
		//monômios são similares se possuem as variáveis com os mesmo coeficientes
		bool is_similar(const monomial &m) const {
			return this->_degree == m._degree && this->_literals == m._literals;
		} 
		
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
				res._coeficient *= val.pow(it->second);
				res._degree -= it->second;
				res._literals.erase(it);
				return res;
			}
			
			it = res._literals.begin();
			res._coeficient *= val.pow(it->second);
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
		polynomial eval(const std::string &, const polynomial &) const;
		
		//avalia o monômio para o valor especificado de uma variável
		monomial eval(const std::string &var, const num_q &val) const {
			monomial res(*this);
			std::map<std::string, num_z>::const_iterator it;
			
			if(val == 0) return monomial();
			if((it = res._literals.find(var)) != res._literals.end()){
				res._coeficient *= val.pow(it->second);
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
				res._coeficient *= val.pow(it->second);
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
				this->_coeficient *= val.pow(it->second);
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
				this->_coeficient *= val.pow(it->second);
				this->_degree -= it->second;
				this->_literals.erase(it);
			}
			return this->ref_eval(args...);
		}	
		
		//produto de dois monômios é um monômio
		monomial operator*(const monomial &m) const {
			if(this->_coeficient == 0 || m._coeficient == 0) return monomial();
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
			
			res._coeficient *= menor->_coeficient;
			res._degree = this->_degree + m._degree;
			return res;
		}
		
		monomial & operator*=(const monomial &m){
			if(this->_coeficient == 0 || m._coeficient == 0) return *this = monomial();			
			
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
			
			this->_coeficient *= m._coeficient;
			this->_degree += m._degree;
			return *this;
		}
		
		//potência de um monômio por um número inteiro maior ou igual a zero
		monomial pow(const num_z &N) const {
			monomial res(*this);
			if(N == 0) return monomial();
			res._coeficient = this->_coeficient.pow(N);
			res._degree *= N;
			for(std::map<std::string, num_z>::iterator it = res._literals.begin(); it != res._literals.end(); ++it)
				it->second *= N;
			
			return res;
		}
		
		//operador sobrecarregado para representar a exponenciação (para facilitar a notação)
		monomial operator^(const num_z &N) const {
			monomial res(*this);
			if(N == 0) return monomial();
			res._coeficient = this->_coeficient.pow(N);
			res._degree *= N;
			for(std::map<std::string, num_z>::iterator it = res._literals.begin(); it != res._literals.end(); ++it)
				it->second *= N;
			
			return res;
		}
		
		monomial & operator^=(const num_z &N){
			if(N == 0) return *this = monomial();
			this->_coeficient = this->_coeficient.pow(N);
			this->_degree *= N;
			for(std::map<std::string, num_z>::iterator it = this->_literals.begin(); it != this->_literals.end(); ++it)
				it->second *= N;
			
			return *this;
		}
		
		polynomial operator+(const monomial &) const;
		polynomial operator-(const monomial &) const;
		monomial operator/(const monomial &) const;
		
		bool operator==(const monomial &m) const {
			return this->_degree == m._degree && this->_coeficient == m._coeficient && this->_literals == m._literals;
		}
		
		bool operator!=(const monomial &m) const {
			return this->_degree != m._degree || this->_coeficient != m._coeficient || this->_literals != m._literals;
		}
		
		bool is_divisible_by(const monomial &m) const {
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
		
		bool divides(const monomial &m) const { 
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
		
		bool is_null() const {
			return this->_coeficient._numerator == 0;
		}
		
};

extern monomial operator*(const Number &, const monomial &);
extern monomial operator*(int, const monomial &);
extern polynomial operator+(int, const monomial &);
extern polynomial operator-(int, const monomial &);

#endif
