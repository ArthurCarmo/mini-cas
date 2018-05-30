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
	int64_t q, q2, u, v, A, B, C, D, T;
	num_z w, z;
	div_tuple t;
	
	while(b._blocks ^ 1){
		A = D = 1;
		B = C = 0;
		u = a._num[a._blocks - 1];
		v = (b._blocks < a._blocks)?0:b._num[a._blocks - 1];

		while(1){
			if((v + C) == 0 || (v + D) == 0) break;
			
			q  = (u+A) / (v+C); //floor((u+A) / (v+C))(?)
			q2 = (u+B) / (v+D); //floor((u+B) / (v+D))(?)
			
			if(q != q2) break;
			
			T = A - q*C;
			A = C;
			C = T;
			T = B - q*D;
			B = D;
			D = T;
			T = u - q*v;
			u = v;
			v = T;
		}
		if(B){
			w = a*A + b*B;
			z = a*C + b*D;
			a = w;
			b = z;
		}else{
			t = (a / b);
			a = b;
			b = t.r;	
		}
	}
	return __num_z_gcd_single(a, b._num[0]); //GCD para precisão simples
}

num_z z_gcd(const num_z &a, const num_z &b){
	num_z m(a), n(b);
	m._sign = n._sign = 0;
	if(m.abs_geq(n))
		return (n._blocks == 1)?__num_z_gcd_single(m, n._num[0]):num_z(__num_z_gcd(m, n));
	return (m._blocks == 1)?__num_z_gcd_single(n, m._num[0]):num_z(__num_z_gcd(n, m));
}

num_z z_gcd(const num_z &a, uint64_t &b){
	return num_z(z_gcd(a, num_z(b)));
}

num_z z_gcd(const uint64_t &a, const num_z &b){
	return num_z(z_gcd(a, num_z(b)));
}
