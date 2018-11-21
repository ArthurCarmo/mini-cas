#include <mini-cas>
using namespace std;

int main(){

	Expr x(monomial('x'));

	Expr e1 = (x - 2) * (x - 3) * (x - 3) * (x - 2);
	Expr e2 = ((x - 2) * (x - 3)) * (x - 3) * (x - 2);
	Expr e3 = ((x - 2) * (x - 3)) * ((x - 3) * (x - 2));
	
	cout << e1 << endl;
	cout << e2 << endl;
	cout << e3 << endl;

	cerr << "WITH DIV" << endl;
		
	Expr e5 = (x - 2) * (x - 3) / (x - 2);
	Expr e6 = (x - 2) * ((x - 3) / (x - 2)) * (x - 3);
	Expr e7 = (x - 2) / ((x - 3) / (x * (x - 2))) * (x - 3);

	cout << e5 << endl;
	cout << e6 << endl;
	cout << e7 << endl;
	
	return 0;
}
