#ifndef __ZM_CONSTRUCTORS_
#define __ZM_CONSTRUCTORS_

template <uint64_t N>
num_zm<N>::num_zm(){

}

template <uint64_t N>
num_zm<N>::num_zm(const num_z &a){
	this->_num = num_z(a)%N;
}

template <uint64_t N>
num_zm<N>::num_zm(const div_tuple &a){
	this->_num = num_z(a.q) % N;
}

template <uint64_t N>
num_zm<N>::num_zm(const mod_tuple &a){
	this->_num = num_z(a.r) % N;
}

template <uint64_t N>
num_zm<N>::num_zm(const uint64_t &a){
	this->_num = a % N;
}

template <uint64_t N>
num_zm<N>::num_zm(const int &a){
	int b = a<0?-a:a;
	this->_num = b % N;
}

template <uint64_t N>
num_zm<N>::num_zm(const uint32_t &a){
	this->_num = a % N;
}

template <uint64_t N>
num_zm<N>::num_zm(const char *a){
	this->_num = (num_z)a % N;
}
	
#endif
