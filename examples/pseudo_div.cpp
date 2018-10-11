#include <mini-cas>
using namespace std;

int main(){
	monomial x('x'), y('y');
	polynomial u = 5*x.pow(4)*y.pow(3) + 3*x*y + 2,
		   v = 2*x.pow(3)*y + 2*x + 3;
	
	cout << u.pseudo_division(v, x) << " | " << u.pseudo_division(v, x).r << endl; 
	
	u = x;
	v = x*y + y;
	
	cout << u.pseudo_division(v, x) << " | " << u.pseudo_division(v, x).r << endl;
	return 0;
}
