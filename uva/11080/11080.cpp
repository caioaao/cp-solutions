#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>

#define UNVISITED 0
#define VISITED 1
#define MAX_V 201

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

int V, E, dfs_num[MAX_V], cores[MAX_V], whites, blacks;
vector<vi> AdjList;
set<ii> exists;

bool dfs(int id, int c1, int c2){
	if(dfs_num[id] == VISITED){
		if(cores[id] == c2) return false;
		return true;
	}
	if(c1 == 0) whites++;
	else blacks++;
	cores[id] = c1;
	dfs_num[id] = VISITED;
	bool can = true;
	for(vi::iterator it = AdjList[id].begin(); it != AdjList[id].end(); ++it){
		if(!dfs(*it,c2,c1)){
			can = false; break;
		}
	}
	return can;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int T, a, b;
	cin >> T;
	while(T--){
		cin >> V >> E;
		AdjList.assign(V, vi());
		exists.clear();
		memset(dfs_num, UNVISITED, sizeof dfs_num);
		memset(cores, -1, sizeof cores);
		for(int i = 0; i < E; i++){
			cin >> a >> b;
			if(!exists.count(ii(a,b))){
				AdjList[a].push_back(b);
				AdjList[b].push_back(a);
				exists.insert(ii(a,b));
				exists.insert(ii(b,a));
			}
		}
		int ans = 0;
		bool can = true;
		for(int i = 0; i < V; i++){
			whites = 0; blacks = 0;
			if(dfs_num[i] == UNVISITED){
				if(!dfs(i, 0,1)){
					can = false; break;
				}
				ans += max(1,min(whites,blacks));
			}
		}
		if(!can) cout << "-1\n";
		else cout << ans << '\n';
	}
}
