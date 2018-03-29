#include "./classes/bigint/bigint.h"


int main(){
	Int a, b;
	
	std::cin >> a;
	std::cin >> b;
	
	std::cout << "------------MAIN-----------------------\n";
	a + b;
	a - b;
	std::cout << a << " = a\n";
	std::cout << b << " = b\n";
	std::cout << "a + b:\n\t" << a + b << "\n";
	std::cout << "a - b:\n\t" << a - b << "\n";
	std::cout << "a * b:\n\t" << a * b << "\n";
/*	std::cout << "a ^ 12:\n\t" << a.pow((unsigned int)12) << "\n";
	std::cout << "\nEnrolando ... \n";
	for(int i = 0; i < 100000000; i++){
		a = a+b;	
		Int c = a-b;
	} */
	
	
	return 0;
}
