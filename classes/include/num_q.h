#ifndef __NUM_Q_H
#define __NUM_Q_H

#include "num_z.h"

	class num_q {
		private:
			num_z _numerator;
			num_z _denominator;
			bool _sign;
			
			void _simplify();
		public: 
			num_q();
			num_q(const num_q &);
			num_q(const num_z &);
			num_q(const num_z &, const num_z &);
			num_q(const num_z &, const int64_t &);
			num_q(const int64_t &, const num_z &);
			num_q abs(){ num_q res(*this); res._sign = 0; return res; };
			
			num_z numerator(){ num_z res(this->_numerator); res._sign = this->_sign; return res; };
			num_z denominator(){ return this->_denominator; };

			operator num_z(){ return (this->_numerator / this->_denominator).q; };
			num_q & operator=(const num_q &);
			num_q & operator=(const num_z &);
			num_q & operator=(const int64_t &);
			num_q & operator+=(const num_q &);
			num_q & operator+=(const num_z &);
			num_q & operator+=(const int64_t &);
			num_q & operator-=(const num_q &);
			num_q & operator-=(const num_z &);
			num_q & operator-=(const int64_t &);
			num_q & operator*=(const num_q &);
			num_q & operator*=(const num_z &);
			num_q & operator*=(const int64_t &);
			num_q & operator/=(const num_q &);
			num_q & operator/=(const num_z &);
			num_q & operator/=(const int64_t &);
			num_q operator+(const num_q &);
			num_q operator+(const num_z &);
			num_q operator+(const int64_t &);
			num_q operator-(const num_q &);
			num_q operator-(const num_z &);
			num_q operator-(const int64_t &);
			num_q operator*(const num_q &);
			num_q operator*(const num_z &);
			num_q operator*(const int64_t &);
			num_q operator/(const num_q &);
			num_q operator/(const num_z &);
			num_q operator/(const int64_t &);
			num_q pow(int64_t);
			bool operator==(const num_q &);
			bool operator==(const num_z &);
			bool operator==(const int64_t &);
			bool operator>=(const num_q &);
			bool operator>=(const num_z &);
			bool operator>=(const int64_t &);
			bool operator<=(const num_q &);
			bool operator<=(const num_z &);
			bool operator<=(const int64_t &);
			bool operator!=(const num_q &);
			bool operator!=(const num_z &);
			bool operator!=(const int64_t &);
			bool operator>(const num_q &);
			bool operator>(const num_z &);
			bool operator>(const int64_t &);
			bool operator<(const num_q &);
			bool operator<(const num_z &);
			bool operator<(const int64_t &);
			bool negative(){ return this->_sign; };
	};

#endif
