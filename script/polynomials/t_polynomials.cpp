#include "../../src/include/mini-cas"
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
	stringstream out;
	monomial mono(num_q(159, 1383), 'x', 1, 'y', 2, 'z', 3);
	monomial unity(num_q(1), 'x', 2, 'y', 4);
	monomial x('x');
	
	polynomial poly1(x, unity, mono, x, monomial('x', 2)), poly2(monomial(num_q(-2), 'x', 1), unity);

	out.str(string());
	out << poly1;
	if(out.str() != "x^2*y^4 + 53/461*x*y^2*z^3 + x^2 + 2*x")
		exit(EXIT_FAILURE);

	out.str(string());
	out << poly2;
	if(out.str() != "x^2*y^4 - 2*x")
		exit(EXIT_FAILURE);
	
	out.str(string());
	out << poly1 + poly2;
	if(out.str() != "2*x^2*y^4 + 53/461*x*y^2*z^3 + x^2")
		exit(EXIT_FAILURE);

	poly1 += polynomial(monomial(num_q(-318, 1383), 'x', 1, 'y', 2, 'z', 3), monomial(num_q(-2), 'x', 1), monomial(num_q(-1), 'x', 2), monomial(num_q(-1), 'x', 2, 'y', 4));
	
	out.str(string());
	out << poly1;
	if(out.str() != "-53/461*x*y^2*z^3")
		exit(EXIT_FAILURE);
	
	polynomial poly3(x^3, x, x^2, monomial(num_q(2), 'x', 4));
	
	out.str(string());
	out << poly3;
	
	if(out.str() != "2*x^4 + x^3 + x^2 + x")
		exit(EXIT_FAILURE);
		
	out.str(string());
	out << poly3 - poly3;
	
	if(out.str() != "0")
		exit(EXIT_FAILURE);
	
	out.str(string());
	out << poly3 * poly3;
	if(out.str() != "4*x^8 + 4*x^7 + 5*x^6 + 6*x^5 + 3*x^4 + 2*x^3 + x^2")
		exit(EXIT_FAILURE);
	
	return 0;
}
