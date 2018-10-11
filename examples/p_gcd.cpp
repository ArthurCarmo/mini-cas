#include <mini-cas>
using namespace std;

int main(){
	monomial x('x'), y('y');
	polynomial u = x*y + y, v = y;
	
	cout << p_gcd(u, v) << endl;
	
	u = x*y.pow(2) + y;
	v = x*y + 1;
	
	cout << u / v << endl;
	
	cout << p_gcd(u, v) << endl;
	
	return 0;
}
