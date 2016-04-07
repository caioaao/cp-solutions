#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

#define MAX_N 2020
#define MAX_K 2020
#define MODP 1000000007

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pii;

ll n, k, memo[MAX_K][MAX_N];

ll dp(ll id, ll last){
	if(id == k) return 1;
	if(memo[id][last] != -1) return memo[id][last];
	
	memo[id][last] = 0;
	
	for(ll x = last; x <= n;x+=last){
		memo[id][last] = (memo[id][last] + dp(id+1, x))%MODP;
	}
	
	return memo[id][last];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n >> k){
		memset(memo, -1, sizeof memo);
		ll ans = 0;
		for(ll i = 1; i <= n; i++){
			ans = (ans+dp(1,i))%MODP;
		}
		cout << ans << &#39;\n&#39;;
	}
}
