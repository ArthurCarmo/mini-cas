#include "../include/num_z.h"

/*
num_z num_z::operator^(const num_z &);
num_z num_z::operator^(const int &);
num_z num_z::operator^(const unsigned int &);
num_z num_z::operator^(const long long &);
num_z num_z::operator^(const unsigned long long &);
num_z num_z::pow(const num_z &);
num_z num_z::pow(const int &);
*/

num_z num_z::pow(const unsigned int &a){ //CORRIGIR
	num_z res(*this);
	if(a == 0) res = 1;
	else for(unsigned int i = a; --i;)
			res = res * res;
	return res;
}
/*
num_z num_z::pow(const long long &);
num_z num_z::pow(const unsigned long long &);
*/
