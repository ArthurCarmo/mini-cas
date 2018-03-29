#include "bigint.h"


std::ostream& operator << (std::ostream &o, const BigInt &a){
	int i = a._blocks-1;
	if(a._sign) o << "-";
	o << a._num[i];
	while(i--)o << std::setfill('0') << std::setw(19) << a._num[i];
	return o;
}

std::istream& operator >> (std::istream &in, BigInt &a){
	char c;
	c = in.get();
	a = 0;
	bool sign = 0;
	if(c == '-'){ 
		sign = 1;
		c = in.get();
	}
	while(c != '\n' && c != ' ' && c != -1 && (c == '.' || c == ',' ||( c >= '0' && c <='9'))){
		if(c == '.' || c == ',');
		else{ 
			a.__left_shift();
			unsigned long long aux = c - '0';
			a += aux;
		}
		c = in.get();
	}
	a._sign = sign;
	return in;
}
