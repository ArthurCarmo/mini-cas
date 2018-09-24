#include "../../src/include/mini-cas"
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
	stringstream out;
	
	monomial mono(num_q(2), 'x', 1, "z", 3, 'y', 2);
	monomial unity(num_q(1), 'x', 2, 'y', 4);
	monomial x('x');
	
	out << (mono^num_z(5));
	if(out.str() != "32*x^5*y^10*z^15")
		exit(EXIT_FAILURE);
	
	out.str(string());	
	out << (unity^num_z(20));
	if(out.str() != "x^40*y^80")
		exit(EXIT_FAILURE);
	
	out.str(string());
	out << (x^num_z(1));
	if(out.str() != "x")
		exit(EXIT_FAILURE);
	
	out.str(string());
	x ^= num_z(7);
	out << x;
	if(out.str() != "x^7")
		exit(EXIT_FAILURE);
		
	out.str(string());
	out << num_z(4)*x;
	if(out.str() != "4*x^7")
		exit(EXIT_FAILURE);
		
	return 0;
}
