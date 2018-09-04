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
		uint32_t _n_vars;
		
	public:
		polynomial();
		polynomial(const monomial &);
		polynomial(const Number &);
};

#endif
