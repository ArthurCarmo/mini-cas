#include <mini-cas.h>

int main(){
	num_z a, b;
	num_zm<7> c(25);
	num_zm<-9> d("22");
	num_z e("0xff");
	num_z f("0b1110");
	
	std::cout << e << " " << f << " " << (num_z(255) == num_z("0b11111111")) << "\n\n";

	std::cin >> a;
	std::cin >> b;

	a + b;
	a - b;
	a * b;
	a / b;
	std::cout << "BIN:\n" << bin(a) << "\n\n";
	std::cout << "HEX:\n" << hex(a) << "\n\n";
	std::cout << "SUM:\n" << a + b << "\n\n";
	std::cout << "SUB:\n" << a - b << "\n\n";
	std::cout << "MUL:\n" << a * b << "\n\n";
	std::cout << "DIV:\n" << a / b << "\n\n";
//	std::cout << "DIT:\n" << (a / b).q << "*b + " << (a / b).r << "\n\n";
	std::cout << "MOD:\n" << a % b << "\n\n";
//	std::cout << "MOT:\n" << (a % b).q << "*b + " << (a % b).r << "\n\n";
	
	return 0;
}
