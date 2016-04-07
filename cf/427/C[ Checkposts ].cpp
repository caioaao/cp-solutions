#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef vector<int> vi;

vector<vi> AdjList;
vector<ll> costs;
vi dfs_num, dfs_low, S, visited;
ll n, m, dfsNC, nSCC;
ll ans, ans2;
void dfs2(int u){
	dfs_low[u] = dfs_num[u] = dfsNC++;
	S.push_back(u);
	visited[u] = 1;
	
	for(int j = 0; j < (int)AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == -1)
			dfs2(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_low[u] == dfs_num[u]){
		ll minN = 1e10, amtV = 0;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			if(costs[v] < minN){
				amtV = 1;
				minN = costs[v];
			}
			else if(costs[v] == minN){
				amtV++;
			}
			if(u == v) break;
		}
		ans = (ans + minN);
		ans2 = (ans2*amtV)%MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n){
		AdjList.assign(n,vi());
		costs.assign(n,0);
		
		for(int i = 0; i < n; i++){
			cin >> costs[i];
			costs[i];
		}
		int a, b;
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			a--;b--;
			
			AdjList[a].push_back(b);
		}
		
		dfs_num.assign(n,-1);
		dfs_low.assign(n,0); visited.assign(n,0);
		ans = dfsNC = nSCC = 0;
		ans2 = 1;
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == -1){
				dfs2(i);
			}
		}
		cout << ans << &#39; &#39; << ans2 << &#39;\n&#39;;
	}
}
