#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_N 100000

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

int servers[MAX_N], N, dfsRoot, dfsNC;
map<int,vi> AdjList;
map<int, int> dfs_num, dfs_low, dfs_parent;
vector<ii> critical_links;

void findB(int u){
	dfs_num[u] = dfs_low[u] = dfsNC++;
	for(int j = 0; j < (int) AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
			
			findB(v);
			if(dfs_low[v] > dfs_num[u]) critical_links.push_back(ii(min(u,v),max(u,v)));
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main(){
	int dc;
	char parent;
	ios_base::sync_with_stdio(false);
	
	while(cin >> N){
		AdjList.clear();
		for(int i = 0; i < N; i++){
			cin >> servers[i];
			dfs_num[servers[i]] = -1;
			cin >> parent >> dc >> parent;
			
			AdjList[servers[i]].assign(dc,0);
			for(int j = 0; j < dc; j++) cin >> AdjList[servers[i]][j];
		}
		dfsNC = 0;
		critical_links.clear();
		for(int i = 0; i < N; i++){
			if(dfs_num[servers[i]] == -1){
				dfsRoot = servers[i];
				findB(servers[i]);
			}
		}
		sort(critical_links.begin(), critical_links.end());
		cout << critical_links.size() << " critical links\n";
		for(vector<ii>::iterator it = critical_links.begin(); it != critical_links.end(); ++it){
			cout << it->first << " - " << it->second << '\n';
		}
		cout << '\n';
	}
}
