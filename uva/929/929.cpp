#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define INF 1e9

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

ll m, n, maze[999][999], dist[999][999];
ll vr[4] = {0, 1, 0, -1}, vc[4] = {1, 0, -1, 0};

int main(){
	ios_base::sync_with_stdio(false);
	
	priority_queue <iii, vector<iii>, greater<iii> > pq;
		
	ll t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		memset(maze, -1, sizeof maze);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = INF;
				cin >> maze[i][j];
			}
		}
		
		dist[0][0] =maze[0][0];
		
		pq.push(iii(dist[0][0],ii(0,0)));

		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			int d = front.first; ii u = front.second;
			if(d > dist[u.first][u.second]) continue;
			
			for(int j = 0; j < 4; j++){
				ii v = ii(vr[j]+u.first, vc[j]+u.second);
				if(v.first >= m || v.second >= n || v.first < 0 || v.second < 0) continue;
				
				if(dist[u.first][u.second] + maze[v.first][v.second] < dist[v.first][v.second]){
					dist[v.first][v.second] = dist[u.first][u.second] + maze[v.first][v.second];
					pq.push(iii(dist[v.first][v.second], v));					
				}
			}
		}
		
		cout << dist[m-1][n-1] << '\n';
	}
}
