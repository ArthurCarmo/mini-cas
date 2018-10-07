#include <mini-cas>
using namespace std;

int main(){
	monomial x('x'), y('y');
	polynomial p(x^2, -(y^2));

	cout << p << endl;	
	cout << p.eval("x", x.pow(2) + y.pow(0)) << endl;
	
	cout << x.eval("x", x.pow(2) + 2*x + y.pow(2), "y", x.pow(2) + 4*x + y) << endl;
	cout << p.ref_eval("x", (2*x + 4 + 8*y)) << endl;

	return 0;
}
