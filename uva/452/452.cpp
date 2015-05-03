#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <string>

#define INF 1e9

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

bitset<27>visited;
vector<vi> AdjMat;
vector<vii> AdjList;
vi indeg, days, dist;

int dfs(int u){
	if(visited.test(u)) return dist[u];
	visited.set(u);
	int ans = days[u];
	for(int v = 0; v < 27; v++){
		if(v != u && AdjMat[u][v] == 1) ans = max(ans,dfs(v)+days[u]);
	}
	return dist[u] = ans;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	
	stringstream buffer;
	string line;
	int T;
	cin >> T;
	getline(cin, line);
	getline(cin, line);
	bool first = true;
	while(T--){
		if(!first) cout << '\n';
		first = false;
		indeg.assign(27,0);
		days.assign(27,0);
		AdjMat.assign(27, vi(27,INF));
		AdjList.assign(27, vii());
		visited.reset();
		
		char task,task2;
		int w;
		while(1){
			getline(cin, line);
			if(line == "") break;
			buffer.clear(); buffer.str(line);
			buffer >> task >> w;
			days[task-'A'] = w;
			while(buffer >> task2){
				if(AdjMat[task2-'A'][task-'A'] == 1 || task2 == ' ') continue;
				indeg[task-'A']++;
				AdjMat[task2-'A'][task-'A'] = 1;
			}
		}
		
		// toposort
		
		queue <int> q;
		for(int i = 0; i < 27; i++){
			if(indeg[i] == 0) q.push(i);
		}
		vi ts;
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(visited.test(u)) continue;
			visited.set(u);
			ts.push_back(u);
			for(int i = 0; i < 27; i++){
				if(AdjMat[u][i] == 1 && --indeg[i] == 0) q.push(i);
			}
		}
		visited.reset();
		dist.assign(27,0);
		int ans = 0;
		for(int i = 0; i < 27; i++){
			if(!visited.test(ts[i])) ans = max(ans,dfs(ts[i]));
		}
		cout << ans << '\n';
	}
}
