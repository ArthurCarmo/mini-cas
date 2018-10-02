#include <mini-cas>
using namespace std;

int main(){
	
	monomial mono(num_q(159, 1383), 'x', 1, 'y', 2, 'z', 3);
	monomial unity(num_q(1), 'x', 2, 'y', 4);
	monomial x('x');
	
	polynomial poly1(x, unity, mono, x, monomial('x', 2)), poly2(monomial(num_q(-2), 'x', 1), unity);

	cout << poly1 << endl;
	cout << poly2 << endl << endl;
	
	cout << poly1 + poly2 << endl;

	poly1 += polynomial(monomial(num_q(-318, 1383), 'x', 1, 'y', 2, 'z', 3), monomial(num_q(-2), 'x', 1), monomial(num_q(-1), 'x', 2), monomial(num_q(-1), 'x', 2, 'y', 4));
	
	cout << poly1 << endl;
	
	cout << endl;
	
	cout << g_min(num_q(3, 7), num_q(20, 44)) << endl;
	cout << g_max(num_q(3, 7), num_q(20, 44)) << endl;
	
	cout << m_gcd(x, unity) << endl;
	cout << m_gcd(x, monomial('y')) << endl;
	
	return 0;
}
