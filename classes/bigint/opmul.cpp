#include "bigint.h"

BigInt BigInt::operator*(const BigInt &a){
	BigInt res;
	unsigned int i = 0;
	unsigned int j = 6;
	if(a == 0 | *this == 0){
		res = 0;
		return res;
	}
	
	BigInt m(*this), n(a);
	unsigned long long parcelas_t[3*this->_blocks];
	unsigned long cont = 0;
	unsigned long n_parc_t = 0;
	unsigned long n_parc_a = 0;
	unsigned int blocks = this->_blocks + a._blocks + 1;
	res = 0;

	if(blocks == res._n_blocks) res.__resize(blocks + 5);
	while(m._blocks ^ 1){
		parcelas_t[n_parc_t++] = m._num[0] % _BLOCK_HALF_LAST_;
		for(j = 10; --j;)
			m.__right_shift();
	}
	
	if(m._num[0] ^ 0){
		parcelas_t[n_parc_t++] = m._num[0] % _BLOCK_HALF_LAST_;
		for(j = 10; --j;)
			m.__right_shift();
		
		if(m._num[0] ^ 0){
			parcelas_t[n_parc_t++] = m._num[0] % _BLOCK_HALF_LAST_;
			for(j = 10; --j;)
				m.__right_shift();
			if(m._num[0] ^ 0)
				parcelas_t[n_parc_t++] = m._num[0];
		}
	}
	
	m = 0;
	
	while(n._blocks ^ 1){
		for(cont = 0; cont < n_parc_t; cont++){
			m = n._num[0] % _BLOCK_HALF_LAST_ * parcelas_t[cont];
			if(m != 0){
				for(j = 9*(cont+n_parc_a) + 1; --j;)
					m.__left_shift();
				res += m;
			}
		}
		for(j = 10; --j;)
			n.__right_shift();
		n_parc_a++;
	}
	if(n._num[0] ^ 0){							
		for(cont = 0; cont < n_parc_t; cont++){
		
			m = (n._num[0] % _BLOCK_HALF_LAST_) * parcelas_t[cont];
			if(m != 0){
				for(j = 9*(cont+n_parc_a) + 1; --j;)
					m.__left_shift();
				res += m;
			}
		}
		
		for(j = 10; --j;)
			n.__right_shift();
		n_parc_a++;
		
		if(n._num[0] ^ 0){
			for(cont = 0; cont < n_parc_t; cont++){
				m = n._num[0] % _BLOCK_HALF_LAST_ * parcelas_t[cont];
				if(m != 0){
					for(j = 9*(cont+n_parc_a) + 1; --j;)
						m.__left_shift();
					res += m;
				}
			}
			for(j = 10; --j;)
				n.__right_shift();
			n_parc_a++;
			if(n._num[0] ^ 0){
				for(cont = 0; cont < n_parc_t; cont++){
					m = n._num[0] % _BLOCK_HALF_LAST_ * parcelas_t[cont];
					if(m != 0){
						for(j = 9*(cont+n_parc_a) + 1; --j;)
							m.__left_shift();
						res += m;
					}
				}
				for(j = 10; --j;)
					n.__right_shift();
				n_parc_a++;
			}
		}
	}
	
	while(res._num[res._blocks-1] == 0)--res._blocks;
	
	res._sign = this->_sign ^ a._sign;
	
	return res;
}
/*
BigInt BigInt::operator*(const int &);
BigInt BigInt::operator*(const unsigned int &);
BigInt BigInt::operator*(const long long &);
BigInt BigInt::operator*(const unsigned long long &);
*/
