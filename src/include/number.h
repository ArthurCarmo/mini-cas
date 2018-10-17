/*
 * Header for the Number abstract class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __NUMBER_CLASS_
#define __NUMBER_CLASS_

#define _CAS_TYPE_Z_  0
#define _CAS_TYPE_Q_  1
#define _CAS_TYPE_ZM_ 2

#include <iostream>

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
		virtual num_z z_value() const = 0;		
		virtual num_q q_value() const = 0;

		virtual Number & operator=(const num_z &) = 0;
		virtual Number & operator=(const num_q &) = 0;
		virtual Number & operator=(const long long &) = 0;
		virtual Number & operator+=(const num_z &) = 0;
		virtual Number & operator+=(const num_q &) = 0;
		virtual Number & operator+=(const long long &) = 0;
		virtual Number & operator-=(const num_z &) = 0;
		virtual Number & operator-=(const num_q &) = 0;
		virtual Number & operator-=(const long long &) = 0;
		virtual Number & operator*=(const num_z &) = 0;
		virtual Number & operator*=(const num_q &) = 0;
		virtual Number & operator*=(const long long &) = 0;
		virtual Number & operator/=(const num_z &) = 0;
		virtual Number & operator/=(const num_q &) = 0;
		virtual Number & operator/=(const long long &) = 0;
		
		virtual bool operator==(const num_q &) const = 0;
		virtual bool operator==(const num_z &) const = 0;
		virtual bool operator==(const long long &) const = 0;
		virtual bool operator>=(const num_q &) const = 0;
		virtual bool operator>=(const num_z &) const = 0;
		virtual bool operator>=(const long long &) const = 0;
		virtual bool operator<=(const num_q &) const = 0;
		virtual bool operator<=(const num_z &) const = 0;
		virtual bool operator<=(const long long &) const = 0;
		virtual bool operator!=(const num_q &) const = 0;
		virtual bool operator!=(const num_z &) const = 0;
		virtual bool operator!=(const long long &) const = 0;
		virtual bool operator>(const num_q &) const = 0;
		virtual bool operator>(const num_z &) const = 0;
		virtual bool operator>(const long long &) const = 0;
		virtual bool operator<(const num_q &) const = 0;
		virtual bool operator<(const num_z &) const = 0;
		virtual bool operator<(const long long &) const = 0;
		
		virtual bool is_zero() const = 0;
		virtual bool is_null() const = 0;
		
};

#endif
