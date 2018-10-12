#include <mini-cas>
using namespace std;

int main(){
	monomial x('x'), y('y');
	polynomial u = 4*x*y + 4*y, v = 2*y;
	
	cout << p_gcd(u, v) << endl;
	cout << p_gcd(u, v, NOT_UNIT) << endl << endl;
	
	u = x*y.pow(2) + y;
	v = x*y + 1;

	cout << p_gcd(u, v) << endl;
	cout << p_gcd(u, v, NOT_UNIT) << endl << endl;

	u = 24;
	v = 16;

	cout << p_gcd(u, v) << endl;
	cout << p_gcd(u, v, NOT_UNIT) << endl << endl;
	
	monomial z('z');
	
	u = (x + y)*(x - y)*(x + z)*(y + z)*(y - z)*(y - z)        ;
	v =                 (x + z)*        (y - z)*        (x - z);

	cout << p_gcd(u, v) << endl;
	cout << p_gcd(u, v, NOT_UNIT) << endl << endl;
	
	u = 4*x.pow(4) - 4;
	v = 2*x.pow(2) + 2;

	cout << p_gcd(u, v) << endl;
	cout << p_gcd(u, v, NOT_UNIT) << endl << endl;

	u = x.pow(4) + 1;
	v = x.pow(2) - 1;

	cout << p_gcd(u, v) << endl;
	cout << p_gcd(u, v, NOT_UNIT) << endl << endl;
	
	return 0;
}
