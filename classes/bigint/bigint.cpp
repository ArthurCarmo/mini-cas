#include "bigint.h"

BigInt::BigInt(){
	this->_n_blocks = _INIT_SIZE_;
	this->_num = new unsigned long long[_INIT_SIZE_];
	for(int i = this->_n_blocks; --i;)
		this->_num[i] = 0;
	this->_num[0] = 0;
	this->_blocks = 1;
	this->_sign = 0;
}

BigInt::BigInt(const BigInt &a){
	this->_n_blocks =  a._n_blocks;
	this->_blocks = a._blocks;
	this->_num = new unsigned long long[this->_n_blocks];
	for(unsigned int i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
}

BigInt::~BigInt(){
//	std::cout << "ENTREI: " << this << "\n";
//	std::cout << (this == NULL )<< "\n";
//	std::cout << this->_num[0] << "\n";
	delete[] this->_num;
//	std::cout << "MORRI\n";
}

void BigInt::__left_shift(){
	if(this->_num[this->_blocks - 1] > _MAX_18_DIGIT_ ){ 
		if(this->_blocks == this->_n_blocks) 
			this->__resize(this->_n_blocks+1); 
		this->_num[this->_blocks++] = 0;
	}
	unsigned int i = this->_blocks;
	while(i--){
		this->_num[i] %= _BLOCK_LAST_64_;
		this->_num[i] *= 10;
		this->_num[i] += i==0?0:(_num[i-1] / _BLOCK_LAST_64_);
	}
}
void BigInt::__right_shift(){
	unsigned int i = 0;
	unsigned int j = this->_blocks - 1;
	for(; i < j; i++){
		this->_num[i] /= 10;
		this->_num[i] += (this->_num[i+1] % 10) * _BLOCK_LAST_64_;
	}
	this->_num[i] /= 10;
	if((this->_num[i] == 0) && (this->_blocks ^ 1))
		this->_blocks--;
}

void BigInt::__resize(unsigned int n){
	unsigned long long *aux = new unsigned long long[n];
	unsigned int blocks = this->_blocks;
	
	for(unsigned int i = blocks; --i;)
		 aux[i] = this->_num[i];		
	
	aux[0] = this->_num[0];
	
	while(blocks < n)
		aux[blocks++] = 0;
	
	this->_n_blocks = n;
	delete[] this->_num;
	this->_num = aux;
}

BigInt BigInt::abs() const{
	BigInt res(*this);
	res._sign = 0;
	return res;
}
