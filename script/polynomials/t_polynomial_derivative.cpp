#include "../../src/include/mini-cas"
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
	stringstream out;
	
	monomial x('x'), y('y'), z('z');
	
	out << polynomial(x^4, 2*(x^3), -1 * (x^2), x, monomial(num_q(1))).derive();
	if(out.str() != "4*x^3 + 6*x^2 - 2*x + 1")
		exit(EXIT_FAILURE);
	
	out.str(string());
	out << polynomial(x*y, y.pow(2), y * x.pow(5)).derive("y");
	if(out.str() != "x^5 + x + 2*y")
		exit(EXIT_FAILURE);
		
	out.str(string());
	out << polynomial(x*y*z, y.pow(2)*z.pow(7), y * x.pow(5)).derive("y", "z");
	if(out.str() != "14*y*z^6 + x")
		exit(EXIT_FAILURE);
		
	return 0;
}
