/*
 * Boolean compare operators for the modulo arithmetic integers class
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#include "../include/num_zm.h"

bool num_zm::congruent(const num_z &a) const {
	return this->_num == ( a % this->_base );
}

bool num_zm::operator==(const num_q &a) const {
	return this->_num == a;
}

bool num_zm::operator==(const num_z &a) const {
	return this->_num == a;
}

bool num_zm::operator==(const long long &a) const {
	return this->_num == a;
}

bool num_zm::operator>=(const num_q &a) const {
	return this->_num >= a;
}

bool num_zm::operator>=(const num_z &a) const {
	return this->_num >= a;
}

bool num_zm::operator>=(const long long &a) const {
	return this->_num >= a;
}

bool num_zm::operator<=(const num_q &a) const {
	return this->_num <= a;
}

bool num_zm::operator<=(const num_z &a) const {
	return this->_num <= a;
}

bool num_zm::operator<=(const long long &a) const {
	return this->_num <= a;
}

bool num_zm::operator!=(const num_q &a) const {
	return this->_num != a;
}

bool num_zm::operator!=(const num_z &a) const {
	return this->_num != a;
}

bool num_zm::operator!=(const long long &a) const {
	return this->_num != a;
}

bool num_zm::operator>(const num_q &a) const {
	return this->_num > a;
}

bool num_zm::operator>(const num_z &a) const {
	return this->_num > a;
}

bool num_zm::operator>(const long long &a) const {
	return this->_num > a;
}

bool num_zm::operator<(const num_q &a) const {
	return this->_num < a;
}

bool num_zm::operator<(const num_z &a) const {
	return this->_num < a;
}

bool num_zm::operator<(const long long &a) const {
	return this->_num < a;
}

