/*
 * Overload of the subtraction operator for the integer numbers
 *
 * Integer subtraction algorithm from Donald Knuth's
 * The Art of Computer Programming, vol. 2: Seminumerical Algorithms
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */


#include "../include/num_z.h"
#include "../include/num_q.h"

num_z num_z::operator-(const num_z &a) const {
	num_z res;
	
	if(this->_sign ^ a._sign) { res = *this; res.flip_sign(); res += a; res._sign = !res._sign;}
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
		res._blocks = maior._blocks;
			
		for(i = 0; i < menor._blocks; i++){
			menor._num[i] += vai_um;
			res._num[i] = (maior._num[i] >= menor._num[i])?(maior._num[i] - menor._num[i]):(_BASE_ + maior._num[i] - menor._num[i]);
			vai_um = (maior._num[i] < menor._num[i]);
		}
		
		for( ; i < maior._blocks; i++){
			if(!vai_um) break;
			res._num[i] = (maior._num[i] != 0)?(maior._num[i] - 1):(_MAX_DIGIT_BASE_);
			vai_um = maior._num[i] == 0;
		}
		
		for( ; i < maior._blocks; i++){
			res._num[i] = maior._num[i];
		}
		
		while(res._num[res._blocks-1] == 0 && (res._blocks ^ 1))
			res._blocks--;
		
		res._sign = res==0?0:sign;
	}
	return res;
}

num_q num_z::operator-(const num_q &a) const {
	num_q res(-a);
	return res += *this;
}

num_z num_z::operator-(const div_tuple &a) const {
	return *this-a.q;
}

num_z num_z::operator-(const mod_tuple &a) const {
	return *this-a.r;
}


num_z num_z::operator-(const int &a) const {
	num_z res(a);
	return *this-res;
}

num_z num_z::operator-(const uint32_t &a) const {
	num_z res(a);
	return *this-res;
}

num_z num_z::operator-(const long long &a) const {
	num_z res(a);
	return *this-res;
}

num_z num_z::operator-(const unsigned long long &a) const {
	num_z res(a);
	return *this-res;
}

num_z num_z::operator-(const char *a) const {
	num_z res(a);
	return *this-res;
}
