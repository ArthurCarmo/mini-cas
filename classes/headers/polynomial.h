#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H

#include "num_q.h"

#define _POLY_INIT_SIZE_ 1000;

struct tripla{
	char _var;
	num_z _expoent;
	num_z _coeficient;
	tripla *_next_var;
};

class polynomial{
	friend std::ostream & operator<<(std::ostream &, const polynomial &);
	
	private:
		tripla _termo[500];
		bool _vars[255];
		unsigned long long _n_termos;
		unsigned int _n_vars;
		
	public:
		polynomial();
		polynomial(const char []);
};

#endif
