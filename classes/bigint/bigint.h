#ifndef __BIGINT_H__
#define __BIGINT_H__
#define _INIT_SIZE_ 10
#define _MAX_CONST_64_ 10000000000000000000
#define _MAX_18_DIGIT_   999999999999999999
#define _MAX_9_DIGIT_             999999999
#define _BLOCK_HALF_LAST_        1000000000
#define _BLOCK_SIZE_64_ 9999999999999999999
#define _BLOCK_HALF_64_ 5000000000000000000
#define _BLOCK_LAST_64_ 1000000000000000000

#include <iostream>
#include <iomanip>
	class BigInt {
		
		friend std::ostream& operator << (std::ostream &, const BigInt &);
		friend std::istream& operator >> (std::istream &, BigInt &);
		
		private:
			unsigned long long *_num;
			bool _sign;
			unsigned int _n_blocks;
			unsigned int _blocks;
			
			void __resize(unsigned int);
			
			void __right_shift();
		public:
			void __left_shift();
			BigInt();
			BigInt(const BigInt &);
			~BigInt();
			BigInt abs() const;
			BigInt & operator=(const BigInt &);
			BigInt & operator=(const long long &);
			BigInt & operator=(const unsigned long long &);
			BigInt & operator=(const int &);
			BigInt & operator=(const unsigned int &);
			BigInt & operator+=(const BigInt &);
			BigInt & operator+=(const long long &);
			BigInt & operator+=(const unsigned long long &);
			BigInt & operator+=(const int &);
			BigInt & operator+=(const unsigned int &);
			BigInt & operator-=(const BigInt &);
			BigInt & operator-=(const long long &);
			BigInt & operator-=(const unsigned long long &);
			BigInt & operator-=(const int &);
			BigInt & operator-=(const unsigned int &);
			BigInt & operator*=(const BigInt &);
			BigInt & operator*=(const long long &);
			BigInt & operator*=(const unsigned long long &);
			BigInt & operator*=(const int &);
			BigInt & operator*=(const unsigned int &);
			BigInt & operator/=(const BigInt &);
			BigInt & operator/=(const long long &);
			BigInt & operator/=(const unsigned long long &);
			BigInt & operator/=(const int &);
			BigInt & operator/=(const unsigned int &);
			BigInt & operator%=(const BigInt &);
			BigInt & operator%=(const long long &);
			BigInt & operator%=(const unsigned long long &);
			BigInt & operator%=(const int &);
			BigInt & operator%=(const unsigned int &);
			BigInt operator+(const BigInt &);
			BigInt operator+(const int &);
			BigInt operator+(const unsigned int &); 
			BigInt operator+(const long long &);
			BigInt operator+(const unsigned long long &);
			BigInt operator-(const BigInt &);
			BigInt operator-(const int &);
			BigInt operator-(const unsigned int &);
			BigInt operator-(const long long &);
			BigInt operator-(const unsigned long long &);
			BigInt operator*(const BigInt &);
			BigInt operator*(const int &);
			BigInt operator*(const unsigned int &);
			BigInt operator*(const long long &);
			BigInt operator*(const unsigned long long &);
			BigInt operator/(const BigInt &);
			BigInt operator/(const int &);
			BigInt operator/(const unsigned int &);
			BigInt operator/(const long long &);
			BigInt operator/(const unsigned long long &);
			BigInt operator%(const BigInt &);
			BigInt operator%(const int &);
			BigInt operator%(const unsigned int &);
			BigInt operator%(const long long &);
			BigInt operator%(const unsigned long long &);
			BigInt operator^(const BigInt &);
			BigInt operator^(const int &);
			BigInt operator^(const unsigned int &);
			BigInt operator^(const long long &);
			BigInt operator^(const unsigned long long &);
			BigInt pow(const BigInt &);
			BigInt pow(const int &);
			BigInt pow(const unsigned int &);
			BigInt pow(const long long &);
			BigInt pow(const unsigned long long &);
			
			bool operator==(const BigInt &) const;
			bool operator==(const int &) const;
			bool operator==(const unsigned int &) const;
			bool operator==(const long long &) const;
			bool operator==(const unsigned long long &) const;
			bool operator>(const BigInt &) const;
			bool operator>(const int &) const;
			bool operator>(const unsigned int &) const;
			bool operator>(const long long &) const;
			bool operator>(const unsigned long long &) const;
			bool operator<(const BigInt &) const;
			bool operator<(const int &) const;
			bool operator<(const unsigned int &) const;
			bool operator<(const long long &) const;
			bool operator<(const unsigned long long &) const;
			bool operator>=(const BigInt &) const;
			bool operator>=(const int &) const;
			bool operator>=(const unsigned int &) const;
			bool operator>=(const long long &) const;
			bool operator>=(const unsigned long long &) const;
			bool operator<=(const BigInt &) const;
			bool operator<=(const int &) const;
			bool operator<=(const unsigned int &) const;
			bool operator<=(const long long &) const;
			bool operator<=(const unsigned long long &) const;
			bool operator!=(const BigInt &) const;
			bool operator!=(const int &) const;
			bool operator!=(const unsigned int &) const;
			bool operator!=(const long long &) const;
			bool operator!=(const unsigned long long &) const;
			
			bool abs_neq(const BigInt &);
			bool abs_eq(const BigInt &);
			bool abs_geq(const BigInt &);
			bool abs_leq(const BigInt &);
			bool abs_gt(const BigInt &);
			bool abs_lt(const BigInt &);
			
	}typedef Int;

#endif
