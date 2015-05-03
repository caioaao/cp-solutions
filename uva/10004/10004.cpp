#include <iostream>
#include <vector>
#include <map>

#define UNVISITED 0
#define VISITED 1
#define EXPLORED 2

using namespace std;

typedef vector<int> vi;
typedef map<int, vi> mvi;

mvi AdjList;
vi color, NodeStat;

bool dfs(int node, int c){
	if(NodeStat[node] == VISITED) {
		if(color[node] != c) return false;
		return true;
	}
	NodeStat[node] = VISITED;
	color[node] = c;
	for(vi::iterator it = AdjList[node].begin(); it != AdjList[node].end(); ++it){
		if(!dfs(*it, !c)) return false;
	}
	return true;
}

int main(){
	int n, l, a, b;

	cin >> n;
	while(n != 0){
		cin >> l;
		AdjList.clear();
		color.assign(n,-1); NodeStat.assign(n,UNVISITED);
		
		for(int i = 0; i < l; i++){
			cin >> a >> b;
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		bool bipartite = true;
		for(int i = 0; i < n; i++){
			if(NodeStat[i] == UNVISITED)
				if(!dfs(i,0)){
					bipartite = false;
					break;
				}
		}
		if(!bipartite) cout << "NOT ";
		cout << "BICOLORABLE.\n";
		
		cin >> n;
	}
}
