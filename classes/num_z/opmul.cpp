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

/* MUL FUNCIONANDO LENTA
	num_z res;
	
	if((a == 0) | (*this == 0)){
		res = 0;
		return res;
	}
	if(a == 1) return *this;
	if(*this == 1) return a;
	
	uint64_t parcelas_t[3*this->_blocks];
	uint64_t cont = 0;
	uint64_t n_parc_t = 0;
	uint64_t n_parc_a = 0;
	uint32_t blocks = this->_blocks + a._blocks;
	num_z m(*this, blocks), n(a);
	
	if(blocks == res._n_blocks) res.__resize(blocks + 1);
	while(m._blocks ^ 1){
		parcelas_t[n_parc_t++] = m._num[0] % _BLOCK_HALF_LAST_;
			m.__right_shift(9);
	}
	
	if(m._num[0] ^ 0){
		parcelas_t[n_parc_t++] = m._num[0] % _BLOCK_HALF_LAST_;
		m.__right_shift(9);
		
		if(m._num[0] ^ 0){
			parcelas_t[n_parc_t++] = m._num[0] % _BLOCK_HALF_LAST_;
			m.__right_shift(9);
			if(m._num[0] ^ 0)
				parcelas_t[n_parc_t++] = m._num[0];
		}
	}
	
	while(n._blocks ^ 1){
		for(cont = 0; cont < n_parc_t; cont++){
			m = n._num[0] % _BLOCK_HALF_LAST_ * parcelas_t[cont];
			if(m != 0){
				m.__left_shift(9*(cont+n_parc_a));
				res += m;
			}
		}
		n.__right_shift(9);
		n_parc_a++;
	}
	if(n._num[0] ^ 0){							
		for(cont = 0; cont < n_parc_t; cont++){
		
			m = (n._num[0] % _BLOCK_HALF_LAST_) * parcelas_t[cont];
			if(m != 0){
				m.__left_shift(9*(cont+n_parc_a));
				res += m;
			}
		}
		n.__right_shift(9);
		n_parc_a++;
		
		if(n._num[0] ^ 0){
			for(cont = 0; cont < n_parc_t; cont++){
				m = n._num[0] % _BLOCK_HALF_LAST_ * parcelas_t[cont];
				if(m != 0){
					m.__left_shift(9*(cont+n_parc_a));
					res += m;
				}
			}
			n.__right_shift(9);
			n_parc_a++;
			if(n._num[0] ^ 0){
				for(cont = 0; cont < n_parc_t; cont++){
					m = n._num[0] % _BLOCK_HALF_LAST_ * parcelas_t[cont];
					if(m != 0){
						m.__left_shift(9*(cont+n_parc_a));
						res += m;
					}
				}
				n.__right_shift(9);
				n_parc_a++;
			}
		}
	}
	
	while(res._num[res._blocks-1] == 0)--res._blocks;
	
	res._sign = this->_sign ^ a._sign;
	
	return res;


*/
