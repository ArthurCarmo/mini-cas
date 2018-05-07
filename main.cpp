#include <mini-cas>

int main(){
	num_z a, b;
	num_zm<7> c(25);
	num_zm<-9> d("22");
	
	for(int i = 0; i < 10; i++)
		std::cout << c - i << " " << d - i << std::endl;
	
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
//	std::cout << "DIT:\n" << (a / b).q << "*b + " << (a / b).r << "\n\n";
	std::cout << "MOD:\n" << a % b << "\n\n";
//	std::cout << "MOT:\n" << (a % b).q << "*b + " << (a % b).r << "\n\n";
	
	return 0;
}
