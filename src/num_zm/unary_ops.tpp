#ifndef __ZM_UNARY_
#define __ZM_UNARY_

template <int64_t N>
num_z num_zm<N>::raw_value() const {
	return this->_num;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-() const{
	return num_z(N)-this->_num;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+() const{
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator++(){
	this->_num += 1;
	if(N < 0){
		if(this->_num == 1) this->_num = N + 1;
	}else{
		if(this->_num == N) this->_num = 0;
	}
	return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator--(){
	this->_num -= 1;
	if(N < 0){
		if(this->_num == N) this->_num = 0;
	}else{
		if(this->_num == -1) this->_num = N - 1;
	}
	return *this;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator++(int){
	num_zm<N> res(*this);
	this->_num += 1;
	if(N < 0){
		if(this->_num == 1) this->_num = N + 1;
	}else{
		if(this->_num == N) this->_num = 0;
	}
	return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator--(int){
	num_zm<N> res(*this);
	this->_num -= 1;
	if(N < 0){
		if(this->_num == N) this->_num = 0;
	}else{
		if(this->_num == -1) this->_num = N - 1;
	}
	return res;
}

#endif
