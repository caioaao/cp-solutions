#include <iostream>
#include <vector>

#define UNVISITED -1

using namespace std;
typedef vector<int> vi;


int N, M, nSCC, dfsC;
vector<vi> AdjList;
vi dfs_num, dfs_low, visited, S;

void findSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsC++;
	S.push_back(u);
	visited[u] = 1;
	for(int i = 0; i < (int)AdjList[u].size(); i++){
		
		int v = AdjList[u][i];
		if(dfs_num[v] == UNVISITED){
			findSCC(v);
			if(nSCC > 1) return ;
		}
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]){
		nSCC++;
		while(1){
			int v = S.back(); S.pop_back();
			visited[v] = 0;
			if(v == u) break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int a, b, p;
	cin >> N >> M;
	while(N != 0 || M != 0){
		AdjList.assign(N+1,vi());
		
		for(int i = 0; i < M; i++){
			cin >> a >> b >> p;
			AdjList[a].push_back(b);
			if(p == 2) AdjList[b].push_back(a);
		}
		dfsC = nSCC = 0;
		dfs_num.assign(N+1, UNVISITED);
		dfs_low.assign(N+1, 0); visited.assign(N+1, 0);
		S.clear();
		for(int i = 1; i <= N; i++){
			if(dfs_num[i] == UNVISITED){
				findSCC(i);
				if(nSCC > 1) break;
			}
		}
		cout << (nSCC == 1) << '\n';
		cin >> N >> M;
	}
}
