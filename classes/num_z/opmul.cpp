#include "../include/num_z.h"

num_z num_z::operator*(const num_z &a){ 
	//Produtos triviais
	if((a == 0) | (*this == 0))return num_z(0);
	if(a == 1) return *this;
	if(*this == 1) return a;
	if(a == -1) return -*this;
	if(*this == -1) { num_z res(-a); return res;}
	
	int sign = this->_sign ^ a._sign;
	uint32_t i, j, m, n;
	uint64_t k;
	uint64_t t;
	num_z res(uint32_t(0));
	
	m = a._blocks;
	n = this->_blocks;
	res._sign = sign;
	res.__resize(m + n);
	res._blocks = m + n;
	
	k = 0;
	
	for(j = 0; j < m; ++j){
		k = 0;
		for(i = 0; i < n; ++i){
			t = ((uint64_t)this->_num[i] * (uint64_t)a._num[j]) + res._num[i+j] + k;
			res._num[i + j] = t % _BASE_;
			k = t / _BASE_;
		}
		res._num[j+n] = k;
	}

	while(res._num[res._blocks - 1] == 0) --res._blocks;
	return res;
}

num_z num_z::operator*(const div_tuple &a){
	return *this * a.q;
}

num_z num_z::operator*(const mod_tuple &a){
	return *this * a.r;
}

num_z num_z::operator*(const int &a){
	num_z res(a);
	return *this*res;
}

num_z num_z::operator*(const uint32_t &a){
	num_z res(a);
	return *this*res;
}

num_z num_z::operator*(const int64_t &a){
	num_z res(a);
	return *this*res;
}

num_z num_z::operator*(const uint64_t &a){
	num_z res(a);
	return *this*res;
}

num_z num_z::operator*(const char *a){
	num_z res(a);
	return *this*res;
}
