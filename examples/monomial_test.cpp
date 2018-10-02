#include <mini-cas>
using namespace std;

int main(){
	
	monomial mono(num_q(159, 1383), 'x', 1, "z", 3, 'y', 2);
	monomial unity(num_q(1), 'x', 2, 'y', 4);
	monomial x('x');
	
	cout << mono << endl;
	cout << unity << endl;
	cout << x << endl;
	
	cout << endl << "MUL:\n";
	cout << x * mono << endl;
	
	unity *= mono;
	
	cout << unity * num_q(461, 53) << endl;
	
	cout << endl << "Derive\n";
	cout << mono.derive() << endl;
	cout << mono << endl;
	cout << mono.derive('y', "z") << endl;
	
	cout << x.derive() << endl;
		
	return 0;
}
