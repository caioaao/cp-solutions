#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

#define INF 1e9

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


/*
 * > AdjList indexing explanation
 *   Apps: 0-25, PCs: 26-35, source: 36, target: 37
 * 
 */
vector<vi> AdjMat;
int mf, f, ssource = 36, starget = 37;
vi p;

void augment(int v, int minEdge){
	if(v == ssource) {f = minEdge; return ; }
	else if(p[v] != -1){
		augment(p[v], min(minEdge, AdjMat[p[v]][v]));
		AdjMat[p[v]][v] -= f;
		AdjMat[v][p[v]] += f;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	string line;
	while(getline(cin,line)){
		AdjMat.assign(38,vi(38,0));
		for(int i =26; i < 36; i++){
			AdjMat[i][starget] = 1;
		}
		
		int nUsers, amt = 0;
		char app;
		
		while(line != ""){
			app = line[0]; nUsers = line[1];
			amt += nUsers-'0';
			AdjMat[ssource][app-'A']+=nUsers-'0';
			for(int i = 3; i < (int)line.length()-1; i++){
				AdjMat[app-'A'][line[i]-'0'+26] = 1;
			}
			getline(cin,line);
		}
		/*
		for(int i = 0; i < 38; i++){
			cout << i << ": ";
			for(int j = 0; j < AdjMat[i].size(); j++) cout << j << ':' << AdjMat[i][j] << ' ';
			cout << endl;
		}*/
		
		mf = 0;
		while(1){
			f = 0;
			vi dist(38,INF); dist[ssource] = 0; queue<int> q; q.push(ssource);
			p.assign(38, -1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == starget) break;
				for(int v = 0; v < 38; v++)
					if(AdjMat[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u]+1, q.push(v), p[v] = u;
			}
			augment(starget,INF);
			if(f == 0) break;
			mf += f;
		}
		if(mf == amt){
			for(int i = 26; i < 36; i++){
				bool has = false;
				for(int j = 0; j < 26; j++){
					if(AdjMat[i][j] == 1){
						has = true;
						app = j+'A';
						cout << app;
						break;
					}
				}
				if(!has) cout << '_';
			}
			cout << '\n';
		}
		else cout << "!\n";
	}
}
