#include <mini-cas>
using namespace std;

int main(){
	monomial x('x');
	Expr e1(x^2);
	Expr e2 = sqrt(sqrt(x));

	cout << e1 << endl;
	cout << e2 << endl;
	
	cout << exp(x.pow(2) + 2*x) << endl;

	return 0;
}
