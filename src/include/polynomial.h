#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H

#include <iostream>
#include <string>

#include "num_q.h"

#define _POLY_INIT_SIZE_ 1000;

struct monomial{
	std::string _var;
	num_z _expoent;
	num_q _coeficient;
	monomial *_next_var;
};

class polynomial{
	friend std::ostream & operator<<(std::ostream &, const polynomial &);
	
	private:
		monomial *_terms;
		uint32_t _n_terms;
		uint32_t _n_vars;
		
	public:
		polynomial();
		polynomial(const monomial &);
		polynomial(const Number &);
		polynomial(const char []);
};

#endif
