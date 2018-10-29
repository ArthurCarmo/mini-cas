/*
 * Header for the modulo arithmetic integers class
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

#include <iosfwd>

#include "number.h"
#include "num_z.h"

class num_zm : public Number {
	friend std::ostream& operator << (std::ostream &, const num_zm &);
	friend std::istream& operator >> (std::istream &, num_zm &);

	private:
		num_z _num;
		num_z _base;
		int _valid;
		
		std::ostream & display() const { return std::cout << *this; };

	public:
		num_zm(const num_zm &);
		num_zm(const num_z &);
		num_zm(const num_z &, const num_z &);
		num_zm(const num_z &, const div_tuple &);
		num_zm(const num_z &, const mod_tuple &);

		num_zm & value() { return *this; };
		num_z z_value() const { return this->_num; };
		num_zm zm_value(const num_z &a) const { return num_zm(a, this->_num); };
		num_q q_value() const;

		
		int type() const { return this->_type; };
		num_z base() const { return this->_base; };
		int32_t lsd() const { return this->_num.lsd(); };
		int32_t msd() const { return this->_num.msd(); };
		
		operator num_z(){ return this->_num; };
	
		num_zm operator-() const;
		num_zm operator+() const;
		num_zm & operator++();
		num_zm & operator--();
		num_zm operator++(int);
		num_zm operator--(int);
		
		num_zm & operator=(const num_zm &);
		num_zm & operator=(const num_z &);
		num_zm & operator=(const num_q &);
		num_zm & operator=(const div_tuple &);
		num_zm & operator=(const mod_tuple &);
		num_zm & operator=(const long long &);
		num_zm & operator=(const unsigned long long &);
		num_zm & operator=(const int &);
		num_zm & operator=(const uint32_t &);
		num_zm & operator=(const char *);
		num_zm & operator+=(const num_zm &);
		num_zm & operator+=(const num_z &);
		num_zm & operator+=(const num_q &);
		num_zm & operator+=(const div_tuple &);
		num_zm & operator+=(const mod_tuple &);
		num_zm & operator+=(const long long &);
		num_zm & operator+=(const unsigned long long &);
		num_zm & operator+=(const int &);
		num_zm & operator+=(const uint32_t &);
		num_zm & operator+=(const char *);
		num_zm & operator-=(const num_zm &);
		num_zm & operator-=(const num_z &);
		num_zm & operator-=(const num_q &);
		num_zm & operator-=(const div_tuple &);
		num_zm & operator-=(const mod_tuple &);
		num_zm & operator-=(const long long &);
		num_zm & operator-=(const unsigned long long &);
		num_zm & operator-=(const int &);
		num_zm & operator-=(const uint32_t &);
		num_zm & operator-=(const char *);
		num_zm & operator*=(const num_zm &);
		num_zm & operator*=(const num_z &);
		num_zm & operator*=(const num_q &);
		num_zm & operator*=(const div_tuple &);
		num_zm & operator*=(const mod_tuple &);
		num_zm & operator*=(const long long &);
		num_zm & operator*=(const unsigned long long &);
		num_zm & operator*=(const int &);
		num_zm & operator*=(const uint32_t &);
		num_zm & operator*=(const char *);
		num_zm & operator/=(const num_zm &);
		num_zm & operator/=(const num_z &);
		num_zm & operator/=(const num_q &);
		num_zm & operator/=(const div_tuple &);
		num_zm & operator/=(const mod_tuple &);
		num_zm & operator/=(const int &);
		num_zm & operator/=(const uint32_t &);
		num_zm & operator/=(const long long &);
		num_zm & operator/=(const unsigned long long &);
		num_zm & operator/=(const char *);
		
		num_zm operator+(const num_zm &) const;
		num_zm operator+(const num_z &) const;
		num_zm operator+(const div_tuple &) const;
		num_zm operator+(const mod_tuple &) const;
		num_zm operator+(const int &) const;
		num_zm operator+(const uint32_t &) const;
		num_zm operator+(const long long &) const;
		num_zm operator+(const unsigned long long &) const;
		num_zm operator+(const char *) const;
		num_zm operator-(const num_zm &) const;
		num_zm operator-(const num_z &) const;
		num_zm operator-(const div_tuple &) const;
		num_zm operator-(const mod_tuple &) const;
		num_zm operator-(const int &) const;
		num_zm operator-(const uint32_t &) const;
		num_zm operator-(const long long &) const;
		num_zm operator-(const unsigned long long &) const;
		num_zm operator-(const char *) const;
		num_zm operator*(const num_zm &) const;
		num_zm operator*(const num_z &) const;
		num_zm operator*(const div_tuple &) const;
		num_zm operator*(const mod_tuple &) const;
		num_zm operator*(const int &) const;
		num_zm operator*(const uint32_t &) const;
		num_zm operator*(const long long &) const;
		num_zm operator*(const unsigned long long &) const;
		num_zm operator*(const char *) const;
		num_zm operator/(const num_zm &) const;
		num_zm operator/(const num_z &) const;
		num_zm operator/(const div_tuple &) const;
		num_zm operator/(const mod_tuple &) const;
		num_zm operator/(const int &) const;
		num_zm operator/(const uint32_t &) const;
		num_zm operator/(const long long &) const;
		num_zm operator/(const unsigned long long &) const;
		num_zm operator/(const char *) const;
		
		
		bool valid(void) const { return _valid; };
		bool has_inverse() const ;
		num_zm inverse() const ;
		num_zm pow(num_z) const;
		
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
		bool congruent(const num_z &) const;
		
};

#endif
