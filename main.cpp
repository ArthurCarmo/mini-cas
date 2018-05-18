#include <mini-cas.h>

int main(){
	num_z a, b;
	num_zm<7> c(25);
	num_zm<-9> d("22");
	
	num_z e("0xff");
	num_z f("0b1110");

	num_zm<-11> g(-23);
	num_zm<23> h("99");
	
//	std::cout << e << " " << f << " " << (num_z(255) == num_z("0b11111111")) << "\n\n";

//	for(int i = 0; i < 10; ++i)
//		std::cout << (c += 1) << " " << (d += 1) << " " << (h *= 2) << " " << (g *= 2) << std::endl;


	std::cin >> a;
	std::cin >> b;

	a + b;
	a - b;
	a * b;
	a / b;
	
//	std::cout << "BIN:\n" << bin(a) << "\n\n";
//	std::cout << "HEX:\n" << hex(a) << "\n\n";
	std::cout << "SUM:\n" << a + b << "\n\n";
	std::cout << "SUB:\n" << a - b << "\n\n";
	std::cout << "MUL:\n" << a * b << "\n\n";
	std::cout << "DIV:\n" << a / b << "\n\n";
//	std::cout << "DIT:\n" << (a / b).q << "*b + " << (a / b).r << "\n\n";
	std::cout << "MOD:\n" << a % b << "\n\n";
//	std::cout << "MOT:\n" << (a % b).q << "*b + " << (a % b).r << "\n\n";
	std::cout << "GCD:\n" << z_gcd(a, b) << "\n\n";

	return 0;
}
