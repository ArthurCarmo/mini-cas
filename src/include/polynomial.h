#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H

#include <iostream>
#include <string>

#include "num_q.h"

#define _POLY_INIT_SIZE_ 1000;

class polynomial{
	friend std::ostream & operator<<(std::ostream &, const polynomial &);
	
	private:
		monomial *_terms;
		uint32_t _n_terms;
		uint32_t _n_vars;
		
	public:
		polynomial();
		polynomial(const monomial[], uint32_t);
		polynomial(const monomial &);
		polynomial(const Number &);
		polynomial(const char []);
};

#endif
