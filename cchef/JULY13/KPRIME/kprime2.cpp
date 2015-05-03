#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

#define ll long long int

ll kprimes[100000];
ll first_primes[100000];
ll min_mults[100000];

int next_prime(ll last, ll number){
	ll now = last+1;

	if(first_primes[now] == -1){
		for(int ii = next_prime(last-1,number)+2; ii <= number/2; ii+=2){
			bool found = true;
			int amt = 0;
			
			for(int jj = 2; jj < ii/2; jj+=2){
				if(ii%jj == 0){
					found = false;
					break;
				}
			}
			
			if(found){
				first_primes[now] = ii;
				// cout << "Encontrado primo novo: " << ii << endl;
				return ii;
			}
		}
		bool found = true;
		for(int jj = 2; jj < number/2; jj+=2){
			if(number%jj == 0){
				found = false;
				break;
			}
		}
		if(found){
			return number;	
		}

		return 0;
	}else return first_primes[now];
}

int calc_kprime(ll n){
	ll kprime = 0;
	ll pr_i = 0;
	ll prime = 2;
	ll resto = n;
	bool diff = true;
	while(resto > 1){
		if(resto % prime == 0){
			// if(kprimes[resto] != -1){
			// 	kprimes[n] = kprime+kprimes[resto];
			// 	return kprimes[n];
			// }
			kprime++;
			while(resto % prime == 0){
				resto /= prime;
			}
			// if(kprimes[resto] != -1){
			// 	kprimes[n] = kprime+kprimes[resto];
			// 	return kprimes[n];
			// }
			kprimes[n] = kprime+calc_kprime(resto);
			return kprimes[n];
		}else{
			prime = next_prime(pr_i++, resto);
			// cout << "Primo: " << prime << " do numero " << n << endl;
			if(prime == 0){
				kprimes[n] = 0;
				return 0;
			}
		}
	}
	kprimes[n] = kprime;
	return kprime;
}

bool is_kprime(ll k, ll n){
	if(kprimes[n] == k){
		return true;
	}
	else if(kprimes[n] == -1){
		calc_kprime(n);
		return is_kprime(k,n);
	}
	else return false;
}

int main(){
	int t;
	ll k, a, b;
	memset(kprimes,-1, sizeof(kprimes));
	memset(first_primes,-1, sizeof(first_primes));
	memset(min_mults,-1, sizeof(min_mults));
	first_primes[0] = 2;
	first_primes[1] = 3;
	min_mults[0] = 0;
	min_mults[1] = 2;
	min_mults[2] = 6;
	min_mults[3] = 30;
	min_mults[4] = 210;

	cin >> t;
	
	for(int cte = 0; cte < t; cte++){
		// cin >> a >> b >> k;
		scanf("%lld %lld %lld\n", &a, &b, &k);


		ll min_mult = 2;
		if(min_mults[k] > 0){
			min_mult = min_mults[k];
		}else{
			ll jj = 0;
			for(jj = 0; min_mults[jj] != -1; jj++ );
			min_mult = min_mults[jj-1];
			for(ll ind = jj; ind < k-1; ind++){
				min_mult *= next_prime(ind, b);
			}
			min_mults[k] = min_mult;
		}
		// cout << min_mult << endl << endl;
		
		ll ii = max(a, min_mult);

		ll num = 0;
		for(; ii <= b; ii++){
			if(is_kprime(k,ii)) num++;
			// cout << ii << kprimes[ii] << endl;
		}

		cout << num << endl;
	}
}