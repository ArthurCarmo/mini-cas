#ifndef __NUMBER_CLASS_
#define __NUMBER_CLASS_

#include "signatures.h"

class Number{
	
	friend std::ostream & operator<<(std::ostream &o, const Number &a){
		return a.display();
	}

	private:
		virtual std::ostream & display() const = 0;

	public:
		virtual Number & value() = 0;

};

#endif
