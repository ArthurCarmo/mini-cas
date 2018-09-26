#include "../../src/include/mini-cas"
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){

	stringstream out;
	
	monomial x('x'), y('y'), z('z');
	polynomial p1(x - y), p2(x.pow(3) - y.pow(3));
	out << x / y << "\n";
	out << x / (2*x) << "\n";
	out << p2 / p1 << "\n";
	polynomial p3 = x.pow(3) + y.pow(3);
	out << "(" << (p3 / p1).q << ")*(" << p1 << ") + " << (p3 / p1).r << "\n";
	
	polynomial p4(x^3, num_q(3)*x.pow(2), num_q(3)*x, num_q(1));
	polynomial p5(x, num_q(1));
	
	out << p4 / p5 << "\n";
	
	out << polynomial() / p5 << "\n";
	out << polynomial() / polynomial(monomial(num_q(4))) << "\n";
	
	p4 /= p5;
	out << p4 << "\n";
	
	p5 /= p4;
	out << p5 << "\n";
	
	if(out.str() != "0\n1/2\nx^2 + x*y + y^2\n(x^2 + x*y + y^2)*(x - y) + 2*y^3\nx^2 + 2*x + 1\n0\n0\nx^2 + 2*x + 1\n0\n")
		exit(EXIT_FAILURE);

	return 0;
}
