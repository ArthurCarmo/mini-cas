#include <mini-cas>
using namespace std;

int main(){
	monomial x('x'), y('y'), z('z');
	polynomial p1(x - y), p2(x.pow(3) - y.pow(3));
	
	cout << x / y << endl;
	cout << x / (2*x) << endl;
	cout << p2 / p1 << endl;
	
	cout << g_pow(2 + x, 3) << endl;
	
	return 0;
}