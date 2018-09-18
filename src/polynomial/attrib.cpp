#include "../include/polynomial.h"

polynomial & polynomial::operator=(const polynomial &p){
	this->_terms = p._terms;
	return *this;
}
