#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define INF 1e9

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;

int V, exit, threshold, E;

int main(){
	ios_base::sync_with_stdio(false);
	int T, a, b, w, ans;
	cin >> T;
	bool first = true;
	
	while(T--){
		if(!first) cout << '\n';
		first = false;
		cin >> V >> exit >> threshold >> E;
		
		vector<vector<ii> > AdjList(V+1,vector<ii>());
		for(int i = 0; i < E; i++){
			cin >> a >> b >> w;
			AdjList[b].push_back(ii(a,w));
		}
		
		vi dist(V+1,INF);
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		dist[exit] =ans= 0;
		pq.push(ii(0,exit));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if(d > dist[u]) continue;
			for(int j = 0; j < (int)AdjList[u].size(); j++){
				ii v = AdjList[u][j];
				if(dist[u]+v.second < dist[v.first]){
					dist[v.first] = dist[u]+v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		for(int i = 1; i <= V; i++)
			if(dist[i] <= threshold) ans++;
		
		cout << ans << '\n';
	}
}
