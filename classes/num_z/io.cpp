#include "../include/num_z.h"


std::ostream& operator << (std::ostream &o, const num_z &a){
	if(a._base_repr == DECIMAL){
		char *output = (char *)malloc(_DIGITS_PER_BLOCK_*a._blocks + a._sign + 1);
		uint64_t n_chars = a._sign;
		uint32_t i = a._blocks-1;

		if(a._sign) sprintf(output, "-");
		n_chars += sprintf(output + n_chars, "%d", a._num[i]);
		while(i--) n_chars += sprintf(output + n_chars, "%09d", a._num[i]);	//TROCAR POR _DIGITS_PER_BLOCK_
		printf("%s", output);
		free(output);
	}else if(a._base_repr == HEX){
		hex_f(a);
	}else{
		bin_f(a);
	}
	return o;
}

std::istream& operator >> (std::istream &in, num_z &a){
	char c;
	bool sign = 0;
	uint32_t aux;
	c = getchar();
	a = 0;
	a._base_repr = DECIMAL;
	while(c == '\n' || c == ' ') 
		c = getchar();

	if(c == '-'){ 
		sign = 1;
		c = getchar();
	}
	
	while(c == '\n' || c == ' ') 
		c = getchar();
		
	if(c == '0'){
		c = getchar();
		if(c == 'x')
			a._base_repr = HEX;
		else if(c == 'b')
			a._base_repr = BIN;
		c = getchar();
	}
	while(c == '.' || c == ',' ||( c >= '0' && c <='9') || (a._base_repr == HEX && (c >= 'a' && c <= 'f'))){
		if(c == '.' || c == ',');
		else{ 
			if(a._base_repr == DECIMAL){
				a.__left_shift();
				aux = c - '0';
			}else if(a._base_repr == HEX){
				a *= 16;
				if(c >= 'a' && c <= 'f')
					aux = 10 + (c - 'a');
				else
					aux = c - '0';
			}else{
				a *= 2;
				aux = c - '0';
			}
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
