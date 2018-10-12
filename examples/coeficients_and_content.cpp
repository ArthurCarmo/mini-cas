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
	
	cout << "\nu:\n";
	
	cout << u.content("x") << endl;	
	cout << u.primitive_part("x") << endl;	
	cout << u.content(x) << endl;	
	cout << u.content(y) << endl;
	cout << u.lc(x*y) << endl;
	cout << u.polynomial_coefficient(x*y) << endl;
	
	polynomial v = (2*y + 2)*x.pow(2) + (y.pow(2) - 2)*x + 3;
	
	cout << "\nv:\n";
	
	cout << v.lc("x") << endl;
	cout << v.lc("y") << endl;
	cout << v.polynomial_coefficient("x", 2) << endl;
	
	polynomial t = (y.pow(2) + 2*y + 2)*x.pow(2) + (y.pow(2) - 2)*x + 3;
	
	cout << "\nt:\n";

	cout << t.lc("x") << endl; //y^2 + 2y + 2
	cout << t.lc("y") << endl << endl; //x^2 + x
	cout << t.polynomial_coefficient("x", 2) << endl; // y^2 + 2y + 2
	cout << t.polynomial_coefficient("x", 0) << endl; // 3
	cout << t.polynomial_coefficient("y", 0) << endl; // 2x^2 + 2x^2 + xy
	cout << t.polynomial_coefficient(x*y, 0) << endl; // 2x^2y + xy^2 + 2x^2 - 2x + 3
	cout << t.polynomial_coefficient(x*y, 1) << endl; // 1
	cout << t.polynomial_coefficient(x*y, 2) << endl; // 0
	
	cout << "\nIsolar coef\n";
	
	cout << t.polynomial_coefficient(x) << endl; // xy^2 + 2xy + y^2 + 2x - 2
	cout << t.polynomial_coefficient(y) << endl; // x^2y + 2x^2 + xy
	cout << t.polynomial_coefficient(x*y) << endl; // x*y + 2x + y
	
	cout << "\nMonomial deg\nv:\n";
	cout << v.lc(x.pow(2)*y) << endl; //2
	cout << "t:\n" << t.lc(x*y) << endl; //1

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
