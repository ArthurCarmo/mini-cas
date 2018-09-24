#include "../../src/include/mini-cas"
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){
	stringstream out;
	
	monomial mono(num_q(159, 1383), 'x', 1, "z", 3, 'y', 2);
	monomial unity(num_q(1), 'x', 2, 'y', 4);
	monomial x('x');
	
	out << mono;
	if(out.str() != "53/461*x*y^2*z^3")
		exit(EXIT_FAILURE);
	
	out.str(string());	
	out << unity;
	if(out.str() != "x^2*y^4")
		exit(EXIT_FAILURE);
	
	out.str(string());
	out << x;
	if(out.str() != "x")
		exit(EXIT_FAILURE);
	
	out.str(string());
	out << x * mono;
	if(out.str() != "53/461*x^2*y^2*z^3")
		exit(EXIT_FAILURE);
	
	unity *= mono;
	
	out.str(string());	
	out << unity * num_q(461, 53);
	if(out.str() != "x^3*y^6*z^3")
		exit(EXIT_FAILURE);
	
	out.str(string());
	out << mono.derive();
	if(out.str() != "53/461*y^2*z^3")
		exit(EXIT_FAILURE);
	
	out.str(string());	
	out << mono;
	if(out.str() != "53/461*x*y^2*z^3")
		exit(EXIT_FAILURE);
	
	out.str(string());	
	out << mono.derive("y", 'z');
	if(out.str() != "318/461*x*y*z^2")
		exit(EXIT_FAILURE);
	
	out.str(string());	
	out << x.derive();  
	if(out.str() != "1")
		exit(EXIT_FAILURE);
		
	return 0;
}
