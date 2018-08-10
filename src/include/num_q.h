#ifndef __NUM_Q_H
#define __NUM_Q_H

#include "number.h"
#include "num_z.h"

	class num_q  : public Number{

		friend std::ostream& operator << (std::ostream &, const num_q &);
		friend std::istream& operator >> (std::istream &, num_q &);
		
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
			num_q(const int64_t &, const int64_t &);
			
			num_q & value(){ return *this; };

			num_q abs(){ num_q res(*this); res._sign = 0; return res; };
			num_q negative(){ num_q res(*this); res._sign = 1; return res; };
			num_q & make_abs(){ this->_sign = 0; return *this; };
			num_q & flip_sign(){ this->_sign = 1 - this->_sign; return *this; };
			num_q & make_negative(){ this->_sign = 1; return *this; };

			num_z numerator() const { num_z res(this->_numerator); res._sign = this->_sign; return res; };
			num_z denominator() const { return this->_denominator; };

			operator num_z(){ return (this->_numerator / this->_denominator).q; };
			num_q operator-() const { num_q res(*this); res._sign = 1 - res._sign; return res; };
			num_q operator+() const { num_q res(*this); return res; };
			
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
			num_q inverse(){ return num_q(this->_denominator, this->_numerator); };
			num_q pow(int64_t);

			bool sign() const { return this->_sign; };

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
	
	};

#endif
