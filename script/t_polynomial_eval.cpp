#include "../../src/include/mini-cas"
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
	stringstream out;
	
	monomial x('x'), y('y'), z('z');
	cout << polynomial(x^4, 2*(x^3), -1 * (x^2), x, monomial(num_q(1))).eval(num_q(20)) << endl;
	cout << polynomial(x*y, y.pow(2), y * x.pow(5)).eval("y", num_q(4)) << endl;
		
	cout << polynomial(x*y*z, y.pow(2)*z.pow(7), y * x.pow(5)).eval("y", num_q(1), "z", num_q(2)) << endl;
		
	return 0;
}
