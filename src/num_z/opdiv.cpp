#include "../include/num_z.h"
#include "../include/num_q.h"

div_tuple num_z::operator/(const num_z &a){ 
	div_tuple res;	
	num_z m(*this, this->_blocks + 1), n(a), parc_m(0, this->_blocks + 1), parc_n(0, a._blocks);
	int64_t j;
	uint32_t n_size;	//Offset dos dígitos para a divisão
	uint32_t size_q;	//Número de dígitos do quociente
	uint64_t q_guess;	//Chute do quociente
	uint64_t d; 		//Offset para reduzir o erro do chute para o quociente
	
	m._sign = 0;
	n._sign = 0;
	size_q = this->_blocks - a._blocks + 1;
	
	//Dividendo > divisor
	if(this->abs_lt(a)){
		res.r = *this;
		return res;
	}
	
	//Dividendo -1, 0 ou 1
	if(a == (uint32_t)0) { int k = 0; printf("%d", 1 / k); }
	if(a == (uint32_t)1){
		res.q = *this;
		return res;
	}
	if(a == (int32_t)-1){
		res.q = -*this;
		return res;
	}
	
	//Divisão por número de um dígito
	if(n._blocks == 1){
		res = *this/(uint32_t)n._num[0];
		res.q._sign = this->_sign ^ a._sign;
		res.r._sign = (res.r == 0)?0:this->_sign;
		return res;
	}
	
	//Divisão de um número com n+m dígitos por um número com n dígitos;
	if(res.q._n_blocks < size_q)
		res.q.__resize(size_q);
	res.q._blocks = size_q;
	
	if(res.r._n_blocks < n._blocks)
		res.r.__resize(n._blocks);
	
	d = _BASE_/(n._num[n._blocks - 1 ] + 1);
	
	m *= d;
	n *= d;

	if(m._blocks == this->_blocks){
		m._num[m._blocks++] = 0;
		
	}

	n_size = n._blocks - 1;
	for(j = m._blocks - 1; j > n_size; --j){	

		q_guess = __guess_quotient(n._num[n._blocks - 1], m._num[j], m._num[j - 1]);

		while(__overstep_quotient(q_guess, n._num[n._blocks - 2], n._num[n._blocks - 1], m._num[j], m._num[j-1], m._num[j-2])) 
			--q_guess;

		//Multipĺicar e subtrair
		parc_n = n * q_guess;
		parc_m._blocks = 1 + n._blocks;
				
		std::copy(m._num + j - n._blocks, m._num + j + 1, parc_m._num);

		if(parc_m._num[parc_m._blocks - 1] == 0) parc_m._num[--parc_m._blocks] = 0;

		while(parc_n > parc_m){
			parc_n = n * --q_guess;
		}
		
		parc_m -= parc_n;
			
		std::copy(parc_m._num, parc_m._num + n._blocks + 1, m._num + j - n._blocks);
		
		while(m._num[m._blocks - 1] == 0 && (m._blocks ^ 1)) --m._blocks;
		
		res.q._num[j - n_size - 1] = q_guess;
		
	}
	//Formatar resultado
	if(res.q._num[res.q._blocks - 1] == 0 && (res.q._blocks ^ 1) ) --res.q._blocks;
	res.r = m / (uint32_t)d;
	res.r._sign = (res.r == 0)?0:this->_sign;
	return res;
}

num_q num_z::operator/(const num_q &a){
	num_q res(a.inverse());
	return res * *this;
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
	
	if(a == 0){
		return res;
	}
	
	if(this->_blocks > _INIT_SIZE_)
		res.q.__resize(this->_blocks);
	
	res.q._blocks = this->_blocks;
	
	for(j = res.q._blocks - 1; j >= 0; --j){
		
		w = ((uint64_t)r * (uint64_t)_BASE_ + this->_num[j]);
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
