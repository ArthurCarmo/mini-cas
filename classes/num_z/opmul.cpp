#include "../include/num_z.h"

num_z num_z::operator*(const num_z &a){ //IMPLEMENTAR KARATSUBA
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

