#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, k, m;
ll dp[55][55];

ll eval(int id, int wLeft){
	// cout << id << ',' << wLeft << ',';
	if(wLeft == 0 && id == k) return 1;
	if(wLeft <= 0 || id == k || wLeft < k-id) return 0;
	if(dp[id][wLeft] != -1) return dp[id][wLeft];
	// cout << dp[id][wLeft] << endl;
	dp[id][wLeft] = 0;
	for(int i = 1; i <=m; i++){
		if(i <= wLeft)
			dp[id][wLeft] += eval(id+1, wLeft-i);
	}
	return dp[id][wLeft];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n >> k >> m){
		memset(dp, -1, sizeof dp);
		
		cout << eval(0, n) << '\n';
	}
}
