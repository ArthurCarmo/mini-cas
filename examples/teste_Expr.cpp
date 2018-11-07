#include <mini-cas>
using namespace std;

int main(){
	monomial x('x');
	Expr ex(x);
	Expr e1(x^2);
	Expr e2 = sqrt(sqrt(x));

	cout << e1 << endl;
	cout << e2 << endl;

	cout << e1 + e2 << endl;
	cout << (e1 + e2).pow(x) << endl;
	
	ex = ex.pow(e2 + e1);
	
	cout << ex << endl;
	ex.commute();
	cout << ex << endl;
	
	return 0;
}
