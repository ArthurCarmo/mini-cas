#include "../include/num_z.h"

num_z num_z::abs() const {
	num_z res(*this);
	res._sign = 0;
	return res;
}

num_z num_z::operator-() const {
	num_z res(*this);
	res._sign = 1-res._sign;
	return res;
}

num_z num_z::operator+() const {
	return *this;
}

num_z & num_z::operator++(){
	*this += 1;
	return *this;
}

num_z & num_z::operator--(){
	*this-=1;
	return *this;
}

num_z num_z::operator++(int){
	num_z res(*this);
	*this += 1;
	return res;
}

num_z num_z::operator--(int){
	num_z res(*this);
	*this -= 1;
	return res;
}
