#include <mini-cas>
using namespace std;

int main(){
	num_q candidates[6] = { num_q(1), num_q(-1), num_q(1, 7), num_q(-1, 7), num_q(7), num_q(-7) };

	monomial x('x');
	polynomial mt = x.pow(3) - 8*x.pow(2) + 5*x + 7;
	
	cout << "mt := " << mt << endl;
	cout << endl;
	for(int i = 0; i < 6; i++)
		cout << "mt(" << candidates[i] << ") = " << mt.eval(candidates[i]) << endl;

	return 0;
}
