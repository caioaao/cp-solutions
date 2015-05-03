#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#define UNVISITED -1

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;


vs nodes; // Transl
map <string, int> nodesId;

int n, m, dfsNumberCounter;
vi dfs_num, dfs_low, visited, S;

vector<vi> AdjList;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for(int j= 0; j < (int)AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]){
		int v; bool first = true;
		while(true){
			if(!first) cout << ", ";
			first = false;
			v = S.back(); S.pop_back(); visited[v] = 0;
			cout << nodes[v];
			if(u == v) break;
		}
		cout << '\n';
	}
}

int main(){
	string s1, s2;
	cin >> n >> m;
	int dataSetNum = 1;
	bool first = true;
	while(n != 0 || m != 0){
		if(not first) cout << '\n';
		first = false;
		nodes.clear(); dfs_num.assign(n, UNVISITED); dfs_low.assign(n,0); visited.assign(n, 0);AdjList.assign(n, vi()); S.clear();
		nodesId.clear();
		dfsNumberCounter = 0;
		int pId = 0;
		for(int i = 0; i < m; i++){
			cin >> s1 >> s2;
			if(!nodesId.count(s1)){
				nodesId[s1] = pId++;
				nodes.push_back(s1);
			}
			if(!nodesId.count(s2)){
				nodesId[s2] = pId++;
				nodes.push_back(s2);
			}
			AdjList[nodesId[s1]].push_back(nodesId[s2]);
		}
		
		cout << "Calling circles for data set " << dataSetNum++ << ":\n";
		
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == UNVISITED)
				tarjanSCC(i);
		}
		
		cin >> n >> m;
	}
}
