#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ios_base::sync_with_stdio(false);
	int T, V, E, source, target, a, b, w;
	cin >> T;
	vector<vii> AdjList;
	vi dist, reached;
	for(int caso = 1; caso <= T; caso++){
		cout << "Case #" << caso << ": ";
		cin >> V >> E >> source >> target;
		AdjList.assign(V, vii());
		for(int i = 0; i < E; i++){
			cin >> a >> b >> w;
			AdjList[a].push_back(ii(b,w));
			AdjList[b].push_back(ii(a,w));
		}
		dist.assign(V,INF);
		reached.assign(V,0);
		dist[source] = 0;
		priority_queue <ii, vii, greater<ii> > pq;
		pq.push(ii(0,source));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			//if(u == target) break;
			if(d > dist[u]) continue;
			for(int j = 0; j < (int)AdjList[u].size(); j++){
				int v = AdjList[u][j].first, w = AdjList[u][j].second;
				reached[v] = true;
				if(dist[v] > dist[u]+w){
					dist[v] = dist[u]+w;
					pq.push(ii(dist[v],v));
				}
			}
		}
		
		if(reached[target]) cout << dist[target] << '\n';
		else cout << "unreachable" << '\n';
	}
}
