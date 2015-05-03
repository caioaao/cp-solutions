#include <iostream>

using namespace std;

void imprime(int n){
	long long ans = 0;
	for(int x = 1; x < n; x++){
		//~ cout << x << '\n';
		int y = n - x;
		for(int a = 1; a < n; a++){
			for(int b = 1; a*b < x*y; b++){
				//~ cout << x << ' ' << a << endl;
				//~ cout << b << ' ' << y << endl << endl;
				ans++;
			}
		}
	}
	
	cout << "Ans: " << ans << endl;
}

int main(){
		imprime(2500);
}
