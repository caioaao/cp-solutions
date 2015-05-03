#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef vector<int> vi;

vi memo, dfs_num, dfs_low,  cyc;
int amtC, dfsNC;
stack<int> S;
vi AdjList(50000);

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNC++;
	S.push(u);
	int v = AdjList[u];
	if(dfs_num[v] == -1)
		tarjanSCC(v);
	dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	
	if(dfs_low[u] == dfs_num[u]){
		amtC = 0;
		while(1){
			v = S.top(); S.pop();
			cyc[amtC++] = v;
			if(u == v) break;
		}
		if(amtC > 1){
			for(int i = 0; i < amtC; i++){
				memo[cyc[i]] = amtC;
			}
		}
	}
}

int dp(int u){
	if(memo[u] != -1) return memo[u];
	return (memo[u] = dp(AdjList[u])+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int t, n, ans, u, v;
	cin >> t;
	for(int caso = 1; caso <=t; caso++){
		cout << "Case " << caso << ": ";
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> u >> v;
			AdjList[u-1] = v-1;
		}
		memo.assign(n,-1);
		dfs_num.assign(n,-1);
		dfs_low.assign(n,0);
		cyc.assign(n,0);
		dfsNC = 0;
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == -1)
				tarjanSCC(i);
		}
		ans = 0;
		//~ for(int i = 0; i < n; i++) cout << memo[i] << ' ';
		//~ cout << endl;
		for(int i = 1; i < n; i++) ans = (dp(ans) < dp(i) ? i : ans);
		cout << ans + 1 << '\n';
	}
}
