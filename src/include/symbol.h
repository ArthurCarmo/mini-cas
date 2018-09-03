#ifndef __SYMBOL_H_
#define __SYMBOL_H_

#include "num_q.h"
#include <string>

class symbol {

	private:
		std::string _value;
		num_q _product;
		num_q _sum;
		
	public:
		symbol(const char *name) {
			this->_value.assign(name);
			this->_sum = 0;
			this->_product = 1;
		};
};

#endif
