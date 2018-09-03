#ifndef __ADDER_H
#define __ADDER_H

template<class T>
T adder(T v) {
	return v;
}

template<class T, class... Args>
T adder(T first, Args... args) {
	return first + adder(args...);
}

#endif
