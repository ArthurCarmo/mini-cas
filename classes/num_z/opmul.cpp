#include "../include/num_z.h"

num_z num_z::operator*(const num_z &a){ //IMPLEMENTAR KARATSUBA
	
	if((a == 0) | (*this == 0))return num_z(0);
	if(a == 1) return *this;
	if(*this == 1) return a;
	if(a == -1) return -*this;
	if(*this == -1) { num_z res(-a); return res;}
	int sign = this->_sign ^ a._sign;
	uint32_t i, j, m, n;
	uint64_t k;
	num_z res(uint32_t(0));
	num_z t;
	
	m = a._blocks;
	n = this->_blocks;
	k = 0;
	
	res.__resize(m + n + 1);
	
	for(j = 0; j < m; ++j){
		k = 0;
		for(i = 0; i < n; ++i){
			t = res._long_mul(this->_num[i],a._num[j]) + res._num[i+j] + k;
			res._num[i + j] = t._mod_b();
			k = t._div_b();
		}
		res._num[j+n] = k;
	}
	
	res._sign = sign;
	res._blocks = m + n;
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
