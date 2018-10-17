/*
 * Header for the rational numbers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __NUM_Q_H
#define __NUM_Q_H

#include <iosfwd>

#include "signatures.h"

#include "number.h"
#include "num_z.h"

	class num_q : public Number{
		
		friend class monomial;

		friend std::ostream& operator << (std::ostream &, const num_q &);
		friend std::istream& operator >> (std::istream &, num_q &);
		friend num_q q_gcd(const num_q &, const num_q &);
		
		private:
			num_z _numerator;
			num_z _denominator;
			bool _sign;
			
			void _simplify();
			std::ostream & display() const { return std::cout << *this; };

		public: 
			num_q();
			num_q(const num_q &);
			num_q(const num_z &);
			num_q(const num_z &, const num_z &);
			num_q(const num_z &, const long long &);
			num_q(const long long &, const num_z &);
			num_q(const long long &, const long long &);
			num_q(int);
			num_q(int, int);
			
			num_q & value() { return *this; };
			num_z z_value() const { return num_z(*this); };
			num_q q_value() const { return *this; };


			num_q abs() const { num_q res(*this); res._sign = 0; return res; };
			num_q negative() const { num_q res(*this); res._sign = 1; return res; };
			num_q & make_abs(){ this->_sign = 0; return *this; };
			num_q & flip_sign(){ this->_sign = 1 - this->_sign; return *this; };
			num_q & make_negative(){ this->_sign = 1; return *this; };
			
			int type(){ return this->_type; };
			num_z numerator() const { num_z res(this->_numerator); res._sign = this->_sign; return res; };
			num_z denominator() const { return this->_denominator; };

			operator num_z(){ return (this->_numerator / this->_denominator).q; };
			num_q operator-() const { num_q res(*this); res._sign = 1 - res._sign; return res; };
			num_q operator+() const { num_q res(*this); return res; };
			
			num_q & operator=(const num_q &);
			num_q & operator=(const num_z &);
			num_q & operator=(const long long &);
			num_q & operator+=(const num_q &);
			num_q & operator+=(const num_z &);
			num_q & operator+=(const long long &);
			num_q & operator-=(const num_q &);
			num_q & operator-=(const num_z &);
			num_q & operator-=(const long long &);
			num_q & operator*=(const num_q &);
			num_q & operator*=(const num_z &);
			num_q & operator*=(const long long &);
			num_q & operator/=(const num_q &);
			num_q & operator/=(const num_z &);
			num_q & operator/=(const long long &);
			num_q operator+(const num_q &) const;
			num_q operator+(const num_z &) const;
			num_q operator+(const long long &) const;
			num_q operator-(const num_q &) const;
			num_q operator-(const num_z &) const;
			num_q operator-(const long long &) const;
			num_q operator*(const num_q &) const;
			num_q operator*(const num_z &) const;
			num_q operator*(const long long &) const;
			num_q operator/(const num_q &) const;
			num_q operator/(const num_z &) const;
			num_q operator/(const long long &) const;
			num_q inverse() const { return num_q(this->_denominator, this->_numerator); };
			num_q pow(const num_z &) const;

			bool sign() const { return this->_sign; };

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
			bool is_zero() const { return this->_numerator.is_zero(); }
			bool is_null() const { return this->_numerator.is_null(); }
	};

#endif
