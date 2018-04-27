#ifndef __BIGINT_H__
#define __BIGINT_H__
#define _INIT_SIZE_ 10
#define _MAX_CONST_64_      10000000000000000000ul
#define _BLOCK_SIZE_64_      9999999999999999999ul
#define _BLOCK_HALF_64_      5000000000000000000ul
#define _BLOCK_LAST_64_      1000000000000000000ul
#define _MAX_18_DIGIT_        999999999999999999ul
#define _MAX_9_DIGIT_                  999999999ul
#define _BLOCK_HALF_LAST_             1000000000ul

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

	struct div_tuple;
	struct mod_tuple;
	
	class num_z {
		
		friend std::ostream& operator << (std::ostream &, const num_z &);
		friend std::istream& operator >> (std::istream &, num_z &);
		
		private:
			uint64_t *_num;
			bool _sign;
			uint32_t _n_blocks;
			uint32_t _blocks;
			
			void __resize(uint32_t);
			void __left_shift();
			void __left_shift(uint32_t);
			void __right_shift();
			void __right_shift(uint32_t);
			num_z _long_mul(uint64_t, uint64_t);
			uint64_t _mod_b();
			uint64_t _div_b();
		public:
			num_z();
			num_z(const num_z &);
			num_z(const num_z &, const uint32_t &);
			num_z(const div_tuple &);
			num_z(const mod_tuple &);
			num_z(const int64_t &);
			num_z(const uint64_t &);
			num_z(const int &);
			num_z(const uint32_t &);
			num_z(const char *);
			~num_z();
			num_z abs();
			num_z operator-() const;
			num_z operator+() const;
			num_z & operator++();
			num_z & operator--();
			num_z operator++(int);
			num_z operator--(int);
			num_z & operator=(const num_z &);
			num_z & operator=(const div_tuple &);
			num_z & operator=(const mod_tuple &);
			num_z & operator=(const int64_t &);
			num_z & operator=(const uint64_t &);
			num_z & operator=(const int &);
			num_z & operator=(const uint32_t &);
			num_z & operator=(const char *);
			num_z & operator+=(const num_z &);
			num_z & operator+=(const div_tuple &);
			num_z & operator+=(const mod_tuple &);
			num_z & operator+=(const int64_t &);
			num_z & operator+=(const uint64_t &);
			num_z & operator+=(const int &);
			num_z & operator+=(const uint32_t &);
			num_z & operator+=(const char *);
			num_z & operator-=(const num_z &);
			num_z & operator-=(const div_tuple &);
			num_z & operator-=(const mod_tuple &);
			num_z & operator-=(const int64_t &);
			num_z & operator-=(const uint64_t &);
			num_z & operator-=(const int &);
			num_z & operator-=(const uint32_t &);
			num_z & operator-=(const char *);
			num_z & operator*=(const num_z &);
			num_z & operator*=(const div_tuple &);
			num_z & operator*=(const mod_tuple &);
			num_z & operator*=(const int64_t &);
			num_z & operator*=(const uint64_t &);
			num_z & operator*=(const int &);
			num_z & operator*=(const uint32_t &);
			num_z & operator*=(const char *);
			num_z & operator/=(const num_z &);
			num_z & operator/=(const div_tuple &);
			num_z & operator/=(const mod_tuple &);
			num_z & operator/=(const int64_t &);
			num_z & operator/=(const uint64_t &);
			num_z & operator/=(const int &);
			num_z & operator/=(const uint32_t &);
			num_z & operator/=(const char *);
			num_z & operator%=(const num_z &);
			num_z & operator%=(const div_tuple &);
			num_z & operator%=(const mod_tuple &);
			num_z & operator%=(const int64_t &);
			num_z & operator%=(const uint64_t &);
			num_z & operator%=(const int &);
			num_z & operator%=(const uint32_t &);
			num_z & operator%=(const char *);
			num_z operator+(const num_z &);
			num_z operator+(const div_tuple &);
			num_z operator+(const mod_tuple &);
			num_z operator+(const int &);
			num_z operator+(const uint32_t &); 
			num_z operator+(const int64_t &);
			num_z operator+(const uint64_t &);
			num_z operator+(const char *);
			num_z operator-(const num_z &);
			num_z operator-(const div_tuple &);
			num_z operator-(const mod_tuple &);
			num_z operator-(const int &);
			num_z operator-(const uint32_t &);
			num_z operator-(const int64_t &);
			num_z operator-(const uint64_t &);
			num_z operator-(const char *);
			num_z operator*(const num_z &);
			num_z operator*(const div_tuple &);
			num_z operator*(const mod_tuple &);
			num_z operator*(const int &);
			num_z operator*(const uint32_t &);
			num_z operator*(const int64_t &);
			num_z operator*(const uint64_t &);
			num_z operator*(const char *);
			div_tuple operator/(const num_z &);
			div_tuple operator/(const div_tuple &);
			div_tuple operator/(const mod_tuple &);
			div_tuple operator/(const int &);
			div_tuple operator/(const uint32_t &);
			div_tuple operator/(const int64_t &);
			div_tuple operator/(const uint64_t &);
			div_tuple operator/(const char *);
			mod_tuple operator%(const num_z &);
			mod_tuple operator%(const div_tuple &);
			mod_tuple operator%(const mod_tuple &);
			mod_tuple operator%(const int &);
			mod_tuple operator%(const uint32_t &);
			mod_tuple operator%(const int64_t &);
			mod_tuple operator%(const uint64_t &);
			mod_tuple operator%(const char *);
			num_z operator^(const num_z &);
			num_z operator^(const div_tuple &);
			num_z operator^(const mod_tuple &);
			num_z operator^(const int &);
			num_z operator^(const uint32_t &);
			num_z operator^(const int64_t &);
			num_z operator^(const uint64_t &);
			num_z operator^(const char *);
			num_z pow(const num_z &);
			num_z pow(const int &);
			num_z pow(const uint32_t &);
			num_z pow(const int64_t &);
			num_z pow(const uint64_t &);
			
			bool operator==(const num_z &) const;
			bool operator==(const div_tuple &) const;
			bool operator==(const mod_tuple &) const;
			bool operator==(const int &) const;
			bool operator==(const uint32_t &) const;
			bool operator==(const int64_t &) const;
			bool operator==(const uint64_t &) const;
			bool operator==(const char *) const;
			bool operator>(const num_z &) const;
			bool operator>(const div_tuple &) const;
			bool operator>(const mod_tuple &) const;
			bool operator>(const int &) const;
			bool operator>(const uint32_t &) const;
			bool operator>(const int64_t &) const;
			bool operator>(const uint64_t &) const;
			bool operator>(const char *) const;
			bool operator<(const num_z &) const;
			bool operator<(const div_tuple &) const;
			bool operator<(const mod_tuple &) const;
			bool operator<(const int &) const;
			bool operator<(const uint32_t &) const;
			bool operator<(const int64_t &) const;
			bool operator<(const uint64_t &) const;
			bool operator<(const char *) const;
			bool operator>=(const num_z &) const;
			bool operator>=(const div_tuple &) const;
			bool operator>=(const mod_tuple &) const;
			bool operator>=(const int &) const;
			bool operator>=(const uint32_t &) const;
			bool operator>=(const int64_t &) const;
			bool operator>=(const uint64_t &) const;
			bool operator>=(const char *) const;
			bool operator<=(const num_z &) const;
			bool operator<=(const div_tuple &) const;
			bool operator<=(const mod_tuple &) const;
			bool operator<=(const int &) const;
			bool operator<=(const uint32_t &) const;
			bool operator<=(const int64_t &) const;
			bool operator<=(const uint64_t &) const;
			bool operator<=(const char *) const;
			bool operator!=(const num_z &) const;
			bool operator!=(const div_tuple &) const;
			bool operator!=(const mod_tuple &) const;
			bool operator!=(const int &) const;
			bool operator!=(const uint32_t &) const;
			bool operator!=(const int64_t &) const;
			bool operator!=(const uint64_t &) const;
			bool operator!=(const char *) const;
			
			bool abs_neq(const num_z &);
			bool abs_eq(const num_z &);
			bool abs_geq(const num_z &);
			bool abs_leq(const num_z &);
			bool abs_gt(const num_z &);
			bool abs_lt(const num_z &);
			
	};
	
	struct div_tuple{
		num_z q;
		num_z r;
		friend std::ostream& operator << (std::ostream &, const div_tuple &);
	
	};
	
	struct mod_tuple{
		num_z q;
		num_z r;
		friend std::ostream& operator << (std::ostream &, const mod_tuple &);
	};
#endif
