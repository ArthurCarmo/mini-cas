#include "../include/polynomial.h"

polynomial & polynomial::operator=(const polynomial &p){
	this->_terms = p._terms;
	this->_n_terms = p._n_terms;
	return *this;
}
