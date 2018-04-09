#include "./classes/num_z/num_z.h"


int main(){
	Int a, b;
	
	std::cin >> a;
	std::cin >> b;
	
	a + b;
	a - b;
	a * b;
	
	std::cout << "SUM:\n" << a + b << "\n\n";
	std::cout << "SUB:\n" << a - b << "\n\n";
	std::cout << "MUL:\n" << a * b << "\n\n";
	
	Int d("-1234567890123456789012345");
	Int e("12345678901234567890123456");
	std::cout << "D+E:\n" << d+e << "\n\n";
	
	return 0;
}
