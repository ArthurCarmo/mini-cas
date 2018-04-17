#include "../include/num_z.h"

/*
num_z num_z::operator^(const num_z &);
num_z num_z::operator^(const int &);
num_z num_z::operator^(const uint32_t &);
num_z num_z::operator^(const int64_t &);
num_z num_z::operator^(const uint64_t &);
num_z num_z::pow(const num_z &);
num_z num_z::pow(const int &);
*/

num_z num_z::pow(const uint32_t &a){ //CORRIGIR
	num_z res(*this);
	if(a == 0) res = 1;
	else for(uint32_t i = a; --i;)
			res = res * res;
	return res;
}
/*
num_z num_z::pow(const int64_t &);
num_z num_z::pow(const uint64_t &);
*/
