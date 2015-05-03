#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_V 1010

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int memo[MAX_V][MAX_V];

vector<vi> AdjList;
int V,E;

bool dp(int u, int v){
	if(u == 0) return true;
	if(u == v) return false;
	if(memo[u][v] != -1) return memo[u][v];
	
	memo[u][v] = false;
	
	for(int i = 0; i < (int)AdjList[v].size(); i++){
		memo[u][v] |= dp(min(u, AdjList[v][i]),max(u, AdjList[v][i]));
		if(memo[u][v]) break;
	}
	return memo[u][v];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> V >> E){
		AdjList.assign(V,vi());
		int a, b;
		for(int i = 0; i < E; i++){
			cin >> a >> b;
			if(a > b) swap(a,b);
			a--; b--;
			AdjList[b].push_back(a);
		}
		memset(memo,-1,sizeof memo);
		ll ans = V-1;
		for(int i = 1; i < V; i++){
			for(int j =i+1; j < V; j++){
				ans += dp(i,j);
			}
		}
		cout << ans << '\n';
	}
}
