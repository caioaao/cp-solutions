#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX_D 1000

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int bombs[MAX_D][MAX_D], visited[MAX_D][MAX_D], R, C, dr[4] = {0,0,-1,1}, dc[4] = {-1,1,0,0};

bool ok(iii p){
	return p.first >= 0 && p.second.first >= 0 && p.first < R && p.second.first < C && !bombs[p.first][p.second.first];
}

int main(){
	ios_base::sync_with_stdio(false);
	int x, y, N, Nr;
	cin >> R >> C;
	while(R != 0){
		cin >> N;
		memset(bombs, 0, sizeof bombs);
		while(N--){
			cin >> x >> Nr;
			while(Nr--){
				cin >> y;
				bombs[x][y] = 1;
			}
		}
		
		memset(visited, 0, sizeof visited);
		
		iii s(0,ii(0,0));
		ii d;
		cin >> s.first >> s.second.first >> d.first >> d.second;
		
		queue <iii> q;
		q.push(s);
		
		while(!q.empty()){
			iii u = q.front(); q.pop();
			if(visited[u.first][u.second.first]) continue;
			visited[u.first][u.second.first] = true;
			for(int i = 0; i < 4; i++){
				iii v(u.first+dr[i], ii(u.second.first+dc[i], u.second.second+1));
				if(ok(v) && !visited[v.first][v.second.first]) q.push(v);
				if(v.first == d.first && v.second.first == d.second){
					cout << v.second.second << '\n';
					goto fim;
				}
			}
		}
		fim:
		cin >> R >> C;
	}
}
