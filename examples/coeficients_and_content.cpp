#include "../src/include/mini-cas"
using namespace std;

int main(){
	monomial x('x'), y('y');
	polynomial p1(num_q(1, 2) * x * y + 6*y);
	polynomial p2(2*x);
	polynomial p3 = -x;
	
	cout << p1.content() << endl;
	cout << p2.content() << endl;
	cout << p3.content() << endl;

	polynomial u = (y.pow(2) + 2*y + 1)*x.pow(2) + (2*y.pow(2) - 2)*x + (3*y + 3);
	
	cout << u.content("x") << endl;	
	cout << u.primitive_part("x") << endl;	
	
	polynomial v = (2*y + 2)*x.pow(2) + (y.pow(2) - 2)*x + 3;
	
	cout << "\nv:\n";
	
	cout << v.lc("x") << endl;
	cout << v.lc("y") << endl;
	cout << v.polynomial_coefficient("x", 2) << endl;
	
	polynomial t = (y.pow(2) + 2*y + 2)*x.pow(2) + (y.pow(2) - 2)*x + 3;
	
	cout << "\nt:\n";

	cout << t.lc("x") << endl;
	cout << t.lc("y") << endl;
	cout << t.polynomial_coefficient("x", 2) << endl;
	cout << t.polynomial_coefficient("x", 0) << endl;
	cout << t.polynomial_coefficient("y", 0) << endl;


	return 0;
}
