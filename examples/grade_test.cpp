#include <mini-cas>
using namespace std;

int main(){
	
	monomial x('x'), y('y'), z('z');
	polynomial p1(x^2, y^2, z^2, x*y, x*z, y*z);
	polynomial p2 = x*(y^2)*z + (z^2) + (x^3) + (x^2)*(z^2);
	
	cout << p1 << endl;
	cout << p2 << endl;

	return 0;
}
