#include <symbolib>

int main(){
	num_z a, b;
	num_zm<7> c("25");
	std::cin >> a;
	std::cin >> b;

	a + b;
	a - b;
	a * b;
	a / b;

	std::cout << "SUM:\n" << a + b << "\n\n";
	std::cout << "SUB:\n" << a - b << "\n\n";
	std::cout << "MUL:\n" << a * b << "\n\n";
	std::cout << "DIV:\n" << a / b << "\n\n";
	std::cout << "MOD:\n" << a % b << "\n\n";
	
	return 0;
}
