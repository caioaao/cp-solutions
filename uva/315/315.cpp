#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;
typedef map<int, vi> mvi;

mvi AdjList;
vi dfs_num, dfs_low, dfs_parent, articulationVertex;
int N, n_c, x, dfsNumberCounter, dfsRoot, rootChildren, articulationCount;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(int j = 0; j < (int)AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED){
			dfs_parent[v] = u;
			
			dfs(v);
			
			if(u == dfsRoot) rootChildren++;
			if(dfs_low[v] >= dfs_num[u] && !articulationVertex[u] && u != dfsRoot){
				articulationVertex[u] = true;
				articulationCount++;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main(){
	string s; stringstream ss;
	cin >> N;
	while(N != 0){
		AdjList.clear();
		dfs_num.assign(N+1,UNVISITED);
		dfs_low.assign(N+1,0);
		articulationVertex.assign(N+1,0);
		dfs_parent.assign(N+1,0);
		articulationCount = 0;
		dfsNumberCounter = 1;
		
		cin >> n_c;
		while(n_c != 0){
			getline(cin, s);
			ss.str(s);
			while(ss >> x){
				AdjList[n_c].push_back(x);
				AdjList[x].push_back(n_c);
			}
			ss.clear();
			cin >> n_c;
		}
		
		for(int i = 1; i < N+1; i++){
			if(dfs_num[i] == UNVISITED){
				dfsRoot = i; rootChildren = 0; dfs(i);
				articulationCount += (rootChildren > 1);
			}
		}
		cout << articulationCount << '\n';
		
		cin >> N;
	}
}
