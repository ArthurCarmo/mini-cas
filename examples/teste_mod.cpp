#include <mini-cas>
using namespace std;

int main(){
	
	num_zm a(3), b(-3);

	for(int i = 0; i < 10; i++){
		cout << (a -= 1) << " " << (b += 1) << endl;
	}

	return 0;
}
