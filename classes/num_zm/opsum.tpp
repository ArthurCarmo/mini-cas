#ifndef __ZM_OPSUM_
#define __ZM_OPSUM_

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const num_zm<N> &a){
	return num_zm<N>(this->_num + a._num);
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const num_z &a){
	return num_zm<N>(this->_num + a);
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const div_tuple &a){
	return num_zm<N>(this->_num + a.q);
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const mod_tuple &a){
	return num_zm<N>(this->_num + a.r);
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const int64_t &a){
	return num_zm<N>(this->_num + a);
}
template <int64_t N>
num_zm<N> num_zm<N>::operator+(const uint64_t &a){
	return num_zm<N>(this->_num + a);
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const int &a){
	return num_zm<N>(this->_num + a);
}
template <int64_t N>
num_zm<N> num_zm<N>::operator+(const uint32_t &a){
	return num_zm<N>(this->_num + a);
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const char *a){
	return num_zm<N>(this->_num + a);
}

#endif
