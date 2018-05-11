#include "../include/num_z.h"


num_z & num_z::operator/=(const num_z &a){
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
		return (*this = 0);
	}
	
	//Dividendo -1, 0 ou 1
	if(a == (uint32_t)0) return *this;
	if(a == (uint32_t)1){
		return *this;
	}
	if(a == (int32_t)-1){
		this->_sign = 1 - this->_sign;
		return *this;
	}
	
	//Divisão por número de um dígito
	if(n._blocks == 1){
		*this = *this/(uint32_t)n._num[0];
		this->_sign ^= a._sign;
		return *this;
	}
	
	//Divisão de um número com n+m dígitos por um número com n dígitos;
	if(this->_n_blocks < size_q)
		this->__resize(size_q);
	
	d = _BASE_/(n._num[n._blocks - 1 ] + 1);
	
	m *= d;
	n *= d;

	if(m._blocks == this->_blocks){
		m._num[m._blocks++] = 0;
	}
	
	this->_blocks = size_q;
	for(i = 0; i < size_q; i++)
		this->_num[i] = 0;
		
	n_size = n._blocks - 1;
	for(j = m._blocks - 1; j > n_size; --j){	
		q_guess = (m._num[j] == n._num[n._blocks-1])?((uint64_t)_MAX_DIGIT_BASE_):(((uint64_t)m._num[j]*(uint64_t)_BASE_ + m._num[j-1])/n._num[n._blocks - 1]);
		while(((uint64_t)n._num[n._blocks - 2]*(uint64_t)q_guess) > ((uint64_t)((uint64_t)m._num[j] * (uint64_t)_BASE_ - (uint64_t)n._num[n._blocks - 1]*(uint64_t)q_guess + m._num[j-1])* (uint64_t)_BASE_ + m._num[j-2])) --q_guess;

		//Multipĺicar e subtrair
		parc_n = n * q_guess;
		parc_m._blocks = 1 + n._blocks;
		
		for(i = 0; i <= n._blocks; i++){
			parc_m._num[n._blocks - i] = m._num[j - i];
		}

		if(parc_m._num[parc_m._blocks - 1] == 0) parc_m._num[--parc_m._blocks] = 0;

		while(parc_n > parc_m){
			parc_n = n * --q_guess;
		}
		
		parc_m -= parc_n;
		
		for(i = 0; i <= n._blocks; i++)
			m._num[j-i] = parc_m._num[n._blocks - i];
		
		while(m._num[m._blocks - 1] == 0 && (m._blocks ^ 1)) --m._blocks;
		
		this->_num[j - n_size - 1] = q_guess;
		
	}
	//Formatar resultado
	if(this->_num[this->_blocks - 1] == 0 && (this->_blocks ^ 1) ) --this->_blocks;
	return *this;
}

num_z & num_z::operator/=(const div_tuple &a){
	return *this /= a.q;
}

num_z & num_z::operator/=(const mod_tuple &a){
	return *this /= a.r;
}

num_z & num_z::operator/=(const int64_t &a){
	num_z res(a);
	return *this /= res;
}

num_z & num_z::operator/=(const uint64_t &a){
	num_z res(a);
	return *this /= res;
}

num_z & num_z::operator/=(const int &a){
	num_z res(a);
	return *this /= res;
}

num_z & num_z::operator/=(const uint32_t &a){
	num_z res(a);
	return *this /= res;
}

num_z & num_z::operator/=(const char *a){
	num_z res(a);
	return *this /= res;
}
