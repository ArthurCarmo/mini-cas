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
		this->_blocks++;
	}
	unsigned int i = this->_blocks;
	while(i--){
		this->_num[i] %= _BLOCK_LAST_64_;
		this->_num[i] *= 10;
		this->_num[i] += i==0?0:(_num[i-1] / _BLOCK_LAST_64_);
	}
}
//void BigInt::__right_shift();

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

//----------------- OPERATORS ------------------------


//--------------ATTRIBUTION--------------------------------

BigInt & BigInt::operator=(const BigInt &a){
	if(this->_n_blocks < a._blocks)
		this->__resize(a._blocks);
	this->_blocks = a._blocks;
	for(unsigned int i = this->_blocks; --i;)
		this->_num[i] = a._num[i];
	this->_num[0] = a._num[0];
	this->_sign = a._sign;
	return *this;
}

BigInt & BigInt::operator=(const int &a){
	this->_sign = 0;
	this->_blocks = 1;
		
	if(a < 0){
		this->_sign = 1;
		this->_num[0] = -a;
	}else{
		this->_num[0] = a;
	}
	return *this;
}

BigInt & BigInt::operator=(const unsigned int &a){
	this->_sign = 0;
	this->_blocks = 1;
	this->_num[0] = a;
	return *this;
}

BigInt & BigInt::operator=(const long long &b){
	long long a = b;
	this->_sign = 0;
	if(a < 0){
		this->_sign = 1;
		a *= -1;
	}
	if(a <= _BLOCK_SIZE_64_){
		this->_blocks = 1;
		this->_num[0] = a;
	}else{
		this->_blocks = 2;
		this->_num[1] = 1;
		this->_num[0] = a - _BLOCK_SIZE_64_ - 1;
	}
	return *this;
}

BigInt & BigInt::operator=(const unsigned long long &a){
	this->_sign = 0;

	if(a <= _BLOCK_SIZE_64_){
		this->_blocks = 1;
		this->_num[0] = a;
	}else{
		this->_blocks = 2;
		this->_num[1] = 1;
		this->_num[0] = a - _BLOCK_SIZE_64_ - 1;
	}
	return *this;
}

//----------------ABS_BOOL------------------------------------------

bool BigInt::abs_eq(const BigInt &a){
	if(this->_blocks ^ a._blocks) return false;
	
	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] ^ a._num[i]) return false;
	return this->_num[0] == a._num[0]; 
}

bool BigInt::abs_neq(const BigInt &a){
	if(this->_blocks ^ a._blocks) return true;
	
	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] ^ a._num[i]) return true;
	return this->_num[0] != a._num[0]; 
}

bool BigInt::abs_geq(const BigInt &a){
	if(this->_blocks > a._blocks) return true;
	else if(a._blocks > this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] > a._num[i]) return true;
		else if(this->_num[i] < a._num[i]) return false;
	return this->_num[0] >= a._num[0];
}

bool BigInt::abs_leq(const BigInt &a){
	if(this->_blocks < a._blocks) return true;
	else if(a._blocks < this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return this->_num[0] <= a._num[0];
}

bool BigInt::abs_gt(const BigInt &a){
	if(this->_blocks > a._blocks) return true;
	else if(a._blocks > this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] > a._num[i]) return true;
		else if(this->_num[i] < a._num[i]) return false;
	return this->_num[0] > a._num[0];
}

bool BigInt::abs_lt(const BigInt &a){
	if(this->_blocks < a._blocks) return true;
	else if(a._blocks < this->_blocks) return false;

	for(unsigned int i = this->_blocks; --i;)
		if(this->_num[i] < a._num[i]) return true;
		else if(this->_num[i] > a._num[i]) return false;
	return this->_num[0] < a._num[0];
}

//--------------ARITHMETIC------------------------------------------

BigInt BigInt::operator+(const BigInt &a){
	BigInt res;
	if(this->_sign ^ a._sign){
		bool st, sa;
		
		st = this->_sign;
		sa = a._sign;
		
		this->_sign = a._sign; 
		
		res = *this-a; 
		
		res._sign = !res._sign;
		this->_sign = st;
	}
	else{
		const BigInt *maior_d;
		const BigInt *menor_d;
		unsigned int m_blocks;
		unsigned int l_blocks;
		bool adjust = 0;
		bool vai_um = 0;
		bool a1 = 0, a2 = 0;
		unsigned int i = 0;
		
		if(a._blocks>this->_blocks){
			maior_d = &a;
			m_blocks= a._blocks;
			menor_d = this;
			l_blocks= this->_blocks;
		}else{
			maior_d = this;
			m_blocks= this->_blocks;
			menor_d = &a;
			l_blocks= a._blocks;
		}
		
		res._blocks = m_blocks;
		res._sign = this->_sign;
		if(res._n_blocks < m_blocks) res.__resize(m_blocks+5);
		
	
		for(; i < l_blocks; i++){
			adjust = 0;
		
			maior_d->_num[i] += vai_um;
			vai_um = 0;
			
			if(menor_d->_num[i] == _BLOCK_HALF_64_ && maior_d->_num[i] == _BLOCK_HALF_64_){
				res._num[i] = vai_um;
				vai_um = 1;
			}else{
				if(menor_d->_num[i] > _BLOCK_HALF_64_){
					adjust = !adjust;
					menor_d->_num[i] -= _BLOCK_HALF_64_;
					a1 = 1;
				}
		
				if(maior_d->_num[i] > _BLOCK_HALF_64_){
					vai_um = adjust;
					adjust = !adjust;
					maior_d->_num[i] -= _BLOCK_HALF_64_;
					a2 = 1;
				}
				res._num[i] = maior_d->_num[i] + menor_d->_num[i] + (adjust?_BLOCK_HALF_64_:0);
				if(res._num[i] > _BLOCK_SIZE_64_) {res._num[i] -= _MAX_CONST_64_; vai_um = 1;}
			}
			if(a1){
				menor_d->_num[i] += _BLOCK_HALF_64_;
				a1 = 0;
			}
			if(a2){
				maior_d->_num[i] += _BLOCK_HALF_64_ -1;
				a2 = 0;
			}
		}
		
		for(; i < m_blocks; i++){
			res._num[i] = maior_d->_num[i] + vai_um;
			vai_um = 0;
			if(res._num[i] > _BLOCK_SIZE_64_){
				vai_um = 1;
				res._num[i] = 0;
			}
		}
		
		if(maior_d->_num[0] >= _BLOCK_HALF_64_) maior_d->_num[0]++;
		if(vai_um){
	 		if(res._blocks == res._n_blocks) res.__resize(res._blocks+1);
	 		res._num[res._blocks++]++;
		}
	}
	return res;
}

BigInt BigInt::operator+(const int &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this+res;
}

BigInt BigInt::operator+(const unsigned int &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this+res;
}

BigInt BigInt::operator+(const long long &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this+res;
}
BigInt BigInt::operator+(const unsigned long long &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this+res;
}

BigInt BigInt::operator-(const BigInt &a){
	BigInt res;
	
	if(this->_sign ^ a._sign) {this->_sign = !this->_sign; res = *this + a; res._sign = this->_sign = !this->_sign;}
	else{
		const BigInt *maior, *menor;
		unsigned int m_blocks;
		unsigned int l_blocks;
		bool vai_um = 0;
		bool sign = 0;
		bool rec = 0;	
		unsigned int i = 0;
		
		if(this->abs_gt(a)){
			maior = this;
			menor = &a;
			sign = this->_sign;
			m_blocks = this->_blocks;
			l_blocks = a._blocks;
		}else{
			maior = &a;
			menor = this;
			sign = !a._sign;
			m_blocks = a._blocks;
			l_blocks = this->_blocks;
		}
		res._blocks = m_blocks;
	
		if(res._n_blocks < m_blocks) res.__resize(m_blocks);
		
		for(; i < l_blocks; i++){
			if(vai_um > maior->_num[i]){
				vai_um = 1;
				maior->_num[i] = _BLOCK_SIZE_64_;
			}
			else{
				maior->_num[i] -= vai_um;
				rec = vai_um;
				vai_um = 0;
			}
			if(maior->_num[i] < menor->_num[i]){
				res._num[i] = _MAX_CONST_64_ - menor->_num[i] + maior->_num[i];
				vai_um = 1;
			}else{
				res._num[i] = maior->_num[i] - menor->_num[i];
			}
			maior->_num[i] += rec;
			rec = 0;
		}
		
		for(; i < m_blocks; i++){
			if(vai_um > maior->_num[i]){
				vai_um = 1;
				res._num[i] = _BLOCK_SIZE_64_;
			}
			else{
				res._num[i] = maior->_num[i] - vai_um;
				vai_um = 0;
			}
		}
		
		while(res._num[res._blocks-1] == 0 && res._blocks > 1)
			res._blocks--;
		
		res._sign = res==0?0:sign;
	}
	return res;
}


BigInt BigInt::operator-(const int &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this-res;
}

BigInt BigInt::operator-(const unsigned int &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this-res;
}

BigInt BigInt::operator-(const long long &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this-res;
}

BigInt BigInt::operator-(const unsigned long long &a){ //EXPANDIR
	BigInt res;
	res = a;
	return *this-res;
}

BigInt BigInt::operator*(const BigInt &a){

}
/*
BigInt BigInt::operator*(const int &);
BigInt BigInt::operator*(const unsigned int &);
BigInt BigInt::operator*(const long long &);
BigInt BigInt::operator*(const unsigned long long &);
BigInt BigInt::operator/(const BigInt &);
BigInt BigInt::operator/(const int &);
BigInt BigInt::operator/(const unsigned int &);
BigInt BigInt::operator/(const long long &);
BigInt BigInt::operator/(const unsigned long long &);
BigInt BigInt::operator%(const BigInt &);
BigInt BigInt::operator%(const int &);
BigInt BigInt::operator%(const unsigned int &);
BigInt BigInt::operator%(const long long &);
BigInt BigInt::operator%(const unsigned long long &);
BigInt BigInt::operator^(const BigInt &);
BigInt BigInt::operator^(const int &);
BigInt BigInt::operator^(const unsigned int &);
BigInt BigInt::operator^(const long long &);
BigInt BigInt::operator^(const unsigned long long &);
BigInt BigInt::pow(const BigInt &);
BigInt BigInt::pow(const int &);
BigInt BigInt::pow(const unsigned int &);
BigInt BigInt::pow(const long long &);
BigInt BigInt::pow(const unsigned long long &);
*/

//-------------BOOL-----------------


bool BigInt::operator==(const BigInt &a) const {
	if(this->_blocks ^ a._blocks || this->_sign ^ a._sign) return false;
	int i = this->_blocks;
	while(i--)
		if(this->_num[i] ^ a._num[i]) return false;
	return true;
}

bool BigInt::operator==(const int &a) const {
	if(this->_blocks ^ 1 || this->_sign ^ (a < 0)) return false;
	return this->_num[0] == a;
}

bool BigInt::operator==(const unsigned int &a) const {
	if(this->_blocks ^ 1 || this->_sign & 1) return false;
	return this->_num[0] == a;
}

bool BigInt::operator==(const long long &a) const {
	if(this->_blocks ^ 1 || this->_sign ^ (a < 0)) return false;
	return this->_num[0] == a;
}

bool BigInt::operator==(const unsigned long long &a) const {
	if(this->_blocks > 2 || this->_sign & 1) return false;
	if(this->_blocks == 1) return this->_num[0] == a;
	if(a > _BLOCK_SIZE_64_) return ((this->_num[1] == 1) && (this->_num[0] == a - _BLOCK_SIZE_64_ - 1)); 
	return this->_num[0] == a;
}

bool BigInt::operator>(const BigInt &a) const {
	if(this->_sign == 0){
		if(a._sign & 1) return true;
		if(this->_blocks > a._blocks) return true;
		else if(a._blocks > this->_blocks) return false;

		int i = this->_blocks;
		while(i--)
			if(this->_num[i] > a._num[i]) return true;
			else if(this->_num[i] < a._num[i]) return false;
		return false;
	}
	if(a._sign == 0) return false;
		if(this->_blocks > a._blocks) return false;
		else if(a._blocks > this->_blocks) return true;

		int i = this->_blocks;
		while(i--)
			if(this->_num[i] < a._num[i]) return true;
			else if(this->_num[i] > a._num[i]) return false;
		return false;
}

bool BigInt::operator>(const int &a) const {
	if(this->_sign == 0)
		if(a < 0 || this->_blocks ^ 1) return true;
		else return this->_num[0] > a;
	else if(a >= 0 || this->_blocks ^ 1) return false;
		else return this->_num[0] < -a;
}

bool BigInt::operator>(const unsigned int &a) const {
	if(this->_sign & 1) return false;
	if(this->_blocks ^ 1) return true;
	return this->_num[0] > a;
}
bool BigInt::operator>(const long long &a) const{
	if(this->_sign == 0)
		if(a < 0 || this->_blocks ^ 1) return true;
		else return this->_num[0] > a;
	else if(a >= 0 || this->_blocks ^ 1) return false;
		else return this->_num[0] < -a;
}

bool BigInt::operator>(const unsigned long long &a) const {
	if(this->_sign & 1) return false;
	if(this->_blocks > 2) return true;
	if(a > _BLOCK_SIZE_64_)
		if(this->_blocks == 1) return false;
		else if(this->_num[1] > 1) return true; 
		else return this->_num[0] > a - _BLOCK_SIZE_64_ - 1;
	else return this->_num[0] > a;
}

/*bool BigInt::operator<(const BigInt &);
bool BigInt::operator<(const int &);
bool BigInt::operator<(const unsigned int &);
bool BigInt::operator<(const long long &);
bool BigInt::operator<(const unsigned long long &);
bool BigInt::operator>=(const BigInt &);
bool BigInt::operator>=(const int &);
bool BigInt::operator>=(const unsigned int &);
bool BigInt::operator>=(const long long &);
bool BigInt::operator>=(const unsigned long long &);
bool BigInt::operator<=(const BigInt &);
bool BigInt::operator<=(const int &);
bool BigInt::operator<=(const unsigned int &);
bool BigInt::operator<=(const long long &);
bool BigInt::operator<=(const unsigned long long &);
bool BigInt::operator!=(const BigInt &);
bool BigInt::operator!=(const int &);
bool BigInt::operator!=(const unsigned int &);
bool BigInt::operator!=(const long long &);
bool BigInt::operator!=(const unsigned long long &);
*/


//--------------I/O--------------------------------

std::ostream& operator << (std::ostream &o, const BigInt &a){
	int i = a._blocks-1;
	if(a._sign) o << "-";
	o << a._num[i];
	while(i--)o << std::setfill('0') << std::setw(19) << a._num[i];
	return o;
}

std::istream& operator >> (std::istream &in, BigInt &a){
	char c;
	c = in.get();
	a = 0;
	bool sign = 0;
	if(c == '-'){ 
		sign = 1;
		c = in.get();
	}
	while(c != '\n' && c != ' ' && c != -1 && (c == '.' || c == ',' ||( c >= '0' && c <='9'))){
		if(c == '.' || c == ',');
		else{ 
			a.__left_shift();
			unsigned long long aux = c - '0';
			a = a + aux;
		}
		c = in.get();
	}
	a._sign = sign;
	return in;
}
