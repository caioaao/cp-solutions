#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX_D 2001

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;


int visited[MAX_D][MAX_D], dist[MAX_D][MAX_D], dr[4] = {0,0,1,-1}, dc[4] = {1,-1,0,0};

int ok(ii p){
	return (p.first >= 0 && p.second >=0 && p.first <= 2000 && p.second <= 2000);
}

int main(){
	ios_base::sync_with_stdio(false);
	int P1, P2, x, y;
	cin >> P1;
	while(P1 != 0){
		queue<ii> q;
		
		memset(dist,-1, sizeof dist);
		memset(visited, 0, sizeof visited);
		for(int i = 0; i < P1; i++){
			cin >> x >> y;
			dist[x][y] = 0;
			q.push(ii(x,y));
		}
		
		cin >> P2;
		for(int i = 0; i < P2; i++){
			cin >> x >> y;
			visited[x][y] = 2; // goal num
		}
		
		int ans = 1e9;
		while(!q.empty()){
			ii u = q.front(); q.pop();
			if(visited[u.first][u.second] == 1) continue;
			visited[u.first][u.second] = 1;
			for(int i = 0; i < 4; i++){
				ii v(u.first+dr[i],u.second+dc[i]);
				if(ok(v)){
					if(visited[v.first][v.second] == 0){
						q.push(v);
						dist[v.first][v.second] = (dist[v.first][v.second] == -1 ? dist[u.first][u.second]+1 : min(dist[v.first][v.second], dist[u.first][u.second]+1));
					}
					else if(visited[v.first][v.second] == 2) ans = min(ans,dist[u.first][u.second]+1);
				}
			}
		}
		cout << ans << endl;
		cin >> P1;
	}
}
