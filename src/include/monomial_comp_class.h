/*
 * Possible compare functions to determine the ordering of monomials 
 * in the polynomial class
 *
 * All the compare functions are described here:
 * https://en.wikipedia.org/wiki/Monomial_order
 *
 * Author: Arthur Gonçalves do Carmo <arthur.goncalves.carmo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 */

#ifndef __MONOMIAL_COMP_CLASS_H_
#define __MONOMIAL_COMP_CLASS_H_

#include "monomial.h"

class glex { 
	public:
		bool operator()(const monomial &l, const monomial &r) const { 
			std::map<std::string, num_z>::const_iterator it_l = l._literals.begin();
			std::map<std::string, num_z>::const_iterator it_r = r._literals.begin();
			if(l._degree > r._degree) return true;
			if(l._degree < r._degree) return false;
		
			do{
				if(it_r == r._literals.end()) return false;
				if(it_l == l._literals.end()) return true;
				if(it_l->first < it_r->first) return true;
				if(it_l->first > it_r->first) return false;
				if(it_l->second < it_r->second) return true;
				if(it_l->second > it_r->second) return false;
		
				++it_l;
				++it_r;
			}while(true);
		}
};

class grevlex { 
	public:
		bool operator()(const monomial &l, const monomial &r) const { 
			std::map<std::string, num_z>::const_reverse_iterator it_l = l._literals.rbegin();
			std::map<std::string, num_z>::const_reverse_iterator it_r = r._literals.rbegin();
			if(l._degree > r._degree) return true;
			if(l._degree < r._degree) return false;
		
			do{
				if(it_l == l._literals.rend()) return false;
				if(it_r == r._literals.rend()) return true;
				if(it_l->first < it_r->first) return true;
				if(it_l->first > it_r->first) return false;
				if(it_l->second < it_r->second) return true;
				if(it_l->second > it_r->second) return false;
		
				++it_l;
				++it_r;
			}while(true);
		}
};

class lex { 
	public:
		bool operator()(const monomial &l, const monomial &r) const { 
			std::map<std::string, num_z>::const_iterator it_l = l._literals.begin();
			std::map<std::string, num_z>::const_iterator it_r = r._literals.begin();
	
			do{
				if(it_r == r._literals.end()) return false;
				if(it_l == l._literals.end()) return true;
				if(it_l->first < it_r->first) return true;
				if(it_l->first > it_r->first) return false;
				if(it_l->second < it_r->second) return true;
				if(it_l->second > it_r->second) return false;
		
				++it_l;
				++it_r;
			}while(true);
		}
};

class monomial_comp_class {
	public:
		bool operator()(const monomial &l, const monomial &r) const {
			return grevlex()(l, r);
		}
};

#endif
