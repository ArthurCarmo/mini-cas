#ifndef __ZM_OPDIV_
#define __ZM_OPDIV_

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const num_zm<N> &a){
	return *this * a.inverse();
}

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const num_z &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const div_tuple &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const mod_tuple &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const int &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const uint32_t &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const int64_t &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const uint64_t &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<int64_t N>
num_zm<N> num_zm<N>::operator/(const char *a){
	num_zm<N> res(this->_num / a);
	return res;
}


template<int64_t N>
bool num_zm<N>::has_inverse(){
	num_z t(0), r(N), newt(1), newr(this->_num), q, aux;
	r._sign = 0;
	newr._sign = 0;
	
	while(newr != 0){		
		q = r / newr;
		
		aux = newt;
		newt = t - (q * newt);
		t = aux;

		aux = newr;
		newr = r - (q * newr);
		r = aux;
	}
	if(t._sign)
		t += N;
	
	return r > 1;
}

template<int64_t N>
num_zm<N> num_zm<N>::inverse(){
	num_zm<N> res;	
	num_z t(0), r(N), newt(1), newr(this->_num), q, aux;
	r._sign = 0;
	newr._sign = 0;
	
	while(newr != 0){		
		q = r / newr;
		
		aux = newt;
		newt = t - (q * newt);
		t = aux;

		aux = newr;
		newr = r - (q * newr);
		r = aux;
	}
	if(t._sign)
		t += N;
	
	t._sign = N < 0;
	res._num = t;
	if(r > 1) { int k = 0; printf("%d", 1 / k); }

	return res;
}

#endif
