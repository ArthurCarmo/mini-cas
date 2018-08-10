#ifndef __BIGINT_H__
#define __BIGINT_H__

#define _INIT_SIZE_                     10
#define _DIGITS_PER_BLOCK_               9
#define _BASE_                  1000000000
#define _MAX_DIGIT_BASE_         999999999
#define _MIN_ALL_DIGITS_         100000000
#define _MAX_NO_CARRY_ON_SHIFT_   99999999
#define DECIMAL 0
#define HEX 1
#define BIN 2

#include "number.h"

	class num_z : public Number{

		template <int64_t N>
		friend class num_zm;
		friend class num_q;

		friend std::ostream& operator << (std::ostream &, const num_z &);
		friend std::istream& operator >> (std::istream &, num_z &);
		friend void hex_f(const num_z &);
		friend void bin_f(const num_z &);
		friend num_z hex(const num_z &);
		friend num_z bin(const num_z &);
		friend num_z z_gcd(const num_z &, const num_z &);
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
			int32_t lsd(){ return this->_num[0]; };
			int32_t msd(){ return this->_num[this->_blocks-1]; };

			num_z & value(){ return *this; };

			num_z abs();
			num_z negative(){ num_z res(*this); res._sign = 1; return res; };
			num_z & make_abs(){ this->_sign = 0; return *this; };
			num_z & flip_sign(){ this->_sign = 1 - this->_sign; return *this; };
			num_z & make_negative(){ this->_sign = 1; return *this; };

			operator div_tuple();
			operator mod_tuple();
			operator bool(){return *this != 0;};
			
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
			num_z & operator=(const std::string &);
			num_z & operator+=(const num_z &);
			num_z & operator+=(const num_q &);
			num_z & operator+=(const div_tuple &);
			num_z & operator+=(const mod_tuple &);
			num_z & operator+=(const int64_t &);
			num_z & operator+=(const uint64_t &);
			num_z & operator+=(const int &);
			num_z & operator+=(const uint32_t &);
			num_z & operator+=(const char *);
			num_z & operator-=(const num_z &);
			num_z & operator-=(const num_q &);
			num_z & operator-=(const div_tuple &);
			num_z & operator-=(const mod_tuple &);
			num_z & operator-=(const int64_t &);
			num_z & operator-=(const uint64_t &);
			num_z & operator-=(const int &);
			num_z & operator-=(const uint32_t &);
			num_z & operator-=(const char *);
			num_z & operator*=(const num_z &);
			num_z & operator*=(const num_q &);
			num_z & operator*=(const div_tuple &);
			num_z & operator*=(const mod_tuple &);
			num_z & operator*=(const int64_t &);
			num_z & operator*=(const uint64_t &);
			num_z & operator*=(const int &);
			num_z & operator*=(const uint32_t &);
			num_z & operator*=(const char *);
			num_z & operator/=(const num_z &);
			num_z & operator/=(const num_q &);
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
			num_q operator+(const num_q &);
			num_z operator+(const div_tuple &);
			num_z operator+(const mod_tuple &);
			num_z operator+(const int &);
			num_z operator+(const uint32_t &); 
			num_z operator+(const int64_t &);
			num_z operator+(const uint64_t &);
			num_z operator+(const char *);
			num_z operator-(const num_z &);
			num_q operator-(const num_q &);
			num_z operator-(const div_tuple &);
			num_z operator-(const mod_tuple &);
			num_z operator-(const int &);
			num_z operator-(const uint32_t &);
			num_z operator-(const int64_t &);
			num_z operator-(const uint64_t &);
			num_z operator-(const char *);
			num_z operator*(const num_z &);
			num_q operator*(const num_q &);
			num_z operator*(const div_tuple &);
			num_z operator*(const mod_tuple &);
			num_z operator*(const int &);
			num_z operator*(const uint32_t &);
			num_z operator*(const int64_t &);
			num_z operator*(const uint64_t &);
			num_z operator*(const char *);
			div_tuple operator/(const num_z &);
			num_q operator/(const num_q &);
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
			
			num_z pow(uint64_t);
			
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
			bool sign() const { return this->_sign; };
			
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
		operator num_z(){ return this->q; }
	};
	
	struct mod_tuple{
		num_z q;
		num_z r;
		friend std::ostream& operator << (std::ostream &, const mod_tuple &);
		operator num_z(){ return this->r; }
	};
#endif
