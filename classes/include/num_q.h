#ifndef __NUM_Q_H
#define __NUM_Q_H

#include "num_z.h"

	class num_q : public num_z{ // USAR HERANÇA?
		private:
			num_z _numerator;
			num_z _denominator;
			bool _sign;
		public: 
			num_q();
			num_q & operator=(const num_q &);
			num_q & operator=(const num_z &);
			num_q & operator=(const int64_t &);
			num_q & operator+(const num_q &);
			num_q & operator+(const num_z &);
			num_q & operator+(const int64_t &);
			num_q & operator-(const num_q &);
			num_q & operator-(const num_z &);
			num_q & operator-(const int64_t &);
			num_q & operator*(const num_q &);
			num_q & operator*(const num_z &);
			num_q & operator*(const int64_t &);
			num_q & operator/(const num_q &);
			num_q & operator/(const num_z &);
			num_q & operator/(const int64_t &);
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
