#include "../include/num_z.h"

num_z num_z::operator*(const num_z &a){ //IMPLEMENTAR KARATSUBA
	num_z res;
	
	if((a == 0) | (*this == 0)){
		res = 0;
		return res;
	}
	if(a == 1) return *this;
	if(*this == 1) return a;
	
	num_z m(*this), n(a);
	unsigned long long parcelas_t[3*this->_blocks];
	unsigned long cont = 0;
	unsigned long n_parc_t = 0;
	unsigned long n_parc_a = 0;
	unsigned int blocks = this->_blocks + a._blocks + 1;
	res = 0;

	if(blocks == res._n_blocks) res.__resize(blocks + 5);
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
	
	m = 0;
	
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
/*
num_z num_z::operator*(const int &);
num_z num_z::operator*(const unsigned int &);
num_z num_z::operator*(const long long &);
num_z num_z::operator*(const unsigned long long &);
*/
