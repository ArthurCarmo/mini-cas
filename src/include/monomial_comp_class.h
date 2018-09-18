#ifndef __MONOMIAL_COMP_CLASS_H_
#define __MONOMIAL_COMP_CLASS_H_

#include "monomial.h"

class monomial_comp_class{
	public:
		bool operator()(const monomial &l, const monomial &r) { 
			std::map<std::string, num_z>::const_iterator it_l = l._literals.begin();
			std::map<std::string, num_z>::const_iterator it_r = r._literals.begin();
			if(l._degree > r._degree) return true;
			if(l._degree < r._degree) return false;
				
			do{
				if(it_r == r._literals.end()) return false;
				if(it_l == l._literals.end()) return true;
				if(it_l->first < it_r->first) return true;
				if(it_l->first > it_r->first) return false;
				if(it_l->second > it_r->second) return true;
				if(it_l->second < it_r->second) return false;
				++it_l;
				++it_r;
			}while(true);
		}
};

#endif
