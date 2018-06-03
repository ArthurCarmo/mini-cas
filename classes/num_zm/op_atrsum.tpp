#ifndef __ZM_ATRSUM_
#define __ZM_ATRSUM_

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const num_zm<N> &a){
	this->_num = this->_num + a._num;
	if(N < 0){
		if(this->_num <= N){
			this->_num -= num_z(N);
		}
	}else if(this->_num >= N){
		this->_num -= num_z(N);
	}
	this->_valid &= a._valid;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const num_z &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const div_tuple &a){
	this->_num += a.q;
	this->_num %= N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const mod_tuple &a){
	this->_num += a.r;
	this->_num %= N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const int64_t &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}
template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const uint64_t &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const int &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}
template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const uint32_t &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const char *a){
	this->_num += a;
	this->_num %= N;
	return *this;
}


#endif
