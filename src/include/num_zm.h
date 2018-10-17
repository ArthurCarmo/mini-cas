/*
 * Header and implementation for the template
 * modulo arithmetic integers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __NUM_ZM_H__
#define __NUM_ZM_H__

#include <iostream>

#include "number.h"
#include "num_z.h"
#include "num_q.h"

template <long long N>
class num_zm : public Number {
	template <long long U> friend std::ostream& operator << (std::ostream &, const num_zm<U> &);
	template <long long U> friend std::istream& operator >> (std::istream &, num_zm<U> &);

	private:
		num_z _num;
		int _valid;
		
		std::ostream & display() const { return std::cout << *this; };

	public:
		num_zm();
		num_zm(const num_zm &);
		num_zm(const num_z &);
		num_zm(const div_tuple &);
		num_zm(const mod_tuple &);
		num_zm(const long long &);
		num_zm(const unsigned long long &);
		num_zm(const int &);
		num_zm(const uint32_t &);
		num_zm(const char *);

		num_zm & value() { return *this; };
		num_z z_value() const { return this->_num; };
		num_q q_value() const { return num_q(this->_num); };

		int type(){ return this->_type; };
		long long base() { return N; };
		int32_t lsd(){ return this->_num.lsd(); };
		int32_t msd(){ return this->_num.msd(); };
		
		operator num_z(){ return this->_num; };
	
		num_zm operator-() const;
		num_zm operator+() const;
		num_zm & operator++();
		num_zm & operator--();
		num_zm operator++(int);
		num_zm operator--(int);
		
		num_zm & operator=(const num_zm<N> &);
		num_zm & operator=(const num_z &);
		num_zm & operator=(const num_q &);
		num_zm & operator=(const div_tuple &);
		num_zm & operator=(const mod_tuple &);
		num_zm & operator=(const long long &);
		num_zm & operator=(const unsigned long long &);
		num_zm & operator=(const int &);
		num_zm & operator=(const uint32_t &);
		num_zm & operator=(const char *);
		num_zm & operator+=(const num_zm<N> &);
		num_zm & operator+=(const num_z &);
		num_zm & operator+=(const num_q &);
		num_zm & operator+=(const div_tuple &);
		num_zm & operator+=(const mod_tuple &);
		num_zm & operator+=(const long long &);
		num_zm & operator+=(const unsigned long long &);
		num_zm & operator+=(const int &);
		num_zm & operator+=(const uint32_t &);
		num_zm & operator+=(const char *);
		num_zm & operator-=(const num_zm<N> &);
		num_zm & operator-=(const num_z &);
		num_zm & operator-=(const num_q &);
		num_zm & operator-=(const div_tuple &);
		num_zm & operator-=(const mod_tuple &);
		num_zm & operator-=(const long long &);
		num_zm & operator-=(const unsigned long long &);
		num_zm & operator-=(const int &);
		num_zm & operator-=(const uint32_t &);
		num_zm & operator-=(const char *);
		num_zm & operator*=(const num_zm<N> &);
		num_zm & operator*=(const num_z &);
		num_zm & operator*=(const num_q &);
		num_zm & operator*=(const div_tuple &);
		num_zm & operator*=(const mod_tuple &);
		num_zm & operator*=(const long long &);
		num_zm & operator*=(const unsigned long long &);
		num_zm & operator*=(const int &);
		num_zm & operator*=(const uint32_t &);
		num_zm & operator*=(const char *);
		num_zm & operator/=(const num_zm<N> &);
		num_zm & operator/=(const num_z &);
		num_zm & operator/=(const num_q &);
		num_zm & operator/=(const div_tuple &);
		num_zm & operator/=(const mod_tuple &);
		num_zm & operator/=(const int &);
		num_zm & operator/=(const uint32_t &);
		num_zm & operator/=(const long long &);
		num_zm & operator/=(const unsigned long long &);
		num_zm & operator/=(const char *);
		
		num_zm operator+(const num_zm<N> &);
		num_zm operator+(const num_z &);
		num_zm operator+(const div_tuple &);
		num_zm operator+(const mod_tuple &);
		num_zm operator+(const int &);
		num_zm operator+(const uint32_t &);
		num_zm operator+(const long long &);
		num_zm operator+(const unsigned long long &);
		num_zm operator+(const char *);
		num_zm operator-(const num_zm<N> &);
		num_zm operator-(const num_z &);
		num_zm operator-(const div_tuple &);
		num_zm operator-(const mod_tuple &);
		num_zm operator-(const int &);
		num_zm operator-(const uint32_t &);
		num_zm operator-(const long long &);
		num_zm operator-(const unsigned long long &);
		num_zm operator-(const char *);
		num_zm operator*(const num_zm<N> &);
		num_zm operator*(const num_z &);
		num_zm operator*(const div_tuple &);
		num_zm operator*(const mod_tuple &);
		num_zm operator*(const int &);
		num_zm operator*(const uint32_t &);
		num_zm operator*(const long long &);
		num_zm operator*(const unsigned long long &);
		num_zm operator*(const char *);
		num_zm operator/(const num_zm<N> &);
		num_zm operator/(const num_z &);
		num_zm operator/(const div_tuple &);
		num_zm operator/(const mod_tuple &);
		num_zm operator/(const int &);
		num_zm operator/(const uint32_t &);
		num_zm operator/(const long long &);
		num_zm operator/(const unsigned long long &);
		num_zm operator/(const char *);
		
		
		bool valid(void){ return _valid; };
		bool has_inverse();
		num_zm inverse();
		num_zm pow(unsigned long long);
		
		bool operator==(const num_q &) const;
		bool operator==(const num_z &) const;
		bool operator==(const long long &) const;
		bool operator>=(const num_q &) const;
		bool operator>=(const num_z &) const;
		bool operator>=(const long long &) const;
		bool operator<=(const num_q &) const;
		bool operator<=(const num_z &) const;
		bool operator<=(const long long &) const;
		bool operator!=(const num_q &) const;
		bool operator!=(const num_z &) const;
		bool operator!=(const long long &) const;
		bool operator>(const num_q &) const;
		bool operator>(const num_z &) const;
		bool operator>(const long long &) const;
		bool operator<(const num_q &) const;
		bool operator<(const num_z &) const;
		bool operator<(const long long &) const;
		bool is_zero() const { return this->_num.is_zero(); }
		bool is_null() const { return this->_num.is_null(); }
		
};

template <long long N>
num_zm<N> & num_zm<N>::operator=(const num_zm<N> &a){
	this->_num = a._num;
	this->_valid = a._valid;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const num_z &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const num_q &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const div_tuple &a){
	this->_num = num_z(a.q) % N;
	this->_valid = 1;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const mod_tuple &a){
	this->_num = num_z(a.r) % N;
	this->_valid = 1;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const long long &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const unsigned long long &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const int &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const uint32_t &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator=(const char *a){
	this->_num = num_z(a) % N;
	this->_valid = 1;
	return *this;
}

template <long long U> std::ostream& operator << (std::ostream &o, const num_zm<U> &a){
	o << a._num;
	return o;
}

template <long long U> std::istream& operator >> (std::istream &i, num_zm<U> &a){
	i >> a._num;
	a._num = a._num%U;
	return i;
}

template <long long N>
num_zm<N>::num_zm(){
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N>::num_zm(const num_zm<N> &a){
	this->_num = a._num;
	this->_valid = a._valid;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N>::num_zm(const num_z &a){
	this->_num = num_z(a)%N;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N>::num_zm(const div_tuple &a){
	this->_num = num_z(a.q) % N;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N>::num_zm(const mod_tuple &a){
	this->_num = num_z(a.r) % N;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N>::num_zm(const unsigned long long &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N>::num_zm(const int &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N>::num_zm(const uint32_t &a){
	this->_num = num_z(a) % N;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N>::num_zm(const char *a){
	this->_num = num_z(a) % N;
	this->_valid = 1;	
	this->_type = _CAS_TYPE_ZM_;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const num_zm<N> &a){
	this->_num *= a._num;
	this->_num %= N;
	this->_valid &= a._valid;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const num_z &a){
	this->_num *= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const num_q &a){
	this->_num *= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const div_tuple &a){
	this->_num *= a.q;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const mod_tuple &a){
	this->_num *= a.r;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const int &a){
	this->_num *= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const uint32_t &a){
	this->_num *= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const long long &a){
	this->_num *= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const unsigned long long &a){
	this->_num *= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator*=(const char *a){
	this->_num *= a;
	this->_num %= N;
	return *this;
}

template <long long N>
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

template <long long N>
num_zm<N> & num_zm<N>::operator+=(const num_z &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator+=(const num_q &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator+=(const div_tuple &a){
	this->_num += a.q;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator+=(const mod_tuple &a){
	this->_num += a.r;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator+=(const long long &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}
template <long long N>
num_zm<N> & num_zm<N>::operator+=(const unsigned long long &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator+=(const int &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}
template <long long N>
num_zm<N> & num_zm<N>::operator+=(const uint32_t &a){
	this->_num += a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator+=(const char *a){
	this->_num += a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator-=(const num_zm<N> &a){
	this->_num -= a._num;
	if(this->_sign ^ a._sign && this->_num != 0)
	 this->_num = num_z(N) + this->_num;
	this->_valid &= a._valid;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator-=(const num_z &a){
	this->_num -= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator-=(const num_q &a){
	this->_num -= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator-=(const div_tuple &a){
	this->_num -= a.q;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator-=(const mod_tuple &a){
	this->_num -= a.r;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator-=(const long long &a){
	this->_num -= a;
	this->_num %= N;
	return *this;
}
template <long long N>
num_zm<N> & num_zm<N>::operator-=(const unsigned long long &a){
	this->_num -= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator-=(const int &a){
	this->_num -= a;
	this->_num %= N;
	return *this;
}
template <long long N>
num_zm<N> & num_zm<N>::operator-=(const uint32_t &a){
	this->_num -= a;
	this->_num %= N;
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator-=(const char *a){
	this->_num -= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const num_zm<N> &a){
	return *this * a.inverse();
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const num_z &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const div_tuple &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const mod_tuple &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const int &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const uint32_t &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const long long &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const unsigned long long &a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<long long N>
num_zm<N> num_zm<N>::operator/(const char *a){
	num_zm<N> res(this->_num / a);
	return res;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const num_zm<N> &a){
	this->_num *= a.inverse();
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const num_z &a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const num_q &a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const div_tuple &a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const mod_tuple &a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const int &a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const uint32_t &a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const long long &a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const unsigned long long &a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
num_zm<N> & num_zm<N>::operator/=(const char *a){
	this->_num /= a;
	this->_num %= N;
	return *this;
}

template<long long N>
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

template<long long N>
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

template <long long N>
num_zm<N> num_zm<N>::operator*(const num_zm<N> &a){
	num_zm<N> res(this->_num * a._num);
	res._valid = this->_valid & a._valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator*(const num_z &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator*(const div_tuple &a){
	num_zm<N> res(this->_num * a.q);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator*(const mod_tuple &a){
	num_zm<N> res(this->_num * a.r);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator*(const int &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator*(const uint32_t &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator*(const long long &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator*(const unsigned long long &a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator*(const char *a){
	num_zm<N> res(this->_num * a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator+(const num_zm<N> &a){
	num_zm<N> res(this->_num + a._num);
	res._valid = this->_valid & a._valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator+(const num_z &a){
	num_zm<N> res(this->_num + a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator+(const div_tuple &a){
	num_zm<N> res(this->_num + a.q);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator+(const mod_tuple &a){
	num_zm<N> res(this->_num + a.r);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator+(const long long &a){
	num_zm<N> res(this->_num + a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator+(const unsigned long long &a){
	num_zm<N> res(this->_num + a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator+(const int &a){
	num_zm<N> res(this->_num + a);
	res._valid = this->_valid;
	return res;
}
template <long long N>
num_zm<N> num_zm<N>::operator+(const uint32_t &a){
	num_zm<N> res(this->_num + a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator+(const char *a){
	num_zm<N> res(this->_num + a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const num_zm<N> &a){
	num_zm<N> res(this->_num - a._num);
	res._valid = this->_valid & a._valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const num_z &a){
	num_zm<N> res(this->_num - a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const div_tuple &a){
	num_zm<N> res(this->_num - a.q);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const mod_tuple &a){
	num_zm<N> res(this->_num - a.r);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const long long &a){
	num_zm<N> res(this->_num - a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const unsigned long long &a){
	num_zm<N> res(this->_num - a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const int &a){
	num_zm<N> res(this->_num - a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const uint32_t &a){
	num_zm<N> res(this->_num - a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-(const char *a){
	num_zm<N> res(this->_num - a);
	res._valid = this->_valid;
	return res;
}

template <long long N>
num_zm<N> num_zm<N>::operator-() const{
	return num_z(N)-this->_num;
}

template <long long N>
num_zm<N> num_zm<N>::operator+() const{
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator++(){
	this->_num += 1;
	if(N < 0){
	if(this->_num == 1) this->_num = N + 1;
	}else{
	if(this->_num == N) this->_num = 0;
	}
	return *this;
}

template <long long N>
num_zm<N> & num_zm<N>::operator--(){
	this->_num -= 1;
	if(N < 0){
	if(this->_num == N) this->_num = 0;
	}else{
	if(this->_num == -1) this->_num = N - 1;
	}
	return *this;
}

template <long long N>
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

template <long long N>
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

template <long long N>
num_zm<N> num_zm<N>::pow(unsigned long long exp) {
	num_zm<N> result(1);
	
	while (exp > 0) {
		if (exp & 1) result *= *this;
		*this *= *this;
		exp >>= 1;
	}
	return result;
}

template <long long N>
bool num_zm<N>::operator==(const num_q &a) const {
	return this->_num == a;
}

template <long long N>
bool num_zm<N>::operator==(const num_z &a) const {
	return this->_num == a;
}

template <long long N>
bool num_zm<N>::operator==(const long long &a) const {
	return this->_num == a;
}

template <long long N>
bool num_zm<N>::operator>=(const num_q &a) const {
	return this->_num >= a;
}

template <long long N>
bool num_zm<N>::operator>=(const num_z &a) const {
	return this->_num >= a;
}

template <long long N>
bool num_zm<N>::operator>=(const long long &a) const {
	return this->_num >= a;
}

template <long long N>
bool num_zm<N>::operator<=(const num_q &a) const {
	return this->_num <= a;
}

template <long long N>
bool num_zm<N>::operator<=(const num_z &a) const {
	return this->_num <= a;
}

template <long long N>
bool num_zm<N>::operator<=(const long long &a) const {
	return this->_num <= a;
}

template <long long N>
bool num_zm<N>::operator!=(const num_q &a) const {
	return this->_num != a;
}

template <long long N>
bool num_zm<N>::operator!=(const num_z &a) const {
	return this->_num != a;
}

template <long long N>
bool num_zm<N>::operator!=(const long long &a) const {
	return this->_num != a;
}

template <long long N>
bool num_zm<N>::operator>(const num_q &a) const {
	return this->_num > a;
}

template <long long N>
bool num_zm<N>::operator>(const num_z &a) const {
	return this->_num > a;
}

template <long long N>
bool num_zm<N>::operator>(const long long &a) const {
	return this->_num > a;
}

template <long long N>
bool num_zm<N>::operator<(const num_q &a) const {
	return this->_num < a;
}

template <long long N>
bool num_zm<N>::operator<(const num_z &a) const {
	return this->_num < a;
}

template <long long N>
bool num_zm<N>::operator<(const long long &a) const {
	return this->_num < a;
}


#endif
