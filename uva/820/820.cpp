#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vi> AdjMat,  dirConn;
vi p;
int n, s, t, c,x, y, w, mf, f;

void augment(int v, int minEdge){
	if(v == s){ f = minEdge; return ;}
	else if(p[v] != -1){
		augment(p[v], min(minEdge,AdjMat[p[v]][v]));
		AdjMat[p[v]][v] -= f;
		AdjMat[v][p[v]] += f;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int caso = 1;
	while(1){
		cin >> n;
		if(n == 0) break;
		cout << "Network " << caso++ << '\n';
		AdjMat.assign(n,vi(n,0));
		dirConn.assign(n,vi(n,false));
		cin >> s >> t >> c;
		s--; t--;
		for(int i = 0; i < c; i++){
			cin >> x >> y >> w;
			x--;y--;
			dirConn[x][y] = dirConn[y][x] = true;
			
			AdjMat[x][y] += w;
			AdjMat[y][x] += w;
		}
		
		
		mf = 0;
		
		while(1){
			f = 0;
			p.assign(n,-1);
			vi dist(n,INF); dist[s] = 0;
			queue<int> q; q.push(s);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == t) break;
				for(int v = 0; v < n; v++)
					if(AdjMat[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u]+1, q.push(v), p[v] = u;
			}
			augment(t, INF);
			if(f == 0) break;
			mf += f;
		}
		cout << "The bandwidth is " << mf << ".\n\n";
	}
}
