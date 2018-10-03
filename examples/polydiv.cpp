#include <mini-cas>
using namespace std;

int main(){
	monomial x('x'), y('y'), z('z');
	polynomial p1(x - y), p2(x.pow(3) - y.pow(3));
	
	cout << x / y << endl;
	cout << x / (2*x) << endl;
	cout << p2 / p1 << endl;
	
	cout << g_pow(2 + x, 3) << endl;
	
/*	polynomial u(x.pow(2)*y.pow(2) + x);
	polynomial v(x*y + 1);
	
	polynomial_tuple pt(u / v);
	
	cout << "(" << pt.q << ")(" << v << ") + (" << pt.r << ")" << endl;
*/

	polynomial u(2*x.pow(2)*y + 3*x.pow(2) + 4*x*y + 5*x + 6*y + 7);
	polynomial v(x*y);
	
	polynomial_tuple pt(u / v);
	polynomial_tuple pt2(u.monomial_based_div(v));
	
	
	cout << "(" << pt.q << ")(" << v << ") + (" << pt.r << ")" << endl;
	cout << "(" << pt2.q << ")(" << v << ") + (" << pt2.r << ")" << endl;
	
	return 0;
}
