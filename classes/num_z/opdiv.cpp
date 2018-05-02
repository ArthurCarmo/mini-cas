#include "../include/num_z.h"

div_tuple num_z::operator/(const num_z &a){ 
	div_tuple res;	
	num_z m(*this), n(a), parc;
	uint32_t j;
	uint32_t m_size;	//Offset dos dígitos para a divisão
	uint32_t size_q;	//Número de dígitos do quociente
	uint32_t offset;
	uint64_t q_guess;	//Chute do quociente
	uint64_t d; 		//Offset para reduzir o erro do chute para o quociente
	
	m._sign = 0;
	n._sign = 0;
	size_q = this->_blocks - a._blocks;

	//Dividendo > divisor
	if(this->abs_lt(a)){
		res.r = (this->_sign ^ a._sign)?(n-m):*this;
		res.r._sign = a._sign;
		return res;
	}
	//Dividendo 0 ou 1
	if(a == (uint32_t)0) return res;
	if(a == (uint32_t)1){
		res.q = *this;
		return res;
	}
	//Divisão por número de um dígito
	if(n._blocks == 1){
		res = *this/n._num[0];
		res.q._sign = this->_sign ^ a._sign;
		if(a._sign)
			res.r -= n;

	}
	
	//Divisão de um número com n+m dígitos por um número com n dígitos;
	if(res.q._n_blocks <= size_q)
		res.q.__resize(size_q + 1);
		
	if(res.r._n_blocks < n._blocks)
		res.r.__resize(n._blocks);
	
	d = _MAX_CONST_64_/(n._num[n._blocks] + 1);
	
	if(d == 1){
		m._num[m._blocks++] = 0;
	}
	m *= d;
	n *= d;
	
	m_size = n._blocks - 1;
	
	for(j = m._blocks - 1; j >= m_size; --j){
		offset = j-m_size -1;
		q_guess = (m._num[j] == n._num[n._blocks-1])?(_BLOCK_SIZE_64_):((m._num[j]*_MAX_CONST_64_ + m._num[j-1])/n._num[n._blocks - 1]);
		while((n._num[n._blocks - 2]*q_guess) > ((m._num[j] * _MAX_CONST_64_ - n._num[n._blocks - 1]*q_guess + m._num[j-1])* _MAX_CONST_64_ + m._num[j-2])) --q_guess;
		parc = n * q_guess;
		if(offset)
			parc.__left_shift((offset) * _DIGITS_PER_BLOCK_);
		if(parc > m) {
			--q_guess;
			parc = n * q_guess;
			if(offset)
				parc.__left_shift(offset * _DIGITS_PER_BLOCK_);
		}
		m -= parc;
		res.q._num[offset] = q_guess;
	}
	
	std::cout << "QUO: " << res.q << "\n\n";
	m.__right_shift(n._blocks * _DIGITS_PER_BLOCK_);
	res.r = m % d;
	std::cout << "MOD: " << res.r << "\n\n";
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
	uint32_t j;
	uint64_t r = 0;
	uint64_t w;
	
	if(this->_blocks >= _INIT_SIZE_)
		res.q.__resize(this->_blocks);
	
	for(j = this->_blocks - 1; j >= 0; --j){
		w = (r * _MAX_CONST_64_ + this->_num[j]);
		res.q._num[j] = w / a;
		r = w % a;
	}
	res.r = r;
	while(res.q._num[res.q._blocks] == 0 && (res.q._blocks ^ 1)) --res.q._blocks;
	
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
