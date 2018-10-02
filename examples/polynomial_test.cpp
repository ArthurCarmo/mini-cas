#include <mini-cas>
using namespace std;

int main(){
	
	monomial mono(num_q(159, 1383), 'x', 1, 'y', 2, 'z', 3);
	monomial unity(num_q(1), 'x', 2, 'y', 4);
	monomial x('x');
	
	polynomial poly1(x, unity, mono, x, monomial('x', 2));
	polynomial poly2 = monomial(num_q(-2), 'x', 1) + unity;

	cout << poly1 << endl;
	cout << poly2 << endl << endl;
	
	cout << poly1 + poly2 << endl;
	
	poly1 += polynomial(monomial(num_q(-318, 1383), 'x', 1, 'y', 2, 'z', 3), monomial(num_q(-2), 'x', 1), monomial(num_q(-1), 'x', 2), monomial(num_q(-1), 'x', 2, 'y', 4));
	
	cout << poly1 << endl;
	cout << poly1.derive("z", "y") << endl;
	cout << poly1 + x << endl;
	cout << x + unity + poly1 << endl;
	
	return 0;
}
