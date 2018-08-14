#ifndef __NUMBER_CLASS_
#define __NUMBER_CLASS_

#define _CAS_TYPE_Z_  0
#define _CAS_TYPE_Q_  1
#define _CAS_TYPE_ZM_ 2

#include "signatures.h"

class Number{
	
	friend std::ostream & operator<<(std::ostream &o, const Number &a){
		return a.display();
	}

	protected:
		int _type;
		virtual std::ostream & display() const = 0;

	public:
		virtual ~Number() {};
		
		virtual Number & value() = 0;
		virtual num_z z_value() = 0;		
		virtual num_q q_value() = 0;

		virtual Number & operator=(const num_z &) = 0;
		virtual Number & operator=(const num_q &) = 0;
		virtual Number & operator=(const int64_t &) = 0;
		virtual Number & operator+=(const num_z &) = 0;
		virtual Number & operator+=(const num_q &) = 0;
		virtual Number & operator+=(const int64_t &) = 0;
		virtual Number & operator-=(const num_z &) = 0;
		virtual Number & operator-=(const num_q &) = 0;
		virtual Number & operator-=(const int64_t &) = 0;
		virtual Number & operator*=(const num_z &) = 0;
		virtual Number & operator*=(const num_q &) = 0;
		virtual Number & operator*=(const int64_t &) = 0;
		virtual Number & operator/=(const num_z &) = 0;
		virtual Number & operator/=(const num_q &) = 0;
		virtual Number & operator/=(const int64_t &) = 0;
		
		virtual bool operator==(const num_q &) const = 0;
		virtual bool operator==(const num_z &) const = 0;
		virtual bool operator==(const int64_t &) const = 0;
		virtual bool operator>=(const num_q &) const = 0;
		virtual bool operator>=(const num_z &) const = 0;
		virtual bool operator>=(const int64_t &) const = 0;
		virtual bool operator<=(const num_q &) const = 0;
		virtual bool operator<=(const num_z &) const = 0;
		virtual bool operator<=(const int64_t &) const = 0;
		virtual bool operator!=(const num_q &) const = 0;
		virtual bool operator!=(const num_z &) const = 0;
		virtual bool operator!=(const int64_t &) const = 0;
		virtual bool operator>(const num_q &) const = 0;
		virtual bool operator>(const num_z &) const = 0;
		virtual bool operator>(const int64_t &) const = 0;
		virtual bool operator<(const num_q &) const = 0;
		virtual bool operator<(const num_z &) const = 0;
		virtual bool operator<(const int64_t &) const = 0;
		
};

#endif
