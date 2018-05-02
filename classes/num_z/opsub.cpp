#include "../include/num_z.h"

num_z num_z::operator-(const num_z &a){
	num_z res;
	
	if(this->_sign ^ a._sign) {this->_sign = !this->_sign; res = *this + a; res._sign = this->_sign = !this->_sign;}
	else{
		num_z maior, menor;
		bool vai_um = 0;
		bool sign = 0;
		uint32_t i = 0;
		
		if(this->abs_gt(a)){
			maior = *this;
			menor = a;
			sign = this->_sign;
		}else{
			maior = a;
			menor = *this;
			sign = !a._sign;
		}
		
		if(res._n_blocks < maior._blocks) res.__resize(maior._blocks);
		if(menor._n_blocks < maior._blocks) menor.__resize(maior._blocks);
		res._blocks = maior._blocks;
		
		for(i = menor._blocks; i < maior._blocks; i++)
			menor._num[i] = 0;
			
		for(i = 0; i < maior._blocks; i++){
			menor._num[i] += vai_um;
			res._num[i] = (maior._num[i] >= menor._num[i])?(maior._num[i] - menor._num[i]):(_MAX_CONST_64_ + maior._num[i] - menor._num[i]);
			vai_um = (maior._num[i] < menor._num[i]);
		}
		
		while(res._num[res._blocks-1] == 0 && (res._blocks ^ 1))
			res._blocks--;
		
		res._sign = res==0?0:sign;
	}
	return res;
}

num_z num_z::operator-(const div_tuple &a){
	return *this-a.q;
}

num_z num_z::operator-(const mod_tuple &a){
	return *this-a.r;
}


num_z num_z::operator-(const int &a){ //EXPANDIR
	num_z res(a);
	return *this-res;
}

num_z num_z::operator-(const uint32_t &a){ //EXPANDIR
	num_z res(a);
	return *this-res;
}

num_z num_z::operator-(const int64_t &a){ //EXPANDIR
	num_z res(a);
	return *this-res;
}

num_z num_z::operator-(const uint64_t &a){ //EXPANDIR
	num_z res(a);
	return *this-res;
}

num_z num_z::operator-(const char *a){
	num_z res(a);
	return *this-res;
}
