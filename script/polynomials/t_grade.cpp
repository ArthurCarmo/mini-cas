#include "../../src/include/mini-cas"
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
	stringstream out;
	
	monomial x('x'), y('y'), z('z');
	polynomial poly(x^2, y^2, z^2, x*y, x*z, y*z);
	polynomial poly2(num_q(1), x, y, x*y, x*(y^2), (x^2)*y, x^2, y^2, x^3, y^3);
	polynomial poly3(x*(y^2)*z, z^2, x^3, (x^2)*(z^2)); 

	out << poly << "\n";
	out << poly2 << "\n";
	out << poly3 << "\n";

	if(out.str() != "x^2 + x * y + y^2 + x * z + y * z + z^2\nx^3 + x^2 * y + x * y^2 + y^3 + x^2 + x * y + y^2 + x + y + 1\nx * y^2 * z + x^2 * z^2 + x^3 + z^2\n")
		exit(EXIT_FAILURE);
	
	return 0;
}
