#include "../include/num_z.h"

bool num_z::operator==(const num_z &a) const {
	if(this->_blocks ^ a._blocks || this->_sign ^ a._sign) return false;
	int i = this->_blocks;
	while(i--)
		if(this->_num[i] ^ a._num[i]) return false;
	return true;
}

bool num_z::operator==(const int &a) const {
	if(this->_blocks ^ 1) return false;
	if(this->_sign ^ (a < 0) && this->_num[0] != 0) return false;
	return (a < 0)?this->_num[0] == (uint64_t)-a:this->_num[0] == (uint64_t)a;
}

bool num_z::operator==(const uint32_t &a) const {
	if(this->_blocks ^ 1 || this->_sign & 1) return false;
	return this->_num[0] == a;
}

bool num_z::operator==(const int64_t &a) const {
	if(this->_blocks ^ 1) return false;
	if(this->_sign ^ (a < 0) && this->_num[0] != 0) return false;
	return (a < 0)?this->_num[0] == (uint64_t)-a:this->_num[0] == (uint64_t)a;
}

bool num_z::operator==(const uint64_t &a) const {
	if(this->_blocks > 2 || this->_sign & 1) return false;
	if(this->_blocks == 1) return this->_num[0] == a;
	if(a > _BLOCK_SIZE_64_) return ((this->_num[1] == 1) && (this->_num[0] == a - _BLOCK_SIZE_64_ - 1)); 
	return this->_num[0] == a;
}

bool num_z::operator>(const num_z &a) const {
	if(this->_sign == 0){
		if(a._sign & 1) return true;
		if(this->_blocks > a._blocks) return true;
		else if(a._blocks > this->_blocks) return false;

		int i = this->_blocks;
		while(i--)
			if(this->_num[i] > a._num[i]) return true;
			else if(this->_num[i] < a._num[i]) return false;
		return false;
	}
	if(a._sign == 0) return false;
		if(this->_blocks > a._blocks) return false;
		else if(a._blocks > this->_blocks) return true;

		int i = this->_blocks;
		while(i--)
			if(this->_num[i] < a._num[i]) return true;
			else if(this->_num[i] > a._num[i]) return false;
		return false;
}

bool num_z::operator>(const int &a) const {
	if(this->_sign == 0)
		if(a < 0 || this->_blocks ^ 1) return true;
		else return this->_num[0] > (uint64_t)a;
	else if(a >= 0 || this->_blocks ^ 1) return false;
		else return this->_num[0] < (uint64_t)-a;
}

bool num_z::operator>(const uint32_t &a) const {
	if(this->_sign & 1) return false;
	if(this->_blocks ^ 1) return true;
	return this->_num[0] > a;
}
bool num_z::operator>(const int64_t &a) const{
	if(this->_sign == 0)
		if(a < 0 || this->_blocks ^ 1) return true;
		else return this->_num[0] > (uint64_t)a;
	else if(a >= 0 || this->_blocks ^ 1) return false;
		else return this->_num[0] < (uint64_t)-a;
}

bool num_z::operator>(const uint64_t &a) const {
	if(this->_sign & 1) return false;
	if(this->_blocks > 2) return true;
	if(a > _BLOCK_SIZE_64_)
		if(this->_blocks == 1) return false;
		else if(this->_num[1] > 1) return true; 
		else return this->_num[0] > a - _BLOCK_SIZE_64_ - 1;
	else return this->_num[0] > a;
}

/*bool num_z::operator<(const num_z &) const;
bool num_z::operator<(const int &) const;
bool num_z::operator<(const uint32_t &) const;
bool num_z::operator<(const int64_t &) const;
bool num_z::operator<(const uint64_t &) const;
bool num_z::operator>=(const num_z &) const;
bool num_z::operator>=(const int &) const;
bool num_z::operator>=(const uint32_t &) const;
bool num_z::operator>=(const int64_t &) const;
bool num_z::operator>=(const uint64_t &) const;
bool num_z::operator<=(const num_z &) const;
bool num_z::operator<=(const int &) const;
bool num_z::operator<=(const uint32_t &) const;
bool num_z::operator<=(const int64_t &) const;
bool num_z::operator<=(const uint64_t &) const;
bool num_z::operator!=(const num_z &) const;
*/

bool num_z::operator!=(const int &a) const {
	if(this->_blocks > 1) return true;
	if((a < 0) ^ this->_sign) return true;
	return (uint64_t)a ^ this->_num[0];
}
/*	
bool num_z::operator!=(const uint32_t &) const;
bool num_z::operator!=(const int64_t &) const;
bool num_z::operator!=(const uint64_t &) const;

*/
