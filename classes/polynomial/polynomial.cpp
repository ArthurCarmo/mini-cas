#include "../headers/polynomial.h"

#define _COEF 0
#define _VAR 1
#define _EXP 2

#ifndef __GET_VAR
#define __GET_VAR


#endif

#ifndef __GET_NUM_Q
#define __GET_NUM_Q \
	j = i;														\
	if(a[j] == '-') ++j;										\
	if(a[j] >= 'a' && a[j] <= 'z'){								\
		this->_termo[k]._var = a[j];							\
		if(!this->_vars[j]){									\
			this->_vars[j] = 1;									\
			this->_n_vars++;									\
			_next = _EXP;										\
			this->_termo[k]._coeficient = 1 - (2* (j == 1));	\
			_last_char = a[j];									\
			i = j;												\
		}														\
	}else{														\
		while(a[j] >= '0' && a[j] <= '9') ++j;					\
		size = j - i;											\
		j = i;													\
		b = new char[size + 1];									\
		for(int k = 0; k < size; k++)							\
			b[k] = a[j++];										\
		b[size] = '\0';											\
		this->_termo[k].coeficient = b	;						\
		_next = _VAR;											\
		i += size												\
		_last_char = a[i];										\
	}

#endif

polynomial::polynomial(const char a[]){
	uint64_t i = 0;
	uint64_t j = 255;
	uint64_t k = 0;
	char *b;
	char _last_char = a[0];
	uint64_t _size;
	unsigned short _next = _COEF;
	this->_n_termos = 0;
	this->_n_vars = 0;
	while(--j) this->_vars[j] = 0;
	while(_last_char ^ '\0'){
		switch(_next){
			case _COEF: __GET_NUM_Q
						break;
			case _VAR: __GET_VAR
						break;
			case _EXP __GET_EXP
						break;
		}
	}
}

std::ostream & operator<<(std::ostream &o, const polynomial &p){
	
	return o;
}

