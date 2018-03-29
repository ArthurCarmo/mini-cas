#include "bigint.h"

/*
BigInt BigInt::operator^(const BigInt &);
BigInt BigInt::operator^(const int &);
BigInt BigInt::operator^(const unsigned int &);
BigInt BigInt::operator^(const long long &);
BigInt BigInt::operator^(const unsigned long long &);
BigInt BigInt::pow(const BigInt &);
BigInt BigInt::pow(const int &);
*/

BigInt BigInt::pow(const unsigned int &a){ //CORRIGIR
	BigInt res(*this);
	if(a == 0) res = 1;
	else for(unsigned int i = a; --i;)
			res = res * res;
	return res;
}
/*
BigInt BigInt::pow(const long long &);
BigInt BigInt::pow(const unsigned long long &);
*/
