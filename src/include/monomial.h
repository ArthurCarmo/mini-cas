#ifndef __MONONOMIAL_H
#define __MONONOMIAL_H

#include "signatures.h"
#include "number.h"
#include "num_z.h"
#include "num_q.h"

#include <ostream>
#include <string>
#include <set>
#include <map>

class monomial{
	
	friend class monomial_comp_class;
	friend class polynomial;
	
	friend std::ostream & operator<<(std::ostream &, const monomial &);
	
	private:
		num_q _coeficient;
		std::map<std::string, num_z> _literals;
		int _var_counter;
		
		//auxiliar para construtor
		void __construct_monomial(const std::string &v, const num_z &exp){
			this->_var_counter++;
			this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
		}

		template<class... Args>
		void __construct_monomial(const std::string &v, const num_z &exp, Args... args){
			this->_var_counter++;
			this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			this->__construct_monomial(args...);
		}
		
		void __construct_monomial(const char &v, const num_z &exp){
			this->_var_counter++;
			this->_literals.insert( std::pair<std::string, num_z> (std::string(1, v), exp) );
		}

		template<class... Args>
		void __construct_monomial(const char &v, const num_z &exp, Args... args){
			this->_var_counter++;
			this->_literals.insert( std::pair<std::string, num_z> (std::string(1, v), exp) );
			this->__construct_monomial(args...);
		}
		
		//auxiliar para derivada
		monomial & __derive_with_respect_to(const std::string &v){
			if(this->_literals.find(v) != this->_literals.end()){
				this->_coeficient *= this->_literals[v];
				this->_literals[v] -= 1;
				if(this->_literals[v] == 0){
					this->_literals.erase(v);
					--this->_var_counter;
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
				if(this->_literals[v] == 0){
					this->_literals.erase(v);
					--this->_var_counter;
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
				if(this->_literals[v] == 0){
					this->_literals.erase(v);
					--this->_var_counter;
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
				if(this->_literals[v] == 0){
					this->_literals.erase(v);
					--this->_var_counter;
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
				this->_var_counter = 0;
			}
			return *this;
		}
		
	public:
		
		//monômio nulo
		monomial(){
			this->_var_counter = 0;
		}
		
		//construtor de cópia
		monomial(const monomial &m){
			this->_coeficient = m._coeficient;
			this->_var_counter = m._var_counter;
			this->_literals = m._literals;
		}
		
		//monômio constante
		monomial(const Number &coef){
			this->_coeficient = coef.q_value();
			this->_var_counter = 0;
		}
		
		//monômio unitário com uma variável
		monomial(const std::string &v, const num_z &exp = 1){
			this->_coeficient = 1;
			this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			this->_var_counter = 1;
		}
		
		monomial(const char &v, const num_z &exp = 1){
			this->_coeficient = 1;
			this->_literals.insert( std::pair<std::string, num_z> (std::string(1, v), exp) );
			this->_var_counter = 1;
		}
		
		//monômio com uma variável
		monomial(const Number &coef, const std::string &v, const num_z &exp = 1){
			this->_coeficient = coef.q_value();
			this->_literals.insert( std::pair<std::string, num_z> (v, exp) );
			this->_var_counter = 1;
		}
		
		monomial(const Number &coef, const char &v, const num_z &exp = 1){
			this->_coeficient = coef.q_value();
			this->_literals.insert( std::pair<std::string, num_z> (std::string(1, v), exp) );
			this->_var_counter = 1;
		}
		
	/* 
		monômio genérico
			
		Uso: (coeficiente, var1, exp1, var2, exp2, ..., varN, expN);	
	*/
		template<class... Args>
		monomial(const Number &coef, Args... args) {
			this->_coeficient = coef.q_value();
			this->_var_counter = 0;
			if(this->_coeficient != 0)
				this->__construct_monomial(args...);
		}
		
		//atribuição
		monomial & operator=(const monomial &m){
			this->_coeficient = m._coeficient;
			this->_var_counter = m._var_counter;
			this->_literals = m._literals;
			return *this;
		}
		
		//string contendo as variáveis com expoente não zero no polinômio
		std::set<std::string> variables() const {
			std::set<std::string> vars;
			for(std::map<std::string, num_z>::const_iterator it = this->_literals.begin(); it != this->_literals.end(); ++it)
					vars.insert(it->first);
			return vars;
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
		
		//funções de manipulação de sinal
		monomial abs() const {
			monomial res(*this);
			res._coeficient._sign = 0;
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
			const monomial * maior = this, * menor = &m;
			if(this->_var_counter < m._var_counter){
				maior = &m;
				menor = this;
			}
			std::map<std::string, num_z>::const_iterator it_maior;
			std::map<std::string, num_z>::const_iterator it_menor;
			
			for(it_menor = menor->_literals.begin(); it_menor != menor->_literals.end(); ++it_menor){
				it_maior = maior->_literals.find(it_menor->first);
				if(it_maior == maior->_literals.end() || it_maior->second != it_menor->second)
					return false;
			}
			return true;
		
		} 
		
		//primeira derivada parcial em relação a x ou à primeira variável por ordem alfabética
		monomial derive() const {
			monomial res(*this);
			if(this->_literals.find("x") != this->_literals.end())
				return res.__derive_with_respect_to("x");
			if(this->_var_counter == 0)
				return monomial();
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
			
		
		//produto de dois monômios é um monômio
		monomial operator*(const monomial &m) const {
			if(this->_coeficient == 0 || m._coeficient == 0) return monomial();
			const monomial * maior = this, * menor = &m;
			
			if(this->_var_counter < m._var_counter){
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
					++res._var_counter;
				}else{
					res._literals[it_menor->first] += it_menor->second;
				}
			}
			
			res._coeficient *= menor->_coeficient;
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
					++this->_var_counter;
				}else{
					this->_literals[it_m->first] += it_m->second;
				}
			}	
			
			this->_coeficient *= m._coeficient;
			return *this;
		}
		
		monomial operator-() const {
			monomial res(*this);
			res._coeficient.flip_sign();
			return res;
		}


		bool operator==(const monomial &m){
			return this->_var_counter == m._var_counter && this->_coeficient == m._coeficient && this->_literals == m._literals;
		}
		
		bool operator!=(const monomial &m){
			return this->_var_counter != m._var_counter || this->_coeficient != m._coeficient || this->_literals != m._literals;
		}
		
};
#endif
