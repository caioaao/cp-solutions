#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAX_N 100510
#define MAX_M 110
#define MODP 1000000009

using namespace std;
typedef long long ll;

ll n, q, m;

ll nums[MAX_N];

ll pot(ll a, ll b, ll MOD) {
	ll x = 1, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD;
		b /= 2;
	}
	return x;
}

ll solve(){
	ll resps[2][MAX_M*2];
	memset(resps,0,sizeof resps);
	resps[0][m] = 1;
	ll nV;
	int curr = 1;
	ll zeros = 0;
	for(ll i = 0; i < n; i++){
		if(nums[i]%m == 0){
			zeros++;
			continue;
		}
		for(ll j = -m+1; j < m; j++){
			nV = (j+nums[i])%m;
			resps[curr][j+m] = (resps[curr][j+m] + resps[!curr][j+m] )%MODP;
			resps[curr][nV+m]  = (resps[curr][nV+m] + resps[!curr][j+m] )%MODP;
		}
		curr = !curr;
		memset(resps[curr],0,sizeof resps[curr]);
	}
	//~ cout << "Zeros: " << zeros << ':' << pot(2,zeros,MODP) << endl;
	return (pot(2,zeros,MODP)*resps[!curr][m])%MODP;
	//~ return resps[!curr][m];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int T;
	
	cin >> T;
	
	while(T--){
		cin >> n >> q;

		for(int i = 0; i < n; i++)
			cin >> nums[i];

		while(q--){
			cin >> m;
			
			cout << solve() << '\n';
		}
	}
}
