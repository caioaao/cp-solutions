#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int V;
vector<vi> AdjList;
vi dailyBoom, visited;


int main(){
	ios_base::sync_with_stdio(false);
	
	cin >>V;
	AdjList.assign(V, vi());
	int N;
	for(int i = 0; i < V; i++){
		cin >> N;
		AdjList[i].assign(N,0);
		for(int j = 0; j < N; j++){
			cin >> AdjList[i][j];
		}
	}
	
	int Q, v0;
	cin >> Q;
	while(Q--){
		dailyBoom.assign(V,0); visited.assign(V,-1);
		cin >> v0;
		if(AdjList[v0].size() == 0){
			cout << "0\n";
			continue;
		}
		
		queue<ii> q;
		q.push(ii(v0,0));
		int ans = 0, fb;
		while(!q.empty()){
			ii u = q.front(); q.pop();
			if(visited[u.first] == 1) continue;
			visited[u.first] = 1;
			if(u.second > 0 && (++dailyBoom[u.second] > ans || (dailyBoom[u.second] == ans && fb > u.second))) ans = dailyBoom[u.second], fb = u.second;
			for(int i = 0; i < (int)AdjList[u.first].size(); i++){
				int v = AdjList[u.first][i];
				q.push(ii(v,(u.second+1)));
			}
		}
		cout << ans << ' ' << fb << '\n';
	}
}
