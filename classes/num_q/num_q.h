#ifndef __NUM_Q_H
#define __NUM_Q_H

#include "bigint.h"

	class Num_Q {
		private:
			Int __numerator;
			Int __denominator;
			bool __sign;
		public: 
			Num_Q();
			Num_Q & operator=(const Num_Q &);
			Num_Q & operator=(const BigInt &);
			Num_Q & operator=(const long long &);
			Num_Q & operator+(const Num_Q &);
			Num_Q & operator+(const BigInt &);
			Num_Q & operator+(const long long &);
			Num_Q & operator-(const Num_Q &);
			Num_Q & operator-(const BigInt &);
			Num_Q & operator-(const long long &);
			Num_Q & operator*(const Num_Q &);
			Num_Q & operator*(const BigInt &);
			Num_Q & operator*(const long long &);
			Num_Q & operator/(const Num_Q &);
			Num_Q & operator/(const BigInt &);
			Num_Q & operator/(const long long &);
			bool operator==(const Num_Q &);
			bool operator==(const BigInt &);
			bool operator==(const long long &);
			bool operator>=(const Num_Q &);
			bool operator>=(const BigInt &);
			bool operator>=(const long long &);
			bool operator<=(const Num_Q &);
			bool operator<=(const BigInt &);
			bool operator<=(const long long &);
			bool operator!=(const Num_Q &);
			bool operator!=(const BigInt &);
			bool operator!=(const long long &);
			bool operator>(const Num_Q &);
			bool operator>(const BigInt &);
			bool operator>(const long long &);
			bool operator<(const Num_Q &);
			bool operator<(const BigInt &);
			bool operator<(const long long &);
	};

#endif