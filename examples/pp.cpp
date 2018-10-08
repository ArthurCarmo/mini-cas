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
	
	cout << (p2 / p3).r << endl;
	
	cout << single_var_gcd(p2, p3) << endl;
	
	return 0;
}
