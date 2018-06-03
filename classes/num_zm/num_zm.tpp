#ifndef __ZM_CONSTRUCTORS_
#define __ZM_CONSTRUCTORS_

template <int64_t N>
num_zm<N>::num_zm(){
	this->_valid = 1;
}

template <int64_t N>
num_zm<N>::num_zm(const num_zm<N> &a){
	this->_num = a._num;
	this->_valid = a._valid;
}

template <int64_t N>
num_zm<N>::num_zm(const num_z &a){
	this->_num = num_z(a)%N;
	this->_valid = 1;
}

template <int64_t N>
num_zm<N>::num_zm(const div_tuple &a){
	this->_num = num_z(a.q) % N;
	this->_valid = 1;
}

template <int64_t N>
num_zm<N>::num_zm(const mod_tuple &a){
	this->_num = num_z(a.r) % N;
	this->_valid = 1;
}

template <int64_t N>
num_zm<N>::num_zm(const uint64_t &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
}

template <int64_t N>
num_zm<N>::num_zm(const int &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
}

template <int64_t N>
num_zm<N>::num_zm(const uint32_t &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
}

template <int64_t N>
num_zm<N>::num_zm(const char *a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
}
	
#endif
