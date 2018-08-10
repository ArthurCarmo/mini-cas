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
		virtual Number & value() = 0;

};

#endif
