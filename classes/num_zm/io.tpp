#ifndef __ZM_IO_
#define __ZM_IO_

template <uint64_t U> std::ostream& operator << (std::ostream &o, const num_zm<U> &a){
	o << a._num;
	return o;
}

template <uint64_t U> std::istream& operator >> (std::istream &i, num_zm<U> &a){
	i >> a._num;
	a._num = a._num%U;
	return i;
}

#endif
