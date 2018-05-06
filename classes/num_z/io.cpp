#include "../include/num_z.h"


std::ostream& operator << (std::ostream &o, const num_z &a){
	char *output = (char *)malloc(_DIGITS_PER_BLOCK_*a._blocks + a._sign + 1);
	uint64_t n_chars = a._sign;
	uint32_t i = a._blocks-1;

	if(a._sign) sprintf(output, "-");
	n_chars += sprintf(output + n_chars, "%d", a._num[i]);
	while(i--) n_chars += sprintf(output + n_chars, "%09d", a._num[i]);	//TROCAR POR _DIGITS_PER_BLOCK_
	printf("%s", output);
	free(output);
	
	return o;
}

std::istream& operator >> (std::istream &in, num_z &a){
	char c;
	bool sign = 0;
	uint32_t aux;
	c = getchar();
	a = 0;
	while(c == '\n' || c == ' ') 
		c = getchar();

	if(c == '-'){ 
		sign = 1;
		c = getchar();
	}
	
	while(c == '\n' || c == ' ') 
		c = getchar();

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

std::ostream& operator << (std::ostream &o, const div_tuple &a){
	o << a.q;
	return o;
}
	
std::ostream& operator << (std::ostream &o, const mod_tuple &a){
	o << a.r;
	return o;
}	
