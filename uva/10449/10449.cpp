#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ii> vii;
typedef vector<ll> vi;

int N, tc = 1, E, a, b, Q;
vi scores, costs, reachable;
vector<vii> AdjList;
vi uSets;

int main(){
	ios_base::sync_with_stdio(false);
	
	while(cin >> N){
		cout << "Set #" << tc++ << '\n';
		if(N == 0) continue;
		scores.assign(N, 0);
		AdjList.assign(N,vii());
		
		for(int i = 0; i < N; i++) cin >> scores[i];
		
		cin >> E;
		
		for(int i = 0; i < E; i++){
			cin >> a >> b;
			a--; b--;
			AdjList[a].push_back(ii(b,(scores[b]-scores[a])*(scores[b]-scores[a])*(scores[b]-scores[a])));
		}
		
		costs.assign(N,INF);
		reachable.assign(N,false);
		costs[0] = 0;
		for(int i = 0; i < N; i++)
			for(int u = 0; u < N; u++)
				for(int j = 0; j < (int)AdjList[u].size(); j++){
					ii v = AdjList[u][j];
					if(costs[v.first] > costs[u]+v.second && costs[u] != INF){
						reachable[v.first] = true;
						costs[v.first] = costs[u]+v.second;
					}
				}
		
		for(int u = 0; u < N; u++)
			for(int j = 0; j < (int)AdjList[u].size(); j++){
				ii v = AdjList[u][j];
				if(costs[v.first] > costs[u]+v.second){
					reachable[v.first] = false;
					costs[v.first] = costs[u]+v.second;
				}
						
				}
		cin >> Q;
		while(Q--){
			cin >> a; a--;
			if(a < N && a >= 0 && reachable[a] && costs[a] >= 3) cout << costs[a] << '\n';
			else cout << "?\n";
		}
	}
}
