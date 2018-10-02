// Conta os números racionais menores que 1 cujo numerador e denominador somam 1000

#include <mini-cas>
using namespace std;

int main(){
	num_q curr;
	int count = 0;
	
	for(int i = 1; i < 500; i++){
		curr = num_q(i, 1000 - i);
		if(curr.numerator() + curr.denominator() == 1000)
			count++;
	}
	
	cout << count << endl;
	
	return 0;
}
