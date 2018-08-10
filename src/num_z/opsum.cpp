#include "../include/num_z.h"
#include "../include/num_q.h"

num_z num_z::operator+(const num_z &a){
	if(this->_sign ^ a._sign){
		bool st;
		
		st = this->_sign;
		
		this->_sign = a._sign; 
		
		num_z res(*this-a); 
		
		res._sign = !res._sign;
		this->_sign = st;
		return res;
	}
	num_z res(*this);
	return res += a;	
	
}

num_q num_z::operator+(const num_q &a){
	num_q res(a);
	return(res += *this);
}

num_z num_z::operator+(const div_tuple &a){
	return *this+a.q;
}

num_z num_z::operator+(const mod_tuple &a){
	return *this+a.r;
}

num_z num_z::operator+(const int &a){ //EXPANDIR
	num_z res(a);
	return res+=*this;
}

num_z num_z::operator+(const uint32_t &a){ //EXPANDIR
	num_z res(a);
	return res+=*this;
}

num_z num_z::operator+(const int64_t &a){ //EXPANDIR
	num_z res(a);
	return res+=*this;
}
num_z num_z::operator+(const uint64_t &a){ //EXPANDIR
	num_z res(a);
	return res+=*this;
}

num_z num_z::operator+(const char *a){
	num_z res(a);
	return res+=*this;
}
