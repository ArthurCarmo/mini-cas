#include "../include/num_z.h"
#include "../include/num_q.h"

bool num_z::operator==(const num_z &a) const {
	if(this->_blocks ^ a._blocks || this->_sign ^ a._sign) return false;
	int i = this->_blocks;
	while(i--)
		if(this->_num[i] ^ a._num[i]) return false;
	return true;
}

bool num_z::operator==(const div_tuple &a) const {
	return *this == a.q;
}
bool num_z::operator==(const mod_tuple &a) const {
	return *this == a.r;
}

bool num_z::operator==(const int &a) const {
	return *this == num_z(a);
}

bool num_z::operator==(const uint32_t &a) const {
	return *this == num_z(a);
}

bool num_z::operator==(const long long &a) const {
	return *this == num_z(a);
}

bool num_z::operator==(const unsigned long long &a) const {
	return *this == num_z(a);
}

bool num_z::operator==(const char *a) const {
	return *this == num_z(a);
}

bool num_z::operator>(const num_z &a) const {
	if(this->_sign == 0){
		if(a._sign) return true;
		if(this->_blocks > a._blocks) return true;
		else if(a._blocks > this->_blocks) return false;

		uint32_t i = this->_blocks;
		while(i--)
			if(this->_num[i] > a._num[i]) return true;
			else if(this->_num[i] < a._num[i]) return false;
		return false;
	}
	if(a._sign == 0) return false;
	if(this->_blocks > a._blocks) return false;
	else if(a._blocks > this->_blocks) return true;

	uint32_t i = this->_blocks;
	while(i--)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return false;
}

bool num_z::operator>(const div_tuple &a) const{
	return *this > a.q;
}

bool num_z::operator>(const mod_tuple &a) const{
	return *this > a.r;
}

bool num_z::operator>(const int32_t &a) const {
	return *this > num_z(a);
}

bool num_z::operator>(const uint32_t &a) const {
	return *this > num_z(a);
}

bool num_z::operator>(const long long &a) const {
	return *this > num_z(a);
}

bool num_z::operator>(const unsigned long long &a) const {
	return *this > num_z(a);
}

bool num_z::operator>(const char *a) const {
	return *this > num_z(a);
}


bool num_z::operator<(const num_z &a) const {
	if(this->_sign){
		if(a._sign){
			if(this->_blocks > a._blocks) return true;
			if(this->_blocks < a._blocks) return false;
			uint32_t i = this->_blocks;
			while(i--){
				if(this->_num[i] > a._num[i])
					return true;
				else if(this->_num[i] < a._num[i]) break;
			}
			return false;
		}
		return true;
	}
	if(a._sign) return true;
	if(this->_blocks < a._blocks) return true;
	if(this->_blocks > a._blocks) return false;
	uint32_t i = this->_blocks;
	while(i--){
		if(this->_num[i] < a._num[i])
			return true;
		else if(this->_num[i] > a._num[i]) break;
	}
	return false;
}

bool num_z::operator<(const div_tuple &a) const {
	return *this < a.q;
}

bool num_z::operator<(const mod_tuple &a) const {
	return *this < a.r;
}

bool num_z::operator<(const int &a) const {
	return *this < num_z(a);
}

bool num_z::operator<(const uint32_t &a) const {
	return *this < num_z(a);
}

bool num_z::operator<(const long long &a) const {
	return *this < num_z(a);
}

bool num_z::operator<(const unsigned long long &a) const {
	return *this < num_z(a);
}

bool num_z::operator<(const char *a) const {
	return *this < num_z(a);
}

bool num_z::operator>=(const num_z &a) const {
	return !(*this < a);
}

bool num_z::operator>=(const div_tuple &a) const {
	return !(*this < a.q);
}

bool num_z::operator>=(const mod_tuple &a) const {
	return !(*this < a.r);
}

bool num_z::operator>=(const int &a) const {
	return !(*this < a);
}

bool num_z::operator>=(const uint32_t &a) const {
	return !(*this < a);
}

bool num_z::operator>=(const long long &a) const {
	return !(*this < a);
}

bool num_z::operator>=(const unsigned long long &a) const {
	return !(*this < a);
}

bool num_z::operator>=(const char *a) const {
	return !(*this < a);
}


bool num_z::operator<=(const num_z &a) const {
	return !(*this > a);
}

bool num_z::operator<=(const div_tuple &a) const {
	return !(*this > (num_z)a.q);
}

bool num_z::operator<=(const mod_tuple &a) const {
	return !(*this > (num_z)a.r);
}

bool num_z::operator<=(const int &a) const {
	return !(*this > (num_z)a);
}

bool num_z::operator<=(const uint32_t &a) const {
	return !(*this > (num_z)a);
}

bool num_z::operator<=(const long long &a) const {
	return !(*this > (num_z)a);
}

bool num_z::operator<=(const unsigned long long &a) const {
	return !(*this > (num_z)a);
}

bool num_z::operator<=(const char *a) const {
	return !(*this > (num_z)a);
}

bool num_z::operator!=(const num_z &a) const {
	unsigned long long i;
	if(this->_sign ^ a._sign) return true;
	if(this->_blocks ^ a._blocks) return true;
	for(i = 0; i < a._blocks; i++)
		if(this->_num[i] ^ a._num[i])
			return true;
	return false;
}

bool num_z::operator!=(const div_tuple &a) const {
	return *this != a.q;
}
bool num_z::operator!=(const mod_tuple &a) const {
	return *this != a.r;
}

bool num_z::operator!=(const int &a) const {
	num_z res(a);
	return *this != res;
}
	
bool num_z::operator!=(const uint32_t &a) const {
	num_z res(a);
	return *this != res;
}

bool num_z::operator!=(const long long &a) const {
	num_z res(a);
	return *this != res;
}

bool num_z::operator!=(const unsigned long long &a) const {
	num_z res(a);
	return *this != res;
}

bool num_z::operator!=(const char *a) const {
	num_z res(a);
	return *this != res;
}

// ------- NUM_Q ------

bool num_z::operator==(const num_q &a) const {
	return a == *this;
}

bool num_z::operator>(const num_q &a) const {
	return a < *this; 
}

bool num_z::operator<(const num_q &a) const {
	return a > *this;
}

bool num_z::operator>=(const num_q &a) const {
	return a <= *this;
}

bool num_z::operator<=(const num_q &a) const {
	return a >= *this;
}

bool num_z::operator!=(const num_q &a) const {
	return a != *this;
}
