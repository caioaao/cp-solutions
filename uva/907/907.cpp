#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_N 610
#define MAX_K 310
#define INF 1e7

using namespace std;
typedef long long ll;

ll memo[MAX_N][MAX_K];
ll dist[MAX_N+1], accum[MAX_N+2];
int N, K;

ll dp(int u, int k_left){
	if(u == N + 1) return 0;
	if(memo[u][k_left] != -1) return memo[u][k_left];
	if(k_left == 0) return memo[u][k_left] = accum[N+1] - accum[u];
	memo[u][k_left] = INF;
	
	for(int i = u+1; i <= N + 1; i++){
		//~ cout << u << ' ' << i << ':' << accum[i]-accum[u] << endl;
		memo[u][k_left] = min(memo[u][k_left], max(accum[i]-accum[u],dp(i,k_left-1)));
	}
	
	return memo[u][k_left];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> N >> K){
		memset(memo, -1, sizeof memo);
		accum[0] = 0;
		for(int i = 0; i < N+1; i++){
			cin >> dist[i];
			accum[i+1] = dist[i] + accum[i];
		}
		cout << dp(0,K) << '\n';
	}
}
