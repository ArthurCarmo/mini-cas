#ifndef __BIGINT_H__
#define __BIGINT_H__
#define _INIT_SIZE_ 10
#define _MAX_CONST_64_      10000000000000000000ull
#define _MAX_18_DIGIT_        999999999999999999ull
#define _MAX_9_DIGIT_                  999999999ull
#define _BLOCK_HALF_LAST_             1000000000ull
#define _BLOCK_SIZE_64_      9999999999999999999ull
#define _BLOCK_HALF_64_      5000000000000000000ull
#define _BLOCK_LAST_64_      1000000000000000000ull

#include <iostream>
#include <iomanip>
	class num_z {
		
		friend std::ostream& operator << (std::ostream &, const num_z &);
		friend std::istream& operator >> (std::istream &, num_z &);
		
		private:
			unsigned long long *_num;
			bool _sign;
			unsigned int _n_blocks;
			unsigned int _blocks;
			
			void __resize(unsigned int);
			void __left_shift();
			void __left_shift(unsigned int);
			void __right_shift();
			void __right_shift(unsigned int);
		public:
			num_z();
			num_z(const num_z &);
			num_z(const long long &);
			num_z(const unsigned long long &);
			num_z(const int &);
			num_z(const unsigned int &);
			num_z(const char []);
			~num_z();
			num_z abs();
			num_z operator-();
			num_z & operator+();
			num_z & operator++();
			num_z & operator--();
			num_z operator++(int);
			num_z operator--(int);
			num_z & operator=(const num_z &);
			num_z & operator=(const long long &);
			num_z & operator=(const unsigned long long &);
			num_z & operator=(const int &);
			num_z & operator=(const unsigned int &);
			num_z & operator=(const char []);
			num_z & operator+=(const num_z &);
			num_z & operator+=(const long long &);
			num_z & operator+=(const unsigned long long &);
			num_z & operator+=(const int &);
			num_z & operator+=(const unsigned int &);
			num_z & operator+=(const char []);
			num_z & operator-=(const num_z &);
			num_z & operator-=(const long long &);
			num_z & operator-=(const unsigned long long &);
			num_z & operator-=(const int &);
			num_z & operator-=(const unsigned int &);
			num_z & operator*=(const num_z &);
			num_z & operator*=(const long long &);
			num_z & operator*=(const unsigned long long &);
			num_z & operator*=(const int &);
			num_z & operator*=(const unsigned int &);
			num_z & operator/=(const num_z &);
			num_z & operator/=(const long long &);
			num_z & operator/=(const unsigned long long &);
			num_z & operator/=(const int &);
			num_z & operator/=(const unsigned int &);
			num_z & operator%=(const num_z &);
			num_z & operator%=(const long long &);
			num_z & operator%=(const unsigned long long &);
			num_z & operator%=(const int &);
			num_z & operator%=(const unsigned int &);
			num_z operator+(const num_z &);
			num_z operator+(const int &);
			num_z operator+(const unsigned int &); 
			num_z operator+(const long long &);
			num_z operator+(const unsigned long long &);
			num_z operator-(const num_z &);
			num_z operator-(const int &);
			num_z operator-(const unsigned int &);
			num_z operator-(const long long &);
			num_z operator-(const unsigned long long &);
			num_z operator*(const num_z &);
			num_z operator*(const int &);
			num_z operator*(const unsigned int &);
			num_z operator*(const long long &);
			num_z operator*(const unsigned long long &);
			num_z operator/(const num_z &);
			num_z operator/(const int &);
			num_z operator/(const unsigned int &);
			num_z operator/(const long long &);
			num_z operator/(const unsigned long long &);
			num_z operator%(const num_z &);
			num_z operator%(const int &);
			num_z operator%(const unsigned int &);
			num_z operator%(const long long &);
			num_z operator%(const unsigned long long &);
			num_z operator^(const num_z &);
			num_z operator^(const int &);
			num_z operator^(const unsigned int &);
			num_z operator^(const long long &);
			num_z operator^(const unsigned long long &);
			num_z pow(const num_z &);
			num_z pow(const int &);
			num_z pow(const unsigned int &);
			num_z pow(const long long &);
			num_z pow(const unsigned long long &);
			
			bool operator==(const num_z &) const;
			bool operator==(const int &) const;
			bool operator==(const unsigned int &) const;
			bool operator==(const long long &) const;
			bool operator==(const unsigned long long &) const;
			bool operator>(const num_z &) const;
			bool operator>(const int &) const;
			bool operator>(const unsigned int &) const;
			bool operator>(const long long &) const;
			bool operator>(const unsigned long long &) const;
			bool operator<(const num_z &) const;
			bool operator<(const int &) const;
			bool operator<(const unsigned int &) const;
			bool operator<(const long long &) const;
			bool operator<(const unsigned long long &) const;
			bool operator>=(const num_z &) const;
			bool operator>=(const int &) const;
			bool operator>=(const unsigned int &) const;
			bool operator>=(const long long &) const;
			bool operator>=(const unsigned long long &) const;
			bool operator<=(const num_z &) const;
			bool operator<=(const int &) const;
			bool operator<=(const unsigned int &) const;
			bool operator<=(const long long &) const;
			bool operator<=(const unsigned long long &) const;
			bool operator!=(const num_z &) const;
			bool operator!=(const int &) const;
			bool operator!=(const unsigned int &) const;
			bool operator!=(const long long &) const;
			bool operator!=(const unsigned long long &) const;
			
			bool abs_neq(const num_z &);
			bool abs_eq(const num_z &);
			bool abs_geq(const num_z &);
			bool abs_leq(const num_z &);
			bool abs_gt(const num_z &);
			bool abs_lt(const num_z &);
			
	}typedef Int;

#endif
