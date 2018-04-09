#include <iostream>
#include <gmpxx.h>
using namespace std;

int main(){
	mpz_class a, b;
	
	cin >> a >> b;
	
	cout << "SUM:\n" << a + b << "\n";
	cout << "SUB:\n" << a - b << "\n";
	cout << "MUL:\n" << a * b << "\n";
	
	return 0;
}
