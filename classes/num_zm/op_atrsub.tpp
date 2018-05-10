#ifndef __ZM_ATRSUB_
#define __ZM_ATRSUB_

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const num_zm<N> &a){
	this->_num -= a._num;
	if(this->_sign ^ a._sign && this->_num != 0)
		 this->_num = num_z(N) + this->_num;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const num_z &a){
	this->_num -= a;
	this->_num = this->_num % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const div_tuple &a){
	this->_num -= a.q;
	this->_num = this->_num % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const mod_tuple &a){
	this->_num -= a.r;
	this->_num = this->_num % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const int64_t &a){
	this->_num -= a;
	this->_num = this->_num % N;
	return *this;
}
template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const uint64_t &a){
	this->_num -= a;
	this->_num = this->_num % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const int &a){
	this->_num -= a;
	this->_num = this->_num % N;
	return *this;
}
template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const uint32_t &a){
	this->_num -= a;
	this->_num = this->_num % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const char *a){
	this->_num -= a;
	this->_num = this->_num % N;
	return *this;
}

#endif
