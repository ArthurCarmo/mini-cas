#include "../../src/include/mini-cas"
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
	stringstream out;
	
	monomial x('x'), y('y'), z('z');
	
	out << polynomial(x^4, 2*(x^3), -1 * (x^2), x, monomial(num_q(1))).eval(num_q(20));
	if(out.str() != "175621")
		exit(EXIT_FAILURE);
	
	out.str(string());
	out << polynomial(x*y, y.pow(2), y * x.pow(5)).eval("y", num_q(4));
	if(out.str() != "4*x^5 + 4*x + 16")
		exit(EXIT_FAILURE);
		
	out.str(string());
	out << polynomial(x*y*z, y.pow(2)*z.pow(7), y * x.pow(5)).eval("y", num_q(1), "z", num_q(2));
	if(out.str() != "x^5 + 2*x + 128")
		exit(EXIT_FAILURE);
		
	return 0;
}
