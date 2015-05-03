#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;
typedef vector<int> vi;

vi visited, rV, dist;
int L, U, R;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> L >>U >>R;
	int caso = 1;
	while(R != 0){
		cout << "Case " << caso++ << ": ";
		visited.assign(10000,0);
		rV.assign(R, 0);
		dist.assign(10000, INF);
		dist[L] = 0;
		for(int i = 0; i < R; i++){
			cin >> rV[i];
		}
		queue<int> q;
		q.push(L);
		bool found = false;
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(visited[u]) continue;
			visited[u] = 1;
			for(int i = 0; i < R; i++){
				int v = (u+rV[i])%10000;
				if(v == U){found = true; dist[v] = min(dist[v],dist[u]+1);}
				if(!visited[v]){
					q.push(v);
					dist[v] = min(dist[v],dist[u]+1);
				}
			}
		}
		if(found) cout << dist[U] << '\n';
		else cout << "Permanently Locked\n";
		cin >> L >>U >>R;
	}
}
