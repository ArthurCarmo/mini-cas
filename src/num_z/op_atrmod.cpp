#include "../include/num_z.h"

num_z & num_z::operator%=(const num_z &a){
	mod_tuple res;	
	num_z m(*this, this->_blocks + 1), n(a), parc_m(0, this->_blocks + 1), parc_n(0, a._blocks);
	long long j;
	uint32_t n_size;	//Offset dos dígitos para a divisão
	unsigned long long q_guess;	//Chute do quociente
	unsigned long long d; 		//Offset para reduzir o erro do chute para o quociente
	
	m._sign = 0;
	n._sign = 0;
	
	//Dividendo -1, 0 ou 1
	if(a == (uint32_t)0) { int k = 0; printf("%d", 1 / k); }
	if(a == (uint32_t)1){
		return (*this = 0);
	}
	if(a == (int32_t)-1){
		return (*this = 0);
	}
	
	//Dividendo > divisor
	if(this->abs_lt(a)){
		res.r = (this->_sign ^ a._sign)?(n-m):*this;
		res.r._sign = (res.r==0)?0:a._sign;
		return (*this = res.r);
	}
	
	//Divisão por número de um dígito
	if(n._blocks == 1){
		res = m%(uint32_t)n._num[0];
		res.q._sign = this->_sign ^ a._sign;
		if(res.r != 0){	
			if(res.q._sign)
				res.r -= n;
			res.r._sign = a._sign;
		}
		return (*this = res.r);
	}
	
	//Divisão de um número com n+m dígitos por um número com n dígitos;
	if(res.r._n_blocks < n._blocks)
		res.r.__resize(n._blocks);
	
	d = _BASE_/(n._num[n._blocks - 1 ] + 1);
	
	m *= d;
	n *= d;
	
	if(m._blocks == this->_blocks)
		m._num[m._blocks++] = 0;

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
	}
	res.r = m / (uint32_t)d;
	if(res.r != 0){
		if(res.q._sign){
			res.r -= n;
			--res.q;
			res.r._sign = a._sign;
		}else{
			res.r._sign = a._sign;
		}
	}
	return (*this = res.r);
}

num_z & num_z::operator%=(const div_tuple &a){
	return *this %= a.q;
}

num_z & num_z::operator%=(const mod_tuple &a){
	return *this %= a.r;
}

num_z & num_z::operator%=(const long long &a){
	num_z res(a);
	return *this %= res;
}

num_z & num_z::operator%=(const unsigned long long &a){
	num_z res(a);
	return *this %= res;
}

num_z & num_z::operator%=(const int &a){
	num_z res(a);
	return *this %= res;
}

num_z & num_z::operator%=(const uint32_t &a){
	num_z res(a);
	return *this %= res;
}

num_z & num_z::operator%=(const char *a){
	num_z res(a);
	return *this %= res;
}
