#include <iostream>
#include <cstring>
#define MAX_V 30010

using namespace std;
typedef long long ll;

int coins[5] = {1,5,10,25,50};
ll dp[6][MAX_V];

ll N;

ll knap(int id, ll val){
	if(dp[id][val] != -1) return dp[id][val];
	if(val == 0) return 1;
	if(id == 5) return 0;
	ll ans = 0, dummy;
	for(int i = 0; i*coins[id] <= val; i++){
		dummy = knap(id+1,val-i*coins[id]);
		if(dummy > 0) ans+= dummy;
	}
	return dp[id][val] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	while(cin >> N){
		memset(dp, -1, sizeof dp);
		ll ans = knap(0,N); 
		if(ans == 1) cout << "There is only 1 way to produce " << N << " cents change.\n";
		else cout << "There are " << ans << " ways to produce " << N << " cents change.\n";
	}
	
}
