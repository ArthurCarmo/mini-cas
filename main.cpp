#include <symbolib.h>

int main(){
	num_z a, b;
	
	std::cin >> a;
	std::cin >> b;
	
	a + b;
	a - b;
	a * b;

	std::cout << "SUM:\n" << a + b << "\n\n";
	std::cout << "SUB:\n" << a - b << "\n\n";
	std::cout << "MUL:\n" << a * b << "\n\n";

//	std::cout << "a++: " << a++ << "\n\n";
//	std::cout << "++a: " << ++a << "\n\n";
//	std::cout << " -a: " << -a << "\n\n";
	
	num_z d("-1234567890123456789012345");
	num_z e("12345678901234567890123456");
	
	std::cout << "D+E:\n" << d+e << "\n\n";
	
//	polynomial p("x^3-2xy +y^2-2+3y");
	
//	std::cout << (18446744073709551615 == -1) << std::endl;
	
	return 0;
}
