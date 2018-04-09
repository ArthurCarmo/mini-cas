#include "num_z.h"

num_z num_z::operator-(const num_z &a){
	num_z res;
	
	if(this->_sign ^ a._sign) {this->_sign = !this->_sign; res = *this + a; res._sign = this->_sign = !this->_sign;}
	else{
		const num_z *maior, *menor;
		unsigned int m_blocks;
		unsigned int l_blocks;
		bool vai_um = 0;
		bool sign = 0;
		bool rec = 0;	
		unsigned int i = 0;
		
		if(this->abs_gt(a)){
			maior = this;
			menor = &a;
			sign = this->_sign;
			m_blocks = this->_blocks;
			l_blocks = a._blocks;
		}else{
			maior = &a;
			menor = this;
			sign = !a._sign;
			m_blocks = a._blocks;
			l_blocks = this->_blocks;
		}
		if(res._n_blocks <= m_blocks) res.__resize(m_blocks+1);
		res._blocks = m_blocks;
		
		for(; i < l_blocks; i++){
			if(vai_um > maior->_num[i]){
				vai_um = 1;
				maior->_num[i] = _BLOCK_SIZE_64_;
			}
			else{
				maior->_num[i] -= vai_um;
				rec = vai_um;
				vai_um = 0;
			}
			if(maior->_num[i] < menor->_num[i]){
				res._num[i] = _MAX_CONST_64_ - menor->_num[i] + maior->_num[i];
				vai_um = 1;
			}else{
				res._num[i] = maior->_num[i] - menor->_num[i];
			}
			maior->_num[i] += rec;
			rec = 0;
		}
		
		for(; i < m_blocks; i++){
			if(vai_um > maior->_num[i]){
				vai_um = 1;
				res._num[i] = _BLOCK_SIZE_64_;
			}
			else{
				res._num[i] = maior->_num[i] - vai_um;
				vai_um = 0;
			}
		}
		
		while(res._num[res._blocks-1] == 0 && res._blocks > 1)
			res._blocks--;
		
		res._sign = res==0?0:sign;
	}
	return res;
}


num_z num_z::operator-(const int &a){ //EXPANDIR
	num_z res;
	res = a;
	return *this-res;
}

num_z num_z::operator-(const unsigned int &a){ //EXPANDIR
	num_z res;
	res = a;
	return *this-res;
}

num_z num_z::operator-(const long long &a){ //EXPANDIR
	num_z res;
	res = a;
	return *this-res;
}

num_z num_z::operator-(const unsigned long long &a){ //EXPANDIR
	num_z res;
	res = a;
	return *this-res;
}
