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
	cout << t.lc("y") << endl << endl;
	cout << t.polynomial_coefficient("x", 2) << endl;
	cout << t.polynomial_coefficient("x", 0) << endl;
	cout << t.polynomial_coefficient("y", 0) << endl;
	cout << t.polynomial_coefficient(x*y, 0) << endl;
	cout << t.polynomial_coefficient(x*y, 1) << endl;
	cout << t.polynomial_coefficient(x*y, 2) << endl;
	
	
//	cout << "\nT:\n" << t.
	
	cout << "\nIsolar coef\n";
	
	cout << t.polynomial_coefficient(x) << endl;
	cout << t.polynomial_coefficient(y) << endl;
	cout << t.polynomial_coefficient(x*y) << endl;
	
	cout << "\nMonomial deg\nv:\n" << v.lc(x*y.pow(2)) << "\nt:\n" << t.lc(x*y) << endl;

	monomial m(x.pow(3)*y.pow(2));
	monomial n(x.pow(4)*y.pow(16));
	
	cout << endl;
	
	cout << m.has_var(x*y) << endl;	//NO
	cout << m.has_var(x.pow(3)*y) << endl; //NO
	cout << n.has_var(x*y) << endl;	//NO
	cout << n.has_var(x.pow(2)*y.pow(8)) << endl; //YES
	cout << n.has_var_deg(x.pow(2)*y.pow(8), 1) << endl; //NO
	cout << n.has_var_deg(x.pow(2)*y.pow(8), 2) << endl; //YES
	
	

	return 0;
}
