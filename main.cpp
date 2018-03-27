#include "classes/bigint.h"

int main(){
	Int a, b;
	
	std::cin >> a;
	std::cin >> b;
	
	std::cout << "------------MAIN-----------------------\n";
	a + b;
	a - b;
	std::cout << a << " = a\n";
	std::cout << b << " = b\n";
	std::cout << a + b << " = a + b | SUM\n";
	std::cout << a - b << " = a - b | SUB\n";

	std::cout << "\nEnrolando ... \n";
	for(int i = 0; i < 100000000; i++){
		a = a+b;	
		Int c = a-b;
	}
	
	std::cout << a << " = a\n";
	return 0;
}
