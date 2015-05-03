#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> primes;
bitset<1000010> isPrime, segIsPrime;

void sieve(){
	isPrime.set();
	isPrime.reset(0); isPrime.reset(1);
	for(int i = 2; i <= 1000000; i++){
		if(isPrime.test(i)){
			primes.push_back(i);
			for(int j = i*2; j <= 1000000; j+=i) isPrime.reset(j);
		}
	}
}

int main(){
	int T;
	ll L, R;
	
	sieve();
	
	cin >> T;
	while(T--){
		cin >> L >> R;
		segIsPrime.set();
		ll amt = 0;
		for(int i = 0; i < (int)primes.size() && primes[i] <= ceil(sqrt(R)); i++){
			for(ll j = (L/primes[i])*primes[i]; j <= R; j+= primes[i]){
				if(j >= L && j <= R && j != primes[i]) segIsPrime.reset(j-L);
			}
			for(ll j = primes[i], p = 1; j <= R; j*=primes[i], p++){
				if( j >= L && j <= R && p > 1 && isPrime.test(p+1)){
					amt++;
				//	cout << j << ' ';
				}
			}
		}
		for(int i = 0; i <= R-L; i++){
			if(segIsPrime.test(i) && i+L > 1){
				amt++;
			//	cout << i+L << ' ';
			}
		}
		cout << amt << '\n';
	}
}
