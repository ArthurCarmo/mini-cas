#include <mini-cas>
using namespace std;

int main(){
	monomial x('x'), y('y');
	polynomial u = x*y + y, v = y;
	
	cout << p_gcd(u, v) << endl;
	
	u = x*y.pow(2) + y;
	v = x*y + 1;

	cout << p_gcd(u, v) << endl;
	
	//Nesse caso o gcd de dois números é 1 porque
	//é espicificado que o gcd de polinômios é sempre mônico
	//(coeficiente do termo de maior grau é 1)
	u = 24;
	v = 16;
	
	cout << p_gcd(u, v) << endl;
	
	monomial z('z');
	
	u = (x + y)*(x - y)*(x + z)*(y + z)*(y - z)*(y - z)        ;
	v =                 (x + z)*        (y - z)*        (x - z);

	cout << p_gcd(u, v) << endl;
	
	return 0;
}
