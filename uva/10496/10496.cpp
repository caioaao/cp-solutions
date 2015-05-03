#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>

#define MAX_N 15
#define MAX_BM 2048
#define INF 1e9

using namespace std;
typedef pair<int, int> ii;

int dp[MAX_N][MAX_BM], N, bmN;

ii nodes[MAX_N];

int manhattan(ii a, ii b){return abs(a.first-b.first)+abs(a.second-b.second);}

int tsp(int id, int bm){
	if(dp[id][bm] != -1) return dp[id][bm];
	if(bm == bmN) return manhattan(nodes[id],nodes[0]);
	dp[id][bm] = INF;
	for(int i = 1; i < N; i++){
		if((bm & (1<< i)) == 0)
			dp[id][bm] = min(dp[id][bm], manhattan(nodes[i],nodes[id])+tsp(i,bm|(1<<i)));
	}
	return dp[id][bm];
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> nodes[0].first >> nodes[0].second;
		cin >> nodes[0].first >> nodes[0].second;
		
		bmN = 2;
		cin >> N;
		N++;
		for(int i = 1; i < N; i++){
			bmN *= 2;
			cin >> nodes[i].first >> nodes[i].second;
		}
		bmN--;
		memset(dp, -1, sizeof dp);
		cout << "The shortest path has length " << tsp(0,1) << '\n';
	}
}
