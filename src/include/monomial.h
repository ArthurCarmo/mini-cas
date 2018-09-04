#ifndef __MONONOMIAL_H
#define __MONONOMIAL_H

#include "num_z.h"
#include "num_q.h"

#include <ostream>
#include <string>
#include <cctype>

class monomial{
	friend std::ostream & operator<<(std::ostream &, const monomial &);

	private:
		num_z _exponent[26];
		num_q _coeficient;
		bool _variables[255];
		int _var_counter;
		
		//auxiliar para construtor
		void __construct_monomial(const char &v, const num_z &exp){
			int var = tolower(v);
			this->_var_counter++;
			this->_exponent[var - 'a'] = exp;
			this->_variables[var] = 1;
		}

		template<class... Args>
		void __construct_monomial(const char &v, const num_z &exp, Args... args){
			int var = tolower(v);
			this->_var_counter++;
			this->_exponent[var - 'a'] = exp;
			this->_variables[var] = 1;
			this->__construct_monomial(args...);
		}
		
		
		//auxiliar para derivada
		monomial & __derive_with_respect_to(const char &v){
			int var = tolower(v);
			if(this->_variables[var]){
				this->_coeficient *= this->_exponent[var - 'a'];
				this->_exponent[var - 'a'] -= 1;
				if(this->_exponent[var - 'a'] == 0){
					this->_variables[var] = 0;
					--this->_var_counter;
				}
				return *this;
			}
			return (*this = monomial());
		}
		
		template<class... Args>
		monomial & __derive_with_respect_to(const char &v, Args... args){
			int var = tolower(v);
			if(this->_variables[var]){
				this->_coeficient *= this->_exponent[var - 'a'];
				this->_exponent[var - 'a'] -= 1;
				if(this->_exponent[var - 'a'] == 0){
					this->_variables[var] = 0;
					--this->_var_counter;
				}
				return this->__derive_with_respect_to(args...);
			}			
			return (*this = monomial());
		}
		
	public:
		
		//monômio nulo
		monomial(){
			for(int i = 'a'; i <= 'z'; i++)
				_variables[i] = 0;
			this->_var_counter = 0;
		}
		
		//construtor de cópia
		monomial(const monomial &m){
			this->_coeficient = m._coeficient;
			this->_var_counter = m._var_counter;
			for(int i = 'a'; i <= 'z'; i++){
				this->_variables[i] = m._variables[i];
				this->_exponent[i - 'a'] = m._exponent[i - 'a'];	
			}
		}
		
		//atribuição
		monomial & operator=(const monomial &m){
			this->_coeficient = m._coeficient;
			this->_var_counter = m._var_counter;
			for(int i = 'a'; i <= 'z'; i++){
				this->_variables[i] = m._variables[i];
				this->_exponent[i - 'a'] = m._exponent[i - 'a'];	
			}
			return *this;
		}
		
		//monômio constante
		monomial(const Number &coef){
			for(int i = 'a'; i <= 'z'; i++)
				_variables[i] = 0;
			this->_coeficient = coef.q_value();
			this->_var_counter = 0;
		}
		
		//monômio unitário com uma variável
		monomial(const char &v, const num_z &exp = 1){
			int var = tolower(v);
			for(int i = 'a'; i <= 'z'; i++)
				_variables[i] = 0;
			this->_coeficient = 1;
			this->_exponent[var - 'a'] = exp;
			this->_variables[var] = 1;
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
			for(int i = 'a'; i <= 'z'; i++)
				_variables[i] = 0;
			if(this->_coeficient != 0)
				this->__construct_monomial(args...);
		}
		
		//string contendo as variáveis com expoente não zero no polinômio
		std::string variables(){
			std::string vars = "";
			for(int i = 'a'; i <= 'z'; i++)
				if(this->_variables[i])
					vars += this->_variables[i];
			return vars;
		}
		
		//expoente da variável var
		num_z exponent(const char &var){
			return this->_exponent[tolower(var) - 'a'];
		}
		
		//coeficiente do monômio
		num_q coeficient(){
			return this->_coeficient;
		}
		
		//monômios são similares se possuem as variáveis com os mesmo coeficientes
		bool similar(const monomial &m){
			for(int i = 'a'; i <= 'z'; i++)
				if(this->_exponent[i - 'a'] != m._exponent[i - 'a'])
					return false;
			return true;
		
		} 
		
		//primeira derivada parcial em relação a x ou à primeira variável por ordem alfabética
		monomial derive(){
			monomial res(*this);
			if(this->_variables['x']){
				return res.__derive_with_respect_to('x');
			}else{
				if(this->_var_counter == 0)
					return monomial();
				else
					for(int i = 'a'; i < 'z'; i++)
						if(this->_variables[i]){
							res.__derive_with_respect_to(i);
							return res;
						}
			}
		}
		
		//primeira derivada parcial do monômio iterativamente em relação às variáveis especificadas
		template<class... Args>
		monomial derive(const char &v, Args... args){
			monomial res(*this);
			return res.__derive_with_respect_to(v, args...);
		}
		
		monomial operator*(const monomial &m){
			if(this->_coeficient == 0 or m._coeficient == 0) return monomial();
			monomial res(*this);
			for(int i = 'a'; i <= 'z'; i++){
				if(m._variables[i]){
					if(!res._variables[i]){
						res._variables[i] = 1;
						++res._var_counter;
					}
					res._exponent[i - 'a'] += m._exponent[i - 'a'];
				}
			}
			res._coeficient *= m._coeficient;
			return res;
		}
		
		monomial & operator*=(const monomial &m){
			if(this->_coeficient == 0 or m._coeficient == 0) return *this = monomial();			
			for(int i = 'a'; i <= 'z'; i++){
				if(m._variables[i]){
					if(!this->_variables[i]){
						this->_variables[i] = 1;
						++this->_var_counter;
					}
					this->_exponent[i - 'a'] += m._exponent[i - 'a'];
				}
			}
			this->_coeficient *= m._coeficient;
			return *this;
		}

};

std::ostream & operator<<(std::ostream &o, const monomial &m){
	int used_variables = 0;
	if(m._var_counter == 0)
		o << m._coeficient;
	else if(m._coeficient != 1)
		o << m._coeficient << " * ";
		
	for(char i = 'a'; i <= 'z'; i++){
		if(m._variables[i]){
			o << i;
			++used_variables;
			if(m._exponent[i - 'a'] != 1){
				o << "^" << m._exponent[i - 'a'];
			}
			if(used_variables < m._var_counter)
				o << " * ";
		}
	}
	return o;
}

#endif
