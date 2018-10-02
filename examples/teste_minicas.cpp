#include <mini-cas>
using namespace std;

int main(){
	Number **p;
	num_z b(910);
	num_q c(2, 3);
	
	p = new Number *[2];
	
	p[0] = &b;
	p[1] = &c;
	
	delete []p;
	
	num_z a;
	
	cin >> a;
	
	cout << a.sqrt() << endl;
	
	return 0;
}
