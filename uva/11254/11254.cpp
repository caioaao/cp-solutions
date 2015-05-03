#include <iostream>
#include <cmath>
#define MAX_N 1000000010


using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	ll n, ans, left, right, p;
	cin >> n;
	while(n != -1){
		if(n == 1) cout << "1 = 1 + ... + 1\n";
		else{
			if(n%2 != 0 ) ans = 2;
			else ans = 1;
			p = (1+sqrt(8*n))/2;
			
			while(p > ans){
				left = (2*n-p*(p-1))/(2*p);
				//if(left == 0) { p--; continue; }
				//cout << primes[id] << ' ' << left << ' ';
				if(2*n == (2*left+p-1)*p) {
					ans = p;
					break;
				}
				p--;
			}
			
			cout << n << " = ";
			left = (2*n-ans*(ans-1))/(2*ans);
			right = left+ans-1;
			cout << left << " + ... + " << right << '\n';
		}
		cin >> n;
	}
}
