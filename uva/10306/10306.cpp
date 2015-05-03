#include <iostream>
#include <cstring>
#include <map>

#define MAX_M 45
#define INF 1e9
#define MAX_AMT 350

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;


int M, S;
ii coins[MAX_M];
int dp[MAX_AMT][MAX_AMT];

ll emod(int x, int y){
	return x*x+y*y;
}
ll emod(ii p){
	return p.first*p.first+p.second*p.second;
}

int minC(int id, ii sum){
	int mod = emod(sum);
	if(mod == S) return 0;
	if(id == M || mod > S) return INF;
	if(dp[id][mod] != -1) return dp[id][mod];
	int ans = INF;
	ii par(0,0);
	for(int i = 0; emod(par) <= S; i++){
		par.first = sum.first+i*coins[id].first;
		par.second = sum.second+i*coins[id].second;
		ans = min(ans, i+minC(id+1,par));
		
	}
	return dp[id][mod] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc, ans, x, y;
	cin >> tc;
	while(tc--){
		memset(dp,-1,sizeof dp);
		cin >> M >> S;
		S *= S;
		for(int i = 0; i < M; i++){
			cin >> x >> y;
			coins[i] = ii(x,y);
		}
		ans = minC(0,ii(0,0));
		if(ans >= INF) cout << "not possible\n";
		else cout << ans << '\n';
	}
}
