#ifndef __NUM_ZM_H__
#define __NUM_ZM_H__

#include "num_z.h"

template <int64_t N>
class num_zm {
 template <int64_t U> friend std::ostream& operator << (std::ostream &, const num_zm<U> &);
 template <int64_t U> friend std::istream& operator >> (std::istream &, num_zm<U> &);
 private:
	num_z _num;
	int _valid;
 public:
	num_zm();
	num_zm(const num_zm &);
	num_zm(const num_z &);
	num_zm(const div_tuple &);
	num_zm(const mod_tuple &);
	num_zm(const int64_t &);
	num_zm(const uint64_t &);
	num_zm(const int &);
	num_zm(const uint32_t &);
	num_zm(const char *);
	num_z raw_value() const;
	operator num_z(){ return this->_num; };

	num_zm operator-() const;
	num_zm operator+() const;
	num_zm & operator++();
	num_zm & operator--();
	num_zm operator++(int);
	num_zm operator--(int);
	num_zm & operator=(const num_zm<N> &);
	num_zm & operator=(const num_z &);
	num_zm & operator=(const div_tuple &);
	num_zm & operator=(const mod_tuple &);
	num_zm & operator=(const int64_t &);
	num_zm & operator=(const uint64_t &);
	num_zm & operator=(const int &);
	num_zm & operator=(const uint32_t &);
	num_zm & operator=(const char *);
	num_zm & operator+=(const num_zm<N> &);
	num_zm & operator+=(const num_z &);
	num_zm & operator+=(const div_tuple &);
	num_zm & operator+=(const mod_tuple &);
	num_zm & operator+=(const int64_t &);
	num_zm & operator+=(const uint64_t &);
	num_zm & operator+=(const int &);
	num_zm & operator+=(const uint32_t &);
	num_zm & operator+=(const char *);
	num_zm & operator-=(const num_zm<N> &);
	num_zm & operator-=(const num_z &);
	num_zm & operator-=(const div_tuple &);
	num_zm & operator-=(const mod_tuple &);
	num_zm & operator-=(const int64_t &);
	num_zm & operator-=(const uint64_t &);
	num_zm & operator-=(const int &);
	num_zm & operator-=(const uint32_t &);
	num_zm & operator-=(const char *);
	num_zm & operator*=(const num_zm<N> &);
	num_zm & operator*=(const num_z &);
	num_zm & operator*=(const div_tuple &);
	num_zm & operator*=(const mod_tuple &);
	num_zm & operator*=(const int64_t &);
	num_zm & operator*=(const uint64_t &);
	num_zm & operator*=(const int &);
	num_zm & operator*=(const uint32_t &);
	num_zm & operator*=(const char *);
	num_zm & operator/=(const num_zm<N> &);
	num_zm & operator/=(const num_z &);
	num_zm & operator/=(const div_tuple &);
	num_zm & operator/=(const mod_tuple &);
	num_zm & operator/=(const int &);
	num_zm & operator/=(const uint32_t &);
	num_zm & operator/=(const int64_t &);
	num_zm & operator/=(const uint64_t &);
	num_zm & operator/=(const char *);
	num_zm operator+(const num_zm<N> &);
	num_zm operator+(const num_z &);
	num_zm operator+(const div_tuple &);
	num_zm operator+(const mod_tuple &);
	num_zm operator+(const int &);
	num_zm operator+(const uint32_t &);
	num_zm operator+(const int64_t &);
	num_zm operator+(const uint64_t &);
	num_zm operator+(const char *);
	num_zm operator-(const num_zm<N> &);
	num_zm operator-(const num_z &);
	num_zm operator-(const div_tuple &);
	num_zm operator-(const mod_tuple &);
	num_zm operator-(const int &);
	num_zm operator-(const uint32_t &);
	num_zm operator-(const int64_t &);
	num_zm operator-(const uint64_t &);
	num_zm operator-(const char *);
	num_zm operator*(const num_zm<N> &);
	num_zm operator*(const num_z &);
	num_zm operator*(const div_tuple &);
	num_zm operator*(const mod_tuple &);
	num_zm operator*(const int &);
	num_zm operator*(const uint32_t &);
	num_zm operator*(const int64_t &);
	num_zm operator*(const uint64_t &);
	num_zm operator*(const char *);
	num_zm operator/(const num_zm<N> &);
	num_zm operator/(const num_z &);
	num_zm operator/(const div_tuple &);
	num_zm operator/(const mod_tuple &);
	num_zm operator/(const int &);
	num_zm operator/(const uint32_t &);
	num_zm operator/(const int64_t &);
	num_zm operator/(const uint64_t &);
	num_zm operator/(const char *);
	bool valid(void){ return _valid; };
	bool has_inverse();
	num_zm inverse();
};

# 1 "inc_tpp.h" 1
# 1 "../num_zm/attrib.tpp" 1



template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const num_zm<N> &a){
 this->_num = a._num;
 this->_valid = a._valid;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const num_z &a){
 this->_num = num_z(a) % N;
 this->_valid = 1;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const div_tuple &a){
 this->_num = num_z(a.q) % N;
 this->_valid = 1;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const mod_tuple &a){
 this->_num = num_z(a.r) % N;
 this->_valid = 1;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const int64_t &a){
 this->_num = num_z(a) % N;
 this->_valid = 1;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const uint64_t &a){
 this->_num = num_z(a) % N;
 this->_valid = 1;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const int &a){
 this->_num = num_z(a) % N;
 this->_valid = 1;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const uint32_t &a){
 this->_num = num_z(a) % N;
 this->_valid = 1;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator=(const char *a){
 this->_num = num_z(a) % N;
 this->_valid = 1;
 return *this;
}
# 2 "inc_tpp.h" 2
# 1 "../num_zm/io.tpp" 1



template <int64_t U> std::ostream& operator << (std::ostream &o, const num_zm<U> &a){
 o << a._num;
 return o;
}

template <int64_t U> std::istream& operator >> (std::istream &i, num_zm<U> &a){
 i >> a._num;
 a._num = a._num%U;
 return i;
}
# 3 "inc_tpp.h" 2
# 1 "../num_zm/num_zm.tpp" 1



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
# 4 "inc_tpp.h" 2
# 1 "../num_zm/op_atrmul.tpp" 1
template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const num_zm<N> &a){
 this->_num *= a._num;
 this->_num %= N;
 this->_valid &= a._valid;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const num_z &a){
 this->_num *= a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const div_tuple &a){
 this->_num *= a.q;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const mod_tuple &a){
 this->_num *= a.r;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const int &a){
 this->_num *= a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const uint32_t &a){
 this->_num *= a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const int64_t &a){
 this->_num *= a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const uint64_t &a){
 this->_num *= a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator*=(const char *a){
 this->_num *= a;
 this->_num %= N;
 return *this;
}
# 5 "inc_tpp.h" 2
# 1 "../num_zm/op_atrsum.tpp" 1



template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const num_zm<N> &a){
 this->_num = this->_num + a._num;
 if(N < 0){
	if(this->_num <= N){
	 this->_num -= num_z(N);
	}
 }else if(this->_num >= N){
	this->_num -= num_z(N);
 }
 this->_valid &= a._valid;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const num_z &a){
 this->_num += a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const div_tuple &a){
 this->_num += a.q;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const mod_tuple &a){
 this->_num += a.r;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const int64_t &a){
 this->_num += a;
 this->_num %= N;
 return *this;
}
template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const uint64_t &a){
 this->_num += a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const int &a){
 this->_num += a;
 this->_num %= N;
 return *this;
}
template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const uint32_t &a){
 this->_num += a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator+=(const char *a){
 this->_num += a;
 this->_num %= N;
 return *this;
}
# 6 "inc_tpp.h" 2
# 1 "../num_zm/op_atrsub.tpp" 1



template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const num_zm<N> &a){
 this->_num -= a._num;
 if(this->_sign ^ a._sign && this->_num != 0)
	 this->_num = num_z(N) + this->_num;
 this->_valid &= a._valid;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const num_z &a){
 this->_num -= a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const div_tuple &a){
 this->_num -= a.q;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const mod_tuple &a){
 this->_num -= a.r;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const int64_t &a){
 this->_num -= a;
 this->_num %= N;
 return *this;
}
template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const uint64_t &a){
 this->_num -= a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const int &a){
 this->_num -= a;
 this->_num %= N;
 return *this;
}
template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const uint32_t &a){
 this->_num -= a;
 this->_num %= N;
 return *this;
}

template <int64_t N>
num_zm<N> & num_zm<N>::operator-=(const char *a){
 this->_num -= a;
 this->_num %= N;
 return *this;
}
# 7 "inc_tpp.h" 2
# 1 "../num_zm/opdiv.tpp" 1



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
# 8 "inc_tpp.h" 2
# 1 "../num_zm/opmul.tpp" 1
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
# 9 "inc_tpp.h" 2
# 1 "../num_zm/opsum.tpp" 1



template <int64_t N>
num_zm<N> num_zm<N>::operator+(const num_zm<N> &a){
 num_zm<N> res(this->_num + a._num);
 res._valid = this->_valid & a._valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const num_z &a){
 num_zm<N> res(this->_num + a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const div_tuple &a){
 num_zm<N> res(this->_num + a.q);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const mod_tuple &a){
 num_zm<N> res(this->_num + a.r);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const int64_t &a){
 num_zm<N> res(this->_num + a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const uint64_t &a){
 num_zm<N> res(this->_num + a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const int &a){
 num_zm<N> res(this->_num + a);
 res._valid = this->_valid;
 return res;
}
template <int64_t N>
num_zm<N> num_zm<N>::operator+(const uint32_t &a){
 num_zm<N> res(this->_num + a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator+(const char *a){
 num_zm<N> res(this->_num + a);
 res._valid = this->_valid;
 return res;
}
# 10 "inc_tpp.h" 2
# 1 "../num_zm/opsub.tpp" 1



template <int64_t N>
num_zm<N> num_zm<N>::operator-(const num_zm<N> &a){
 num_zm<N> res(this->_num - a._num);
 res._valid = this->_valid & a._valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-(const num_z &a){
 num_zm<N> res(this->_num - a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-(const div_tuple &a){
 num_zm<N> res(this->_num - a.q);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-(const mod_tuple &a){
 num_zm<N> res(this->_num - a.r);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-(const int64_t &a){
 num_zm<N> res(this->_num - a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-(const uint64_t &a){
 num_zm<N> res(this->_num - a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-(const int &a){
 num_zm<N> res(this->_num - a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-(const uint32_t &a){
 num_zm<N> res(this->_num - a);
 res._valid = this->_valid;
 return res;
}

template <int64_t N>
num_zm<N> num_zm<N>::operator-(const char *a){
 num_zm<N> res(this->_num - a);
 res._valid = this->_valid;
 return res;
}
# 11 "inc_tpp.h" 2
# 1 "../num_zm/unary_ops.tpp" 1



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