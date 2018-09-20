#include "../include/num_z.h"

//SQRT
num_z num_z::sqrt(){
	num_z xk(*this);
	num_z prev;
	if(*this == uint32_t(0)) return num_z(0);
	do{
		prev = xk;
		xk = (xk + ( *this / xk ) ) / 2;
	}while(prev != xk and prev != (xk - 1));
	
	return prev;
}

num_z z_sqrt(const num_z &a){
	num_z n(a);
	num_z xk(a);
	num_z prev;
	
	if(a == uint32_t(0)) return num_z(0);

	do{
		prev = xk;
		xk = (xk + ( n / xk ) ) / 2;
	}while(prev != xk and prev != (xk - 1));
	
	return prev;
}

//GCD
num_z num_z::gcd(const num_z &b){
	num_z m(*this), n(b);
	m._sign = n._sign = 0;
	if(m.abs_geq(n))
		return (n._blocks == 1)?__num_z_gcd_single(m, n._num[0]):num_z(__num_z_gcd(m, n));
	return (m._blocks == 1)?__num_z_gcd_single(n, m._num[0]):num_z(__num_z_gcd(n, m));
}

//WRAPPER
num_z z_gcd(const num_z &a, const num_z &b){
	num_z m(a), n(b);
	m._sign = n._sign = 0;
	if(m.abs_geq(n))
		return (n._blocks == 1)?__num_z_gcd_single(m, n._num[0]):num_z(__num_z_gcd(m, n));
	return (m._blocks == 1)?__num_z_gcd_single(n, m._num[0]):num_z(__num_z_gcd(n, m));
}

//GCD EUCLIDES
num_z __num_z_gcd_single(num_z &a, uint32_t b){
	if(b == 0) return a;
	div_tuple res(a / b);
	uint32_t n = res.r._num[0];
	uint32_t gcd = b;
	b = n;
	while(b != 0){
		n = gcd % b;
		gcd = b;
		b = n;
	}
	return num_z(gcd);
}

//GCD LEHMER
num_z __num_z_gcd(num_z &a, num_z &b){
	int64_t q, q2, u, v, A, B, C, D, T;
	num_z w, z;
	div_tuple t;
	
	while(b._blocks ^ 1){
		A = D = 1;
		B = C = 0;
		u = a._num[a._blocks - 1];
		v = (b._blocks < a._blocks)?0:b._num[a._blocks - 1];
		while(1){
			if((v + C) == 0 || (v + D) == 0) break;
			
			q  = (u+A) / (v+C); //floor((u+A) / (v+C))(?)
			q2 = (u+B) / (v+D); //floor((u+B) / (v+D))(?)
			
			if(q != q2) break;
			
			T = A - q*C;
			A = C;
			C = T;
			T = B - q*D;
			B = D;
			D = T;
			T = u - q*v;
			u = v;
			v = T;
		}
		if(B){
			w = a*A + b*B;
			z = a*C + b*D;
			a = w;
			b = z;
		}else{
			t = (a / b);
			a = b;
			b = t.r;	
		}
	}
	return __num_z_gcd_single(a, b._num[0]); //GCD para precisão simples
}

num_z z_gcd(const num_z &a, uint64_t &b){
	return z_gcd(a, num_z(b));
}

num_z z_gcd(const uint64_t &a, const num_z &b){
	return z_gcd(b, num_z(a));
}

//POW
num_z num_z::pow(const num_z &N) const {
	num_z p(*this);
	
	if(N == 0) return num_z(1);
	if(N == 1) return *this;
	div_tuple q = N / 2;
	p = this->pow(q.q);
	if(N._num[0] & 1) return *this * p * p;
	return p * p;
}

num_z num_z::pow(uint64_t N) const {
	num_z p(*this);
	
	if(N == 0) return num_z(1);
	if(N == 1) return *this;
	p = this->pow(N >> 1);
	if(N & 1) return *this * p * p;
	return p * p;
}

num_z z_pow(const num_z &a, const num_z &N){
	num_z res;

	if(N == 0) return num_z(1);
	if(N == 1) return a;
	div_tuple q = N / 2;
	res = z_pow(a, q.q);
	if(N._num[0] & 1) return a * res * res;
	return res * res;
}

//BITSHIFT
void num_z::__bit_lshift(){
	uint32_t i, n = this->_blocks - 1;
	for(i = 0; i < n; i++){
		this->_num[i] >>= 1;
		this->_num[i] |= (this->_num[i+1] & 1) << 31;
	}
	this->_num[n] >>= 1;
}

//LCM
num_z num_z::lcm(const num_z &b){
	return (*this*b)/z_gcd(*this, b);
}

num_z z_lcm(const num_z &a, const num_z &b){
	num_z res(a);
	return (res*b)/z_gcd(a, b);
}

//INLINE FUNCTIONS
uint32_t __guess_quotient(const uint64_t &n, const uint64_t &m0, const uint64_t &m1){
	return ( m0 == n )?_MAX_DIGIT_BASE_:( (m0*_BASE_ + m1) / n );
}

bool __overstep_quotient(const uint64_t &q_guess, const uint64_t &n2, const uint64_t &n1, const uint64_t &m0, const uint64_t &m1, const uint64_t &m2){
	return n2 * q_guess > ( m0 * _BASE_ - n1 * q_guess + m1 ) * _BASE_ + m2;
}
