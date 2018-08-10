#ifndef __NUM_ZM_H__
#define __NUM_ZM_H__

#include "num_z.h"

template <int64_t N>
class num_zm {
	template <int64_t U> friend std::ostream& operator << (std::ostream &, const num_zm<U> &);
	template <int64_t U> friend std::istream& operator >> (std::istream &, num_zm<U> &);
	private:
		num_z _num;
		int _valid;
	public:
		num_zm();
		num_zm(const num_zm &);
		num_zm(const num_z &);
		num_zm(const div_tuple &);
		num_zm(const mod_tuple &);
		num_zm(const int64_t &);
		num_zm(const uint64_t &);
		num_zm(const int &);
		num_zm(const uint32_t &);
		num_zm(const char *);	

		num_z raw_value() const;
		operator num_z(){ return this->_num; };
//		operator num_q(){ return num_q(this->_num, 1); };
		num_zm operator-() const;
		num_zm operator+() const;
		num_zm & operator++();
		num_zm & operator--();
		num_zm operator++(int);
		num_zm operator--(int);
		num_zm & operator=(const num_zm<N> &);
		num_zm & operator=(const num_z &);
		num_zm & operator=(const div_tuple &);
		num_zm & operator=(const mod_tuple &);
		num_zm & operator=(const int64_t &);
		num_zm & operator=(const uint64_t &);
		num_zm & operator=(const int &);
		num_zm & operator=(const uint32_t &);
		num_zm & operator=(const char *);
		num_zm & operator+=(const num_zm<N> &);
		num_zm & operator+=(const num_z &);
		num_zm & operator+=(const div_tuple &);
		num_zm & operator+=(const mod_tuple &);
		num_zm & operator+=(const int64_t &);
		num_zm & operator+=(const uint64_t &);
		num_zm & operator+=(const int &);
		num_zm & operator+=(const uint32_t &);
		num_zm & operator+=(const char *);
		num_zm & operator-=(const num_zm<N> &);
		num_zm & operator-=(const num_z &);
		num_zm & operator-=(const div_tuple &);
		num_zm & operator-=(const mod_tuple &);
		num_zm & operator-=(const int64_t &);
		num_zm & operator-=(const uint64_t &);
		num_zm & operator-=(const int &);
		num_zm & operator-=(const uint32_t &);
		num_zm & operator-=(const char *);
		num_zm & operator*=(const num_zm<N> &);
		num_zm & operator*=(const num_z &);
		num_zm & operator*=(const div_tuple &);
		num_zm & operator*=(const mod_tuple &);
		num_zm & operator*=(const int64_t &);
		num_zm & operator*=(const uint64_t &);
		num_zm & operator*=(const int &);
		num_zm & operator*=(const uint32_t &);
		num_zm & operator*=(const char *);
		num_zm & operator/=(const num_zm<N> &);
		num_zm & operator/=(const num_z &);
		num_zm & operator/=(const div_tuple &);
		num_zm & operator/=(const mod_tuple &);
		num_zm & operator/=(const int &);
		num_zm & operator/=(const uint32_t &);
		num_zm & operator/=(const int64_t &);
		num_zm & operator/=(const uint64_t &);
		num_zm & operator/=(const char *);
		num_zm operator+(const num_zm<N> &);
		num_zm operator+(const num_z &);
		num_zm operator+(const div_tuple &);
		num_zm operator+(const mod_tuple &);
		num_zm operator+(const int &);
		num_zm operator+(const uint32_t &); 
		num_zm operator+(const int64_t &);
		num_zm operator+(const uint64_t &);
		num_zm operator+(const char *);
		num_zm operator-(const num_zm<N> &);
		num_zm operator-(const num_z &);
		num_zm operator-(const div_tuple &);
		num_zm operator-(const mod_tuple &);
		num_zm operator-(const int &);
		num_zm operator-(const uint32_t &);
		num_zm operator-(const int64_t &);
		num_zm operator-(const uint64_t &);
		num_zm operator-(const char *);
		num_zm operator*(const num_zm<N> &);
		num_zm operator*(const num_z &);
		num_zm operator*(const div_tuple &);
		num_zm operator*(const mod_tuple &);
		num_zm operator*(const int &);
		num_zm operator*(const uint32_t &);
		num_zm operator*(const int64_t &);
		num_zm operator*(const uint64_t &);
		num_zm operator*(const char *);
		num_zm operator/(const num_zm<N> &);
		num_zm operator/(const num_z &);
		num_zm operator/(const div_tuple &);
		num_zm operator/(const mod_tuple &);
		num_zm operator/(const int &);
		num_zm operator/(const uint32_t &);
		num_zm operator/(const int64_t &);
		num_zm operator/(const uint64_t &);
		num_zm operator/(const char *);
		bool valid(void){ return _valid; };
		bool has_inverse();
		num_zm inverse();
		
};

#include "inc_tpp.h"

#endif
