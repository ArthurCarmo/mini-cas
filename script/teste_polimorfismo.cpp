#include<mini-cas>
using namespace std;

int main(){
	Number **my_vector = new Number * [3];

	my_vector[0] = new num_z("18446744073709551616");
	my_vector[1] = new num_zm<7>(24);
	my_vector[2] = new num_q(2, 6);

	for(int i = 0; i < 3; i++)
		cout << my_vector[i]->value() << endl;

	cout << my_vector[2]->q_value() + my_vector[1]->z_value() << endl;

	num_z a("102919310"), b(310419);
	a = b;

	a = b + a;
	a = a + b; 

	cout << a << endl;
	
	for(int i = 0; i < 3; i++)
		delete my_vector[i];
	delete[] my_vector;

	return 0;
}
