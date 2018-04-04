#include <stdio.h>
#include <gmp.h>

int main(){

	mpz_t a, b, c;

	mpz_init(a);
	mpz_init(b);
	mpz_init(c);
	
	gmp_scanf("%Zd", a);
	gmp_scanf("%Zd", b);
	
	mpz_add(c, a, b);
	mpz_sub(c, a, b);
	mpz_mul(c, a, b);
	
	mpz_add(c, a, b);
	gmp_printf("SUM:\n%Zd\n", c);
	printf("\n");
	
	mpz_sub(c, a, b);
	gmp_printf("SUB:\n%Zd\n", c);
	printf("\n");
	
	mpz_mul(c, a, b);
	gmp_printf("MUL:\n%Zd\n", c);
	printf("\n");
	
	return 0;
}
