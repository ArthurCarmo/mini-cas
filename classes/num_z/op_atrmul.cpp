#include "../include/num_z.h"


num_z & num_z::operator*=(const num_z &a){
	if((a == 0) | (*this == 0))return (*this = 0);
	if(a == 1) return *this;
	if(*this == 1) return (*this = a);
	if(a == -1) return (*this = -*this);
	if(*this == -1) { *this = -a; return *this;}
	int sign = this->_sign ^ a._sign;
	uint32_t i, j, m, n;
	uint64_t k;
	uint64_t t;
	num_z res(uint32_t(0));
	
	m = a._blocks;
	n = this->_blocks;
	k = 0;
	
	res.__resize(m + n + 1);
	
	for(j = 0; j < m; ++j){
		k = 0;
		for(i = 0; i < n; ++i){
			t = (uint64_t)this->_num[i] * (uint64_t)a._num[j] + res._num[i+j] + k;
			res._num[i + j] = t % _MAX_CONST_64_;
			k = t / _MAX_CONST_64_;
		}
		res._num[j+n] = k;
	}
	
	res._sign = sign;
	res._blocks = m + n;
	while(res._num[res._blocks - 1] == 0) --res._blocks;
	*this = res;
	return *this;
}

num_z & num_z::operator*=(const div_tuple &a){
	return *this *= a.q;
}

num_z & num_z::operator*=(const mod_tuple &a){
	return *this *= a.r;
}

num_z & num_z::operator*=(const int64_t &a){
	return *this *= (num_z)a;
}

num_z & num_z::operator*=(const uint64_t &a){
	return *this *= (num_z)a;
}

num_z & num_z::operator*=(const int &a){
	return *this *= (num_z)a;
}

num_z & num_z::operator*=(const uint32_t &a){
	return *this *= (num_z)a;
}

num_z & num_z::operator*=(const char *a){
	return *this *= (num_z)a;
}

