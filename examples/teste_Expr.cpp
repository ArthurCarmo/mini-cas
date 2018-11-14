#include <mini-cas>
using namespace std;

int main(){
	monomial x('x'), a('a'), b('b');
	
	Expr ex(x);
	Expr e1(x^2);
	Expr e2 = sqrt(sqrt(x));

	function f("f");

	cout << e1 << endl;
	cout << e2 << endl;

	cout << e1 + e2 << endl;
	cout << (e1 + e2).pow(x) << endl;
	
	ex = ex.pow(e2 + e1);
	
	cout << ex << endl;
	ex.commute();
	cout << ex << endl;
	
	cout << f(a, b) << endl;
	
	Expr p_factor1 = (x - 3);
	Expr p_factor2 = (x - 1);
	
	cout << p_factor1 * p_factor2 << endl;
	
	cout << p_factor1 + 1 << endl;
	cout << 1 + (x + p_factor1) << endl;
	
	
	Expr rational = p_factor1 / p_factor2 * p_factor2;
	cout << rational << endl;
	rational.commute();
	cout << rational << endl;
	
	Expr m1(monomial('x'));
	Expr p1 = (m1.pow(2) + 2*m1 + 4) * (m1 + 2);
	
	cout << p1 << endl;
	
	return 0;
}
