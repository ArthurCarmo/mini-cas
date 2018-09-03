#ifndef __MULTIPLIER_H
#define __MULTIPLIER_H

template<class T>
T multiplier(T v) {
	return v;
}

template<class T, class... Args>
T multiplier(T first, Args... args) {
	return first * adder(args...);
}

#endif
