#include <symbolib>

int main(){
	num_z a, b;
	num_zm<7> c((uint32_t) 25), d((int32_t)-25);
	num_zm<-7>e((uint64_t)25), f(-25);
	std::cout << c << " " << d << " " << e << " " << f << "\n\n";
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
