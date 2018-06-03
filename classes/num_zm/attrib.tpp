#ifndef __ZM_ATTRIB_
#define __ZM_ATTRIB_

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const num_zm<N> &a){
	this->_num = a._num;
	this->_valid = a._valid;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const num_z &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;	
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const div_tuple &a){
	this->_num = num_z(a.q) % N;
	this->_valid = 1;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const mod_tuple &a){
	this->_num = num_z(a.r) % N;
	this->_valid = 1;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const int64_t &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const uint64_t &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const int &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const uint32_t &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const char *a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

#endif
