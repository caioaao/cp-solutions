#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX_N 100100

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> AdjList, AdjListT;
vi S;
int dfs_num[MAX_N], sccIds[MAX_N], sccIndeg[MAX_N];

void Kosaraju(int u){
	dfs_num[u] = 1;
	for(int j = 0; j < (int) AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == 0)
		Kosaraju(v);
	}
	S.push_back(u);
}
void Kosaraju(int u, int sccId){
	dfs_num[u] = 1;
	sccIds[u] = sccId;
	
	for(int j = 0; j < (int) AdjListT[u].size(); j++){
		int v = AdjListT[u][j];
		if(dfs_num[v] == 0)
		Kosaraju(v,sccId);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int T,n, m, a, b;
	cin >> T;
	while(T--){
		cin >> n >> m;
		if(m == 0 || n == 0){
			cout << n << '\n';
			continue;
		}
		AdjList.assign(n,vi());
		AdjListT.assign(n,vi());
		while(m--){
			cin >> a >> b;
			a--;b--;
			AdjList[a].push_back(b);
			AdjListT[b].push_back(a);
		}
		S.clear();
		memset(dfs_num,0,sizeof dfs_num);
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == 0) Kosaraju(i);
		}
		
		memset(dfs_num,0,sizeof dfs_num);
		for(int i = n - 1; i >= 0; i--){
			if(dfs_num[S[i]] == 0){
				sccIndeg[S[i]] = 0;
				Kosaraju(S[i],S[i]);
			}
		}
		for(int u = 0; u < n; u++){
			for(int j = 0; j < (int)AdjListT[u].size(); j++){
				int v = AdjListT[u][j];
				if(sccIds[u] != sccIds[v]) sccIndeg[sccIds[u]]++;
			}
		}
		int ans = 0;
		for(int u = 0; u < n; u++){
			if(sccIds[u] == u && sccIndeg[u] == 0) ans++;
		}
		cout << ans << '\n';
	}
}
