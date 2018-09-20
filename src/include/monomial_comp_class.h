#ifndef __MONOMIAL_COMP_CLASS_H_
#define __MONOMIAL_COMP_CLASS_H_

#include "monomial.h"

class monomial_comp_class{
	private:
	
		bool glex(const monomial &l, const monomial &r) const { 
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
		
		bool grevlex(const monomial &l, const monomial &r) const { 
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

		bool plex(const monomial &l, const monomial &r) const { 
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

		bool lexdeg(const monomial &l, const monomial &r) const {
			/*
				TO DO
			*/
			return true;
		}

	public:
		bool operator()(const monomial &l, const monomial &r) const { 
			return grevlex(l, r);
		}
};

#endif
