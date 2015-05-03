#include <iostream>
#include <cstring>
#include <algorithm>
#include <bitset>

#define MAX_N 2510
#define MAX_M 1563000

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
bitset<MAX_M> isPrime;

ll mults[MAX_M], multsAcc[MAX_M];

ll sqp(ll a, ll b){
	ll ans = 0;
	while(a % b == 0) a/=b, ans++;
	return ans;
}

void calc(){
	isPrime.set();
	memset(mults, 0, sizeof mults);
	mults[0] = 0;
	mults[1] = 1;
	for(ll i = 2; i < MAX_M; i++){
		if(isPrime[i]){
			mults[i] = 2;
			for(ll j = i+i; j < MAX_M; j+=i){
				isPrime.reset(j);
				if(mults[j] == 0) mults[j] = 1;
				mults[j] *= sqp(j,i)+1;
			}
		}
	}
	//~ for(ll i = 3;  i < 10; i++) cout << i << ':' << mults[i] << endl;
	//~ cout << mults[12] << endl;
	multsAcc[0] = 0;
	for(ll i = 1; i < MAX_M; i++){
		multsAcc[i] = mults[i]+multsAcc[i-1];
		//~ cout << i << ':' << mults[i] << ' ' << multsAcc[i] << endl;
	}
	//~ cout << ind << endl;
}



int main(){
	ios_base::sync_with_stdio(false);
	
	ll T, n;
	cin >> T;
	
	//~ sieve();
	calc();
	//~ for(int i = 3; i < 10; i++)
		//~ cout << "Ate " << i << ':' << multsAcc[i] << endl;
	
	//~ cout << endl << endl;
	
	while(T--){
		cin >> n;
		ll ans = 0;
		ll y;
		for(ll x = 1; x < n; x++){
			//~ cout << i << 'x' << n-i   << '=' << i*(n-i)<< endl;
			//~ cout << multsAcc[i*(n-i) - 2] << endl << endl;
			y = n-x;
			ans += multsAcc[x*y - 1];
			//~ cout << i*(n-i) - 1 << ':' << ans << endl;
		}
		cout << ans << '\n';
	}
}
