#include "../include/num_z.h"

num_z __num_z_gcd_single(num_z &a, uint32_t b){
	div_tuple res(a / b);
	uint32_t n = res.r._num[0];
	uint32_t gcd = b;
	b = n;
	while(b != 0){
		n = gcd % b;
		gcd = b;
		b = n;
	}
	return num_z(gcd);
}

num_z __num_z_gcd(num_z &a, num_z &b){
	div_tuple res(a / b);
	while(b != 0){
		if(b < _BASE_) __num_z_gcd_single(a, b._num[0]);
		a = b;
		b = res.r;
		res = a / b;
	}
	return a;
}

num_z z_gcd(const num_z &a, const num_z &b){
	num_z m(a), n(b);
	m._sign = n._sign = 0;
	if(m.abs_geq(n))
		return (n < _BASE_)?__num_z_gcd_single(m, n._num[0]):num_z(__num_z_gcd(m, n));
	return (m < _BASE_)?__num_z_gcd_single(n, m._num[0]):num_z(__num_z_gcd(n, m));
}

num_z z_gcd(const num_z &a, uint64_t &b){
	return num_z(z_gcd(a, num_z(b)));
}

num_z z_gcd(const uint64_t &a, const num_z &b){
	return num_z(z_gcd(a, num_z(b)));
}
