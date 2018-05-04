#include "../include/num_z.h"

div_tuple num_z::operator/(const num_z &a){ 
	div_tuple res;	
	num_z m(*this, this->_blocks + 1), n(a), parc_m(0, this->_blocks + 1), parc_n(0, a._blocks);
	int64_t i, j;
	uint32_t n_size;	//Offset dos dígitos para a divisão
	uint32_t size_q;	//Número de dígitos do quociente
	uint64_t q_guess;	//Chute do quociente
	uint64_t d; 		//Offset para reduzir o erro do chute para o quociente
	
	m._sign = 0;
	n._sign = 0;
	size_q = this->_blocks - a._blocks + 1;
	
	//Dividendo > divisor
	if(this->abs_lt(a)){
		res.r = (this->_sign ^ a._sign)?(n-m):*this;
		res.r._sign = 0;
		return res;
	}
	
	//Dividendo -1, 0 ou 1
	if(a == (uint32_t)0) return res;
	if(a == (uint32_t)1){
		res.q = *this;
		return res;
	}
	if(a == (int32_t)-1){
		res.q = *this;
		return res;
	}
	
	//Divisão por número de um dígito
	if(n._blocks == 1){
		res = *this/(uint32_t)n._num[0];
		res.q._sign = this->_sign ^ a._sign;
		res.r._sign = this->_sign;
		return res;
	}
	
	//Divisão de números cujo quociente é 1
	if(m._blocks == n._blocks && ((uint64_t)m._num[m._blocks-1] < (2ull * (uint64_t)n._num[m._blocks - 1]))){
		m -= n;
		res.q = 1;
		res.q._sign = this->_sign ^ a._sign;
		res.r = m;
		res.r._sign = this->_sign;
		return res;
	}
	
	//Divisão de um número com n+m dígitos por um número com n dígitos;
	if(res.q._n_blocks < size_q)
		res.q.__resize(size_q);
	res.q._blocks = size_q;
	
	if(res.r._n_blocks < n._blocks)
		res.r.__resize(n._blocks);
	
	d = _MAX_CONST_64_/(n._num[n._blocks - 1 ] + 1);
	
	m *= d;
	n *= d;
	
	n_size = n._blocks - 1;
	for(j = m._blocks - 1; j > n_size; --j){	
		q_guess = (m._num[j] == n._num[n._blocks-1])?((uint64_t)_BLOCK_SIZE_64_):(((uint64_t)m._num[j]*(uint64_t)_MAX_CONST_64_ + m._num[j-1])/n._num[n._blocks - 1]);
		while(((uint64_t)n._num[n._blocks - 2]*(uint64_t)q_guess) > ((uint64_t)((uint64_t)m._num[j] * (uint64_t)_MAX_CONST_64_ - (uint64_t)n._num[n._blocks - 1]*(uint64_t)q_guess + m._num[j-1])* (uint64_t)_MAX_CONST_64_ + m._num[j-2])) --q_guess;

		//Multipĺicar e subtrair
		parc_n = n * q_guess;
		parc_m._blocks = parc_n._blocks;
		
		for(i = 0; i < parc_n._blocks; i++){
			parc_m._num[n._blocks - i] = m._num[j - i];
		}
		
		while(parc_n > parc_m){
			parc_n = n * --q_guess;
			parc_m._blocks = parc_n._blocks;
			for(i = 0; i < parc_n._blocks; i++)
				parc_m._num[n._blocks - i] = m._num[j - i];
		}
		
		parc_m -= parc_n;
		
		for(i = 0; i < parc_n._blocks; i++)
			m._num[j-i] = parc_m._num[n._blocks - i];
		
//		while(m._num[m._blocks - 1] == 0 && (m._blocks ^ 1)) --m._blocks;
		
		res.q._num[j - n_size - 1] = q_guess;
		
	}
	//Formatar resultado
	if(res.q._num[res.q._blocks - 1] == 0 && (res.q._blocks ^ 1) ) --res.q._blocks;
	res.r = m / (uint32_t)d;
	res.r._sign = this->_sign;
	return res;
}

div_tuple num_z::operator/(const div_tuple &a){
	num_z res(a.q);
	return *this/res;
}

div_tuple num_z::operator/(const mod_tuple &a){
	num_z res(a.r);
	return *this/res;
}

div_tuple num_z::operator/(const int &a){
	num_z res(a);
	return *this/res;
}

div_tuple num_z::operator/(const uint32_t &a){
	div_tuple res;
	int64_t j;
	uint64_t r = 0;
	uint64_t w;
	
	if(this->_blocks > _INIT_SIZE_)
		res.q.__resize(this->_blocks);
	
	res.q._blocks = this->_blocks;
	
	for(j = res.q._blocks - 1; j >= 0; --j){
		
		w = ((uint64_t)r * (uint64_t)_MAX_CONST_64_ + this->_num[j]);
		res.q._num[j] = w / a;
		r = w % a;
	}
	
	res.r = r;

	while((res.q._num[res.q._blocks - 1] == 0) && (res.q._blocks ^ 1)) --res.q._blocks;
	
	return res;
}

div_tuple num_z::operator/(const int64_t &a){
	num_z res(a);
	return *this/res;
}

div_tuple num_z::operator/(const uint64_t &a){
	num_z res(a);
	return *this/res;
}

div_tuple num_z::operator/(const char *a){
	num_z res(a);
	return *this/res;
}

/*	DIV 1 FUNCIONANDO
	div_tuple res;	
	num_z m(*this), n(a);
	uint32_t size_m;
	uint32_t digits;
	uint64_t q1 = 10;
	
	m._sign = 0;
	n._sign = 0;
	size_m = this->_blocks - a._blocks;
	
	if(this->abs_lt(a)){
		res.r = (this->_sign ^ a._sign)?(n-m):*this;
		res.r._sign = a._sign;
		return res;
	}
	if(a == (uint32_t)0) return res;
	if(a == (uint32_t)1){
		res.q = *this;
		return res;
	}
	
//		 NORMALIZAR 
	digits = _DIGITS_PER_BLOCK_*size_m;
	while(m._num[m._blocks-1]/q1){
		q1 *= 10;
		++digits;
	}
	q1 = 10;
	
	while(n._num[n._blocks-1]/q1){
		q1 *= 10;
		--digits;
	}
	
	if(digits ^ 0)
		n.__left_shift(digits);
		
//		 SUBTRAIR
	while(1){
		if(m.abs_geq(n)){
			++res.q;
			m -= n;
		}else{
			if(digits-- > 0){
				res.q.__left_shift();
				n.__right_shift();
			}
			else break;
		}
	}
	
	res.q._sign = this->_sign ^ a._sign;
	
	if(m != 0){
		res.r = m;
		if(res.q._sign)
			res.r -= n;
		res.r._sign = a._sign;
	}
	
	return res;		
*/
