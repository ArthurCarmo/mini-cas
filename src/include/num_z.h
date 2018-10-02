#ifndef __BIGINT_H__
#define __BIGINT_H__

#define _INIT_SIZE_                    100
#define _DIGITS_PER_BLOCK_               9
#define _BASE_                  1000000000
#define _MAX_DIGIT_BASE_         999999999
#define _MIN_ALL_DIGITS_         100000000
#define _MAX_NO_CARRY_ON_SHIFT_   99999999
#define DECIMAL 0
#define HEX 1
#define BIN 2

#include <cstdio>
#include <cstdlib>

#include <iosfwd>
#include <string>
#include <algorithm>

#include "number.h"
	
	class num_z : public Number{

		template <long long N>
		friend class num_zm;
		friend class num_q;

		friend std::ostream& operator << (std::ostream &, const num_z &);
		friend std::istream& operator >> (std::istream &, num_z &);
		friend std::string hex_f(const num_z &);
		friend std::string bin_f(const num_z &);
		friend num_z hex(const num_z &);
		friend num_z bin(const num_z &);
		friend num_z z_pow(const num_z &, const num_z &);
		friend num_z z_gcd(const num_z &, const num_z &);
		friend num_z z_lcm(const num_z &, const num_z &);
		friend num_z z_sqrt(const num_z &);
		friend num_z __num_z_gcd(num_z &, num_z &);
		friend num_z __num_z_gcd_single(num_z &, uint32_t);
		
		private:
			uint32_t *_num;
			bool _sign;
			uint32_t _n_blocks;
			uint32_t _blocks;
			int _base_repr;
			
			void __resize(uint32_t);
			void __left_shift();
			void __left_shift(uint32_t);
			void __right_shift();
			void __right_shift(uint32_t);
			void __bit_lshift();
			
			std::ostream & display() const { return std::cout << *this; };
			
		public:
			num_z();
			num_z(const num_z &);
			num_z(const num_q &);
			num_z(const num_z &, const uint32_t &);
			num_z(const div_tuple &);
			num_z(const mod_tuple &);
			num_z(const long long &);
			num_z(const unsigned long long &);
			num_z(const int &);
			num_z(const uint32_t &);
			num_z(const char *);
			~num_z();

			int type() const { return this->_type; } ;
			std::string to_string() const;
			int32_t lsd() const { return this->_num[0]; };
			int32_t msd() const { return this->_num[this->_blocks-1]; };

			num_z & value() { return *this; };
			num_z z_value() const { return *this; };
			num_q q_value() const;

			num_z abs() const;
			num_z negative() const { num_z res(*this); res._sign = 1; return res; };
			num_z & make_abs(){ this->_sign = 0; return *this; };
			num_z & flip_sign(){ this->_sign = 1 - this->_sign; return *this; };
			num_z & make_negative(){ this->_sign = 1; return *this; };
			num_z sqrt();
			num_z gcd(const num_z &);
			num_z lcm(const num_z &);

			operator bool() const {return this->_blocks > 1 || this->_num[0] != 0;};
			
			num_z operator-() const;
			num_z operator+() const;
			num_z & operator++();
			num_z & operator--();
			num_z operator++(int);
			num_z operator--(int);
			num_z & operator=(const num_z &);
			num_z & operator=(const num_q &);
			num_z & operator=(const div_tuple &);
			num_z & operator=(const mod_tuple &);
			num_z & operator=(const long long &);
			num_z & operator=(const unsigned long long &);
			num_z & operator=(const int &);
			num_z & operator=(const uint32_t &);
			num_z & operator=(const char *);
			num_z & operator=(const std::string &);
			num_z & operator+=(const num_z &);
			num_z & operator+=(const num_q &);
			num_z & operator+=(const div_tuple &);
			num_z & operator+=(const mod_tuple &);
			num_z & operator+=(const long long &);
			num_z & operator+=(const unsigned long long &);
			num_z & operator+=(const int &);
			num_z & operator+=(const uint32_t &);
			num_z & operator+=(const char *);
			num_z & operator-=(const num_z &);
			num_z & operator-=(const num_q &);
			num_z & operator-=(const div_tuple &);
			num_z & operator-=(const mod_tuple &);
			num_z & operator-=(const long long &);
			num_z & operator-=(const unsigned long long &);
			num_z & operator-=(const int &);
			num_z & operator-=(const uint32_t &);
			num_z & operator-=(const char *);
			num_z & operator*=(const num_z &);
			num_z & operator*=(const num_q &);
			num_z & operator*=(const div_tuple &);
			num_z & operator*=(const mod_tuple &);
			num_z & operator*=(const long long &);
			num_z & operator*=(const unsigned long long &);
			num_z & operator*=(const int &);
			num_z & operator*=(const uint32_t &);
			num_z & operator*=(const char *);
			num_z & operator/=(const num_z &);
			num_z & operator/=(const num_q &);
			num_z & operator/=(const div_tuple &);
			num_z & operator/=(const mod_tuple &);
			num_z & operator/=(const long long &);
			num_z & operator/=(const unsigned long long &);
			num_z & operator/=(const int &);
			num_z & operator/=(const uint32_t &);
			num_z & operator/=(const char *);
			num_z & operator%=(const num_z &);
			num_z & operator%=(const div_tuple &);
			num_z & operator%=(const mod_tuple &);
			num_z & operator%=(const long long &);
			num_z & operator%=(const unsigned long long &);
			num_z & operator%=(const int &);
			num_z & operator%=(const uint32_t &);
			num_z & operator%=(const char *);
			num_z operator+(const num_z &) const;
			num_q operator+(const num_q &) const;
			num_z operator+(const div_tuple &) const;
			num_z operator+(const mod_tuple &) const;
			num_z operator+(const int &) const;
			num_z operator+(const uint32_t &) const; 
			num_z operator+(const long long &) const;
			num_z operator+(const unsigned long long &) const;
			num_z operator+(const char *) const;
			num_z operator-(const num_z &) const;
			num_q operator-(const num_q &) const;
			num_z operator-(const div_tuple &) const;
			num_z operator-(const mod_tuple &) const;
			num_z operator-(const int &) const;
			num_z operator-(const uint32_t &) const;
			num_z operator-(const long long &) const;
			num_z operator-(const unsigned long long &) const;
			num_z operator-(const char *) const;
			num_z operator*(const num_z &) const;
			num_q operator*(const num_q &) const;
			num_z operator*(const div_tuple &) const;
			num_z operator*(const mod_tuple &) const;
			num_z operator*(const int &) const;
			num_z operator*(const uint32_t &) const;
			num_z operator*(const long long &) const;
			num_z operator*(const unsigned long long &) const;
			num_z operator*(const char *) const;
			div_tuple operator/(const num_z &) const;
			num_q operator/(const num_q &) const;
			div_tuple operator/(const div_tuple &) const;
			div_tuple operator/(const mod_tuple &) const;
			div_tuple operator/(const int &) const;
			div_tuple operator/(const uint32_t &) const;
			div_tuple operator/(const long long &) const;
			div_tuple operator/(const unsigned long long &) const;
			div_tuple operator/(const char *) const;
			mod_tuple operator%(const num_z &) const;
			mod_tuple operator%(const div_tuple &) const;
			mod_tuple operator%(const mod_tuple &) const;
			mod_tuple operator%(const int &) const;
			mod_tuple operator%(const uint32_t &) const;
			mod_tuple operator%(const long long &) const;
			mod_tuple operator%(const unsigned long long &) const;
			mod_tuple operator%(const char *) const;
			
			num_z pow(const num_z &) const;
			num_z pow(unsigned long long) const;
			
			bool operator==(const num_z &) const;
			bool operator==(const num_q &) const;
			bool operator==(const div_tuple &) const;
			bool operator==(const mod_tuple &) const;
			bool operator==(const int &) const;
			bool operator==(const uint32_t &) const;
			bool operator==(const long long &) const;
			bool operator==(const unsigned long long &) const;
			bool operator==(const char *) const;
			bool operator>(const num_z &) const;
			bool operator>(const num_q &) const;
			bool operator>(const div_tuple &) const;
			bool operator>(const mod_tuple &) const;
			bool operator>(const int &) const;
			bool operator>(const uint32_t &) const;
			bool operator>(const long long &) const;
			bool operator>(const unsigned long long &) const;
			bool operator>(const char *) const;
			bool operator<(const num_z &) const;
			bool operator<(const num_q &) const;
			bool operator<(const div_tuple &) const;
			bool operator<(const mod_tuple &) const;
			bool operator<(const int &) const;
			bool operator<(const uint32_t &) const;
			bool operator<(const long long &) const;
			bool operator<(const unsigned long long &) const;
			bool operator<(const char *) const;
			bool operator>=(const num_z &) const;
			bool operator>=(const num_q &) const;
			bool operator>=(const div_tuple &) const;
			bool operator>=(const mod_tuple &) const;
			bool operator>=(const int &) const;
			bool operator>=(const uint32_t &) const;
			bool operator>=(const long long &) const;
			bool operator>=(const unsigned long long &) const;
			bool operator>=(const char *) const;
			bool operator<=(const num_z &) const;
			bool operator<=(const num_q &) const;
			bool operator<=(const div_tuple &) const;
			bool operator<=(const mod_tuple &) const;
			bool operator<=(const int &) const;
			bool operator<=(const uint32_t &) const;
			bool operator<=(const long long &) const;
			bool operator<=(const unsigned long long &) const;
			bool operator<=(const char *) const;
			bool operator!=(const num_z &) const;
			bool operator!=(const num_q &) const;
			bool operator!=(const div_tuple &) const;
			bool operator!=(const mod_tuple &) const;
			bool operator!=(const int &) const;
			bool operator!=(const uint32_t &) const;
			bool operator!=(const long long &) const;
			bool operator!=(const unsigned long long &) const;
			bool operator!=(const char *) const;

			bool sign() const { return this->_sign; };			
			bool odd() const { return this->_num[0] % 2; };
			bool even() const { return  1 - this->_num[0] % 2; };

			bool abs_neq(const num_z &) const;
			bool abs_eq(const num_z &) const;
			bool abs_geq(const num_z &) const;
			bool abs_leq(const num_z &) const;
			bool abs_gt(const num_z &) const;
			bool abs_lt(const num_z &) const;

	};
	
	struct div_tuple{
		num_z q;
		num_z r;
		div_tuple() { }
		div_tuple(const div_tuple &d){
			this->q = d.q;
			this->r = d.r;
		}
		
		friend std::ostream& operator << (std::ostream &, const div_tuple &);
		operator num_z(){ return this->q; }
		div_tuple & operator=(const div_tuple &d){
			this->q = d.q;
			this->r = d.r;
			return *this;
		}
	};
	
	struct mod_tuple{
		num_z q;
		num_z r;
		mod_tuple() { }
		mod_tuple(const mod_tuple &m) {
			this->q = m.q;
			this->r = m.r;
		}
		
		friend std::ostream& operator << (std::ostream &, const mod_tuple &);
		operator num_z(){ return this->r; }
		mod_tuple & operator=(const mod_tuple &m){
			this->q = m.q;
			this->r = m.r;
			return *this;
		}
	};
	
uint32_t __guess_quotient(const unsigned long long &, const unsigned long long &, const unsigned long long &);
bool __overstep_quotient(const unsigned long long &, const unsigned long long &, const unsigned long long &, const unsigned long long &, const unsigned long long &, const unsigned long long &);

#endif
