#ifndef __ZM_ATTRIB_
#define __ZM_ATTRIB_

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const num_zm<N> &a){
	this->_num = a._num;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const num_z &a){
	this->_num = num_z(a) % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const div_tuple &a){
	this->_num = num_z(a.q) % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const mod_tuple &a){
	this->_num = num_z(a.r) % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const int64_t &a){
	this->_num = num_z(a) % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const uint64_t &a){
	this->_num = num_z(a) % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const int &a){
	this->_num = num_z(a) % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const uint32_t &a){
	this->_num = num_z(a) % N;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const char *a){
	this->_num = num_z(a) % N;
	return *this;
}

#endif
