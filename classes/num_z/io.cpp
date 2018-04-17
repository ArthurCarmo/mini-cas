#include "../include/num_z.h"


std::ostream& operator << (std::ostream &o, const num_z &a){
	int i = a._blocks-1;
	if(a._sign) printf("-");
	printf("%llu", a._num[i]);
	while(i--)printf("%019llu", a._num[i]);
	return o;
}

std::istream& operator >> (std::istream &in, num_z &a){
	char c;
	bool sign = 0;
	uint32_t aux;
	
	c = getchar();
	a = 0;
	if(c == '-'){ 
		sign = 1;
		c = getchar();
	}
	while(c == '.' || c == ',' ||( c >= '0' && c <='9')){
		if(c == '.' || c == ',');
		else{ 
			a.__left_shift();
			aux = c - '0';
			a += aux;
		}
		c = getchar();
	}
	a._sign = sign;
	return in;
}
