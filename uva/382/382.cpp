#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	long long n, sum;
	cout << "PERFECTION OUTPUT\n";
	cin >> n;
	while(n != 0){
		sum = !(n == 1);
		for(int i = 2; i <= sqrt(n); i++){
			if(n % i == 0 && n/i != 1 && n/i != n) {
				sum += i;
				if(n > 3 && n/i != i)sum +=(n/i);
			}
		}
		cout << setw(5) << n;
		if(sum == n) cout << "  PERFECT\n";
		else if(sum < n) cout << "  DEFICIENT\n";
		else cout << "  ABUNDANT\n";
		
		
		cin >> n;
	}
	cout << "END OF OUTPUT\n";
}
