#include "../include/num_z.h"

mod_tuple num_z::operator%(const num_z &a){
	mod_tuple res;
	num_z m(*this), n(a);
	uint32_t size_m;
	uint32_t digits;
	uint64_t q1 = 10;
	if(this->abs_lt(a)){
		res.r = (this->_sign)?(n-m):*this;
		return res;
	}
	if(a == (unsigned int)1){
		res.q = *this;
		return res;
	}
	
	m._sign = 0;
	n._sign = 0;

	size_m = this->_blocks - a._blocks;
	
	res.q._sign = this->_sign ^ a._sign;
	
	/* NORMALIZAR */
	digits = 19*size_m;
	while(m._num[m._blocks-1]/q1){
		q1 *= 10;
		++digits;
	}
	q1 = 10;
	
	while(n._num[n._blocks-1]/q1){
		q1 *= 10;
		--digits;
	}
	
	if(digits ^ 0)
		n.__left_shift(digits);
		
	/* SUBTRAIR */
	while(1){
		if(m.abs_geq(n)){
			++res.q;
			m = m - n;
		}else{
			if(digits-- > 0){
				res.q.__left_shift();
				n.__right_shift();
			}
			else break;
		}
	}
	
	res.r = m;
	return res;
}

mod_tuple num_z::operator%(const div_tuple &a){
	num_z res(*this);
	return res%a.q;
}

mod_tuple num_z::operator%(const mod_tuple &a){
	num_z res(*this);
	return res%a.r;
}

mod_tuple num_z::operator%(const int &a){
	num_z res(*this);
	return res%a;
}

mod_tuple num_z::operator%(const uint32_t &a){
	num_z res(*this);
	return res%a;
}

mod_tuple num_z::operator%(const int64_t &a){
	num_z res(*this);
	return res%a;
}

mod_tuple num_z::operator%(const uint64_t &a){
	num_z res(*this);
	return res%a;
}

mod_tuple num_z::operator%(const char *a){
	num_z res(*this);
	return res%a;
}


