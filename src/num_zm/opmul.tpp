template <int64_t N>
num_zm<N> num_zm<N>::operator*(const num_zm<N> &a){
	num_zm<N> res(this->_num * a._num);
	res._valid = this->_valid & a._valid;
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator*(const num_z &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator*(const div_tuple &a){
	num_zm<N> res(this->_num * a.q);
	res._valid = this->_valid;
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator*(const mod_tuple &a){
	num_zm<N> res(this->_num * a.r);
	res._valid = this->_valid;
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator*(const int &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator*(const uint32_t &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator*(const int64_t &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator*(const uint64_t &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator*(const char *a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}
