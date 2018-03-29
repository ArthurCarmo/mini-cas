#include "bigint.h"

BigInt BigInt::operator+(const BigInt &a){
	BigInt res;
	if(this->_sign ^ a._sign){
		bool st, sa;
		
		st = this->_sign;
		sa = a._sign;
		
		this->_sign = a._sign; 
		
		res = *this-a; 
		
		res._sign = !res._sign;
		this->_sign = st;
	}
	else{
		const BigInt *maior_d;
		const BigInt *menor_d;
		unsigned int m_blocks;
		unsigned int l_blocks;
		bool vai_um = 0;
		bool a1 = 0, a2 = 0;
		unsigned int i = 0;
		
		if(a._blocks>this->_blocks){
			maior_d = &a;
			m_blocks= a._blocks;
			menor_d = this;
			l_blocks= this->_blocks;
		}else{
			maior_d = this;
			m_blocks= this->_blocks;
			menor_d = &a;
			l_blocks= a._blocks;
		}
		
		if(res._n_blocks < m_blocks) res.__resize(m_blocks+5);
		res._blocks = m_blocks;
		res._sign = this->_sign;
		
	
		for(; i < l_blocks; i++){
			
			if(menor_d->_num[i] == _BLOCK_HALF_64_ && maior_d->_num[i] == _BLOCK_HALF_64_){
				res._num[i] = vai_um;
				vai_um = 1;
			}else{
				a1 = menor_d->_num[i] > _BLOCK_HALF_64_;
				a2 = maior_d->_num[i] > _BLOCK_HALF_64_;

				res._num[i] = vai_um + (maior_d->_num[i] - (a2?_BLOCK_HALF_64_:0)) + (menor_d->_num[i] - (a1?_BLOCK_HALF_64_:0));
				
				vai_um = 0;
				
				if(res._num[i] > _BLOCK_SIZE_64_) {res._num[i] -= _MAX_CONST_64_; vai_um = 1;}
				
				if(a1){
					res._num[i] += _BLOCK_HALF_64_;
					if(res._num[i] > _BLOCK_SIZE_64_) {res._num[i] -= _MAX_CONST_64_; vai_um = 1;}
				}
				if(a2){
					res._num[i] += _BLOCK_HALF_64_;
					if(res._num[i] > _BLOCK_SIZE_64_) {res._num[i] -= _MAX_CONST_64_; vai_um = 1;}
				}
			}
		}
		
		for(; i < m_blocks; i++){
			res._num[i] = maior_d->_num[i] + vai_um;
			vai_um = 0;
			if(res._num[i] > _BLOCK_SIZE_64_){
				vai_um = 1;
				res._num[i] = 0;
			}
		}
		
		if(vai_um){
	 		if(res._blocks == res._n_blocks) res.__resize(res._blocks+1);
	 		res._num[res._blocks++]++;
		}
	}
	return res;
}

BigInt BigInt::operator+(const int &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this+res;
}

BigInt BigInt::operator+(const unsigned int &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this+res;
}

BigInt BigInt::operator+(const long long &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this+res;
}
BigInt BigInt::operator+(const unsigned long long &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this+res;
}
